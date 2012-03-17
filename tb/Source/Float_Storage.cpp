// ��������������������������������������������������������������������������������������������������������������������������
// TNT Basic
// Float_Storage.cpp
// � Mark Tully 2000
// 25/4/99
// ��������������������������������������������������������������������������������������������������������������������������

/* ***** BEGIN LICENSE BLOCK *****
*
* Copyright (c) 1999, Mark Tully and John Treece-Birch
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
	Support for the storage of floating point numbers
*/

#include		"Float_Storage.h"
#include		"CStackFrame.h"
#include		"CProgram.h"

// ��������������������������������������������������������������������������������������������������������������������������
//		� CFloatSymbol::GetValue
// ��������������������������������������������������������������������������������������������������������������������������
TTBFloat CFloatSymbol::GetValue(
	CProgram	&ioProgram)
{	
	return GetStackFrame(ioProgram)->mStorage.AccessFloat(mSymbolTableIndex);
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CFloatSymbol::SetValue
// ��������������������������������������������������������������������������������������������������������������������������
void CFloatSymbol::SetValue(
	CProgram	&ioProgram,
	TTBFloat	inFloat)
{
	GetStackFrame(ioProgram)->mStorage.AccessFloat(mSymbolTableIndex)=inFloat;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CFloatArraySymbol::AllocateStorage						/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// creates new elements with the value of zero
void CFloatArrayStore::AllocateStorage(
	CProgram		&ioState,
	UInt32			inNumElements)
{
	UInt32			wasCount=mArray.GetCount();

	if (inNumElements>wasCount)				// add new ones
	{
		mArray.InsertItemsAt(inNumElements-mArray.GetCount(),LArray::index_Last,0.0);
		// zero the ones which existed
		mArray.AssignItemsAt(wasCount,1,0.0);
	}
	else if (inNumElements<wasCount)		// delete old ones
	{
		mArray.RemoveItemsAt(wasCount-inNumElements,inNumElements+1);
		mArray.AssignItemsAt(inNumElements,1,0.0);
	}
	else
		mArray.AssignItemsAt(wasCount,1,0.0);
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CFloatArrayItem::GetValue								/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
TTBFloat CFloatArrayItem::GetValue(
	CProgram		&ioProgram)
{
	return static_cast<CFloatArraySymbol*>(mArray)->GetFloatArrayStorage(ioProgram).Access(ioProgram,mItemIndex);
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CFloatArrayItem::SetValue								/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
void CFloatArrayItem::SetValue(
	CProgram		&ioProgram,
	TTBFloat		inFloat)
{
	static_cast<CFloatArraySymbol*>(mArray)->GetFloatArrayStorage(ioProgram).Access(ioProgram,mItemIndex)=inFloat;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CFloatArraySymbol::GetFloatArrayStorage
// ��������������������������������������������������������������������������������������������������������������������������
// Returns the array storage from the stack frame
CFloatArrayStore &CFloatArraySymbol::GetFloatArrayStorage(
	CProgram				&ioState)
{
	return GetStackFrame(ioState)->mStorage.GetFloatArray(mSymbolTableIndex);
}