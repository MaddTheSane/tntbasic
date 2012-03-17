// ��������������������������������������������������������������������������������������������������������������������������
// TNT Linked List Library
// CListIndexerT.h
// Mark Tully
// 22/3/99
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

#pragma once

#include		"CLinkedListT.h"
#include		"CListElementT.h"

template <class T>
class CLinkedListT;

template <class T>
class CListElementT;

template <class T>
class CListIndexerT
{
	protected:
		bool						mUnlinkDirection;	// direction that will be moved in if the current element is unlinked
														// true = forward, false = backwards
		const CLinkedListT<T>		*mList;				// list to index through
		CListElementT<T>			*mIndexElement;		// element currently being indexed

		virtual void				ElementUnavailable(
										CListElementT<T>	*inUnlink);
											
	public:
		CListElementT< CListIndexerT<T> >	mLinkInIndexersList;

		// Constructor
									CListIndexerT(
										const CLinkedListT<T>	*inListToIndex,
										bool					inIndexFromStart=true);
		virtual						~CListIndexerT();

		// Low level functions called by parent list
		virtual void				ElementDying(
										CListElementT<T>	*inDying);
		virtual void				ElementUnlinking(
										CListElementT<T>	*inGonnaGo);			// called by the list when an element is to be removed
		virtual void				ListDestroyed();								// called by the list when the list is destoyed


		// Unlinked index preference
		virtual void				SetUnlinkAdvanceDirection(
										bool			inDirection);
		virtual bool				GetUnlinkAdvanceDirection()			{ return mUnlinkDirection; }

		// Indexing commands
		virtual void				RewindIndexing();
		virtual void				FastForwardIndexing();
		virtual void				StartIndexingAt(
										CListElementT<T>	*inStart);
		virtual void				StartIndexingAt(
										TListIndex			inIndex);
		virtual CListElementT<T>	*GetNextElement();	
		virtual CListElementT<T>	*GetPrevElement();
		
#ifndef NO_DATA_ACCESSORS
		virtual T					*GetNextData();
		virtual T					*GetPrevData();
#endif
};

// ��������������������������������������������������������������������������������������������������������������������������
//		� Constructor
// ��������������������������������������������������������������������������������������������������������������������������
// Connects the indexer to the list
template <class T>
CListIndexerT<T>::CListIndexerT(
	const CLinkedListT<T>	*inListToIndex,
	bool					inIndexFromStart) :
	mLinkInIndexersList(this)
{
	mList=inListToIndex;
	mIndexElement=0L;
	
	if (mList)
		mList->AddIndexer(this);
	
	SetUnlinkAdvanceDirection(inIndexFromStart);
	if (inIndexFromStart)
		RewindIndexing();
	else
		FastForwardIndexing();
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� Destructor
// ��������������������������������������������������������������������������������������������������������������������������
// Disconnects the indexer to the list
template <class T>
CListIndexerT<T>::~CListIndexerT()
{
	if (mList)
		mList->RemoveIndexer(this);
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� SetUnlinkAdvanceDirection
// ��������������������������������������������������������������������������������������������������������������������������
// Use this to set the direction which the index will move in if you unlink the element which is under index. true will
// process onto the next element, false onto the previous element. Which one you move to depends on the directions you
// are indexing through the list in. If you're going from end to start you would pass false, if you're going from start
// to end you would pass true. Note that it defaults to the direction you specifiy to the constructor.
template <class T>
void CListIndexerT<T>::SetUnlinkAdvanceDirection(
	bool				inNewDirection)
{
	mUnlinkDirection=inNewDirection;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� ElementUnavailable
// ��������������������������������������������������������������������������������������������������������������������������
// This routine is called when an element is deleted or unlinked from a list being indexed
template <class T>
void CListIndexerT<T>::ElementUnavailable(
	CListElementT<T>		*inUnlink)
{
	if (inUnlink==mIndexElement)
	{
		if (mUnlinkDirection)
			mIndexElement=mIndexElement->GetNextElement();
		else
			mIndexElement=mIndexElement->GetPrevElement();
	}
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� ElementUnlinking
// ��������������������������������������������������������������������������������������������������������������������������
// This is called when an element is being removed from the list. We check if it's our index element and advance the index
template <class T>
void CListIndexerT<T>::ElementUnlinking(
	CListElementT<T>		*inUnlink)
{
	ElementUnavailable(inUnlink);
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� ElementDying
// ��������������������������������������������������������������������������������������������������������������������������
// This is called when an element is being deleted from the list. We check if it's our index element and advance the index
template <class T>
void CListIndexerT<T>::ElementDying(
	CListElementT<T>		*inUnlink)
{
	ElementUnavailable(inUnlink);
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� ListDestroyed
// ��������������������������������������������������������������������������������������������������������������������������
// Called when the list being operated on is destroyed (ie deleted)
// When this happens the indexing can still be continued as the elements will still be linked together - they just won't
// have any way of being added/removed.
template <class T>
void CListIndexerT<T>::ListDestroyed()
{
	mList=0L;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� RewindIndexing
// ��������������������������������������������������������������������������������������������������������������������������
template <class T>
void CListIndexerT<T>::RewindIndexing()
{
	if (mList)
		mIndexElement=mList->GetFirstElement();
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� FastForwardIndexing
// ��������������������������������������������������������������������������������������������������������������������������
template <class T>
void CListIndexerT<T>::FastForwardIndexing()
{
	if (mList)
		mIndexElement=mList->GetLastElement();
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� StartIndexingAt
// ��������������������������������������������������������������������������������������������������������������������������
template <class T>
void CListIndexerT<T>::StartIndexingAt(
	CListElementT<T>	*inStart)
{
	mIndexElement=inStart;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� StartIndexingAt
// ��������������������������������������������������������������������������������������������������������������������������
template <class T>
void CListIndexerT<T>::StartIndexingAt(
	TListIndex			inIndex)
{
	if (mList)
		mIndexElement=mList->GetNthElement(inIndex);
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� GetNextElement
// ��������������������������������������������������������������������������������������������������������������������������
template <class T>
CListElementT<T> *CListIndexerT<T>::GetNextElement()
{
	CListElementT<T>		*temp=mIndexElement;

	if (mIndexElement)
		mIndexElement=mIndexElement->GetNextElement();
	
	return temp;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� GetPrevElement
// ��������������������������������������������������������������������������������������������������������������������������
template <class T>
CListElementT<T> *CListIndexerT<T>::GetPrevElement()
{
	CListElementT<T>		*temp=mIndexElement;

	if (mIndexElement)
		mIndexElement=mIndexElement->GetPrevElement();
	
	return temp;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� GetNextData
// ��������������������������������������������������������������������������������������������������������������������������
template <class T>
T* CListIndexerT<T>::GetNextData()
{
	CListElementT<T>		*ele=GetNextElement();
	
	if (ele)
		return ele->GetData();
	else
		return 0L;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� GetPrevData
// ��������������������������������������������������������������������������������������������������������������������������
template <class T>
T* CListIndexerT<T>::GetPrevData()
{
	CListElementT<T>		*ele=GetPrevElement();
	
	if (ele)
		return ele->GetData();
	else
		return 0L;
}
