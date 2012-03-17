// ��������������������������������������������������������������������������������������������������������������������������
// TNT Library
// CMusicDriver.cpp
// � Mark Tully 2001
// 31/10/01
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
	An abstract class for a music driver.
	
	Read TNT Music Library.doc for details.
	
	Note : Use Pause/Resume when the player pauses/unpauses the game. It should be seen as Pause engine, not pause music
	       Use Play/Stop to control music playback
*/

#include		"TNT_Debugging.h"
#include		"CMusicDriver.h"

// ��������������������������������������������������������������������������������������������������������������������������
//		� Constructor													/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
CMusicDriver::CMusicDriver() : 
	CListElementT<CMusicDriver>(this)
{
	mPlaying=false;
	mPaused=false;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� Destructor
// ��������������������������������������������������������������������������������������������������������������������������
CMusicDriver::~CMusicDriver()
{
}
		
// ��������������������������������������������������������������������������������������������������������������������������
//		� PauseDriver
// ��������������������������������������������������������������������������������������������������������������������������
// Pauses the currently playing music - if any. This should be used when the player pauses the game
// It should be seen as pause driver rather than pause music.
void CMusicDriver::PauseDriver()
{
	if (!mPaused)
	{
		mPaused=true;
		if (mPlaying)
			PauseDriverSelf();
	}
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� ResumeDriver
// ��������������������������������������������������������������������������������������������������������������������������
// Begins playing the music again BUT ONLY IF IT WAS PAUSED with the Pause command
void CMusicDriver::ResumeDriver()
{
	if (mPaused)
	{
		mPaused=false;
		if (mPlaying)
			ResumeDriverSelf();
	}
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� PlayMusic												/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Plays the current music from the beginning after it has be loaded or if it has been stopped from where it left off. Does
// nothing if the music is not loaded
void CMusicDriver::PlayMusic()
{
	PlayMusicSelf();
	mPlaying=true;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� IsMusicPlaying
// ��������������������������������������������������������������������������������������������������������������������������
// Returns the state of the music
UTNTMusicManager::EPlayState CMusicDriver::IsMusicPlaying()
{
	if (mPaused && mPlaying)
		return UTNTMusicManager::kPlayingButPaused;
	else if (mPlaying)
		return IsMusicPlayingSelf() ? UTNTMusicManager::kPlaying : UTNTMusicManager::kNotPlaying;
	else
		return UTNTMusicManager::kNotPlaying;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� StopMusic											/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Stops the music if playing
void CMusicDriver::StopMusic()
{
	if (mPlaying)
	{
		StopMusicSelf();
		mPlaying=false;
	}
}
		
// ��������������������������������������������������������������������������������������������������������������������������
//		� LoadMusic											/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Loads a Musc handle. The offset allows you to skip past the Musc header to the actual data
// supported by your driver.
// The driver DOES NOT ADOPT the handle. You may dispose of it after this call.
void CMusicDriver::LoadMusic(
	Handle		inHandle,
	UInt32		inOffset)
{
	ResetDriver();
	LoadMusicSelf(inHandle,inOffset);
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� LoadMusic											/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
void CMusicDriver::LoadMusic(
	FSSpec		&inSpec)
{
	ResetDriver();
	LoadMusicSelf(inSpec);
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� ResetDriver										/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Stops any music and unloads it, resets the driver to the state it was in when first constructed
void CMusicDriver::ResetDriver()
{
	StopMusic();
	mPaused=false;
	ResetDriverSelf();
	SetVolume(100);
	SetLooping(false);
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� GetPlayPosition									/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Returns the # of ticks into the music we are
#pragma mark CMusicDriver::GetPlayPosition()

// ��������������������������������������������������������������������������������������������������������������������������
//		� GetMusicLength									/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Returns the # of ticks into the music we are
#pragma mark CMusicDriver::GetMusicLength()

// ��������������������������������������������������������������������������������������������������������������������������
//		� SetPlayPosition									/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Sets the play position, don't know what happens if you get it past the end
#pragma mark CMusicDriver::SetPlayPosition()

// ��������������������������������������������������������������������������������������������������������������������������
//		� SetVolume
// ��������������������������������������������������������������������������������������������������������������������������
// Sets the music volume, pass in a percentage
#pragma mark CMusicDriver::SetVolume()

// ��������������������������������������������������������������������������������������������������������������������������
//		� GetVolume
// ��������������������������������������������������������������������������������������������������������������������������
// Gets the music volume as a percentage
#pragma mark CMusicDriver::GetVolume()

// ��������������������������������������������������������������������������������������������������������������������������
//		� LoadMusicSelf										/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Override this lad to load music into the driver.
#pragma mark CMusicDriver::LoadMusicSelf()

// ��������������������������������������������������������������������������������������������������������������������������
//		� ResetDriverSelf									/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Override this to reset the driver. Unload any music and free up ram. Return the driver to the state it was in when
// first constructed
#pragma mark CMusicDriver::ResetDriverSelf()

// ��������������������������������������������������������������������������������������������������������������������������
//		� PauseDriverSelf									/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// This is used to pause the driver. The music should be stopped and as many resources as possible should be given back
// to the system. This call will typically be made when the user has switched apps.
#pragma mark CMusicDriver::PauseDriverSelf()

// ��������������������������������������������������������������������������������������������������������������������������
//		� ResumeDriverSelf									/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Opposite of above. This will only be called after a PauseDriverSelf(). Resume playback where it left off
#pragma mark CMusicDriver::ResumeDriverSelf()

// ��������������������������������������������������������������������������������������������������������������������������
//		� PlayMusicSelf										/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Begin playing the loaded music from the current position. If the music hasn't began playing yet then run it from the
// beginning
#pragma mark CMusicDriver::PlayMusicSelf()

// ��������������������������������������������������������������������������������������������������������������������������
//		� StopMusicSelf										/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Stops the music playing. Remember where it's up to because it could be resumed with PlayMusicSelf again.
#pragma mark CMusicDriver::StopMusicSelf()

// ��������������������������������������������������������������������������������������������������������������������������
//		� SupportsType
// ��������������������������������������������������������������������������������������������������������������������������
// return true if the driver supports music of this type
#pragma mark CMusicDriver::SupportsType()