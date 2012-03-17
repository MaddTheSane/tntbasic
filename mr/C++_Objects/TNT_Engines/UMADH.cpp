// ��������������������������������������������������������������������������������������������������������������������������
// TNT Library
// UMADH.cpp
// � Mark Tully 2000
// 11/4/00
// ��������������������������������������������������������������������������������������������������������������������������

/* ***** BEGIN LICENSE BLOCK *****
*
* Copyright (c) 2000, Mark Tully and John Treece-Birch
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
	A wrapper class for the MADH library by Antoine Rosset.
	
	Note : Use Pause/Resume when the player pauses/unpauses the game. It should be seen as Pause engine, not pause music
	       Use Play/Stop to control music playback
*/

#include		"TNT_Debugging.h"
#include		"UMADH.h"
#include		"RDriver.h"

bool UMADH::sPlaying=false;
bool UMADH::sPaused=false;
bool UMADH::sMusicLoaded=false;

// ��������������������������������������������������������������������������������������������������������������������������
//		� Initialise												/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Call before any use of the UMADH class
void UMADH::Initialise()
{
	MADDriverSettings	init;
	OSErr				err;
	
	err=MADInitLibrary("",false);
	ThrowIfOSErr_(err);
	
	MADGetBestDriver(&init);
	
	err=MADCreateDriver( &init);
	ThrowIfOSErr_(err);
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� ShutDown
// ��������������������������������������������������������������������������������������������������������������������������
// Kills the music driver
void UMADH::ShutDown()
{
	MADDisposeDriver();					// Dispose driver
	MADDisposeLibrary();				// Close Music Library
}
		
// ��������������������������������������������������������������������������������������������������������������������������
//		� Pause
// ��������������������������������������������������������������������������������������������������������������������������
// Pauses the currently playing music - if any. This should be used when the player pauses the game
void UMADH::Pause()
{
	if (!sPaused)
	{
		sPaused=true;
		if (sPlaying)
		{
			::MADStopMusic();
			::MADStopDriver();
		}
	}
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� Resume
// ��������������������������������������������������������������������������������������������������������������������������
// Begines playing the music again BUT ONLY IF IT WAS PAUSED with the Pause command
void UMADH::Resume()
{
	if (sPaused)
	{
		sPaused=false;
		if (sPlaying)
		{
			::MADStartDriver();
			::MADPlayMusic();
		}
	}
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� Play												/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Plays the current music from the beginning after it has be loaded or if it has been stopped from where it left off. Does
// nothing if the music is not loaded
void UMADH::Play()
{
	if (sMusicLoaded)
	{
		ThrowIfOSErr_(::MADStartDriver());
		ThrowIfOSErr_(::MADPlayMusic());
		sPlaying=true;
	}
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� IsPlaying
// ��������������������������������������������������������������������������������������������������������������������������
// Returns the state of the music
UMADH::EPlayState UMADH::IsPlaying()
{
	if (sPaused && sPlaying)
		return kPlayingButPaused;
	else if (sPlaying)
		return kPlaying;
	else
		return kNotPlaying;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� Stop												/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Stops the music if playing
void UMADH::Stop()
{
	if (sPlaying)
	{
		ThrowIfOSErr_(::MADStopMusic());
		ThrowIfOSErr_(::MADStopDriver());
		sPlaying=false;
	}
}
		
// ��������������������������������������������������������������������������������������������������������������������������
//		� LoadMADHResource									/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Loads a 'MADH' music mod from a resource.
void UMADH::LoadMADHResource(
	ResIDT		inResId)
{
	ThrowIfOSErr_(::MADLoadMusicRsrc(kMADHResourceType,inResId));
	sMusicLoaded=true;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� Reset												/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Stops any music and unloads it
void UMADH::Reset()
{
	Stop();
	if (sMusicLoaded)
	{
		sMusicLoaded=false;
		::MADDisposeMusic();
	}
	sPaused=false;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� GetPlayPosition									/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Returns the # of ticks into the music we are
UInt32 UMADH::GetPlayPosition()
{
	if (sMusicLoaded)
	{
		long	fullTime,currTime;
	
		ThrowIfOSErr_(::MADGetMusicStatus(&fullTime,&currTime));
		
		return currTime;
	}
	else
		return 0;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� GetMusicLength									/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Returns the # of ticks into the music we are
UInt32 UMADH::GetMusicLength()
{
	if (sMusicLoaded)
	{
		long	fullTime,currTime;
	
		ThrowIfOSErr_(::MADGetMusicStatus(&fullTime,&currTime));
		
		return fullTime;
	}
	else
		return 0;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� SetPlayPosition									/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Sets the play position, don't know what happens if you get it past the end
void UMADH::SetPlayPosition(
	UInt32		inTicks)
{
	if (sMusicLoaded)
		ThrowIfOSErr_(::MADSetMusicStatus(0,GetMusicLength(),inTicks));
}
