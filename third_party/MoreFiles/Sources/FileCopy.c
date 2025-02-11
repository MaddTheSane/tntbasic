/*
	File:		FileCopy.c

	Contains:	A robust, general purpose file copy routine.

	Version:	MoreFiles

	Copyright:	� 1992-2002 by Apple Computer, Inc., all rights reserved.

	Disclaimer:	IMPORTANT:  This Apple software is supplied to you by Apple Computer, Inc.
				("Apple") in consideration of your agreement to the following terms, and your
				use, installation, modification or redistribution of this Apple software
				constitutes acceptance of these terms.  If you do not agree with these terms,
				please do not use, install, modify or redistribute this Apple software.

				In consideration of your agreement to abide by the following terms, and subject
				to these terms, Apple grants you a personal, non-exclusive license, under Apple�s
				copyrights in this original Apple software (the "Apple Software"), to use,
				reproduce, modify and redistribute the Apple Software, with or without
				modifications, in source and/or binary forms; provided that if you redistribute
				the Apple Software in its entirety and without modifications, you must retain
				this notice and the following text and disclaimers in all such redistributions of
				the Apple Software.  Neither the name, trademarks, service marks or logos of
				Apple Computer, Inc. may be used to endorse or promote products derived from the
				Apple Software without specific prior written permission from Apple.  Except as
				expressly stated in this notice, no other rights or licenses, express or implied,
				are granted by Apple herein, including but not limited to any patent rights that
				may be infringed by your derivative works or by other works in which the Apple
				Software may be incorporated.

				The Apple Software is provided by Apple on an "AS IS" basis.  APPLE MAKES NO
				WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION THE IMPLIED
				WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A PARTICULAR
				PURPOSE, REGARDING THE APPLE SOFTWARE OR ITS USE AND OPERATION ALONE OR IN
				COMBINATION WITH YOUR PRODUCTS.

				IN NO EVENT SHALL APPLE BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL OR
				CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
				GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
				ARISING IN ANY WAY OUT OF THE USE, REPRODUCTION, MODIFICATION AND/OR DISTRIBUTION
				OF THE APPLE SOFTWARE, HOWEVER CAUSED AND WHETHER UNDER THEORY OF CONTRACT, TORT
				(INCLUDING NEGLIGENCE), STRICT LIABILITY OR OTHERWISE, EVEN IF APPLE HAS BEEN
				ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

	File Ownership:

		DRI:				Apple Macintosh Developer Technical Support

		Other Contact:		Apple Macintosh Developer Technical Support
							<http://developer.apple.com/bugreporter/>

		Technology:			DTS Sample Code

	Writers:

		(JL)	Jim Luther

	Change History (most recent first):

		 <4>	10/24/02	JL		[3074862]  Added work around for the PBHGetVolParms vMServerAdr
									problem in the Mac OS X Carbon File Manager (3074835).
		 <3>	 8/23/02	JL		[2853901]  Updated standard disclaimer.
		 <2>	  2/7/01	JL		Added standard header. Updated names of includes. Updated
									various routines to use new calling convention of the
									MoreFilesExtras accessor functions.
		<1>		12/06/99	JL		MoreFiles 1.5.
*/

#include <MacTypes.h>
#include <Carbon/Carbon.h>

#define	__COMPILINGMOREFILES

#include "MoreFiles.h"
#include "MoreFilesExtras.h"
#include "MoreDesktopMgr.h"
#include "FileCopy.h"

/*****************************************************************************/

/* local constants */

/*	The deny-mode privileges to use when opening the source and destination files. */

enum
{
	srcCopyMode = dmRdDenyWr,
	dstCopyMode = dmWrDenyRdWr
};

/*	The largest (16K) and smallest (.5K) copy buffer to use if the caller doesn't supply 
**	their own copy buffer. */

enum
{
	bigCopyBuffSize  = 0x00004000,
	minCopyBuffSize  = 0x00000200
};

/*****************************************************************************/

/* static prototypes */

static	OSErr	GetDestinationDirInfo(short vRefNum,
									  long dirID,
									  ConstStr255Param name,
									  long *theDirID,
									  Boolean *isDirectory,
									  Boolean *isDropBox);
/*	GetDestinationDirInfo tells us if the destination is a directory, it's
	directory ID, and if it's an AppleShare drop box (write privileges only --
	no read or search privileges).
	vRefNum		input:	Volume specification.
	dirID		input:	Directory ID.
	name		input:	Pointer to object name, or nil when dirID
						specifies a directory that's the object.
	theDirID	output:	If the object is a file, then its parent directory
						ID. If the object is a directory, then its ID.
	isDirectory	output:	True if object is a directory; false if
						object is a file.
	isDropBox	output:	True if directory is an AppleShare drop box.
*/

static	OSErr	CheckForForks(short vRefNum,
							  long dirID,
							  ConstStr255Param name,
							  Boolean *hasDataFork,
							  Boolean *hasResourceFork);
/*	CheckForForks tells us if there is a data or resource fork to copy.
	vRefNum		input:	Volume specification of the file's current
							location.
	dirID		input:	Directory ID of the file's current location.
	name		input:	The name of the file.
*/

static	OSErr	PreflightFileCopySpace(short srcVRefNum,
									   long srcDirID,
									   ConstStr255Param srcName,
									   ConstStr255Param dstVolName,
									   short dstVRefNum,
									   Boolean *spaceOK);
/*	PreflightFileCopySpace determines if there's enough space on a
	volume to copy the specified file to that volume.
	Note: The results of this routine are not perfect. For example if the
	volume's catalog or extents overflow file grows when the new file is
	created, more allocation blocks may be needed beyond those needed for
	the file's data and resource forks.

	srcVRefNum		input:	Volume specification of the file's current
							location.
	srcDirID		input:	Directory ID of the file's current location.
	srcName			input:	The name of the file.
	dstVolName		input:	A pointer to the name of the volume where
							the file will be copied or NULL.
	dstVRefNum		input:	Volume specification indicating the volume
							where the file will be copied.
	spaceOK			output:	true if there's enough space on the volume for
							the file's data and resource forks.
*/

/*****************************************************************************/

static	OSErr	GetDestinationDirInfo(short vRefNum,
									  long dirID,
									  ConstStr255Param name,
									  long *theDirID,
									  Boolean *isDirectory,
									  Boolean *isDropBox)
{
	CInfoPBRec pb;
	OSErr error;

	pb.dirInfo.ioACUser = 0;	/* ioACUser used to be filler2, clear it before calling GetCatInfo */
	error = GetCatInfoNoName(vRefNum, dirID, name, &pb);
	*theDirID = pb.dirInfo.ioDrDirID;
	*isDirectory = (pb.dirInfo.ioFlAttrib & kioFlAttribDirMask) != 0;
	/* see if access priviledges are make changes, not see folder, and not see files (drop box) */
	*isDropBox = userHasDropBoxAccess(pb.dirInfo.ioACUser);
	
	return ( error );
}

/*****************************************************************************/

static	OSErr	CheckForForks(short vRefNum,
							  long dirID,
							  ConstStr255Param name,
							  Boolean *hasDataFork,
							  Boolean *hasResourceFork)
{
	HParamBlockRec pb;
	OSErr error;
	
	pb.fileParam.ioNamePtr = (StringPtr)name;
	pb.fileParam.ioVRefNum = vRefNum;
	pb.fileParam.ioFVersNum = 0;
	pb.fileParam.ioDirID = dirID;
	pb.fileParam.ioFDirIndex = 0;
	error = PBHGetFInfoSync(&pb);
	*hasDataFork = (pb.fileParam.ioFlLgLen != 0);
	*hasResourceFork = (pb.fileParam.ioFlRLgLen != 0);
	
	return ( error );
}

/*****************************************************************************/

static	OSErr	PreflightFileCopySpace(short srcVRefNum,
									   long srcDirID,
									   ConstStr255Param srcName,
									   ConstStr255Param dstVolName,
									   short dstVRefNum,
									   Boolean *spaceOK)
{
	UniversalFMPB pb;
	OSErr error;
	unsigned long dstFreeBlocks;
	unsigned long dstBlksPerAllocBlk;
	unsigned long srcDataBlks;
	unsigned long srcResourceBlks;
	
	error = XGetVolumeInfoNoName(dstVolName, dstVRefNum, &pb.xPB);
	if ( error == noErr )
	{
		/* get allocation block size (always multiple of 512) and divide by 512
		  to get number of 512-byte blocks per allocation block */
		dstBlksPerAllocBlk = ((unsigned long)pb.xPB.ioVAlBlkSiz >> 9);
		
		/* Convert freeBytes to free disk blocks (512-byte blocks) */
		dstFreeBlocks = U32SetU(U64ShiftRight(pb.xPB.ioVFreeBytes, 9));
		
		/* Now, get the size of the file's data resource forks */
		pb.hPB.fileParam.ioNamePtr = (StringPtr)srcName;
		pb.hPB.fileParam.ioVRefNum = srcVRefNum;
		pb.hPB.fileParam.ioFVersNum = 0;
		pb.hPB.fileParam.ioDirID = srcDirID;
		pb.hPB.fileParam.ioFDirIndex = 0;
		error = PBHGetFInfoSync(&pb.hPB);
		if ( error == noErr )
		{
			/* Since space on Mac OS disks is always allocated in allocation blocks, */
			/* this code takes into account rounding up to the end of an allocation block. */

			/* get number of 512-byte blocks needed for data fork */
			if ( ((unsigned long)pb.hPB.fileParam.ioFlLgLen & 0x000001ff) != 0 )
			{
				srcDataBlks = ((unsigned long)pb.hPB.fileParam.ioFlLgLen >> 9) + 1;
			}
			else
			{
				srcDataBlks = (unsigned long)pb.hPB.fileParam.ioFlLgLen >> 9;
			}
			
			/* now, calculate number of new allocation blocks needed */
			if ( srcDataBlks % dstBlksPerAllocBlk )
			{
				srcDataBlks = (srcDataBlks / dstBlksPerAllocBlk) + 1;
			}
			else
			{
				srcDataBlks /= dstBlksPerAllocBlk;
			}
		
			/* get number of 512-byte blocks needed for resource fork */
			if ( ((unsigned long)pb.hPB.fileParam.ioFlRLgLen & 0x000001ff) != 0 )
			{
				srcResourceBlks = ((unsigned long)pb.hPB.fileParam.ioFlRLgLen >> 9) + 1;
			}
			else
			{
				srcResourceBlks = (unsigned long)pb.hPB.fileParam.ioFlRLgLen >> 9;
			}

			/* now, calculate number of new allocation blocks needed */
			if ( srcResourceBlks % dstBlksPerAllocBlk )
			{
				srcResourceBlks = (srcResourceBlks / dstBlksPerAllocBlk) + 1;
			}
			else
			{
				srcResourceBlks /= dstBlksPerAllocBlk;
			}
			
			/* Is there enough room on the destination volume for the source file? */
			*spaceOK = ( ((srcDataBlks + srcResourceBlks) * dstBlksPerAllocBlk) <= dstFreeBlocks );
		}
	}
	
	return ( error );
}

/*****************************************************************************/

pascal	OSErr	FileCopy(short srcVRefNum,
						 long srcDirID,
						 ConstStr255Param srcName,
						 short dstVRefNum,
						 long dstDirID,
						 ConstStr255Param dstPathname,
						 ConstStr255Param copyName,
						 void *copyBufferPtr,
						 long copyBufferSize,
						 Boolean preflight)
{
	OSErr	err;

	short	srcRefNum = 0,			/* 0 when source data and resource fork are closed  */
			dstDataRefNum = 0,		/* 0 when destination data fork is closed */
			dstRsrcRefNum = 0;		/* 0 when destination resource fork is closed */
	
	Str63	dstName;				/* The filename of the destination. It might be the
									** source filename, it might be a new name... */
	
	GetVolParmsInfoBuffer infoBuffer; /* Where PBGetVolParms dumps its info */
	long	srcServerAdr;			/* AppleTalk server address of source (if any) */
	
	Boolean	dstCreated = false,		/* true when destination file has been created */
			ourCopyBuffer = false,	/* true if we had to allocate the copy buffer */
			isDirectory,			/* true if destination is really a directory */
			isDropBox;				/* true if destination is an AppleShare drop box */
	
	long	tempLong;
	short	tempInt;
	
	Boolean	spaceOK;				/* true if there's enough room to copy the file to the destination volume */

	Boolean	hasDataFork;
	Boolean	hasResourceFork;

	/* Preflight for size */
	if ( preflight )
	{
		err = PreflightFileCopySpace(srcVRefNum, srcDirID, srcName,
									 dstPathname, dstVRefNum, &spaceOK);
		if ( err != noErr )
		{
			return ( err );
		}
		
		if ( !spaceOK )
		{
			return ( dskFulErr );
		}
	}

	/* get the destination's real dirID and make sure it really is a directory */
	err = GetDestinationDirInfo(dstVRefNum, dstDirID, dstPathname,
								&dstDirID, &isDirectory, &isDropBox);
	if ( err != noErr )
	{
		goto ErrorExit;
	}
	
	if ( !isDirectory )
	{
		return ( dirNFErr );
	}

	/* get the destination's real vRefNum */
	err = DetermineVRefNum(dstPathname, dstVRefNum, &dstVRefNum);
	if ( err != noErr )
	{
		goto ErrorExit;
	}
	
	/* See if PBHCopyFile can be used.  Using PBHCopyFile saves time by letting the file server
	** copy the file if the source and destination locations are on the same file server. */
	tempLong = sizeof(infoBuffer);
	err = HGetVolParms(srcName, srcVRefNum, &infoBuffer, &tempLong);
	if ( (err != noErr) && (err != paramErr) )
	{
		return ( err );
	}

	if ( (err != paramErr) && hasCopyFile(&infoBuffer) )
	{
		/* The source volume supports PBHCopyFile. */
		srcServerAdr = infoBuffer.vMServerAdr;

		/* Now, see if the destination volume is on the same file server. */
		tempLong = sizeof(infoBuffer);
		err = HGetVolParms(NULL, dstVRefNum, &infoBuffer, &tempLong);
		if ( (err != noErr) && (err != paramErr) )
		{
			return ( err );
		}
		if ( (err != paramErr) && (srcServerAdr == infoBuffer.vMServerAdr) )
		{
			/* Source and Dest are on same server and PBHCopyFile is supported. Copy with CopyFile. */
			
			/* Note: the Mac OS X Carbon File Manager in 10.2 doesn't return unique
			** vMServerAdr values for network volumes on different servers -- instead it
			** returns 1 for all network volumes. When PBBHCopyFile is called with
			** netowork volumes which are not on the same server, the Carbon
			** File Manager returns the error result diffVolErr. So, as a work-around
			** for that bug a diffVolErr result will not fail, it will just
			** fall through to the code that copies a file when PBBHCopyFile cannot
			** be used. */
			
			err = HCopyFile(srcVRefNum, srcDirID, srcName, dstVRefNum, dstDirID, NULL, copyName);
			if ( err == noErr )
			{
				/* AppleShare's CopyFile clears the isAlias bit, so I still need to attempt to copy
				   the File's attributes to attempt to get things right. */
				if ( copyName != NULL )				/* Did caller supply copy file name? */
				{
					/* Yes, use the caller supplied copy file name. */
					(void) CopyFileMgrAttributes(srcVRefNum, srcDirID, srcName,
												 dstVRefNum, dstDirID, copyName, true);
				}
				else
				{
					/* They didn't, so get the source file name and use it. */
					if ( GetFilenameFromPathname(srcName, dstName) == noErr )
					{
						/* */
						(void) CopyFileMgrAttributes(srcVRefNum, srcDirID, srcName,
													 dstVRefNum, dstDirID, dstName, true);
					}
				}
				return ( err );
			}
			else if ( err != diffVolErr )
			{
				return ( err );
			}
			/* else fall through to the code that copies the file by hand */
		}
	}

	/* If we're here, then PBHCopyFile couldn't be used so we have to copy the file by hand. */

	/* Make sure a copy buffer is allocated. */
	if ( copyBufferPtr == NULL )
	{
		/* The caller didn't supply a copy buffer so grab one from the application heap.
		** Try to get a big copy buffer, if we can't, try for a 512-byte buffer.
		** If 512 bytes aren't available, we're in trouble. */
		copyBufferSize = bigCopyBuffSize;
		copyBufferPtr = NewPtr(copyBufferSize);
		if ( copyBufferPtr == NULL )
		{
			copyBufferSize = minCopyBuffSize;
			copyBufferPtr = NewPtr(copyBufferSize);
			if ( copyBufferPtr == NULL )
			{
				return ( memFullErr );
			}
		}
		ourCopyBuffer = true;
	}

	/* Open the source data fork. */
	err = HOpenAware(srcVRefNum, srcDirID, srcName, srcCopyMode, &srcRefNum);
	if ( err != noErr )
		return ( err );
	
	/* Once a file is opened, we have to exit via ErrorExit to make sure things are cleaned up */
	
	/* See if the copy will be renamed. */
	if ( copyName != NULL )				/* Did caller supply copy file name? */
		BlockMoveData(copyName, dstName, copyName[0] + 1);	/* Yes, use the caller supplied copy file name. */
	else
	{	/* They didn't, so get the source file name and use it. */
		err = GetFileLocation(srcRefNum, &tempInt, &tempLong, dstName);
		if ( err != noErr )
		{
			goto ErrorExit;
		}
	}

	/* Create the destination file. */
	err = HCreateMinimum(dstVRefNum, dstDirID, dstName);
	if ( err != noErr )
	{
		goto ErrorExit;
	}
	dstCreated = true;	/* After creating the destination file, any
						** error conditions should delete the destination file */

	/* An AppleShare dropbox folder is a folder for which the user has the Make Changes
	** privilege (write access), but not See Files (read access) and See Folders (search access).
	** Copying a file into an AppleShare dropbox presents some special problems. Here are the
	** rules we have to follow to copy a file into a dropbox:
	** � File attributes can be changed only when both forks of a file are empty.
	** � DeskTop Manager comments can be added to a file only when both forks of a file 
	**   are empty.
	** � A fork can be opened for write access only when both forks of a file are empty.
	** So, with those rules to live with, we'll do those operations now while both forks
	** are empty. */

	if ( isDropBox )
	{
		/* We only set the file attributes now if the file is being copied into a
		** drop box. In all other cases, it is better to set the attributes last
		** so that if FileCopy is modified to give up time to other processes
		** periodicly, the Finder won't try to read any bundle information (because
		** the bundle-bit will still be clear) from a partially copied file. If the
		** copy is into a drop box, we have to set the attributes now, but since the
		** destination forks are opened with write/deny-read/deny-write permissions,
		** any Finder that might see the file in the drop box won't be able to open
		** its resource fork until the resource fork is closed.
		**
		** Note: if you do modify FileCopy to give up time to other processes, don't
		** give up time between the time the destination file is created (above) and
		** the time both forks are opened (below). That way, you stand the best chance
		** of making sure the Finder doesn't read a partially copied resource fork.
		*/
		/* Copy attributes but don't lock the destination. */
		err = CopyFileMgrAttributes(srcVRefNum, srcDirID, srcName,
									dstVRefNum, dstDirID, dstName, false);
		if ( err != noErr )
		{
			goto ErrorExit;
		}
	}

	/* Attempt to copy the comments while both forks are empty.
	** Ignore the result because we really don't care if it worked or not. */
	(void) DTCopyComment(srcVRefNum, srcDirID, srcName, dstVRefNum, dstDirID, dstName);

	/* See which forks we need to copy. By doing this, we won't create a data or resource fork
	** for the destination unless it's really needed (some foreign file systems such as
	** the ProDOS File System and Macintosh PC Exchange have to create additional disk
	** structures to support resource forks). */
	err = CheckForForks(srcVRefNum, srcDirID, srcName, &hasDataFork, &hasResourceFork);
	if ( err != noErr )
	{
		goto ErrorExit;
	}
	
	if ( hasDataFork )
	{
		/* Open the destination data fork. */
		err = HOpenAware(dstVRefNum, dstDirID, dstName, dstCopyMode, &dstDataRefNum);
		if ( err != noErr )
		{
			goto ErrorExit;
		}
	}

	if ( hasResourceFork )
	{
		/* Open the destination resource fork. */
		err = HOpenRFAware(dstVRefNum, dstDirID, dstName, dstCopyMode, &dstRsrcRefNum);
		if ( err != noErr )
		{
			goto ErrorExit;
		}
	}

	if ( hasDataFork )
	{
		/* Copy the data fork. */
		err = CopyFork(srcRefNum, dstDataRefNum, copyBufferPtr, copyBufferSize);
		if ( err != noErr )
		{
			goto ErrorExit;
		}
	
		/* Close both data forks and clear reference numbers. */
		(void) FSClose(srcRefNum);
		(void) FSClose(dstDataRefNum);
		srcRefNum = dstDataRefNum = 0;
	}
	else
	{
		/* Close the source data fork since it was opened earlier */
		(void) FSClose(srcRefNum);
		srcRefNum = 0;
	}

	if ( hasResourceFork )
	{
		/* Open the source resource fork. */
		err = HOpenRFAware(srcVRefNum, srcDirID, srcName, srcCopyMode, &srcRefNum);
		if ( err != noErr )
		{
			goto ErrorExit;
		}
	
		/* Copy the resource fork. */
		err = CopyFork(srcRefNum, dstRsrcRefNum, copyBufferPtr, copyBufferSize);
		if ( err != noErr )
		{
			goto ErrorExit;
		}
	
		/* Close both resource forks and clear reference numbers. */
		(void) FSClose(srcRefNum);
		(void) FSClose(dstRsrcRefNum);
		srcRefNum = dstRsrcRefNum = 0;
	}

	/* Get rid of the copy buffer if we allocated it. */
	if ( ourCopyBuffer )
	{
		DisposePtr((Ptr)copyBufferPtr);
	}

	/* Attempt to copy attributes again to set mod date.  Copy lock condition this time
	** since we're done with the copy operation.  This operation will fail if we're copying
	** into an AppleShare dropbox, so we don't check for error conditions. */
	CopyFileMgrAttributes(srcVRefNum, srcDirID, srcName,
							dstVRefNum, dstDirID, dstName, true);

	/* Hey, we did it! */
	return ( noErr );
	
ErrorExit:
	if ( srcRefNum != 0 )
	{
		(void) FSClose(srcRefNum);		/* Close the source file */
	}
	if ( dstDataRefNum != 0 )
	{
		(void) FSClose(dstDataRefNum);	/* Close the destination file data fork */
	}
	if ( dstRsrcRefNum != 0 )
	{
		(void) FSClose(dstRsrcRefNum);	/* Close the destination file resource fork */
	}
	if ( dstCreated )
	{
		(void) HDelete(dstVRefNum, dstDirID, dstName);	/* Delete dest file.  This may fail if the file 
												   is in a "drop folder" */
	}
	if ( ourCopyBuffer )	/* dispose of any memory we allocated */
	{
		DisposePtr((Ptr)copyBufferPtr);
	}
	
	return ( err );
}

/*****************************************************************************/

pascal	OSErr	FSpFileCopy(const FSSpec *srcSpec,
							const FSSpec *dstSpec,
							ConstStr255Param copyName,
							void *copyBufferPtr,
							long copyBufferSize,
							Boolean preflight)
{
	return ( FileCopy(srcSpec->vRefNum, srcSpec->parID, srcSpec->name,
					 dstSpec->vRefNum, dstSpec->parID, dstSpec->name,
					 copyName, copyBufferPtr, copyBufferSize, preflight) );
}

/*****************************************************************************/

