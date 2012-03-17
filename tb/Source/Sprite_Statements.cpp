// ��������������������������������������������������������������������������������������������������������������������������
// TNT Basic
// Sprite_Statements.cpp
// � Mark Tully and John Treece-Birch 2000
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
	CSetSpriteStatement			Changes the position/image of the sprite indicated. Allocates the sprite if it doesn't exist
	CPasteSpriteStatement		Pastes the image indicated onto the backdrop
	CKillSpriteStatement		Frees a particular sprite, or every sprite, depending on the parameters
*/

#include		"Sprite_Statements.h"
#include		"CArithExpression.h"
#include		"CTBSprite16.h"
#include		"CTBSpriteGL.h"
#include		"CProgram.h"
#include		"CSpriteManager.h"
#include		"CBLSpriteImage.h"
#include		"CBLCanvas.h"
#include		"CGLCanvas.h"
#include		"CGraphicsContext16.h"
#include		"CGraphicsContextGL.h"
#include		"basic.tab.h"

// ��������������������������������������������������������������������������������������������������������������������������
//		� CSetSpriteStatement::ExecuteSelf												/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Assigns the specified values to the sprite
void CSetSpriteStatement::ExecuteSelf(
	CProgram			&ioState)
{	
	TTBInteger			spriteIndex=mSprite(ioState);
	CTBSprite			*sprite=ioState.GetSpriteManager().GetSprite(spriteIndex);

	if (!mNewX.IsNull())
		sprite->SetX(mNewX(ioState));
	if (!mNewY.IsNull())
		sprite->SetY(mNewY(ioState));
	if (!mNewI.IsNull())
		sprite->SetSpriteImage(ioState.GetSpriteManager().GetImage(mNewI(ioState),sprite->GetBank()));

	sprite->SetCanvas(ioState.CheckGraphicsMode()->GetWorkCanvasIndex());

	sprite->SetVisibility(true);
}
		
// ��������������������������������������������������������������������������������������������������������������������������
//		� CPasteSpriteStatement::ExecuteSelf											/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Pastes the sprite indicated on the the backdrop. Does nothing if the sprite doesn't exist
void CPasteSpriteStatement::ExecuteSelf(
	CProgram			&ioState)
{
	CGraphicsContext	*graphics=ioState.CheckGraphicsMode();
	
	if (graphics->GetType()==CGraphicsContext::kBlastGraphicsContext)
	{
		CTBSprite			*sprite=ioState.GetSpriteManager().GetSprite(mSprite(ioState));
		CCanvas				*canvas=ioState.CheckGraphicsMode()->GetCanvas(sprite->GetCanvas());
		Rect				rect;
		
		FSetRect(rect,0,0,canvas->GetHeight(),canvas->GetWidth());

		((CTBSprite16*)sprite)->RenderSpriteClipped(0,0,*(CBLCanvas*)canvas,rect);
		((CTBSprite16*)sprite)->GetSpriteRect(rect);
		canvas->InvalCanvasRect(rect);
	}
	else
	{	
		CGraphicsContextGL	*glGraphics=(CGraphicsContextGL*)graphics;
		CTBSpriteGL			*sprite=(CTBSpriteGL*)ioState.GetSpriteManager().GetSprite(mSprite(ioState));
		
		if (sprite->Valid())
		{
			CGLCanvas			*canvas=(CGLCanvas*)graphics->GetCanvas(sprite->GetCanvas());
			float				screenWidth=glGraphics->GetWidth()/2.0f;
			float				screenHeight=glGraphics->GetHeight()/2.0f;
			Rect				destRect,copyRect;
			
			sprite->CalculateRect(destRect);
			
			copyRect=destRect;
			
			canvas->ClipRect(copyRect);
			
			// Copy the background to the screen
			glPixelStorei(GL_UNPACK_ROW_LENGTH,canvas->GetWidth());
			glPixelStorei(GL_UNPACK_SKIP_ROWS,canvas->GetHeight()-1-destRect.bottom);
			glPixelStorei(GL_UNPACK_SKIP_PIXELS,destRect.left);
			
			glRasterPos2f(-1.0f,(glGraphics->GetHeight()-FRectHeight(copyRect))/screenHeight-1.0f);
			glDrawPixels(FRectWidth(copyRect),FRectHeight(copyRect),GL_RGB,GL_UNSIGNED_BYTE,canvas->GetPixels());
			
			glPixelStorei(GL_UNPACK_SKIP_PIXELS,0);
			glPixelStorei(GL_UNPACK_SKIP_ROWS,0);
			glPixelStorei(GL_UNPACK_ROW_LENGTH,0);
			
			// Render the sprite
			glEnable(GL_TEXTURE_2D);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
		
			float	top,left,bottom,right;
			
			sprite->CalculateRenderCoords(top,left,bottom,right);
		
			top=-top;
			bottom=-bottom;
		
			glPushMatrix();
			glTranslatef(((destRect.left-copyRect.left)+sprite->GetXOffset())/screenWidth-1.0f,(glGraphics->GetHeight()-((destRect.top-copyRect.top)+sprite->GetYOffset()))/screenHeight-1.0f,0.0f);
			glScalef((float)2.0f/(float)glGraphics->GetWidth(),(float)2.0f/(float)glGraphics->GetHeight(),1.0f);
			
			if (sprite->GetAngle())
			{
				glRotatef(sprite->GetAngle(),0,0,1.0);
				glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
				glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
			}
			else
			{
				glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
				glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
			}
			
			glScalef(sprite->GetXScale(),sprite->GetYScale(),0.0f);
			
			if (sprite->IsColoured())
			{
				glColor4f(sprite->GetRed(),sprite->GetGreen(),sprite->GetBlue(),sprite->GetOpacity());
				glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_BLEND);
			}
			else
			{
				glColor4f(1.0f,1.0f,1.0f,sprite->GetOpacity());
				glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
			}
				
			glBindTexture(GL_TEXTURE_2D,sprite->GetTextureNumber());
			glBegin(GL_QUADS);
				glTexCoord2f(0.0f,sprite->GetHeightPercent()); glVertex3f(left,bottom,0.0f);
				
				glTexCoord2f(0.0f,0.0f); glVertex3f(left,top,0.0f);
				
				glTexCoord2f(sprite->GetWidthPercent(),0.0f); glVertex3f(right,top,0.0f);
				
				glTexCoord2f(sprite->GetWidthPercent(),sprite->GetHeightPercent()); glVertex3f(right,bottom,0.0f);
			glEnd();
			glPopMatrix();
		
			// Shutdown sprite drawing
			glDisable(GL_BLEND);
			glDisable(GL_TEXTURE_2D);	
				
			// Copy back to thae canvas
			glPixelStorei(GL_PACK_ROW_LENGTH,canvas->GetWidth());
			glPixelStorei(GL_PACK_SKIP_ROWS,canvas->GetHeight()-destRect.bottom);
			glPixelStorei(GL_PACK_SKIP_PIXELS,destRect.left);
			
			glReadPixels(0,glGraphics->GetHeight()-FRectHeight(copyRect),FRectWidth(copyRect),FRectHeight(copyRect),GL_RGB,GL_UNSIGNED_BYTE,canvas->GetPixels());
			
			glPixelStorei(GL_UNPACK_ROW_LENGTH,0);
			glPixelStorei(GL_UNPACK_SKIP_ROWS,0);
			glPixelStorei(GL_UNPACK_SKIP_PIXELS,0);
		}
	}
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CKillSpriteStatement::ExecuteSelf											/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Frees the ram for the sprite
void CKillSpriteStatement::ExecuteSelf(
	CProgram			&ioState)
{
	if (!mSprite.IsNull())	// kill a particular sprite
		ioState.GetSpriteManager().KillSprite(mSprite(ioState));
	else					// kill them, kill them all...
		ioState.GetSpriteManager().KillAllSprites();
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CSetSpriteTransparency::ExecuteSelf
// ��������������������������������������������������������������������������������������������������������������������������
// Transparency 100 means opacity 0
// Mentioning no names...John...
void CSetSpriteTransparencyStatement::ExecuteSelf(
	CProgram				&ioState)
{
	CTBSprite			*sprite=ioState.GetSpriteManager().GetSprite(mSprite->EvaluateInt(ioState));
	
	TTBInteger			transp=mTransp->EvaluateInt(ioState);
	
	if (transp<0)
		transp=0;
	else if (transp>100)
		transp=100;
	
	sprite->SetOpacity(100-transp);
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CGetSpriteAttributeFunction::EvaluateInt
// ��������������������������������������������������������������������������������������������������������������������������
// General accessor for all sprite funcs
TTBInteger CGetSpriteAttributeFunction::EvaluateInt(
	CProgram				&ioState)
{
	CTBSprite			*sprite=ioState.GetSpriteManager().GetSprite(mSprite->EvaluateInt(ioState));

	switch (mAttribute)
	{
		case GETSPRITETRANSPARENCY:
			return 100-sprite->GetOpacity()*100;
			break;
		
		case SPRITEX:
			return sprite->GetX();
			break;
			
		case SPRITEY:
			return sprite->GetY();
			break;
			
		case SPRITEI:
			return sprite->GetImageIndex();
			break;
			
		case SPRITEBANK:
			return ioState.GetSpriteManager().GetBankResId(sprite->GetBank());
			break;
			
		case SPRITEMOVING:
			return sprite->mLocalMoanChannel.IsMoving();
			break;
			
		case SPRITEANIMATING:
			return sprite->mLocalMoanChannel.IsAnimating();
			break;
			
		case SPRITESCALING:
			return sprite->mLocalMoanChannel.IsScaling();
			break;
			
		case SPRITEROTATING:
			return sprite->mLocalMoanChannel.IsRotating();
			break;
			
		default:
			Throw_(kTNTErr_InternalError);
			break;
	}
	
	return 0;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CSpriteColourStatement::ExecuteSelf
// ��������������������������������������������������������������������������������������������������������������������������
void CSpriteColourStatement::ExecuteSelf(
	CProgram				&ioState)
{
	CTBSprite			*sprite=ioState.GetSpriteManager().GetSprite(mSprite->EvaluateInt(ioState));
	RGBColour			colour;

	if (ioState.InHardwareMode())
		BlastColour24ToRGBColour(mColour->EvaluateInt(ioState),&colour);
	else
		BlastColour16ToRGBColour(mColour->EvaluateInt(ioState),&colour);

	sprite->SetColour(colour);
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CSpriteColourOffStatement::ExecuteSelf
// ��������������������������������������������������������������������������������������������������������������������������
void CSpriteColourOffStatement::ExecuteSelf(
	CProgram				&ioState)
{
	CTBSprite			*sprite=ioState.GetSpriteManager().GetSprite(mSprite->EvaluateInt(ioState));

	sprite->DisableColour();
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CSetSpriteBankStatement::ExecuteSelf
// ��������������������������������������������������������������������������������������������������������������������������
void CSetSpriteBankStatement::ExecuteSelf(
	CProgram				&ioState)
{
	CTBSprite			*sprite=ioState.GetSpriteManager().GetSprite(mSprite->EvaluateInt(ioState));

	ResID		number;

	if (!mResID.IsNull())
		number=mResID(ioState);
	else
		number=ioState.GetResIdForName(kBLImageBankType,mResName(ioState));
	
	TTBInteger		imageIndex=sprite->GetImageIndex();
	
	sprite->SetBank(number);
	sprite->SetSpriteImage(ioState.GetSpriteManager().GetImage(imageIndex,sprite->GetBank()));
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CSetSpritePriorityStatement::ExecuteSelf
// ��������������������������������������������������������������������������������������������������������������������������
void CSetSpritePriorityStatement::ExecuteSelf(
	CProgram				&ioState)
{
	ioState.GetSpriteManager().SetSpritePriority(mSprite(ioState),mPriority(ioState));
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CSetSpriteAngleStatement::ExecuteSelf
// ��������������������������������������������������������������������������������������������������������������������������
void CSetSpriteAngleStatement::ExecuteSelf(
	CProgram				&ioState)
{
	CTBSprite		*sprite=ioState.GetSpriteManager().GetSprite(mSprite->EvaluateInt(ioState));

	sprite->SetAngle(-mAngle->EvaluateFloat(ioState));
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CSetSpriteXScaleStatement::ExecuteSelf
// ��������������������������������������������������������������������������������������������������������������������������
void CSetSpriteXScaleStatement::ExecuteSelf(
	CProgram				&ioState)
{
	CTBSprite		*sprite=ioState.GetSpriteManager().GetSprite(mSprite->EvaluateInt(ioState));
	
	sprite->SetXScale(mScale->EvaluateFloat(ioState));
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CSetSpriteYScaleAngle::ExecuteSelf
// ��������������������������������������������������������������������������������������������������������������������������
void CSetSpriteYScaleStatement::ExecuteSelf(
	CProgram				&ioState)
{
	CTBSprite		*sprite=ioState.GetSpriteManager().GetSprite(mSprite->EvaluateInt(ioState));
	
	sprite->SetYScale(mScale->EvaluateFloat(ioState));
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CSetSpriteXFlip::ExecuteSelf
// ��������������������������������������������������������������������������������������������������������������������������
void CSetSpriteXFlipStatement::ExecuteSelf(
	CProgram				&ioState)
{
	CTBSprite		*sprite=ioState.GetSpriteManager().GetSprite(mSprite->EvaluateInt(ioState));
	
	if (mValue(ioState))
		sprite->SetXFlip(true);
	else
		sprite->SetXFlip(false);
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CSetSpriteYFlip::ExecuteSelf
// ��������������������������������������������������������������������������������������������������������������������������
void CSetSpriteYFlipStatement::ExecuteSelf(
	CProgram				&ioState)
{
	CTBSprite		*sprite=ioState.GetSpriteManager().GetSprite(mSprite->EvaluateInt(ioState));
	
	if (mValue(ioState))
		sprite->SetYFlip(true);
	else
		sprite->SetYFlip(false);
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CSpriteAngle::EvaluateFloat
// ��������������������������������������������������������������������������������������������������������������������������
TTBFloat CSpriteAngleFunction::EvaluateFloat(
	CProgram				&ioState)
{
	CTBSprite		*sprite=ioState.GetSpriteManager().GetSprite(mSprite->EvaluateInt(ioState));

	return -sprite->GetAngle();
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CSpriteXScaleAngle::EvaluateFloat
// ��������������������������������������������������������������������������������������������������������������������������
TTBFloat CSpriteXScaleFunction::EvaluateFloat(
	CProgram				&ioState)
{
	CTBSprite		*sprite=ioState.GetSpriteManager().GetSprite(mSprite->EvaluateInt(ioState));
	
	return sprite->GetXScale();
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CSpriteYScaleAngle::EvaluateFloat
// ��������������������������������������������������������������������������������������������������������������������������
TTBFloat CSpriteYScaleFunction::EvaluateFloat(
	CProgram				&ioState)
{
	CTBSprite		*sprite=ioState.GetSpriteManager().GetSprite(mSprite->EvaluateInt(ioState));
	
	return sprite->GetYScale();
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CSpriteXFlip::EvaluateInt
// ��������������������������������������������������������������������������������������������������������������������������
TTBInteger CSpriteXFlipFunction::EvaluateInt(
	CProgram				&ioState)
{
	CTBSprite		*sprite=ioState.GetSpriteManager().GetSprite(mSprite->EvaluateInt(ioState));
	
	return sprite->GetXFlip();
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CSpriteYFlip::EvaluateInt
// ��������������������������������������������������������������������������������������������������������������������������
TTBInteger CSpriteYFlipFunction::EvaluateInt(
	CProgram				&ioState)
{
	CTBSprite		*sprite=ioState.GetSpriteManager().GetSprite(mSprite->EvaluateInt(ioState));
	
	return sprite->GetYFlip();
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CSpriteActive::EvaluateInt
// ��������������������������������������������������������������������������������������������������������������������������
TTBInteger CSpriteActiveFunction::EvaluateInt(
	CProgram				&ioState)
{
	CTBSprite		*sprite=ioState.GetSpriteManager().GetSpriteNoCreate(mSprite->EvaluateInt(ioState));
	
	if (sprite)
		return true;
		
	return false;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CSpriteCropStatement::ExecuteSelf
// ��������������������������������������������������������������������������������������������������������������������������
void CSpriteCropStatement::ExecuteSelf(
	CProgram				&ioState)
{
	CTBSprite		*sprite=ioState.GetSpriteManager().GetSprite(mSprite->EvaluateInt(ioState));
	Rect			rect;
	
	rect.top=mTop(ioState);
	rect.left=mLeft(ioState);
	rect.bottom=mBottom(ioState);
	rect.right=mRight(ioState);
	
	sprite->Crop(rect);
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CSpriteCropOffStatement::ExecuteSelf
// ��������������������������������������������������������������������������������������������������������������������������
void CSpriteCropOffStatement::ExecuteSelf(
	CProgram				&ioState)
{
	CTBSprite		*sprite=ioState.GetSpriteManager().GetSprite(mSprite->EvaluateInt(ioState));
	
	sprite->CropOff();
}