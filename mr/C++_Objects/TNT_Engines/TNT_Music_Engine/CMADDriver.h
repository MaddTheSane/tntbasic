// ��������������������������������������������������������������������������������������������������������������������������
// TNT Library
// CMADDriver.h
// � Mark Tully 2000
// 12/4/00
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

#pragma once

class	MADMusic;
class	MADLibrary;
class	MADDriverRec;

#include "CMusicDriver.h"

class CMADDriver : public CMusicDriver
{
	protected:
		bool						mMadPlaying;			// whether the CMADDriver thinks music is currently playing
															// i can't find an API function to actually find this out!
		MADMusic					*mMusic;				// the music, 0 for none
		MADDriverRec				*mDriver;				// the driver
		SInt32						mLastRecordedPosition;	// see rem at top of .cpp file

		static MADLibrary			*sLib;

		virtual void				PauseDriverSelf();
		virtual void				ResumeDriverSelf();
		virtual void /*e*/			ResetDriverSelf();
		virtual void /*e*/			PlayMusicSelf();
		virtual void /*e*/			StopMusicSelf();
		virtual bool				IsMusicPlayingSelf();
		virtual void /*e*/			LoadMusicSelf(
										Handle			inHandle,
										UInt32			inOffset);
		virtual void /*e*/			LoadMusicSelf(
										FSSpec			&inSpec);

	public:		
		// ������������������������������������������������������������������������������������������������������������������
		//	� Statics
		// ������������������������������������������������������������������������������������������������������������������
		static const ResType		kCurrentMADType='MADK';

		static void /*e*/			Initialise();
		static void					ShutDown();
		static MADLibrary			*GetLib()		{ return sLib; }
		
		// ������������������������������������������������������������������������������������������������������������������
		//	� Non-statics
		// ������������������������������������������������������������������������������������������������������������������
									CMADDriver();
		virtual						~CMADDriver();

		virtual bool				SupportsType(
										OSType		inType)		{ return inType==kCurrentMADType; }				
		virtual SInt32 /*e*/		GetMusicLength();
		virtual SInt32 /*e*/		GetPlayPosition();
		virtual void /*e*/			SetPlayPosition(
										SInt32		inTicks);
		virtual void				SetVolume(
										SInt32		inVolume);
		virtual SInt32				GetVolume();
		virtual void				Tick();
		virtual SInt32				GetTickFrequency()		{ return 30; }
		virtual EventTimerInterval	GetCarbonTickFrequency()	{ return kEventDurationMillisecond*500; }

		virtual bool				IsLooping();
		virtual void				SetLooping(
										bool		inLoop) ;
};