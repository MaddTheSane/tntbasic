// �������������������������������������������������������������������������������������������������������������������������
// CCarbonWindowLayer.h
// TNT Library
// Mark Tully
// 22/5/02
// �������������������������������������������������������������������������������������������������������������������������

/* ***** BEGIN LICENSE BLOCK *****
*
* Copyright (c) 2002, Mark Tully and John Treece-Birch
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

#include "CWindowLayer.h"

class CCarbonWindowLayer : public CWindowLayer
{
	private:
		typedef CWindowLayer			inheritedLayer;
		
	protected:
		static SInt32					sLevel;
		static WindowGroupRef			sRootGroup;
		
		WindowGroupRef					mWindowGroup;
		
		virtual void					ShowWindow(CWindow *win);
		
	public:
		// don't call these directly, instead use CWindow-> routines
		virtual void					SelectWindow(CWindow *windowPtr);		

										CCarbonWindowLayer(TWindowLayerFlags flags=0);
		virtual							~CCarbonWindowLayer();

		virtual void					AddWindow(
											CListElementT<CWindow> *listEle);

		virtual CWindow					*GetVisibleFrontWindow();
		virtual CWindow					*GetVisibleBackWindow();
		virtual CWindow					*GetAbsoluteFrontWindow();
		virtual CWindow					*GetAbsoluteBackWindow();
		virtual CWindow					*GetSelectedWindow();	
		
		virtual void					DragWindow(EventRecord &eventRecord,CWindow *windowPtr);
};