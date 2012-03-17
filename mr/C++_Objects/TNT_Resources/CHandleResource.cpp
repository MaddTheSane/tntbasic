// ��������������������������������������������������������������������������������������������������������������������������
// TNT Library
// CHandleResource.cpp
// � Mark Tully and TNT Software 2003 -- All Rights Reserved
// 23/2/03
// ��������������������������������������������������������������������������������������������������������������������������

/* ***** BEGIN LICENSE BLOCK *****
*
* Copyright (c) 2003, Mark Tully and John Treece-Birch
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
	Implementation of a handle based resource
*/

#include "CHandleResource.h"
#include "Marks Routines.h"

// ��������������������������������������������������������������������������������������������������������������������������
//		� Constructor
// ��������������������������������������������������������������������������������������������������������������������������
CHandleResource::CHandleResource(
	CResourceContainer	*inParent,
	ResType				inType,
	TResId				inId,
	const TResName		inName,
	Handle				inHandle,
	bool				inAdoptHandle) :
	CResource(inParent,inType,inId,inName),
	mHandle(inHandle),
	mOwnsHandle(inAdoptHandle)
{
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� Destructor
// ��������������������������������������������������������������������������������������������������������������������������
CHandleResource::~CHandleResource()
{
	if (mOwnsHandle && mHandle)
		::BetterDisposeHandle(mHandle);
}
		
// ��������������������������������������������������������������������������������������������������������������������������
//		� GetSize
// ��������������������������������������������������������������������������������������������������������������������������
UInt32 CHandleResource::GetSize()
{
	AssertThrow_(mHandle);
	return ::GetHandleSize(mHandle);
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� SetSizeSelf								/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
void CHandleResource::SetSizeSelf(
	UInt32		inNewSize)
{
	ThrowIfOSErr_(::BetterSetHandleSize(mHandle,inNewSize,0));
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� PutResourceDataSelf
// ��������������������������������������������������������������������������������������������������������������������������
OSStatus CHandleResource::PutResourceDataSelf(
	UInt32		inWriteOffset,
	const void	*inData,
	UInt32		&ioByteCount)
{
	if (!mHandle)
		return err_NilPointer;
	
	Size		size=GetSize();
	OSStatus	stat=noErr;
	
	if ((ioByteCount+inWriteOffset)>size)
	{
		stat=::BetterSetHandleSize(mHandle,ioByteCount+inWriteOffset,0);
		if (stat)
			return stat;
	}
	
	if (ioByteCount>0)
		::BlockMoveData(inData,(*mHandle)+inWriteOffset,ioByteCount);
	
	return stat;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� GetResourceDataSelf
// ��������������������������������������������������������������������������������������������������������������������������
OSStatus CHandleResource::GetResourceDataSelf(
	UInt32		inReadOffset,
	void		*outBuffer,
	UInt32		&ioByteCount)
{
	if (!mHandle)
		return err_NilPointer;
	
	Size		size=GetSize();
	OSStatus	stat=noErr;
	
	if ((inReadOffset+ioByteCount)>size)
	{
		if (inReadOffset>=size)
			ioByteCount=0;
		else
			ioByteCount=size-inReadOffset;
		
		stat=readErr;
	}
	
	if (ioByteCount>0)
		::BlockMoveData((*mHandle)+inReadOffset,outBuffer,ioByteCount);
	
	return stat;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� DetachHandle
// ��������������������������������������������������������������������������������������������������������������������������
// returns the handle from this resource and disassociates it. You probably don't want to do this unless
// you're about to set a new one with updatehandleandinfo
Handle CHandleResource::DetachHandle()
{
	Handle	h=mHandle;
	mHandle=NULL;
	mOwnsHandle=false;
	return h;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� UpdateHandleAndInfo						/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// allows the parent container to update the resource data associated with this resource when
// it is changed. Don't use this from out side of the resoruce container class
void CHandleResource::UpdateHandleAndInfo(
	ResType				inNewType,
	TResId				inNewId,
	const TResName		inNewName,
	Handle				inNewDataH,
	bool				inAdoptHandle)
{
	if (inNewDataH && inNewDataH!=mHandle)
	{
		if (mHandle && mOwnsHandle)
			::BetterDisposeHandle(mHandle);		
		mHandle=inNewDataH;
		mOwnsHandle=inAdoptHandle;
	}

	UpdateInfo(inNewType,inNewId,inNewName);
}
