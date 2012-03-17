// ��������������������������������������������������������������������������������������������������������������������������
// TNT Basic
// TNTMap_Statements.cpp
// � John Treece-Birch 2000
// 19/5/00
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
	TNT Map Statements
*/

#include			"TNTMap_Statements.h"
#include			"CArithExpression.h"
#include			"CStrExpression.h"
#include			"CProgram.h"
#include			"CGraphicsContext16.h"
#include			"basic.tab.h"

// ��������������������������������������������������������������������������������������������������������������������������
//		� ExecuteSelf
// ��������������������������������������������������������������������������������������������������������������������������
void CLoadTNTMapStatement::ExecuteSelf(
	CProgram			&ioState)
{
	ResID		number;

	if (!mResID.IsNull())
		number=mResID(ioState);
	else
		number=ioState.GetResIdForName(kTNTMapResType,mResName(ioState));
	
	UTNTMapManager::LoadTNTMap(ioState,number);
}

#pragma mark -

// ��������������������������������������������������������������������������������������������������������������������������
//		� ExecuteSelf
// ��������������������������������������������������������������������������������������������������������������������������
void CUnloadTNTMapStatement::ExecuteSelf(
	CProgram			&ioState)
{
	ResID		number;

	if (!mResID.IsNull())
		number=mResID(ioState);
	else
		number=ioState.GetResIdForName(kTNTMapResType,mResName(ioState));
	
	UTNTMapManager::UnloadTNTMap(ioState,number);
}

#pragma mark -

// ��������������������������������������������������������������������������������������������������������������������������
//		� ExecuteSelf
// ��������������������������������������������������������������������������������������������������������������������������
void CSetCurrentTNTMapStatement::ExecuteSelf(
	CProgram			&ioState)
{
	ResID		number;

	if (!mResID.IsNull())
		number=mResID(ioState);
	else
	{
		number=ioState.GetResIdForName(kTNTMapResType,mResName(ioState));
	}
	
	UTNTMapManager::SetCurrentMap(ioState,number);
}

#pragma mark -

// ��������������������������������������������������������������������������������������������������������������������������
//		� EvaluateInt
// ��������������������������������������������������������������������������������������������������������������������������
TTBInteger CGetTileFunction::EvaluateInt(
	CProgram			&ioState)
{
	return UTNTMapManager::GetTile(mX(ioState),mY(ioState),mZ(ioState));
}

#pragma mark -

// ��������������������������������������������������������������������������������������������������������������������������
//		� ExcuteSelf
// ��������������������������������������������������������������������������������������������������������������������������
void CSetMapTileStatement::ExecuteSelf(
	CProgram			&ioState)
{
	UTNTMapManager::SetTile(ioState,mX(ioState),mY(ioState),mZ(ioState),mTile(ioState));
}

#pragma mark -

// ��������������������������������������������������������������������������������������������������������������������������
//		� EvaluateInt
// ��������������������������������������������������������������������������������������������������������������������������
TTBInteger CGetTNTMapWidthFunction::EvaluateInt(
	CProgram			&ioState)
{
	if (mTileProperties)
		return UTNTMapManager::GetTileWidth();
	else
		return UTNTMapManager::GetMapWidth();
}

#pragma mark -

// ��������������������������������������������������������������������������������������������������������������������������
//		� EvaluateInt
// ��������������������������������������������������������������������������������������������������������������������������
TTBInteger CGetTNTMapHeightFunction::EvaluateInt(
	CProgram			&ioState)
{
	if (mTileProperties)
		return UTNTMapManager::GetTileHeight();
	else
		return UTNTMapManager::GetMapHeight();
}

#pragma mark -

// ��������������������������������������������������������������������������������������������������������������������������
//		� EvaluateInt
// ��������������������������������������������������������������������������������������������������������������������������
TTBInteger CGetTNTMapLayersFunction::EvaluateInt(
	CProgram			&ioState)
{
	return UTNTMapManager::CountLayers();
}

#pragma mark -

// ��������������������������������������������������������������������������������������������������������������������������
//		� EvaluateInt
// ��������������������������������������������������������������������������������������������������������������������������
TTBInteger CCountObjectsFunction::EvaluateInt(
	CProgram			&ioState)
{
	return UTNTMapManager::CountObjects();
}

#pragma mark -

// ��������������������������������������������������������������������������������������������������������������������������
//		� EvaluateInt
// ��������������������������������������������������������������������������������������������������������������������������
TTBInteger CGetNthObjectTypeFunction::EvaluateInt(
	CProgram			&ioState)
{
	return UTNTMapManager::GetNthObjectType(mIndex(ioState));
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� Evaluate
// ��������������������������������������������������������������������������������������������������������������������������
CCString &CGetNthObjectNameFunction::Evaluate(
	CProgram			&ioState)
{
	mString=UTNTMapManager::GetNthObjectName(mIndex(ioState));
	return mString;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� EvaluateInt
// ��������������������������������������������������������������������������������������������������������������������������
TTBInteger CGetNthObjectXFunction::EvaluateInt(
	CProgram			&ioState)
{
	return UTNTMapManager::GetNthObjectX(mIndex(ioState));
}

#pragma mark -

// ��������������������������������������������������������������������������������������������������������������������������
//		� EvaluateInt
// ��������������������������������������������������������������������������������������������������������������������������
TTBInteger CGetNthObjectYFunction::EvaluateInt(
	CProgram			&ioState)
{
	return UTNTMapManager::GetNthObjectY(mIndex(ioState));
}

#pragma mark -

// ��������������������������������������������������������������������������������������������������������������������������
//		� EvaluateInt
// ��������������������������������������������������������������������������������������������������������������������������
TTBInteger CGetNthObjectZFunction::EvaluateInt(
	CProgram			&ioState)
{
	return UTNTMapManager::GetNthObjectZ(mIndex(ioState));
}

#pragma mark -

// ��������������������������������������������������������������������������������������������������������������������������
//		� EvaluateInt
// ��������������������������������������������������������������������������������������������������������������������������
TTBInteger CCountPolygonsFunction::EvaluateInt(
	CProgram			&ioState)
{
	return UTNTMapManager::CountPolygons();
}

#pragma mark -

// ��������������������������������������������������������������������������������������������������������������������������
//		� EvaluateInt
// ��������������������������������������������������������������������������������������������������������������������������
TTBInteger CInPolygonFunction::EvaluateInt(
	CProgram			&ioState)
{
	return UTNTMapManager::InPolygon(mX(ioState),mY(ioState),mZ(ioState),mIndex(ioState));
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� Evaluate
// ��������������������������������������������������������������������������������������������������������������������������
CCString &CPolyNameFunction::Evaluate(
	CProgram			&ioState)
{
	UTNTMapManager::GetPolygonName(mPolyIndex(ioState),mString);
	return mString;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� EvaluateInt
// ��������������������������������������������������������������������������������������������������������������������������
TTBInteger CPolyBoundsFunction::EvaluateInt(
	CProgram			&ioState)
{
	TTBInteger	top,left,bottom,right;
	UTNTMapManager::GetPolygonBounds(mPolyIndex(ioState),top,left,bottom,right);

	switch (mDimension)
	{
		case POLYBOUNDSY:
			return top;
			break;

		case POLYBOUNDSX:
			return left;
			break;

		case POLYBOUNDSHEIGHT:
			return bottom-top;
			break;

		case POLYBOUNDSWIDTH:
			return right-left;
			break;

		default:
			Throw_(-1);
			break;
	}
	
	return 0;
}

#pragma mark -

// ��������������������������������������������������������������������������������������������������������������������������
//		� ExecuteSelf
// ��������������������������������������������������������������������������������������������������������������������������
void CDrawMapSectionStatement::ExecuteSelf(
	CProgram			&ioState)
{
	UTNTMapManager::DrawSection(mLeft(ioState),mTop(ioState),mRight(ioState),mBottom(ioState),mLayer(ioState),mX(ioState),mY(ioState),ioState.CheckGraphicsMode()->GetWorkCanvas());
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� EvaluateInt
// ��������������������������������������������������������������������������������������������������������������������������
TTBInteger CMapLineColFunction::EvaluateInt(
	CProgram			&ioState)
{
	return UTNTMapManager::LineCol(mStartX(ioState),mStartY(ioState),mEndX(ioState),mEndY(ioState),mLayer(ioState),mStartTile(ioState),mEndTile(ioState));
}