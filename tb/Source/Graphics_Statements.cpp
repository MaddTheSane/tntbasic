// ��������������������������������������������������������������������������������������������������������������������������
// TNT Basic
// Graphics_Statements.cpp
// � Mark Tully 2000
// 1/1/00
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
	A collection of statments for working with graphics.
	
	CSyncScreenStatement		: Renders the current frame to the screen
	CSetFrameRateStament		: Allows the maximum frames per seconds to be changed
	CGraphicsModeStatement		: Changes to graphics mode
	CTextModeStatement			: Changes to text mode
	CSetVBLSyncStatement		: Turns VBL syncing on/off
	CConstColourFunction		: Function for returning a colour constant
*/

#include		"Root.h"
#include		"Graphics_Statements.h"
#include		"CApplication.h"
#include		"CArithExpression.h"
#include		"CProgram.h"
#include		"Basic.tab.h"
#include		"UCursorManager.h"

#include		"CGraphicsContext.h"
#include		"CGraphicsContext16.h"
#include		"CGraphicsContextGL.h"

// ��������������������������������������������������������������������������������������������������������������������������
//		� ExecuteSelf										/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Blits all changes to the screen
void CSyncScreenStatement::ExecuteSelf(
	CProgram	&ioState)
{
	// stop auto flushing of tb graphics under x
	if (ioState.GetGraphicsContext())
		ioState.GetGraphicsContext()->ClearQDDirtyRgn();

	ioState.CheckGraphicsMode()->RenderSpritesAndBlit();
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� ExecuteSelf										/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Changes the frame rate
void CSetFrameRateStatement::ExecuteSelf(
	CProgram	&ioState)
{
	if (!mFrameRate.IsNull())
		ioState.CheckGraphicsMode()->SetFrameRate(mFrameRate(ioState));
	else
		ioState.CheckGraphicsMode()->SetFrameRate(0);
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� ExecuteSelf										/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Blits all changes to the screen
void CSetVBLSyncStatement::ExecuteSelf(
	CProgram	&ioState)
{
	ioState.CheckGraphicsMode()->SetVBLSync(mState);
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� ExecuteSelf										/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Changes the graphics mode to the one specified
// The context is immediately activated
void CTextModeStatement::ExecuteSelf(
	CProgram	&ioState)
{
	CGraphicsContext		*context=ioState.GetGraphicsContext();
	
	if (context)
	{
		ioState.SetGraphicsContext(0);
		delete context;
	}
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� ExecuteSelf										/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Changes the graphics mode to the one specified
// The context is immediately activated
void CGraphicsModeStatement::ExecuteSelf(
	CProgram	&ioState)
{
	CGraphicsContext		*context=ioState.GetGraphicsContext();
	
	if (context)
		delete context;

	ioState.SetGraphicsContext(0);
	
	context=new CGraphicsContext16(mWidth->EvaluateInt(ioState),mHeight->EvaluateInt(ioState),mGoFullScreen,&ioState);
	ThrowIfMemFull_(context);
	
	ioState.SetGraphicsContext(context);
	
	// Show fps if required
	if (CApplication::GetApplication()->IsFPSVisible())
		context->ShowFPS(true);
		
	// init the cursor if it's visible in case it was over the text window when we opened the context
	if (UCursorManager::IsVisible())
		::InitCursor();
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� ExecuteSelf										/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Changes the graphics mode to the one specified
// The context is immediately activated
void CGraphicsModeHardwareStatement::ExecuteSelf(
	CProgram	&ioState)
{
	CGraphicsContext		*context=ioState.GetGraphicsContext();
	
	if (context)
		delete context;

	ioState.SetGraphicsContext(0);
	
	context=new CGraphicsContextGL(mWidth->EvaluateInt(ioState),mHeight->EvaluateInt(ioState),mGoFullScreen,&ioState);
	ThrowIfMemFull_(context);
	
	ioState.SetGraphicsContext(context);
	
	// Show fps if required
	if (CApplication::GetApplication()->IsFPSVisible())
		context->ShowFPS(true);
		
	// init the cursor if it's visible in case it was over the text window when we opened the context
	if (UCursorManager::IsVisible())
		::InitCursor();
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CSetSpriteBankStatement::ExecuteSelf											/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
void CSetDefaultSpriteBankStatement::ExecuteSelf(
	CProgram			&ioState)
{
	ResID		number;

	if (!mResID.IsNull())
		number=mResID(ioState);
	else
		number=ioState.GetResIdForName(kBLImageBankType,mResName(ioState));
	
	ioState.CheckGraphicsMode()->mSpriteManager.SetDefaultSpriteBank(number);
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� COpenCanvasStatement::ExecuteSelf												/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Creates a new canvas with the index specified. If it exists then it's reallocated
void COpenCanvasStatement::ExecuteSelf(
	CProgram			&ioState)
{
	ioState.CheckGraphicsMode()->mCanvasManager.OpenCanvas(mCanvasIndex(ioState),mWidth(ioState),mHeight(ioState));
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CCloseCanvasStatement::ExecuteSelf											/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
void CCloseCanvasStatement::ExecuteSelf(
	CProgram			&ioState)
{
	if (mIndex.IsNull())
		ioState.CheckGraphicsMode()->mCanvasManager.CloseAllCanvases();
	else
		ioState.CheckGraphicsMode()->mCanvasManager.CloseCanvas(mIndex->EvaluateInt(ioState));
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CTargetCanvasStatement::ExecuteSelf											/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
void CTargetCanvasStatement::ExecuteSelf(
	CProgram			&ioState)
{
	ioState.CheckGraphicsMode()->mCanvasManager.TargetCanvas(mIndex->EvaluateInt(ioState));
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CConstColourFunction::EvaluateInt												/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
TTBInteger CConstColourFunction::EvaluateInt(
	CProgram			&ioState)
{
	if (ioState.InHardwareMode())
	{
		switch (mColourToken)
		{
			case WHITE:
				return kBLWhite24;
				break;
				
			case BLACK:
				return kBLBlack24;
				break;

			case RED:
				return 0xFF<<kRedShift24;
				break;		

			case GREEN:
				return 0xFF<<kGreenShift24;
				break;		

			case BLUE:
				return 0xFF<<kBlueShift24;
				break;		

			case YELLOW:
				return (0xFF<<kRedShift24)|(0xFF<<kGreenShift24);
				break;
				
			default:
				SignalString_("CConstColourFunction::EvaluateInt() - Unknown colour token");
				break;
		}
	}
	else
	{
		switch (mColourToken)
		{
			case WHITE:
				return kBLWhite16;
				break;
				
			case BLACK:
				return kBLBlack16;
				break;

			case RED:
				return 31<<kRedShift16;
				break;		

			case GREEN:
				return 31<<kGreenShift16;
				break;		

			case BLUE:
				return 31<<kBlueShift16;
				break;		

			case YELLOW:
				return (31<<kRedShift16)|(31<<kGreenShift16);
				break;
				
			default:
				SignalString_("CConstColourFunction::EvaluateInt() - Unknown colour token");
				break;
		}
	}

	return 0;
}

