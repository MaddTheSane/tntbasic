// ��������������������������������������������������������������������������������������������������������������������������
// TNT Basic
// UExpressions.cpp
// � Mark Tully 2000
// 14/4/00
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
	Utility classes for managing expressions
*/

#include		"TNT_Debugging.h"
#include		"UExpressions.h"
#include		"CArithExpression.h"
#include		"CStrExpression.h"
#include		"CGeneralExpression.h"

// ��������������������������������������������������������������������������������������������������������������������������
//		� ~StGenExpression::Destructor
// ��������������������������������������������������������������������������������������������������������������������������
StGenExpression::~StGenExpression()
{
	delete mExp;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� ~StArithExpression::Destructor
// ��������������������������������������������������������������������������������������������������������������������������
StArithExpression::~StArithExpression()
{
	delete mExp;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� StGenExpression::operator=
// ��������������������������������������������������������������������������������������������������������������������������
StGenExpression &StGenExpression::operator=(
	CGeneralExpression *inExp)
{
	delete mExp;
	mExp=inExp;
	return *this;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� StArithExpression::operator=
// ��������������������������������������������������������������������������������������������������������������������������
StArithExpression &StArithExpression::operator=(
	CArithExpression	*inExp)
{
	delete mExp;
	mExp=inExp;
	
	return *this;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� StArithExpression::operator()								/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Evaluates the expression
TTBInteger StArithExpression::operator()(
	CProgram	&ioState)
{
	AssertThrow_(mExp);
	return mExp->EvaluateInt(ioState);
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� ~StStrExpression::Destructor
// ��������������������������������������������������������������������������������������������������������������������������
StStrExpression::~StStrExpression()
{
	delete mExp;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� StStrExpression::operator=
// ��������������������������������������������������������������������������������������������������������������������������
StStrExpression &StStrExpression::operator=(
	CStrExpression	*inExp)
{
	delete mExp;
	mExp=inExp;
	
	return *this;
}

// ��������������������������������������������������������������������������������������������������������������������������
//		� StStrExpression::operator()								/*e*/
// ��������������������������������������������������������������������������������������������������������������������������
// Evaluates the expression
CCString &StStrExpression::operator()(
	CProgram	&ioState)
{
	AssertThrow_(mExp);
	return mExp->Evaluate(ioState);
}