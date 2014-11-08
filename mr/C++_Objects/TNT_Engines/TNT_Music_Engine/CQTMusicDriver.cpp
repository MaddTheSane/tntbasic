// ��������������������������������������������������������������������������������������������������������������������������
// TNT Library
// CQTMusicDriver.cpp
// � Mark Tully and John Treece-Birch 2001
// 2/11/01
// ��������������������������������������������������������������������������������������������������������������������������

/* ***** BEGIN LICENSE BLOCK *****
*
* Copyright (c) 2001, Mark Tully and John Treece-Birch
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
*
* * Redistributions of source code must retain the above copyright notice, this list
*   of conditions and the following disclaimer.
* * Redistributions in binary form must reproduce the above copyright notice, this
*   list of conditions and the following disclaimer in the documentation and/or other
*   materials provided with the distribution.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
* NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
* PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
* OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
*
* ***** END LICENSE BLOCK ***** */

/*	
	A wrapper class for using quicktime to play music, currently Mp3s.
	
	This class is easiest used through the UTNTMusicManager class.
	
	Note : Use Pause/Resume when the player pauses/unpauses the game. It should be seen as Pause engine, not pause music
	       Use Play/Stop to control music playback
*/

#include		"TNT_Debugging.h"
#include		"CQTMusicDriver.h"
#include		<PlayerPROCore/PlayerPROCore.h>
#include		"Utility Objects.h"
#include		"Marks Routines.h"

WindowPtr		CQTMusicDriver::sWindow=0;
FSSpec			CQTMusicDriver::sSpoolSpec;

// ��������������������������������������������������������������������������������������������������������������������������
//		� Initialise												Static /*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Call before instantiating any CQTMusicDriver, inits quick time. Also opens a small window to play movies in, our
// movies have no graphics but we still need a valid port for the movie.
void CQTMusicDriver::Initialise()
{
	if (sWindow)
		Debug_("CQTMusicDriver::Initialise() called twice!");

	ThrowIfOSErr_(::EnterMovies());	
	
	Rect	smallRect={0,0,10,10};
	
	ThrowIfMemFull_(sWindow=::NewCWindow(0L,&smallRect,"\p",false,kWindowDocumentProc,0L,false,0L));
	
	ThrowIfOSErr_(::FindFolder(kOnSystemDisk,kTemporaryFolderType,kCreateFolder,&sSpoolSpec.vRefNum,&sSpoolSpec.parID));
	LString::CopyPStr("\pTNT Basic Music File",sSpoolSpec.name);
	
	// append process id so that each process has a unique spool name
	OSType					sig;
	ProcessSerialNumber		me;
	StringPtr				str="\p1234";
	
	ThrowIfOSErr_(::GetCurrentProcess(&me));
	sig=::GetProcessCreator(&me);
	
	::BlockMoveData(&sig,&str[1],sizeof(sig));
	::ConcatPStr(sSpoolSpec.name,str);
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� ShutDown													Static
// ��������������������������������������������������������������������������������������������������������������������������
// Kills qt and closes window
void CQTMusicDriver::ShutDown()
{
	::ExitMovies();				// Shutdown quicktime
	::DisposeWindow(sWindow);
	sWindow=0;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� Constructor													/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
CQTMusicDriver::CQTMusicDriver() :
	mMovie(0),
	mIsLooping(false),
	mQTPlaying(false)
{
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� Destructor
// ��������������������������������������������������������������������������������������������������������������������������
CQTMusicDriver::~CQTMusicDriver()
{
	if (mMovie)
	{
		::StopMovie(mMovie);
		::DisposeMovie(mMovie);
		mMovie=0L;
	}
}
		
// ��������������������������������������������������������������������������������������������������������������������������
//		� PauseDriverSelf
// ��������������������������������������������������������������������������������������������������������������������������
// Pauses the currently playing music. This should be used when the player pauses the game
void CQTMusicDriver::PauseDriverSelf()
{
	if (mMovie)
		::StopMovie(mMovie);
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� ResumeDriverSelf
// ��������������������������������������������������������������������������������������������������������������������������
// Begins playing the music again BUT ONLY IF IT WAS PAUSED with the Pause command
void CQTMusicDriver::ResumeDriverSelf()
{
	if (mMovie)
		::StartMovie(mMovie);
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� PlayMusicSelf											/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Plays the current music from the beginning after it has be loaded or if it has been stopped from where it left off. Does
// nothing if the music is not loaded
void CQTMusicDriver::PlayMusicSelf()
{
	if (mMovie)
	{
		::StartMovie(mMovie);
		mQTPlaying=true;
	}
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� IsMusicPlayingSelf
// ��������������������������������������������������������������������������������������������������������������������������
// Returns the state of the music
bool CQTMusicDriver::IsMusicPlayingSelf()
{
	return mQTPlaying;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� StopMusicSelf											/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Stops the music if playing
void CQTMusicDriver::StopMusicSelf()
{
	if (mMovie)
	{
		::StopMovie(mMovie);
		mQTPlaying=false;
	}
}
		
// ��������������������������������������������������������������������������������������������������������������������������
//		� LoadMusicSelf										/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
void CQTMusicDriver::LoadMusicSelf(
	Handle		inHandle,
	UInt32		inOffset)
{
	short		fileRefNum=-1;
		
	::FSpDelete(&sSpoolSpec);		// make sure it's not there
	ThrowIfOSErr_(::FSpCreate(&sSpoolSpec,'TNTB','MPEG',0));
	
	Try_
	{
		ThrowIfOSErr_(::FSpOpenDF(&sSpoolSpec,fsWrPerm,&fileRefNum));
		
		long	handleSize=::GetHandleSize(inHandle)-inOffset;
		
		{
			UHandleLocker	lock(inHandle);
			
			ThrowIfOSErr_(::FSWrite(fileRefNum,&handleSize,*inHandle+inOffset));
		}
		
		ThrowIfOSErr_(::FSClose(fileRefNum));
		fileRefNum=-1;
		
		UPortSaver		safe(sWindow);
		
		Str255		movieName;
		Boolean		wasChanged;
		SInt16		movieResFile,movieResID;
		OSErr		err;

		ThrowIfOSErr_(::OpenMovieFile(&sSpoolSpec,&movieResFile,fsRdPerm));
		err=::NewMovieFromFile(&mMovie,movieResFile,&movieResID,movieName,newMovieActive,&wasChanged);
		if (err)
		{
			::CloseMovieFile(movieResFile);
			ThrowIfOSErr_(err);
		}
		
		ThrowIfOSErr_(::CloseMovieFile(movieResFile));
		
		::GoToBeginningOfMovie(mMovie);
		::SetMovieVolume(mMovie,mVolumeLevel);		// apply current volume
		
		// if we're supposed to be looping make sure we apply the property to the movie
		if (mIsLooping)
		{
			mIsLooping=false;
			SetLooping(true);
		}
	}
	Catch_(err)
	{
		// clean up
		if (fileRefNum!=-1)
			::FSClose(fileRefNum);
		::FSpDelete(&sSpoolSpec);
		
		throw;
	}
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� LoadMusicSelf										/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
void CQTMusicDriver::LoadMusicSelf(
	FSSpec		&inSpec)
{
	UPortSaver		safe(sWindow);
	Str255			movieName;
	Boolean			wasChanged;
	SInt16			movieResFile,movieResID;
	OSErr			err;

	ThrowIfOSErr_(::OpenMovieFile(&inSpec,&movieResFile,fsRdPerm));
	err=::NewMovieFromFile(&mMovie,movieResFile,&movieResID,movieName,newMovieActive,&wasChanged);
	if (err)
	{
		::CloseMovieFile(movieResFile);
		ThrowIfOSErr_(err);
	}
	
	ThrowIfOSErr_(::CloseMovieFile(movieResFile));
	
	::GoToBeginningOfMovie(mMovie);
	::SetMovieVolume(mMovie,mVolumeLevel);		// apply current volume
	
	// if we're supposed to be looping make sure we apply the property to the movie
	if (mIsLooping)
	{
		mIsLooping=false;
		SetLooping(true);
	}
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� ResetDriverSelf									/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Disposes of music, reset() will have called stop already
void CQTMusicDriver::ResetDriverSelf()
{
	if (mMovie)
	{
		::DisposeMovie(mMovie);
		mMovie=0L;
		
		// Delete the spool file
		::FSpDelete(&sSpoolSpec);
	}
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� GetPlayPosition									/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Returns the # of ticks into the music we are
SInt32 CQTMusicDriver::GetPlayPosition()
{
	if (mMovie)
	{
		TimeRecord	time;
			
		::GetMovieTime(mMovie,&time);
		
		return (60*(time.value.hi+time.value.lo))/time.scale;	// we want it in ticks
	}
	else
		return 0;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� GetMusicLength									/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Returns the # of ticks into the music we are
SInt32 CQTMusicDriver::GetMusicLength()
{
	if (mMovie)
	{
		TimeValue	time;
		TimeScale	timeScale;
		
		time=::GetMovieDuration(mMovie)*60;		// we want it in ticks
		timeScale=::GetMovieTimeScale(mMovie);
		
		return time/timeScale;
	}
	else
		return 0;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� SetPlayPosition									/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Sets the play position
void CQTMusicDriver::SetPlayPosition(
	SInt32		inTicks)
{
	if (mMovie)
	{
		TimeValue	value=(inTicks*::GetMovieTimeScale(mMovie))/60;
				
		::SetMovieTimeValue(mMovie,value);
	}
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� SetVolume
// ��������������������������������������������������������������������������������������������������������������������������
// Sets the music volume from a percentage
void CQTMusicDriver::SetVolume(
	SInt32		inValue)
{
	/*
		QuickTime movie volumes are expressed in the range -1 to 1 in 16 bit 8:8 fixed point
		So it ranges from 0x0100 (kFullVolume) to 0.
		
		Scale the percent accordingly.
	*/

	if (inValue>=100)
		mVolumeLevel=kFullVolume;
	else if (inValue<=0)
		mVolumeLevel=0;
	else
		mVolumeLevel=(inValue*kFullVolume)/100;

	if (mMovie)		
		::SetMovieVolume(mMovie,mVolumeLevel);
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� GetVolume
// ��������������������������������������������������������������������������������������������������������������������������
// Gets the music volume as a percentage
SInt32 CQTMusicDriver::GetVolume()
{
	return (mVolumeLevel*100)/kFullVolume;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� Tick
// ��������������������������������������������������������������������������������������������������������������������������
void CQTMusicDriver::Tick()
{
	if (mMovie)
	{
		if (::IsMovieDone(mMovie) && !IsLooping())
		{
			if (mQTPlaying)
			{
				StopMusic();
				::GoToBeginningOfMovie(mMovie);	// put play head back to the beginning when it reaches the end
			}
		}
		else
		{
			UPortSaver	safe(sWindow);		// change port just to be safe
			::MoviesTask(mMovie,0L);
		}
	}
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� IsLooping
// ��������������������������������������������������������������������������������������������������������������������������
bool CQTMusicDriver::IsLooping()
{
	return mIsLooping;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� SetLooping
// ��������������������������������������������������������������������������������������������������������������������������
void CQTMusicDriver::SetLooping(
	bool			inLoop)
{
	if (mIsLooping!=inLoop)
	{
		mIsLooping=inLoop;
		if (mMovie)
		{
			TimeBase		t=::GetMovieTimeBase(mMovie);

			if (inLoop)
				::SetTimeBaseFlags(t,::GetTimeBaseFlags(t)|loopTimeBase);
			else
				::SetTimeBaseFlags(t,::GetTimeBaseFlags(t)&~loopTimeBase);
		}
	}
}