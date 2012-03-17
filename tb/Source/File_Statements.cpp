// ��������������������������������������������������������������������������������������������������������������������������
// TNT Basic
// File_Statements.cpp
// � John Treece-Birch 2001
// 4/5/01
// ��������������������������������������������������������������������������������������������������������������������������

/* ***** BEGIN LICENSE BLOCK *****
*
* Copyright (c) 2001, Mark Tully and John Treece-Birch
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

#include "File_Statements.h"
#include "UFileManager.h"
#include "CProgram.h"
#include "UGammaManager.h"
#include "UCursorManager.h"
#include "CGraphicscontext16.h"
#include "CApplication.h"

// ��������������������������������������������������������������������������������������������������������������������������
//		� GetDataType
// ��������������������������������������������������������������������������������������������������������������������������
UFileManager::EDataType GetDataType(
	StStrExpression		&inDataType,
	CProgram			&ioState)
{
	UFileManager::EDataType		dataType=UFileManager::kDataFile;
	
	if (!inDataType.IsNull())
	{
		CCString	&dataTypeString=inDataType(ioState);
		
		if (std::strcasecmp(dataTypeString,"Data")==0)
			dataType=UFileManager::kDataFile;
		else if (std::strcasecmp(dataTypeString,"Text")==0)
			dataType=UFileManager::kTextFile;
		else
			UTBException::ThrowUnknownFileFormat(dataTypeString);
	}
	
	return dataType;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CCreateFileFunction::EvaluateInt
// ��������������������������������������������������������������������������������������������������������������������������
TTBInteger CCreateFileFunction::EvaluateInt(
	CProgram				&ioState)
{
	CCString	string=mType(ioState);

	if (string.GetLength()!=4)
		UTBException::ThrowFileTypeWrongLength();
		
	OSType		type=(string.mString[0] << 24) + (string.mString[1] << 16) + (string.mString[2] << 8) + string.mString[3];

	return UFileManager::CreateFile(mPath(ioState),type,GetDataType(mDataType,ioState));
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CFileOpen::EvaluateInt
// ��������������������������������������������������������������������������������������������������������������������������
TTBInteger CFileOpenFunction::EvaluateInt(
	CProgram				&ioState)
{
	CCString	string=mType(ioState);

	if (string.GetLength()!=4)
		UTBException::ThrowFileTypeWrongLength();
		
	OSType		type=(string.mString[0] << 24) + (string.mString[1] << 16) + (string.mString[2] << 8) + string.mString[3];
	
	return UFileManager::OpenFile(mPath(ioState),mReadWrite(ioState),type,GetDataType(mDataType,ioState));
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CAskCreateFileFunction::EvaluateInt
// ��������������������������������������������������������������������������������������������������������������������������
TTBInteger CAskCreateFileFunction::EvaluateInt(
	CProgram				&ioState)
{
	CCString	string=mType(ioState);

	if (string.GetLength()!=4)
		UTBException::ThrowFileTypeWrongLength();
		
	OSType		type=(string.mString[0] << 24) + (string.mString[1] << 16) + (string.mString[2] << 8) + string.mString[3];
	
	UGammaManager::Pause();
	UCursorManager::RememberCursor();
	UCursorManager::ShowCursor();
	::FlushEvents(everyEvent,0L);
	
	TTBInteger	value=UFileManager::AskUserFileCreate(type,GetDataType(mDataType,ioState));

	if (ioState.GetGraphicsContext())
	{
		ioState.GetGraphicsContext()->GetCanvas(0)->InvalCanvas();
		ioState.GetGraphicsContext()->RenderSpritesAndBlit();
	}
	
	UCursorManager::ReturnCursor();
	UGammaManager::Resume();	
	CApplication::GetApplication()->ClearKeyboard(); // will have lost key ups so clear them out now
	
	return value;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CAskFileOpen::EvaluateInt
// ��������������������������������������������������������������������������������������������������������������������������
TTBInteger CAskFileOpenFunction::EvaluateInt(
	CProgram				&ioState)
{
	CCString	string=mType(ioState);

	if (string.GetLength()!=4)
		UTBException::ThrowFileTypeWrongLength();
		
	OSType		type=(string.mString[0] << 24) + (string.mString[1] << 16) + (string.mString[2] << 8) + string.mString[3];
		
	UGammaManager::Pause();
	UCursorManager::RememberCursor();
	UCursorManager::ShowCursor();
	::FlushEvents(everyEvent,0L);
	
	TTBInteger	value=UFileManager::AskUserFileOpen(mReadWrite(ioState),type,GetDataType(mDataType,ioState));
	
	if (ioState.GetGraphicsContext())
	{
		ioState.GetGraphicsContext()->GetCanvas(0)->InvalCanvas();
		ioState.GetGraphicsContext()->RenderSpritesAndBlit();
	}
	
	UCursorManager::ReturnCursor();
	UGammaManager::Resume();
	CApplication::GetApplication()->ClearKeyboard(); // will have lost key ups so clear them out now
	
	return value;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CFileCloseStatement::ExecuteSelf
// ��������������������������������������������������������������������������������������������������������������������������
void CFileCloseStatement::ExecuteSelf(
	CProgram			&ioState)
{
	UFileManager::CloseFile(mFile(ioState));
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CNewFolderStatement::ExecuteSelf
// ��������������������������������������������������������������������������������������������������������������������������
void CNewFolderStatement::ExecuteSelf(
	CProgram				&ioState)
{
	UFileManager::NewFolder(mFolder(ioState));
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CDeleteFileStatement::ExecuteSelf
// ��������������������������������������������������������������������������������������������������������������������������
void CDeleteFileStatement::ExecuteSelf(
	CProgram				&ioState)
{
	UFileManager::DeleteFile(mFile(ioState));
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CFileWriteNumberStatement::ExecuteSelf
// ��������������������������������������������������������������������������������������������������������������������������
void CFileWriteNumberStatement::ExecuteSelf(
	CProgram			&ioState)
{
	if (mData.Get()->IsFloat())
		UFileManager::FileWriteFloat(mFile(ioState),mData->EvaluateFloat(ioState));
	else
		UFileManager::FileWriteInteger(mFile(ioState),mData(ioState));
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CFileWriteStringStatement::ExecuteSelf
// ��������������������������������������������������������������������������������������������������������������������������
void CFileWriteStringStatement::ExecuteSelf(
	CProgram			&ioState)
{
	UFileManager::FileWriteString(mFile(ioState),mData(ioState));
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CFileReadString::Evaluate
// ��������������������������������������������������������������������������������������������������������������������������
CCString &CFileReadStringFunction::Evaluate(
	CProgram				&ioState)
{
	UFileManager::FileReadString(mFile(ioState),mString);
	return mString;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CFileReadInt::EvaluateInt
// ��������������������������������������������������������������������������������������������������������������������������
TTBInteger CFileReadIntFunction::EvaluateInt(
	CProgram				&ioState)
{
	return UFileManager::FileReadInteger(mFile(ioState));
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CFileReadFloat::EvaluateFloat
// ��������������������������������������������������������������������������������������������������������������������������
TTBFloat CFileReadFloatFunction::EvaluateFloat(
	CProgram				&ioState)
{
	return UFileManager::FileReadFloat(mFile(ioState));
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CFileLengthFunction::EvaluateInt
// ��������������������������������������������������������������������������������������������������������������������������
TTBInteger CFileLengthFunction::EvaluateInt(
	CProgram				&ioState)
{
	return UFileManager::FileLength(mFile(ioState));
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CFilePos::EvaluateInt
// ��������������������������������������������������������������������������������������������������������������������������
TTBInteger CFilePosFunction::EvaluateInt(
	CProgram				&ioState)
{
	return UFileManager::FilePos(mFile(ioState));
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CSetFilePosStatement::ExecuteSelf
// ��������������������������������������������������������������������������������������������������������������������������
void CSetFilePosStatement::ExecuteSelf(
	CProgram			&ioState)
{
	UFileManager::SetFilePos(mFile(ioState),mPos(ioState));
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CFileExistsFunction::EvaluateInt
// ��������������������������������������������������������������������������������������������������������������������������
TTBInteger CFileExistsFunction::EvaluateInt(
	CProgram				&ioState)
{
	return UFileManager::FileExists(mPath(ioState));
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CFileTypeFunction::Evaluate
// ��������������������������������������������������������������������������������������������������������������������������
CCString &CFileTypeFunction::Evaluate(
	CProgram				&ioState)
{
	OSType		type=UFileManager::FileType(mPath(ioState));
	mString.mString[0]=0;	// clear string
	
	mString+=(type >> 24);
	mString+=(type >> 16);
	mString+=(type >> 8);
	mString+=type;
	
	return mString;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CSetDirectoryUserPreferencesStatement::ExecuteSelf
// ��������������������������������������������������������������������������������������������������������������������������
void CSetDirectoryUserPreferencesStatement::ExecuteSelf(
	CProgram				&ioState)
{
	UFileManager::SetDirectoryUserPreferences();
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CSetDirectoryTemporaryStatement::ExecuteSelf
// ��������������������������������������������������������������������������������������������������������������������������
void CSetDirectoryTemporaryStatement::ExecuteSelf(
	CProgram				&ioState)
{
	UFileManager::SetDirectoryTemporary();
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CSetDirectorySystemPreferencesStatement::ExecuteSelf
// ��������������������������������������������������������������������������������������������������������������������������
void CSetDirectorySystemPreferencesStatement::ExecuteSelf(
	CProgram				&ioState)
{
	UFileManager::SetDirectorySystemPreferences();
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� CSetDirectoryHomeStatement::ExecuteSelf
// ��������������������������������������������������������������������������������������������������������������������������
void CSetDirectoryGameStatement::ExecuteSelf(
	CProgram				&ioState)
{
	UFileManager::SetDirectoryGame();
}