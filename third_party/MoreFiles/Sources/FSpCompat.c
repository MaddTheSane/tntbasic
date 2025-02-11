/*
	File:		FSpCompat.c

	Contains:	FSSpec compatibility functions.

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

		 <3>	 8/23/02	JL		[2853901, 2936011]  Updated standard disclaimer. Moved
									GenerateUniqueName to MoreFilesExtras.c.
		 <2>	  2/7/01	JL		Added standard header. Updated names of includes. Updated
									various routines to use new calling convention of the
									MoreFilesExtras accessor functions.
		<1>		12/06/99	JL		MoreFiles 1.5.
*/

/*
**	If building application 68K code, set GENERATENODATA to 0 for faster code.
**	If building stand-alone 68K code, set GENERATENODATA to 1 so globals
**		(static variables) are not used.
*/
#ifndef GENERATENODATA
#define GENERATENODATA 0
#endif

#include <MacTypes.h>
#include <Carbon/Carbon.h>

#define	__COMPILINGMOREFILES

#include "MoreFilesExtras.h"
#include "FSpCompat.h"

/*****************************************************************************/

/* local constants */

enum {
	gestaltBugFixAttrsTwo					= 'bugy',
	gestaltFSpExchangeFilesCompatibilityFix	= 26,
	gestaltBugFixAttrsThree					= 'bugx',
	gestaltFSpCreateScriptSupportFix		= 1
};

/*****************************************************************************/

/* static prototypes */


#if !__MACOSSEVENORLATER
static	Boolean	FSHasFSSpecCalls(void);

static	Boolean	QTHasFSSpecCalls(void);
#endif	/* !__MACOSSEVENORLATER */

#if !__MACOSSEVENFIVEORLATER
static	Boolean	HasFSpExchangeFilesCompatibilityFix(void);
#endif	/* !__MACOSSEVENFIVEORLATER */

#if !__MACOSSEVENFIVEONEORLATER
static	Boolean	HasFSpCreateScriptSupportFix(void);
#endif	/* !__MACOSSEVENFIVEONEORLATER */

/*****************************************************************************/

/* FSHasFSSpecCalls returns true if the file system provides FSSpec calls. */

#if !__MACOSSEVENORLATER
static	Boolean	FSHasFSSpecCalls(void)
{
	long			response;
#if !GENERATENODATA
	static Boolean	tested = false;
	static Boolean	result = false;
#else
	Boolean	result = false;
#endif
	
#if !GENERATENODATA
	if ( !tested )
	{
		tested = true;
#endif
		if ( Gestalt(gestaltFSAttr, &response) == noErr )
		{
			result = ((response & (1L << gestaltHasFSSpecCalls)) != 0);
		}
#if !GENERATENODATA
	}
#endif
	return ( result );
}
#endif	/* !__MACOSSEVENORLATER */

/*****************************************************************************/

/* QTHasFSSpecCalls returns true if QuickTime provides FSSpec calls */
/* except for FSpExchangeFiles. */

#if !__MACOSSEVENORLATER
static	Boolean	QTHasFSSpecCalls(void)
{
	long			response;
#if !GENERATENODATA
	static Boolean	tested = false;
	static Boolean	result = false;
#else
	Boolean	result = false;
#endif
	
#if !GENERATENODATA
	if ( !tested )
	{
		tested = true;
#endif
		result = (Gestalt(gestaltQuickTimeVersion, &response) == noErr);
#if !GENERATENODATA
	}
#endif
	return ( result );
}
#endif	/* !__MACOSSEVENORLATER */

/*****************************************************************************/

/* HasFSpExchangeFilesCompatibilityFix returns true if FSpExchangeFiles */
/* compatibility code has been fixed in system software. */
/* This was fixed by System Update 3.0, so if SystemSevenFiveOrLater */
/* is true, then we know the fix is in. */

#if !__MACOSSEVENFIVEORLATER
static	Boolean	HasFSpExchangeFilesCompatibilityFix(void)
{
	long			response;
#if !GENERATENODATA
	static Boolean	tested = false;
	static Boolean	result = false;
#else	/* !GENERATENODATA */
	Boolean	result = false;
#endif	/* !GENERATENODATA */
	
#if !GENERATENODATA
	if ( !tested )
	{
		tested = true;
#endif	/* !GENERATENODATA */
		if ( Gestalt(gestaltBugFixAttrsTwo, &response) == noErr )
		{
			result = ((response & (1L << gestaltFSpExchangeFilesCompatibilityFix)) != 0);
		}
#if !GENERATENODATA
	}
#endif	/* !GENERATENODATA */
	return ( result );
}
#endif	/* !__MACOSSEVENFIVEORLATER */

/*****************************************************************************/

/* HasFSpCreateScriptSupportFix returns true if FSpCreate and */
/* FSpCreateResFile have been fixed in system software to correctly set */
/* the scriptCode in the volume's catalog. */
/* This was fixed by System 7.5 Update 1.0 */

#if !__MACOSSEVENFIVEONEORLATER
static	Boolean	HasFSpCreateScriptSupportFix(void)
{
	long			response;
#if !GENERATENODATA
	static Boolean	tested = false;
	static Boolean	result = false;
#else
	Boolean	result = false;
#endif	/* !GENERATENODATA */
	
#if !GENERATENODATA
	if ( !tested )
	{
		tested = true;
#endif	/* !GENERATENODATA */
		if ( Gestalt(gestaltBugFixAttrsThree, &response) == noErr )
		{
			result = ((response & (1L << gestaltFSpCreateScriptSupportFix)) != 0);
		}
#if !GENERATENODATA
	}
#endif	/* !GENERATENODATA */
	return ( result );
}
#endif	/* !__MACOSSEVENFIVEONEORLATER */

/*****************************************************************************/

/*
**	File Manager FSp calls
*/

/*****************************************************************************/

pascal	OSErr	FSMakeFSSpecCompat(short vRefNum,
								   long dirID,
								   ConstStr255Param fileName,
								   FSSpec *spec)
{
	OSErr	result;
	
#if !__MACOSSEVENORLATER
	if ( !FSHasFSSpecCalls() && !QTHasFSSpecCalls() )
	{
		Boolean	isDirectory;
		
		result = GetObjectLocation(vRefNum, dirID, fileName,
									&(spec->vRefNum), &(spec->parID), spec->name,
									&isDirectory);
	}
	else
#endif	/* !__MACOSSEVENORLATER */
	{
		/* Let the file system create the FSSpec if it can since it does the job */
		/* much more efficiently than I can. */
		result = FSMakeFSSpec(vRefNum, dirID, fileName, spec);

		/* Fix a bug in Macintosh PC Exchange's MakeFSSpec code where 0 is */
		/* returned in the parID field when making an FSSpec to the volume's */
		/* root directory by passing a full pathname in MakeFSSpec's */
		/* fileName parameter. Fixed in Mac OS 8.1 */
		if ( (result == noErr) && (spec->parID == 0) )
			spec->parID = fsRtParID;
	}
	return ( result );
}

/*****************************************************************************/

pascal	OSErr	FSpOpenDFCompat(const FSSpec *spec,
								char permission,
								short *refNum)
{
#if !__MACOSSEVENORLATER
	if ( !FSHasFSSpecCalls() && !QTHasFSSpecCalls() )
	{
		OSErr			result;
		HParamBlockRec	pb;
		
		pb.ioParam.ioVRefNum = spec->vRefNum;
		pb.fileParam.ioDirID = spec->parID;
		pb.ioParam.ioNamePtr = (StringPtr) &(spec->name);
		pb.ioParam.ioVersNum = 0;
		pb.ioParam.ioPermssn = permission;
		pb.ioParam.ioMisc = NULL;
		result = PBHOpenSync(&pb);	/* OpenDF not supported by System 6, so use Open */
		*refNum = pb.ioParam.ioRefNum;
		return ( result );
	}
	else
#endif	/* !__MACOSSEVENORLATER */
	{
		return ( FSpOpenDF(spec, permission, refNum) );
	}
}

/*****************************************************************************/

pascal	OSErr	FSpOpenRFCompat(const FSSpec *spec,
								char permission,
								short *refNum)
{
#if !__MACOSSEVENORLATER
	if ( !FSHasFSSpecCalls() && !QTHasFSSpecCalls() )
	{
		OSErr			result;
		HParamBlockRec	pb;
		
		pb.ioParam.ioVRefNum = spec->vRefNum;
		pb.fileParam.ioDirID = spec->parID;
		pb.ioParam.ioNamePtr = (StringPtr) &(spec->name);
		pb.ioParam.ioVersNum = 0;
		pb.ioParam.ioPermssn = permission;
		pb.ioParam.ioMisc = NULL;
		result = PBHOpenRFSync(&pb);
		*refNum = pb.ioParam.ioRefNum;
		return ( result );
	}
	else
#endif	/* !__MACOSSEVENORLATER */
	{
		return ( FSpOpenRF(spec, permission, refNum) );
	}
}

/*****************************************************************************/

pascal	OSErr	FSpCreateCompat(const FSSpec *spec,
								OSType creator,
								OSType fileType,
								ScriptCode scriptTag)
{
#if !__MACOSSEVENFIVEONEORLATER
	OSErr			result;
	UniversalFMPB	pb;

	
	if (
#if !__MACOSSEVENORLATER
		 (!FSHasFSSpecCalls() && !QTHasFSSpecCalls()) ||
#endif	/* !__MACOSSEVENORLATER */
		 !HasFSpCreateScriptSupportFix() )
	{
		/*	If FSpCreate isn't called, this code will be executed */
		pb.hPB.fileParam.ioVRefNum = spec->vRefNum;
		pb.hPB.fileParam.ioDirID = spec->parID;
		pb.hPB.fileParam.ioNamePtr = (StringPtr) &(spec->name);
		pb.hPB.fileParam.ioFVersNum = 0;
		result = PBHCreateSync(&(pb.hPB));
		if ( result == noErr )
		{
			/* get info on created item */
			pb.ciPB.hFileInfo.ioFDirIndex = 0;
			result = PBGetCatInfoSync(&(pb.ciPB));
			if ( result == noErr )
			{
				/* Set fdScript in FXInfo */
				/* The negative script constants (smSystemScript, smCurrentScript, and smAllScripts) */
				/* don't make sense on disk, so only use scriptTag if scriptTag >= smRoman */
				/* (smRoman is 0). fdScript is valid if high bit is set (see IM-6, page 9-38) */
				pb.ciPB.hFileInfo.ioFlXFndrInfo.fdScript = (scriptTag >= smRoman) ?
															((char)scriptTag | (char)0x80) :
															(smRoman);
				/* Set creator/fileType */
				pb.ciPB.hFileInfo.ioFlFndrInfo.fdCreator = creator;
				pb.ciPB.hFileInfo.ioFlFndrInfo.fdType = fileType;
				/* Restore ioDirID field in pb which was changed by PBGetCatInfo */
				pb.ciPB.hFileInfo.ioDirID = spec->parID;
				result = PBSetCatInfoSync(&(pb.ciPB));
			}
		}
		return ( result );
	}
	else
#endif	/* !__MACOSSEVENFIVEONEORLATER */
	{
		return ( FSpCreate(spec, creator, fileType, scriptTag) );
	}
}

/*****************************************************************************/

pascal	OSErr	FSpDirCreateCompat(const FSSpec *spec,
								   ScriptCode scriptTag,
								   long *createdDirID)
{
#if !__MACOSSEVENORLATER
	if ( !FSHasFSSpecCalls() && !QTHasFSSpecCalls() )
	{
		OSErr			result;
		UniversalFMPB	pb;
		
		pb.hPB.fileParam.ioVRefNum = spec->vRefNum;
		pb.hPB.fileParam.ioDirID = spec->parID;
		pb.hPB.fileParam.ioNamePtr = (StringPtr) &(spec->name);
		result = PBDirCreateSync(&(pb.hPB));
		*createdDirID = pb.hPB.fileParam.ioDirID;
		if ( result == noErr )
		{
			/* get info on created item */
			pb.ciPB.dirInfo.ioFDirIndex = 0;
			pb.ciPB.dirInfo.ioDrDirID = spec->parID;
			result = PBGetCatInfoSync(&(pb.ciPB));
			if ( result == noErr )
			{
				/* Set frScript in DXInfo */
				/* The negative script constants (smSystemScript, smCurrentScript, and smAllScripts) */
				/* don't make sense on disk, so only use scriptTag if scriptTag >= smRoman */
				/* (smRoman is 0). frScript is valid if high bit is set (see IM-6, page 9-38) */
				pb.ciPB.dirInfo.ioDrFndrInfo.frScript = (scriptTag >= smRoman) ?
															((char)scriptTag | (char)0x80) :
															(smRoman);
				/* Restore ioDirID field in pb which was changed by PBGetCatInfo */
				pb.ciPB.dirInfo.ioDrDirID = spec->parID;			
				result = PBSetCatInfoSync(&(pb.ciPB));
			}
		}
		return ( result );
	}
	else
#endif	/* !__MACOSSEVENORLATER */
	{
		return ( FSpDirCreate(spec, scriptTag, createdDirID) );
	}
}

/*****************************************************************************/

pascal	OSErr	FSpDeleteCompat(const FSSpec *spec)
{
#if !__MACOSSEVENORLATER
	if ( !FSHasFSSpecCalls() && !QTHasFSSpecCalls() )
	{
		HParamBlockRec	pb;
		
		pb.ioParam.ioVRefNum = spec->vRefNum;
		pb.fileParam.ioDirID = spec->parID;
		pb.ioParam.ioNamePtr = (StringPtr) &(spec->name);
		pb.ioParam.ioVersNum = 0;
		return ( PBHDeleteSync(&pb) );
	}
	else
#endif	/* !__MACOSSEVENORLATER */
	{
		return ( FSpDelete(spec) );
	}
}

/*****************************************************************************/

pascal	OSErr	FSpGetFInfoCompat(const FSSpec *spec,
								  FInfo *fndrInfo)
{
#if !__MACOSSEVENORLATER
	if ( !FSHasFSSpecCalls() && !QTHasFSSpecCalls() )
	{
		OSErr			result;
		HParamBlockRec	pb;
		
		pb.fileParam.ioVRefNum = spec->vRefNum;
		pb.fileParam.ioDirID = spec->parID;
		pb.fileParam.ioNamePtr = (StringPtr) &(spec->name);
		pb.fileParam.ioFVersNum = 0;
		pb.fileParam.ioFDirIndex = 0;
		result = PBHGetFInfoSync(&pb);
		*fndrInfo = pb.fileParam.ioFlFndrInfo;
		return ( result );
	}
	else
#endif	/* !__MACOSSEVENORLATER */
	{
		return ( FSpGetFInfo(spec, fndrInfo) );
	}
}

/*****************************************************************************/

pascal	OSErr	FSpSetFInfoCompat(const FSSpec *spec,
								  const FInfo *fndrInfo)
{
#if !__MACOSSEVENORLATER
	if ( !FSHasFSSpecCalls() && !QTHasFSSpecCalls() )
	{
		OSErr			result;
		HParamBlockRec	pb;
		
		pb.fileParam.ioVRefNum = spec->vRefNum;
		pb.fileParam.ioDirID = spec->parID;
		pb.fileParam.ioNamePtr = (StringPtr) &(spec->name);
		pb.fileParam.ioFVersNum = 0;
		pb.fileParam.ioFDirIndex = 0;
		result = PBHGetFInfoSync(&pb);
		if ( result == noErr )
		{
			pb.fileParam.ioFlFndrInfo = *fndrInfo;
			pb.fileParam.ioDirID = spec->parID;
			result = PBHSetFInfoSync(&pb);
		}
		return ( result );
	}
	else
#endif	/* !__MACOSSEVENORLATER */
	{
		return ( FSpSetFInfo(spec, fndrInfo) );
	}
}

/*****************************************************************************/

pascal	OSErr	FSpSetFLockCompat(const FSSpec *spec)
{
#if !__MACOSSEVENORLATER
	if ( !FSHasFSSpecCalls() && !QTHasFSSpecCalls() )
	{
		HParamBlockRec	pb;
		
		pb.fileParam.ioVRefNum = spec->vRefNum;
		pb.fileParam.ioDirID = spec->parID;
		pb.fileParam.ioNamePtr = (StringPtr) &(spec->name);
		pb.fileParam.ioFVersNum = 0;
		return ( PBHSetFLockSync(&pb) );
	}
	else
#endif	/* !__MACOSSEVENORLATER */
	{
		return ( FSpSetFLock(spec) );
	}
}

/*****************************************************************************/

pascal	OSErr	FSpRstFLockCompat(const FSSpec *spec)
{
#if !__MACOSSEVENORLATER
	if ( !FSHasFSSpecCalls() && !QTHasFSSpecCalls() )
	{
		HParamBlockRec	pb;
		
		pb.fileParam.ioVRefNum = spec->vRefNum;
		pb.fileParam.ioDirID = spec->parID;
		pb.fileParam.ioNamePtr = (StringPtr) &(spec->name);
		pb.fileParam.ioFVersNum = 0;
		return ( PBHRstFLockSync(&pb) );
	}
	else
#endif	/* !__MACOSSEVENORLATER */
	{
		return ( FSpRstFLock(spec) );
	}
}

/*****************************************************************************/

pascal	OSErr	FSpRenameCompat(const FSSpec *spec,
								ConstStr255Param newName)
{
#if !__MACOSSEVENORLATER
	if ( !FSHasFSSpecCalls() && !QTHasFSSpecCalls() )
	{
		HParamBlockRec	pb;
		
		pb.ioParam.ioVRefNum = spec->vRefNum;
		pb.fileParam.ioDirID = spec->parID;
		pb.ioParam.ioNamePtr = (StringPtr) &(spec->name);
		pb.ioParam.ioVersNum = 0;
		pb.ioParam.ioMisc = (Ptr) newName;
		return ( PBHRenameSync(&pb) );
	}
	else
#endif	/* !__MACOSSEVENORLATER */
	{
		return ( FSpRename(spec, newName) );
	}
}

/*****************************************************************************/

pascal	OSErr	FSpCatMoveCompat(const FSSpec *source,
								 const FSSpec *dest)
{
#if !__MACOSSEVENORLATER
	if ( !FSHasFSSpecCalls() && !QTHasFSSpecCalls() )
	{
		CMovePBRec	pb;
		
		/* source and destination volume must be the same */
		if ( source->vRefNum != dest->vRefNum )
			return ( paramErr );
		
		pb.ioNamePtr = (StringPtr) &(source->name);
		pb.ioVRefNum = source->vRefNum;
		pb.ioDirID = source->parID;
		pb.ioNewDirID = dest->parID;
		pb.ioNewName = (StringPtr) &(dest->name);
		return ( PBCatMoveSync(&pb) );
	}
	else
#endif	/* !__MACOSSEVENORLATER */
	{
		return ( FSpCatMove(source, dest) );
	}
}

/*****************************************************************************/

pascal	OSErr	FSpExchangeFilesCompat(const FSSpec *source,
									   const FSSpec *dest)
{
#if !__MACOSSEVENFIVEORLATER
	if ( 
#if !__MACOSSEVENORLATER
		 !FSHasFSSpecCalls() ||
#endif	/* !__MACOSSEVENORLATER */
		 !HasFSpExchangeFilesCompatibilityFix() )
	{
		HParamBlockRec			pb;
		CInfoPBRec				catInfoSource, catInfoDest;
		OSErr					result, result2;
		Str31					unique1, unique2;
		StringPtr				unique1Ptr, unique2Ptr, swapola;
		GetVolParmsInfoBuffer	volInfo;
		long					theSeed, temp;
		
		/* Make sure the source and destination are on the same volume */
		if ( source->vRefNum != dest->vRefNum )
		{
			result = diffVolErr;
			goto errorExit3;
		}
		
		/* Try PBExchangeFiles first since it preserves the file ID reference */
		pb.fidParam.ioNamePtr = (StringPtr) &(source->name);
		pb.fidParam.ioVRefNum = source->vRefNum;
		pb.fidParam.ioDestNamePtr = (StringPtr) &(dest->name);
		pb.fidParam.ioDestDirID = dest->parID;
		pb.fidParam.ioSrcDirID = source->parID;
	
		result = PBExchangeFilesSync(&pb);
	
		/* Note: The compatibility case won't work for files with *Btree control blocks. */
		/* Right now the only *Btree files are created by the system. */
		if ( result != noErr )
		{
			pb.ioParam.ioNamePtr = NULL;
			pb.ioParam.ioBuffer = (Ptr) &volInfo;
			pb.ioParam.ioReqCount = sizeof(volInfo);
			result2 = PBHGetVolParmsSync(&pb);
			
			/* continue if volume has no fileID support (or no GetVolParms support) */
			if ( (result2 == noErr) && hasFileIDs(&volInfo) )
			{
				goto errorExit3;
			}
	
			/* Get the catalog information for each file */
			/* and make sure both files are *really* files */
			catInfoSource.hFileInfo.ioVRefNum = source->vRefNum;
			catInfoSource.hFileInfo.ioFDirIndex = 0;
			catInfoSource.hFileInfo.ioNamePtr = (StringPtr) &(source->name);
			catInfoSource.hFileInfo.ioDirID = source->parID;
			catInfoSource.hFileInfo.ioACUser = 0; /* ioACUser used to be filler2 */
			result = PBGetCatInfoSync(&catInfoSource);
			if ( result != noErr )
			{
				goto errorExit3;
			}
			if ( (catInfoSource.hFileInfo.ioFlAttrib & kioFlAttribDirMask) != 0 )
			{
				result = notAFileErr;
				goto errorExit3;
			}
			
			catInfoDest.hFileInfo.ioVRefNum = dest->vRefNum;
			catInfoDest.hFileInfo.ioFDirIndex = 0;
			catInfoDest.hFileInfo.ioNamePtr = (StringPtr) &(dest->name);
			catInfoDest.hFileInfo.ioDirID = dest->parID;
			catInfoDest.hFileInfo.ioACUser = 0; /* ioACUser used to be filler2 */
			result = PBGetCatInfoSync(&catInfoDest);
			if ( result != noErr )
			{
				goto errorExit3;
			}
			if ( (catInfoDest.hFileInfo.ioFlAttrib & kioFlAttribDirMask) != 0 )
			{
				result = notAFileErr;
				goto errorExit3;
			}
			
			/* generate 2 filenames that are unique in both directories */
			theSeed = 0x64666A6C;	/* a fine unlikely filename */
			unique1Ptr = (StringPtr)&unique1;
			unique2Ptr = (StringPtr)&unique2;
			
			result = GenerateUniqueName(source->vRefNum, &theSeed, source->parID, dest->parID, unique1Ptr);
			if ( result != noErr )
			{
				goto errorExit3;
			}
	
			GenerateUniqueName(source->vRefNum, &theSeed, source->parID, dest->parID, unique2Ptr);
			if ( result != noErr )
			{
				goto errorExit3;
			}
	
			/* rename source to unique1 */
			pb.fileParam.ioNamePtr = (StringPtr) &(source->name);
			pb.ioParam.ioMisc = (Ptr) unique1Ptr;
			pb.ioParam.ioVersNum = 0;
			result = PBHRenameSync(&pb);
			if ( result != noErr )
			{
				goto errorExit3;
			}
			
			/* rename dest to unique2 */
			pb.ioParam.ioMisc = (Ptr) unique2Ptr;
			pb.ioParam.ioVersNum = 0;
			pb.fileParam.ioNamePtr = (StringPtr) &(dest->name);
			pb.fileParam.ioDirID = dest->parID;
			result = PBHRenameSync(&pb);
			if ( result != noErr )
			{
				goto errorExit2;	/* back out gracefully by renaming unique1 back to source */
			}
				
			/* If files are not in same directory, swap their locations */
			if ( source->parID != dest->parID )
			{
				/* move source file to dest directory */
				pb.copyParam.ioNamePtr = unique1Ptr;
				pb.copyParam.ioNewName = NULL;
				pb.copyParam.ioNewDirID = dest->parID;
				pb.copyParam.ioDirID = source->parID;
				result = PBCatMoveSync((CMovePBPtr) &pb);
				if ( result != noErr )
				{
					goto errorExit1;	/* back out gracefully by renaming both files to original names */
				}
				
				/* move dest file to source directory */
				pb.copyParam.ioNamePtr = unique2Ptr;
				pb.copyParam.ioNewDirID = source->parID;
				pb.copyParam.ioDirID = dest->parID;
				result = PBCatMoveSync((CMovePBPtr) &pb);
				if ( result != noErr)
				{
					/* life is very bad.  We'll at least try to move source back */
					pb.copyParam.ioNamePtr = unique1Ptr;
					pb.copyParam.ioNewName = NULL;
					pb.copyParam.ioNewDirID = source->parID;
					pb.copyParam.ioDirID = dest->parID;
					(void) PBCatMoveSync((CMovePBPtr) &pb);	/* ignore errors */
					goto errorExit1;	/* back out gracefully by renaming both files to original names */
				}
			}
			
			/* Make unique1Ptr point to file in source->parID */
			/* and unique2Ptr point to file in dest->parID */
			/* This lets us fall through to the rename code below */
			swapola = unique1Ptr;
			unique1Ptr = unique2Ptr;
			unique2Ptr = swapola;
	
			/* At this point, the files are in their new locations (if they were moved) */
			/* Source is named Unique1 (name pointed to by unique2Ptr) and is in dest->parID */
			/* Dest is named Unique2 (name pointed to by unique1Ptr) and is in source->parID */
			/* Need to swap attributes except mod date and swap names */
	
			/* swap the catalog info by re-aiming the CInfoPB's */
			catInfoSource.hFileInfo.ioNamePtr = unique1Ptr;
			catInfoDest.hFileInfo.ioNamePtr = unique2Ptr;
			
			catInfoSource.hFileInfo.ioDirID = source->parID;
			catInfoDest.hFileInfo.ioDirID = dest->parID;
			
			/* Swap the original mod dates with each file */
			temp = catInfoSource.hFileInfo.ioFlMdDat;
			catInfoSource.hFileInfo.ioFlMdDat = catInfoDest.hFileInfo.ioFlMdDat;
			catInfoDest.hFileInfo.ioFlMdDat = temp;
			
			/* Here's the swap (ignore errors) */
			(void) PBSetCatInfoSync(&catInfoSource); 
			(void) PBSetCatInfoSync(&catInfoDest);
			
			/* rename unique2 back to dest */
errorExit1:
			pb.ioParam.ioMisc = (Ptr) &(dest->name);
			pb.ioParam.ioVersNum = 0;
			pb.fileParam.ioNamePtr = unique2Ptr;
			pb.fileParam.ioDirID = dest->parID;
			(void) PBHRenameSync(&pb);	/* ignore errors */
	
			/* rename unique1 back to source */
errorExit2:
			pb.ioParam.ioMisc = (Ptr) &(source->name);
			pb.ioParam.ioVersNum = 0;
			pb.fileParam.ioNamePtr = unique1Ptr;
			pb.fileParam.ioDirID = source->parID;
			(void) PBHRenameSync(&pb); /* ignore errors */
		}
errorExit3: { /* null statement */ }
		return ( result );
	}
	else
#endif	/* !__MACOSSEVENFIVEORLATER */
	{
		return ( FSpExchangeFiles(source, dest) );
	}
}

/*****************************************************************************/

/* 
**	Resource Manager FSp calls
*/

/*****************************************************************************/

pascal	short	FSpOpenResFileCompat(const FSSpec *spec,
									 SignedByte permission)
{
#if !__MACOSSEVENORLATER
	if ( !FSHasFSSpecCalls() && !QTHasFSSpecCalls() )
	{
		return ( HOpenResFile(spec->vRefNum, spec->parID, spec->name, permission) );
	}
	else
#endif	/* !__MACOSSEVENORLATER */
	{
		return ( FSpOpenResFile(spec, permission) );
	}
}

/*****************************************************************************/

pascal	void	FSpCreateResFileCompat(const FSSpec *spec,
									   OSType creator,
									   OSType fileType,
									   ScriptCode scriptTag)
{	
#if !__MACOSSEVENFIVEONEORLATER
	if (
#if !__MACOSSEVENORLATER
		 (!FSHasFSSpecCalls() && !QTHasFSSpecCalls()) ||
#endif	/* !__MACOSSEVENORLATER */
		 !HasFSpCreateScriptSupportFix() )
	{
		OSErr			result;
		CInfoPBRec		pb;
		
		HCreateResFile(spec->vRefNum, spec->parID, spec->name);
		if ( ResError() == noErr )
		{
			/* get info on created item */
			pb.hFileInfo.ioVRefNum = spec->vRefNum;
			pb.hFileInfo.ioDirID = spec->parID;
			pb.hFileInfo.ioNamePtr = (StringPtr) &(spec->name);
			pb.hFileInfo.ioFDirIndex = 0;
			result = PBGetCatInfoSync(&pb);
			if ( result == noErr )
			{
				/* Set fdScript in FXInfo */
				/* The negative script constants (smSystemScript, smCurrentScript, and smAllScripts) */
				/* don't make sense on disk, so only use scriptTag if scriptTag >= smRoman */
				/* (smRoman is 0). fdScript is valid if high bit is set (see IM-6, page 9-38) */
				pb.hFileInfo.ioFlXFndrInfo.fdScript = (scriptTag >= smRoman) ?
														((char)scriptTag | (char)0x80) :
														(smRoman);
				/* Set creator/fileType */
				pb.hFileInfo.ioFlFndrInfo.fdCreator = creator;
				pb.hFileInfo.ioFlFndrInfo.fdType = fileType;
				
				/* Restore ioDirID field in pb which was changed by PBGetCatInfo */
				pb.hFileInfo.ioDirID = spec->parID;
				result = PBSetCatInfoSync(&pb);
			}
			/* Set ResErr low memory global to result */
			LMSetResErr(result);
		}
		return;
	}
	else
#endif	/* !__MACOSSEVENFIVEONEORLATER */
	{
		FSpCreateResFile(spec, creator, fileType, scriptTag);
		return;
	}
}

/*****************************************************************************/
