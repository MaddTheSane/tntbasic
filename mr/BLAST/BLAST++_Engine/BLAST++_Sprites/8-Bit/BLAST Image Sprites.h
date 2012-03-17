/***************************************************************************************************

BLAST Image Sprites.h
Extension of BLAST++� engine
� TNT Software 1997
All right reserved
Mark Tully

29/8/97		:	Started it

***************************************************************************************************/

/* ***** BEGIN LICENSE BLOCK *****
*
* Copyright (c) 1997, Mark Tully and John Treece-Birch
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

#include	"BLAST Sprite Base.h"

typedef class ImageSprite8 : public BlastSprite, public BlastSpriteTintIngredient
{
	protected:
		ImageHandle					image;
	
	public:
		// ********* Constructor *********
									ImageSprite8();
	
		// ********* Override *********
		virtual void				RenderSprite(long xOff,long yOff,ABCPtr rec);
		virtual void				RenderSpriteClipped(long xOff,long yOff,ABCPtr rec,Rect &clipRect);
		virtual void				RecalcSprite(long xOff,long yOff,Rect &clipRect,Boolean masterRecalc);

		// ********* Image accessors *********
		virtual void				SetImage(ImageHandle image);
		virtual	void				SetImage(short bank,short image);
		virtual ImageHandle			GetImage();

} ImageSprite8, *ImageSprite8Ptr, **ImageSprite8Handle;