// ��������������������������������������������������������������������������������������������������������������������������
// TNT Basic
// Integer_Storage.cpp
// � Mark Tully 1999
// 23/12/99
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
	Classes for storing integers. Includes a symbol table for variables and an implementation of an integer array.
	Implements a symbol table for storing integers
*/

#include		"Integer_Storage.h"
#include		"CStackFrame.h"
#include		"CProgram.h"

// ��������������������������������������������������������������������������������������������������������������������������
//		� CIntegerSymbol::GetValue
// ��������������������������������������������������������������������������������������������������������������������������
TTBInteger CIntegerSymbol::GetValue(
	CProgram	&ioProgram)
{	
	return GetStackFrame(ioProgram)->mStorage.AccessInteger(mSymbolTableIndex);
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CIntegerSymbol::SetValue
// ��������������������������������������������������������������������������������������������������������������������������
void CIntegerSymbol::SetValue(
	CProgram	&ioProgram,
	TTBInteger	inInt)
{
	GetStackFrame(ioProgram)->mStorage.AccessInteger(mSymbolTableIndex)=inInt;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CIntegerArraySymbol::AllocateStorage						/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// creates new elements with the value of zero
void CIntegerArrayStore::AllocateStorage(
	CProgram		&ioState,
	UInt32			inNumElements)
{
//	mArray.InsertItemsAt(inNumElements,LArray::index_Last,(TTBInteger)0);
	UInt32			wasCount=mArray.GetCount();

	if (inNumElements>wasCount)				// add new ones
	{
		mArray.InsertItemsAt(inNumElements-mArray.GetCount(),LArray::index_Last,(TTBInteger)0);
		// zero the ones which existed
		mArray.AssignItemsAt(wasCount,1,(TTBInteger)0);
	}
	else if (inNumElements<wasCount)		// delete old ones
	{
		mArray.RemoveItemsAt(wasCount-inNumElements,inNumElements+1);
		mArray.AssignItemsAt(inNumElements,1,(TTBInteger)0);
	}
	else
		mArray.AssignItemsAt(wasCount,1,(TTBInteger)0);

}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CIntegerArrayItem::GetValue								/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
TTBInteger CIntegerArrayItem::GetValue(
	CProgram		&ioProgram)
{
	return static_cast<CIntegerArraySymbol*>(mArray)->GetIntArrayStorage(ioProgram).Access(ioProgram,mItemIndex);
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CIntegerArrayItem::SetValue								/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
void CIntegerArrayItem::SetValue(
	CProgram		&ioProgram,
	TTBInteger		inInt)
{
	static_cast<CIntegerArraySymbol*>(mArray)->GetIntArrayStorage(ioProgram).Access(ioProgram,mItemIndex)=inInt;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CIntegerArraySymbol::GetIntArrayStorage
// ��������������������������������������������������������������������������������������������������������������������������
// Returns the array storage from the stack frame
CIntegerArrayStore &CIntegerArraySymbol::GetIntArrayStorage(
	CProgram				&ioState)
{
	return GetStackFrame(ioState)->mStorage.GetIntArray(mSymbolTableIndex);
}