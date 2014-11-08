/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         basicparse
#define yylex           basiclex
#define yyerror         basicerror
#define yylval          basiclval
#define yychar          basicchar
#define yydebug         basicdebug
#define yynerrs         basicnerrs
#define yylloc          basiclloc

/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "basic.y"

// ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
// TNT Basic
// Basic.yacc
// © Mark Tully 1999-2000
// 21/12/99
// ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ

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

//#define		YYDEBUG		1				// to enable debugging set this to 1 and set bascidebug in main() to true

#define		free(x) std::free(x)		// The bison generated code needs this to compile in cw

#include	"BisonTokenLocation.h"

#define		YYLTYPE		SBisonTokenLoc

#include	"UTBException.h"
#include	"CArithExpression.h"
#include	"CStrExpression.h"
#include	"CGeneralExpression.h"
#include	"UFunctionMgr.h"

#include	"Drawing_Statements.h"
#include	"Networking_Statements.h"	// needed for networking str functions
#include	"Misc_Statements.h"			// needed for resource str functions
#include	"Data_Statements.h"
#include	"Procedural_Statements.h"

#include	"CBreakBlockStatement.h"
#include	"CForStatement.h"
#include	"CJumpStatement.h"
#include	"CConditionalBlock.h"
#include	"CStatementBlock.h"
#include	"CProgram.h"
#include	"CLabelTable.h"
#include	"UCString.h"
#include	"CProcedure.h"
#include	"CPrimitiveStorage.h"
#include	"CVariableSymbol.h"

void AppendEndIfBreaks(
	CStatement			*inStatementList);
CStatement *ExtractInitStatements(
	CVariableNode		*inList);
void FlushExp();
void FlushList();
bool CheckArrayIndexList(
	CProgram			&inProgram,
	CGeneralExpression	*inExp,
	const STextRange	&inListTerminatingLoc);		
CStatement *MakeAssignmentStatement(
	const CPrimitiveStorage	&inLValue,
	CGeneralExpression	*inRValue,
	const STextRange	&inRValueLoc);
CArithExpression *CheckSingleNumExp(
	CGeneralExpression *&inExp,
	const STextRange	&inRange);
int yyerror(
	char *s);
		
// yylex must be declared as external here to allow linker to correctly link up the lexer and parser
extern int yylex();

// Extern the line number so that the parser knows what line an error has occured on
extern int gLineno;

// ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
//		¥ CheckSingleNumExp
// ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
// Returns the single arith exp if available, if not it logs the error. It always deletes the general expression. Only
// checks the first element, ignores the rest of the list if it exists.
CArithExpression *CheckSingleNumExp(
	CGeneralExpression *&inExp,
	const STextRange	&inRange)
{
	if (CGeneralExpressionErr::ContainsErrors(inExp))
	{
		// assume errors already reported
		delete inExp;
		inExp=0;
		return 0;
	}	
		
	CArithExpression	*exp=NULL;
	
	if (inExp)
	{		
		exp=inExp->ReleaseArithExp();	
		delete inExp;
		inExp=0;
	}
	
	if (!exp)
		LogException_(UTBException::ThrowWithRange(inRange,kTBErr_ExpectedNumExp));
	
	return exp; // <<-- Can be nil
}

// ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
//		¥ CheckArrayIndexList
// ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
// Returns true if the list is a valid comma seperated list. Logs errors and DELETES THE LIST if not.
bool CheckArrayIndexList(
	CProgram			&inProgram,
	CGeneralExpression	*inExp,
	const STextRange	&inListTerminatingLoc)
{
	if (CGeneralExpressionErr::ContainsErrors(inExp))
	{
		delete inExp;
		return false;
	}

	STextRange		range=inListTerminatingLoc;

	Try_
	{
		if (!inExp)
			UTBException::ThrowExpectedNumExp(range);

		for (CGeneralExpression *exp=inExp; exp; exp=exp->TailData())
		{
			// check for number
			if (exp->IsNullExp())	// empty expression?
			{
				if (exp->GetSeperator()!=CGeneralExpression::kUnspecified)
					range=exp->GetSepLoc();
				UTBException::ThrowExpectedNumExp(range);
			}
			else if (!exp->GetArithExp())
			{
				exp->GetExpLoc(range);
				UTBException::ThrowExpectedNumExp(range);
			}
				
			// check for comma
			switch (exp->GetSeperator())
			{
				case CGeneralExpression::kComma:
				case CGeneralExpression::kUnspecified:
					break;
				default:
					UTBException::ThrowExpectedComma(exp->GetSepLoc());
					break;
			}
		}
	}
	Catch_(err)
	{
		delete inExp;
		inProgram.LogError(err);
		return false;
	}
	
	return true;
}

// ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
//		¥ ExtractInitStatements
// ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
// Extracts all the initialization statements from a variable list and returns them
CStatement *ExtractInitStatements(
	CVariableNode		*inList)
{
	CStatement		*head=0;
	
	for (CVariableNode *node=inList; node; node=node->TailData())
	{
		head=ConsData(head,node->mInitStatement);
		node->mInitStatement=0L;
	}
	
	return head;
}

// ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
//		¥ AppendEndIfBreaks										/*e*/
// ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
// This routine takes a list of CConditionalStatementBlocks. For each one it appends a CBreakBlockStatement to the sub
// statement list. This causes the
// if statement to be exited when one of the conditional statement blocks executes, thus stopping any of the following
// conditional statement blocks or the else case being executed. The else case has not been added to inStatementList yet, it
// is just the if and elseifs.
void AppendEndIfBreaks(
	CStatement			*inStatementList)
{	
	for (CStatementBlock *block=dynamic_cast<CStatementBlock*>(inStatementList); block; block=dynamic_cast<CStatementBlock*>(block->TailData()))
	{
		CStatement		*breaker=new CBreakBlockStatement(2);		// break out of two blocks - the condititional and the container block

		UTBException::ThrowIfNoParserMemory(breaker);

		// Now append break to the end of the list
		block->AppendSubStatement(breaker);
	}
}

// ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
//		¥ MakeAssignmentStatement								/*e*/
// ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
// Makes an assignment statement. Performs type checking on data, if inRValue is null it doesn't create the statement but
// doens't throw an error either. inRValue is adopted by this function.
CStatement *MakeAssignmentStatement(
	const CPrimitiveStorage	&inLValue,
	CGeneralExpression	*inRValue,
	const STextRange	&inRValueLoc)
{
	if (!inRValue)
		return 0;	// earlier parse error screwed rhs of assignment, can't initialize but error will have been logged
		
	StGenExpression				del1(inRValue);
	
	CStatement	*result=0;
	
	// Perform the type check
	switch (inLValue.GetType())
	{
		case CVariableSymbol::kUndeclaredPrimitive:	// can't type check this
			break;
		
		case CVariableSymbol::kInteger:
		case CVariableSymbol::kFloat:
			if (!inRValue->GetArithExp())
			{
				// type error
				UTBException::ThrowExpectedNumExp(inRValueLoc);
			}
			else
			{
				if (inLValue.GetType()==CVariableSymbol::kInteger)
					result=new CIntAssignmentStatement(inLValue.mIntStore,inRValue->ReleaseArithExp());
				else
					result=new CFloatAssignmentStatement(inLValue.mFloatStore,inRValue->ReleaseArithExp());					
			}
			UTBException::ThrowIfNoParserMemory(result);
			break;
			
		case CVariableSymbol::kString:
			if (!inRValue->GetStrExp())
			{
				// type error
				UTBException::ThrowExpectedStrExp(inRValueLoc);
			}
			else
				result=new CStrAssignmentStatement(inLValue.mStrStore,inRValue->ReleaseStrExp());

			UTBException::ThrowIfNoParserMemory(result);
			break;
		
		default:
			SignalPStr_("\pUnknown variable class in MakeAssignmentStatement");
			Throw_(-1);
			break;
	}
	
	return result;
}

#undef yylex
#define yylex PatchedLex
int PatchedLex();

// A handy macro for use during parse tree construction
#define TBStatement_(x)			do {yyval.statement=new x; UTBException::ThrowIfNoParserMemory(yyval.statement); } while (false)
#define TBStrFunction_(x)		do {yyval.strExp=new x; UTBException::ThrowIfNoParserMemory(yyval.strExp); } while (false)
#define TBArithFunction_(x)		do {yyval.arithExp=new x; UTBException::ThrowIfNoParserMemory(yyval.arithExp); } while (false)
#define	TBGeneralExp_(x)		do {yyval.genExp=new x; UTBException::ThrowIfNoParserMemory(yyval.genExp); } while (false)

// Creates exp only if tests are not nil. If one is nil and the others not then the non nil is deallocted and nil is
// returned as the reult.
#define TBMaybeArithExp1_(test,exp)			do {if (test)  { yyval.arithExp=new exp; UTBException::ThrowIfNoParserMemory(yyval.arithExp); } else yyval.arithExp=0L; } while (false)
#define TBMaybeArithExp2_(test,test2,exp)	do {if (test && test2)  { yyval.arithExp=new exp; UTBException::ThrowIfNoParserMemory(yyval.arithExp); } else { yyval.arithExp=0L; delete test; delete test2; } } while (false)
#define TBMaybeStrExp1_(test,exp)			do {if (test)  { yyval.strExp=new exp; UTBException::ThrowIfNoParserMemory(yyval.strExp); } else yyval.strExp=0L; } while (false)
#define TBMaybeStrExp2_(test,test2,exp)		do {if (test && test2)  { yyval.strExp=new exp; UTBException::ThrowIfNoParserMemory(yyval.strExp); } else { yyval.strExp=0L; delete test; delete test2; } } while (false)
#define TBGenExpOrError_(test,exp)			do {if (test) yyval.genExp=new exp; else yyval.genExp=new CGeneralExpressionErr; UTBException::ThrowIfNoParserMemory(yyval.genExp); } while (false)


/* Line 371 of yacc.c  */
#line 381 "basic.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "basic.tab.h".  */
#ifndef YY_BASIC_BASIC_TAB_H_INCLUDED
# define YY_BASIC_BASIC_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int basicdebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     REM = 258,
     INTEGER = 259,
     STRLITERAL = 260,
     LABEL = 261,
     FLOAT = 262,
     PROCIDENTIFIER = 263,
     LABELIDENTIFIER = 264,
     INTIDENTIFIER = 265,
     STRIDENTIFIER = 266,
     FLOATIDENTIFIER = 267,
     UNDECLAREDPRIMITIVE = 268,
     INTARRAYIDENTIFIER = 269,
     STRARRAYIDENTIFIER = 270,
     FLOATARRAYIDENTIFIER = 271,
     UNDECLAREDARRAY = 272,
     PLUS = 273,
     MINUS = 274,
     DIVIDE = 275,
     TIMES = 276,
     POWER = 277,
     OPENBRACKET = 278,
     CLOSEBRACKET = 279,
     UMINUS = 280,
     EQUALS = 281,
     LT = 282,
     GT = 283,
     LTE = 284,
     GTE = 285,
     COMMA = 286,
     ENDLINE = 287,
     NEQ = 288,
     OPENSQBRACKET = 289,
     CLOSESQBRACKET = 290,
     SEMICOLON = 291,
     IF = 292,
     ELSEIF = 293,
     ELSE = 294,
     ENDIF = 295,
     AND = 296,
     OR = 297,
     NOT = 298,
     WHILE = 299,
     THEN = 300,
     INTEGERTYPE = 301,
     FLOATTYPE = 302,
     STRINGTYPE = 303,
     SHARED = 304,
     GLOBAL = 305,
     NETGLOBAL = 306,
     IMPORTANTNETGLOBAL = 307,
     DATA = 308,
     READ = 309,
     RESTORE = 310,
     WEND = 311,
     REPEAT = 312,
     UNTIL = 313,
     FOREVER = 314,
     FOR = 315,
     TO = 316,
     STEP = 317,
     NEXT = 318,
     GOTO = 319,
     DIM = 320,
     PROCEDURE = 321,
     ENDPROC = 322,
     TNTB_TRUE = 323,
     TNTB_FALSE = 324,
     END = 325,
     BREAK = 326,
     PRINT = 327,
     GRAPHICSMODE = 328,
     GRAPHICSMODEHARDWARE = 329,
     TEXTMODE = 330,
     BUTTON = 331,
     WINDOWMODE = 332,
     WINDOWMODEHARDWARE = 333,
     STATEMENTNAME = 334,
     ARITHFUNCTIONNAME = 335,
     STRFUNCTIONNAME = 336,
     SPRITE = 337,
     SYNCSCREEN = 338,
     VBLSYNCON = 339,
     VBLSYNCOFF = 340,
     FRAMERATE = 341,
     FRAMERATEMAX = 342,
     DRAWPICTRES = 343,
     PASTESPRITE = 344,
     PASTEIMAGE = 345,
     ISPRESSED = 346,
     PROCRESULT = 347,
     PROCRESULTSTR = 348,
     BEEP = 349,
     FADEUP = 350,
     FADEDOWN = 351,
     FADETO = 352,
     HIDEMOUSE = 353,
     SHOWMOUSE = 354,
     PROCRESULTFLOAT = 355,
     GETMOUSEX = 356,
     GETMOUSEY = 357,
     LOADSOUNDS = 358,
     PLAYSOUND = 359,
     LOOPSOUND = 360,
     SOUNDRESULT = 361,
     STOPSOUND = 362,
     STOPCHANNEL = 363,
     SOUNDPLAYING = 364,
     CHANNELPLAYING = 365,
     UNLOADSOUNDS = 366,
     MOVESOUND = 367,
     MOVECHANNEL = 368,
     SOUNDVOLUME = 369,
     SETSOUNDVOLUME = 370,
     SPRITEOFF = 371,
     INITNETWORKING = 372,
     HOSTNETGAME = 373,
     JOINNETGAME = 374,
     GETNETPLAYERNAME = 375,
     COUNTNETPLAYERS = 376,
     GETNETID = 377,
     LEAVENETGAME = 378,
     MORENETEVENTS = 379,
     GETNETEVENTTYPE = 380,
     GETNETEVENTCONTENT = 381,
     NETGAMETERMINATED = 382,
     NETPLAYERLEFT = 383,
     NETPLAYERDISCONNECTED = 384,
     NETCONNECTIONLOST = 385,
     SETNETDATA = 386,
     UPDATENETDATA = 387,
     SETNETWORKINGNORMAL = 388,
     SETNETWORKINGREGISTERED = 389,
     COUNTRESOURCES = 390,
     GETRESOURCENAME = 391,
     RESOURCEEXISTS = 392,
     LOADIMAGES = 393,
     UNLOADIMAGES = 394,
     SETSPRITEBANK = 395,
     SETDEFAULTSPRITEBANK = 396,
     SETSPRITEPRIORITY = 397,
     LOADINPUTBANK = 398,
     POLLINPUT = 399,
     EDITINPUT = 400,
     SUSPENDINPUT = 401,
     RESUMEINPUT = 402,
     LOADMUSIC = 403,
     PLAYMUSIC = 404,
     STOPMUSIC = 405,
     GETMUSICLENGTH = 406,
     GETMUSICPOSITION = 407,
     SETMUSICPOSITION = 408,
     MUSICVOLUME = 409,
     SETMUSICVOLUME = 410,
     MUSICLOOPON = 411,
     MUSICLOOPOFF = 412,
     ISMUSICPLAYING = 413,
     DRAWTEXT = 414,
     TEXTFONT = 415,
     TEXTSIZE = 416,
     TEXTFACE = 417,
     NUMTOSTRING = 418,
     STRINGTONUM = 419,
     TEXTWIDTH = 420,
     TEXTHEIGHT = 421,
     TEXTDESCENT = 422,
     OPENCANVAS = 423,
     CLOSECANVAS = 424,
     TARGETCANVAS = 425,
     PAINTCANVAS = 426,
     COPYCANVAS = 427,
     CANVASFX = 428,
     SPRITECOL = 429,
     SPRITECOLRECT = 430,
     POINTINRECT = 431,
     WAITMOUSEDOWN = 432,
     WAITMOUSEUP = 433,
     WAITMOUSECLICK = 434,
     UP = 435,
     DOWN = 436,
     LEFT = 437,
     RIGHT = 438,
     SPACE = 439,
     SETSPRITETRANSPARENCY = 440,
     GETSPRITETRANSPARENCY = 441,
     SPRITECOLOUROFF = 442,
     SPRITECOLOUR = 443,
     LOADTNTMAP = 444,
     UNLOADTNTMAP = 445,
     SETCURRENTTNTMAP = 446,
     GETTNTMAPWIDTH = 447,
     GETTNTMAPHEIGHT = 448,
     GETTNTMAPLAYERS = 449,
     COUNTOBJECTS = 450,
     GETNTHOBJECTNAME = 451,
     GETNTHOBJECTTYPE = 452,
     GETNTHOBJECTX = 453,
     GETNTHOBJECTY = 454,
     GETNTHOBJECTZ = 455,
     COUNTPOLYGONS = 456,
     INPOLYGON = 457,
     POLYNAME = 458,
     POLYBOUNDSX = 459,
     POLYBOUNDSY = 460,
     POLYBOUNDSWIDTH = 461,
     POLYBOUNDSHEIGHT = 462,
     GETTILE = 463,
     DRAWMAPSECTION = 464,
     SETMAPTILE = 465,
     GETMAPTILEWIDTH = 466,
     GETMAPTILEHEIGHT = 467,
     MAPLINECOL = 468,
     LINE = 469,
     FILLRECT = 470,
     FRAMERECT = 471,
     FILLOVAL = 472,
     FRAMEOVAL = 473,
     FILLPOLY = 474,
     FRAMEPOLY = 475,
     SETPIXELCOLOUR = 476,
     GETPIXEL = 477,
     SETPENCOLOUR = 478,
     GETPENCOLOUR = 479,
     SETPENTRANSPARENCY = 480,
     GETPENTRANSPARENCY = 481,
     GETREDCOMPONENT = 482,
     GETGREENCOMPONENT = 483,
     GETBLUECOMPONENT = 484,
     SETREDCOMPONENT = 485,
     SETGREENCOMPONENT = 486,
     SETBLUECOMPONENT = 487,
     ABS = 488,
     MOD = 489,
     SIN = 490,
     COS = 491,
     TAN = 492,
     INVSIN = 493,
     INVCOS = 494,
     INVTAN = 495,
     RADSIN = 496,
     RADCOS = 497,
     RADTAN = 498,
     INVRADSIN = 499,
     INVRADCOS = 500,
     INVRADTAN = 501,
     CALCULATEANGLE = 502,
     ANGLEDIFFERENCE = 503,
     DEGTORAD = 504,
     RADTODEG = 505,
     SQUAREROOT = 506,
     MIN = 507,
     MAX = 508,
     WRAP = 509,
     BITAND = 510,
     BITOR = 511,
     BITXOR = 512,
     BITTEST = 513,
     SETBIT = 514,
     BITSHIFT = 515,
     CEIL = 516,
     ROUND = 517,
     FLOOR = 518,
     RANDOM = 519,
     SETRANDOMSEED = 520,
     GETTIMER = 521,
     DELAY = 522,
     INVALRECT = 523,
     NEWBUTTON = 524,
     CLEARBUTTONS = 525,
     WAITBUTTONCLICK = 526,
     POLLBUTTONCLICK = 527,
     GETBUTTONCLICK = 528,
     CREATEVIEWPORT = 529,
     CREATEMAPVIEWPORT = 530,
     REMOVEVIEWPORT = 531,
     VIEWPORTOFFSET = 532,
     GETVIEWPORTXOFFSET = 533,
     GETVIEWPORTYOFFSET = 534,
     GETVIEWPORTWIDTH = 535,
     GETVIEWPORTHEIGHT = 536,
     DRAWTRACKINGON = 537,
     DRAWTRACKINGOFF = 538,
     MAKECOLOUR = 539,
     NTHRESOURCEID = 540,
     LOWERCASE = 541,
     UPPERCASE = 542,
     STRINGLENGTH = 543,
     REMOVECHAR = 544,
     GETCHAR = 545,
     LEFTSTR = 546,
     RIGHTSTR = 547,
     MIDSTR = 548,
     COUNTIMAGES = 549,
     IMAGEWIDTH = 550,
     IMAGEHEIGHT = 551,
     IMAGEXOFF = 552,
     IMAGEYOFF = 553,
     SETIMAGEOFFSETS = 554,
     WHITE = 555,
     BLACK = 556,
     RED = 557,
     GREEN = 558,
     BLUE = 559,
     YELLOW = 560,
     COPYIMAGE = 561,
     DELETEIMAGE = 562,
     IMAGECOLLISIONTOLERANCE = 563,
     IMAGECOLLISIONTYPE = 564,
     SETIMAGECOLLISION = 565,
     CREATEFILE = 566,
     FILEOPEN = 567,
     ASKCREATEFILE = 568,
     ASKUSERFILEOPEN = 569,
     FILECLOSE = 570,
     FILEWRITE = 571,
     FILEREADSTRING = 572,
     FILEREADFLOAT = 573,
     FILEREADINT = 574,
     NEWFOLDER = 575,
     DELETEFILE = 576,
     FILEPOS = 577,
     SETFILEPOS = 578,
     FILELENGTH = 579,
     FILEEXISTS = 580,
     FILETYPE = 581,
     SETDIRECTORYSYSTEMPREFERENCES = 582,
     SETDIRECTORYUSERPREFERENCES = 583,
     SETDIRECTORYTEMPORARY = 584,
     SETDIRECTORYGAME = 585,
     SPRITEX = 586,
     SPRITEY = 587,
     SPRITEI = 588,
     MOVESPRITE = 589,
     SPRITEBANK = 590,
     SPRITEMOVING = 591,
     SPRITEANIMATING = 592,
     ANIMSPRITE = 593,
     SETMOANPROG = 594,
     ADDSPRITETOCHAN = 595,
     ADDVIEWPORTTOCHAN = 596,
     CHANMOVE = 597,
     CHANANIM = 598,
     REMOVESPRITEFROMCHAN = 599,
     REMOVEVIEWPORTFROMCHAN = 600,
     AUTOMOANON = 601,
     AUTOMOANOFF = 602,
     AUTOMOANING = 603,
     STEPMOAN = 604,
     MOVEVIEWPORT = 605,
     VIEWPORTMOVING = 606,
     PAUSECHANNEL = 607,
     UNPAUSECHANNEL = 608,
     CHANPAUSED = 609,
     RESETCHAN = 610,
     CHANREG = 611,
     SETCHANREG = 612,
     RESTARTCHAN = 613,
     CHANPLAY = 614,
     SETSPRITEANGLE = 615,
     SPRITEANGLE = 616,
     SETSPRITEXSCALE = 617,
     SPRITEXSCALE = 618,
     SETSPRITEYSCALE = 619,
     SPRITEYSCALE = 620,
     SCALESPRITE = 621,
     SPRITESCALING = 622,
     SETSPRITEXFLIP = 623,
     SETSPRITEYFLIP = 624,
     SPRITEXFLIP = 625,
     SPRITEYFLIP = 626,
     ROTATESPRITE = 627,
     SPRITEROTATING = 628,
     SPRITEACTIVE = 629,
     SPRITECROP = 630,
     SPRITECROPOFF = 631,
     DISABLEBREAK = 632,
     READRAWKEY = 633,
     RAW2ASCII = 634,
     RAW2SCANCODE = 635,
     RAW2STR = 636,
     CHAR2ASCII = 637,
     ASCII2CHAR = 638,
     KEYBOARDREPEATON = 639,
     KEYBOARDREPEATOFF = 640,
     GETKEYBOARDREPEAT = 641,
     CLEARKEYBOARD = 642,
     WAITKEYPRESS = 643,
     RAWMODSHIFT = 644,
     RAWMODCOMMAND = 645,
     RAWMODOPTION = 646,
     RAWMODCAPS = 647,
     RAWMODCONTROL = 648,
     RAWFILTNUMBER = 649,
     RAWFILTPRINT = 650,
     RAWFILTNAV = 651,
     RAWFILTDEL = 652,
     STREDITORCONTENTS = 653,
     SETSTREDITORCONTENTS = 654,
     STREDITORCURSOR = 655,
     SETSTREDITORCURSOR = 656,
     STREDITORINPUT = 657
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 307 "basic.y"

	class CGeneralExpression	*genExp;
	class CArithExpression		*arithExp;
	class CStrExpression		*strExp;
	class CProgram				*program;
	class CStatement			*statement;
	class CIntegerStorage		*intStorage;
	class CStrStorage			*strStorage;
	class CFloatStorage			*floatStorage;
	class CLabelEntry			*labelEntry;
	class CArrayDimEntry		*arrayEntry;
	class CProcedure			*procedureDef;
	class CVariableNode			*variableNode;
	class CIntegerArraySymbol	*intArray;
	class CConditionalBlock		*conditionalBlock;
	class CForStatement			*forStatement;
	char						*string;
	int							tokenId;			// used to specify a token id for a general statement
	class CVariableSymbol		*variable;
	class CArraySymbol			*array;
	class CPrimitiveStorage		*storage;


/* Line 387 of yacc.c  */
#line 850 "basic.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE basiclval;
extern YYLTYPE basiclloc;
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int basicparse (void *YYPARSE_PARAM);
#else
int basicparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int basicparse (void);
#else
int basicparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_BASIC_BASIC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 891 "basic.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2499

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  403
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  221
/* YYNRULES -- Number of states.  */
#define YYNSTATES  422

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   657

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    33,    37,    39,    43,
      47,    49,    53,    57,    59,    61,    63,    67,    71,    73,
      75,    78,    82,    87,    89,    91,    95,    99,   103,   107,
     109,   113,   116,   119,   122,   125,   127,   131,   135,   139,
     142,   145,   148,   151,   154,   157,   162,   167,   168,   170,
     174,   178,   182,   185,   192,   195,   202,   204,   209,   214,
     218,   222,   224,   227,   232,   237,   239,   242,   247,   252,
     256,   258,   260,   262,   264,   266,   268,   270,   273,   276,
     280,   284,   288,   292,   296,   300,   304,   306,   310,   314,
     318,   322,   326,   330,   334,   338,   342,   346,   350,   354,
     356,   358,   360,   364,   366,   370,   372,   374,   375,   377,
     379,   381,   383,   387,   391,   395,   399,   403,   407,   411,
     415,   419,   420,   423,   427,   429,   431,   433,   435,   437,
     439,   441,   443,   445,   447,   449,   451,   453,   455,   457,
     459,   461,   463,   465,   467,   470,   472,   476,   478,   482,
     484,   488,   490,   494,   498,   500,   502,   504,   513,   517,
     523,   529,   535,   543,   551,   559,   563,   567,   571,   573,
     577,   579,   583,   587,   591,   595,   597,   601,   603,   607,
     611,   615,   619,   623,   626,   633,   637,   641,   642,   646,
     647,   651,   655,   659,   664,   671,   678,   684,   691,   698,
     705,   710,   711,   714,   717,   719,   722,   725,   730,   735,
     737,   741
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     404,     0,    -1,   434,    -1,    46,    -1,    48,    -1,    47,
      -1,    10,    -1,    11,    -1,    12,    -1,    13,    -1,    14,
      -1,    15,    -1,    16,    -1,    17,    -1,    10,    -1,    14,
       1,    35,    -1,    14,   433,    35,    -1,    11,    -1,    15,
     433,    35,    -1,    15,     1,    35,    -1,    12,    -1,    16,
     433,    35,    -1,    16,     1,    35,    -1,   408,    -1,   410,
      -1,   409,    -1,    17,   433,    35,    -1,    17,     1,    35,
      -1,    13,    -1,   406,    -1,   407,    35,    -1,   406,    31,
     412,    -1,   407,    35,    31,   412,    -1,   406,    -1,   406,
      -1,   413,    26,     1,    -1,   413,    26,   432,    -1,   407,
       1,    35,    -1,   407,   433,    35,    -1,   414,    -1,   414,
      31,   415,    -1,   405,   415,    -1,     1,   415,    -1,   405,
       1,    -1,   405,   406,    -1,   417,    -1,   418,    31,   417,
      -1,     1,    31,   417,    -1,   418,    31,     1,    -1,   405,
     412,    -1,     1,   412,    -1,   405,     1,    -1,   406,    23,
      -1,     8,    23,    -1,     1,    23,    -1,   420,     1,    24,
      32,    -1,   420,   433,    24,    32,    -1,    -1,   418,    -1,
      66,     8,    23,    -1,    66,     8,     1,    -1,    66,     1,
      23,    -1,    66,     1,    -1,   423,     1,    24,   434,   425,
      32,    -1,   423,     1,    -1,   423,   422,    24,   434,   425,
      32,    -1,    67,    -1,    67,    23,   432,    24,    -1,    67,
      23,     1,    24,    -1,    79,   433,    32,    -1,    79,     1,
      32,    -1,    80,    -1,    80,     1,    -1,    80,    23,   433,
      24,    -1,    80,    23,     1,    24,    -1,    81,    -1,    81,
       1,    -1,    81,    23,   433,    24,    -1,    81,    23,     1,
      24,    -1,    23,   429,    24,    -1,     4,    -1,     7,    -1,
     427,    -1,    92,    -1,   100,    -1,   408,    -1,   410,    -1,
      19,   429,    -1,    43,   429,    -1,   429,    18,   429,    -1,
     429,    19,   429,    -1,   429,    21,   429,    -1,   429,    20,
     429,    -1,   429,    22,   429,    -1,   429,    41,   429,    -1,
     429,    42,   429,    -1,   430,    -1,   429,    26,   429,    -1,
     429,    33,   429,    -1,   429,    27,   429,    -1,   429,    29,
     429,    -1,   429,    28,   429,    -1,   429,    30,   429,    -1,
     431,    26,   431,    -1,   431,    33,   431,    -1,   431,    27,
     431,    -1,   431,    29,   431,    -1,   431,    28,   431,    -1,
     431,    30,   431,    -1,    68,    -1,    69,    -1,    93,    -1,
      23,   431,    24,    -1,   409,    -1,   431,    18,   431,    -1,
       5,    -1,   428,    -1,    -1,   429,    -1,   431,    -1,    13,
      -1,   432,    -1,   433,    31,   432,    -1,   433,    61,   432,
      -1,   433,    36,   432,    -1,     1,    31,   432,    -1,     1,
      61,   432,    -1,     1,    36,   432,    -1,   433,    31,     1,
      -1,   433,    36,     1,    -1,   433,    61,     1,    -1,    -1,
     434,   435,    -1,   434,     1,    32,    -1,   471,    -1,   460,
      -1,   465,    -1,   466,    -1,   468,    -1,   445,    -1,   444,
      -1,   456,    -1,   452,    -1,   473,    -1,   451,    -1,   424,
      -1,   421,    -1,   459,    -1,   438,    -1,   440,    -1,   442,
      -1,   454,    -1,   436,    -1,    32,    -1,   416,    32,    -1,
      50,    -1,   437,   416,    32,    -1,    51,    -1,   439,   416,
      32,    -1,    52,    -1,   441,   416,    32,    -1,    49,    -1,
     443,     1,    32,    -1,   443,   419,    32,    -1,   426,    -1,
     446,    -1,   447,    -1,   173,    14,    35,    31,   429,    61,
     429,    32,    -1,   173,     1,    32,    -1,   131,    10,    31,
     429,    32,    -1,   131,    12,    31,   429,    32,    -1,   131,
      11,    31,   431,    32,    -1,   131,    14,   433,    35,    31,
     429,    32,    -1,   131,    16,   433,    35,    31,   429,    32,
      -1,   131,    15,   433,    35,    31,   431,    32,    -1,   131,
       1,    32,    -1,   407,   433,    35,    -1,   407,     1,    35,
      -1,   448,    -1,   449,    31,   448,    -1,    65,    -1,   450,
     449,    32,    -1,   450,     1,    32,    -1,    53,   433,    32,
      -1,    53,     1,    32,    -1,    55,    -1,   453,     9,    32,
      -1,    64,    -1,   455,     9,    32,    -1,    37,   432,    32,
      -1,    37,     1,    32,    -1,    37,   432,    45,    -1,    37,
       1,    45,    -1,   458,   435,    -1,   457,   434,   462,   463,
      40,    32,    -1,    38,   432,    32,    -1,    38,     1,    32,
      -1,    -1,   461,   434,   462,    -1,    -1,    39,    32,   434,
      -1,    44,   432,    32,    -1,    44,     1,    32,    -1,   464,
     434,    56,    32,    -1,    57,    32,   434,    58,   432,    32,
      -1,    57,    32,   434,    58,     1,    32,    -1,    57,    32,
     434,    59,    32,    -1,    60,   411,    26,     1,   469,    32,
      -1,    60,     1,    26,   433,   469,    32,    -1,    60,   411,
      26,   433,   469,    32,    -1,   467,   434,   470,    32,    -1,
      -1,    62,   432,    -1,    62,     1,    -1,    63,    -1,    63,
     411,    -1,    63,     1,    -1,   411,    26,   432,    32,    -1,
     411,    26,     1,    32,    -1,   411,    -1,   411,    31,   472,
      -1,    54,   472,    32,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   451,   451,   460,   461,   462,   466,   467,   468,   469,
     473,   474,   475,   476,   480,   484,   489,   500,   504,   514,
     520,   524,   534,   542,   543,   544,   545,   546,   547,   555,
     556,   557,   558,   564,   570,   572,   582,   611,   616,   656,
     657,   663,   664,   669,   681,   683,   684,   685,   686,   690,
     691,   692,   707,   714,   715,   718,   725,   741,   742,   746,
     764,   770,   775,   782,   795,   806,   827,   832,   846,   861,
     871,   879,   886,   892,   904,   912,   919,   931,   943,   962,
     963,   964,   965,   966,   967,   968,   969,   970,   971,   972,
     973,   974,   975,   976,   977,   978,   979,   988,   989,   990,
     991,   992,   993,   994,   995,   996,   997,   998,   999,  1000,
    1001,  1010,  1011,  1012,  1013,  1014,  1015,  1025,  1026,  1027,
    1028,  1031,  1032,  1033,  1034,  1035,  1036,  1037,  1038,  1039,
    1040,  1048,  1049,  1050,  1055,  1055,  1055,  1055,  1055,  1055,
    1055,  1056,  1056,  1056,  1056,  1056,  1056,  1056,  1057,  1057,
    1057,  1057,  1057,  1057,  1066,  1077,  1079,  1090,  1092,  1103,
    1105,  1119,  1127,  1135,  1175,  1175,  1175,  1177,  1179,  1182,
    1184,  1186,  1188,  1195,  1202,  1209,  1218,  1234,  1241,  1242,
    1244,  1246,  1257,  1264,  1275,  1282,  1287,  1296,  1301,  1332,
    1341,  1347,  1365,  1371,  1387,  1435,  1444,  1450,  1451,  1469,
    1470,  1477,  1488,  1494,  1527,  1550,  1562,  1581,  1587,  1593,
    1633,  1678,  1679,  1683,  1691,  1692,  1709,  1726,  1746,  1753,
    1754,  1757
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "REM", "INTEGER", "STRLITERAL", "LABEL",
  "FLOAT", "PROCIDENTIFIER", "LABELIDENTIFIER", "INTIDENTIFIER",
  "STRIDENTIFIER", "FLOATIDENTIFIER", "UNDECLAREDPRIMITIVE",
  "INTARRAYIDENTIFIER", "STRARRAYIDENTIFIER", "FLOATARRAYIDENTIFIER",
  "UNDECLAREDARRAY", "PLUS", "MINUS", "DIVIDE", "TIMES", "POWER",
  "OPENBRACKET", "CLOSEBRACKET", "UMINUS", "EQUALS", "LT", "GT", "LTE",
  "GTE", "COMMA", "ENDLINE", "NEQ", "OPENSQBRACKET", "CLOSESQBRACKET",
  "SEMICOLON", "IF", "ELSEIF", "ELSE", "ENDIF", "AND", "OR", "NOT",
  "WHILE", "THEN", "INTEGERTYPE", "FLOATTYPE", "STRINGTYPE", "SHARED",
  "GLOBAL", "NETGLOBAL", "IMPORTANTNETGLOBAL", "DATA", "READ", "RESTORE",
  "WEND", "REPEAT", "UNTIL", "FOREVER", "FOR", "TO", "STEP", "NEXT",
  "GOTO", "DIM", "PROCEDURE", "ENDPROC", "TNTB_TRUE", "TNTB_FALSE", "END",
  "BREAK", "PRINT", "GRAPHICSMODE", "GRAPHICSMODEHARDWARE", "TEXTMODE",
  "BUTTON", "WINDOWMODE", "WINDOWMODEHARDWARE", "STATEMENTNAME",
  "ARITHFUNCTIONNAME", "STRFUNCTIONNAME", "SPRITE", "SYNCSCREEN",
  "VBLSYNCON", "VBLSYNCOFF", "FRAMERATE", "FRAMERATEMAX", "DRAWPICTRES",
  "PASTESPRITE", "PASTEIMAGE", "ISPRESSED", "PROCRESULT", "PROCRESULTSTR",
  "BEEP", "FADEUP", "FADEDOWN", "FADETO", "HIDEMOUSE", "SHOWMOUSE",
  "PROCRESULTFLOAT", "GETMOUSEX", "GETMOUSEY", "LOADSOUNDS", "PLAYSOUND",
  "LOOPSOUND", "SOUNDRESULT", "STOPSOUND", "STOPCHANNEL", "SOUNDPLAYING",
  "CHANNELPLAYING", "UNLOADSOUNDS", "MOVESOUND", "MOVECHANNEL",
  "SOUNDVOLUME", "SETSOUNDVOLUME", "SPRITEOFF", "INITNETWORKING",
  "HOSTNETGAME", "JOINNETGAME", "GETNETPLAYERNAME", "COUNTNETPLAYERS",
  "GETNETID", "LEAVENETGAME", "MORENETEVENTS", "GETNETEVENTTYPE",
  "GETNETEVENTCONTENT", "NETGAMETERMINATED", "NETPLAYERLEFT",
  "NETPLAYERDISCONNECTED", "NETCONNECTIONLOST", "SETNETDATA",
  "UPDATENETDATA", "SETNETWORKINGNORMAL", "SETNETWORKINGREGISTERED",
  "COUNTRESOURCES", "GETRESOURCENAME", "RESOURCEEXISTS", "LOADIMAGES",
  "UNLOADIMAGES", "SETSPRITEBANK", "SETDEFAULTSPRITEBANK",
  "SETSPRITEPRIORITY", "LOADINPUTBANK", "POLLINPUT", "EDITINPUT",
  "SUSPENDINPUT", "RESUMEINPUT", "LOADMUSIC", "PLAYMUSIC", "STOPMUSIC",
  "GETMUSICLENGTH", "GETMUSICPOSITION", "SETMUSICPOSITION", "MUSICVOLUME",
  "SETMUSICVOLUME", "MUSICLOOPON", "MUSICLOOPOFF", "ISMUSICPLAYING",
  "DRAWTEXT", "TEXTFONT", "TEXTSIZE", "TEXTFACE", "NUMTOSTRING",
  "STRINGTONUM", "TEXTWIDTH", "TEXTHEIGHT", "TEXTDESCENT", "OPENCANVAS",
  "CLOSECANVAS", "TARGETCANVAS", "PAINTCANVAS", "COPYCANVAS", "CANVASFX",
  "SPRITECOL", "SPRITECOLRECT", "POINTINRECT", "WAITMOUSEDOWN",
  "WAITMOUSEUP", "WAITMOUSECLICK", "UP", "DOWN", "LEFT", "RIGHT", "SPACE",
  "SETSPRITETRANSPARENCY", "GETSPRITETRANSPARENCY", "SPRITECOLOUROFF",
  "SPRITECOLOUR", "LOADTNTMAP", "UNLOADTNTMAP", "SETCURRENTTNTMAP",
  "GETTNTMAPWIDTH", "GETTNTMAPHEIGHT", "GETTNTMAPLAYERS", "COUNTOBJECTS",
  "GETNTHOBJECTNAME", "GETNTHOBJECTTYPE", "GETNTHOBJECTX", "GETNTHOBJECTY",
  "GETNTHOBJECTZ", "COUNTPOLYGONS", "INPOLYGON", "POLYNAME", "POLYBOUNDSX",
  "POLYBOUNDSY", "POLYBOUNDSWIDTH", "POLYBOUNDSHEIGHT", "GETTILE",
  "DRAWMAPSECTION", "SETMAPTILE", "GETMAPTILEWIDTH", "GETMAPTILEHEIGHT",
  "MAPLINECOL", "LINE", "FILLRECT", "FRAMERECT", "FILLOVAL", "FRAMEOVAL",
  "FILLPOLY", "FRAMEPOLY", "SETPIXELCOLOUR", "GETPIXEL", "SETPENCOLOUR",
  "GETPENCOLOUR", "SETPENTRANSPARENCY", "GETPENTRANSPARENCY",
  "GETREDCOMPONENT", "GETGREENCOMPONENT", "GETBLUECOMPONENT",
  "SETREDCOMPONENT", "SETGREENCOMPONENT", "SETBLUECOMPONENT", "ABS", "MOD",
  "SIN", "COS", "TAN", "INVSIN", "INVCOS", "INVTAN", "RADSIN", "RADCOS",
  "RADTAN", "INVRADSIN", "INVRADCOS", "INVRADTAN", "CALCULATEANGLE",
  "ANGLEDIFFERENCE", "DEGTORAD", "RADTODEG", "SQUAREROOT", "MIN", "MAX",
  "WRAP", "BITAND", "BITOR", "BITXOR", "BITTEST", "SETBIT", "BITSHIFT",
  "CEIL", "ROUND", "FLOOR", "RANDOM", "SETRANDOMSEED", "GETTIMER", "DELAY",
  "INVALRECT", "NEWBUTTON", "CLEARBUTTONS", "WAITBUTTONCLICK",
  "POLLBUTTONCLICK", "GETBUTTONCLICK", "CREATEVIEWPORT",
  "CREATEMAPVIEWPORT", "REMOVEVIEWPORT", "VIEWPORTOFFSET",
  "GETVIEWPORTXOFFSET", "GETVIEWPORTYOFFSET", "GETVIEWPORTWIDTH",
  "GETVIEWPORTHEIGHT", "DRAWTRACKINGON", "DRAWTRACKINGOFF", "MAKECOLOUR",
  "NTHRESOURCEID", "LOWERCASE", "UPPERCASE", "STRINGLENGTH", "REMOVECHAR",
  "GETCHAR", "LEFTSTR", "RIGHTSTR", "MIDSTR", "COUNTIMAGES", "IMAGEWIDTH",
  "IMAGEHEIGHT", "IMAGEXOFF", "IMAGEYOFF", "SETIMAGEOFFSETS", "WHITE",
  "BLACK", "RED", "GREEN", "BLUE", "YELLOW", "COPYIMAGE", "DELETEIMAGE",
  "IMAGECOLLISIONTOLERANCE", "IMAGECOLLISIONTYPE", "SETIMAGECOLLISION",
  "CREATEFILE", "FILEOPEN", "ASKCREATEFILE", "ASKUSERFILEOPEN",
  "FILECLOSE", "FILEWRITE", "FILEREADSTRING", "FILEREADFLOAT",
  "FILEREADINT", "NEWFOLDER", "DELETEFILE", "FILEPOS", "SETFILEPOS",
  "FILELENGTH", "FILEEXISTS", "FILETYPE", "SETDIRECTORYSYSTEMPREFERENCES",
  "SETDIRECTORYUSERPREFERENCES", "SETDIRECTORYTEMPORARY",
  "SETDIRECTORYGAME", "SPRITEX", "SPRITEY", "SPRITEI", "MOVESPRITE",
  "SPRITEBANK", "SPRITEMOVING", "SPRITEANIMATING", "ANIMSPRITE",
  "SETMOANPROG", "ADDSPRITETOCHAN", "ADDVIEWPORTTOCHAN", "CHANMOVE",
  "CHANANIM", "REMOVESPRITEFROMCHAN", "REMOVEVIEWPORTFROMCHAN",
  "AUTOMOANON", "AUTOMOANOFF", "AUTOMOANING", "STEPMOAN", "MOVEVIEWPORT",
  "VIEWPORTMOVING", "PAUSECHANNEL", "UNPAUSECHANNEL", "CHANPAUSED",
  "RESETCHAN", "CHANREG", "SETCHANREG", "RESTARTCHAN", "CHANPLAY",
  "SETSPRITEANGLE", "SPRITEANGLE", "SETSPRITEXSCALE", "SPRITEXSCALE",
  "SETSPRITEYSCALE", "SPRITEYSCALE", "SCALESPRITE", "SPRITESCALING",
  "SETSPRITEXFLIP", "SETSPRITEYFLIP", "SPRITEXFLIP", "SPRITEYFLIP",
  "ROTATESPRITE", "SPRITEROTATING", "SPRITEACTIVE", "SPRITECROP",
  "SPRITECROPOFF", "DISABLEBREAK", "READRAWKEY", "RAW2ASCII",
  "RAW2SCANCODE", "RAW2STR", "CHAR2ASCII", "ASCII2CHAR",
  "KEYBOARDREPEATON", "KEYBOARDREPEATOFF", "GETKEYBOARDREPEAT",
  "CLEARKEYBOARD", "WAITKEYPRESS", "RAWMODSHIFT", "RAWMODCOMMAND",
  "RAWMODOPTION", "RAWMODCAPS", "RAWMODCONTROL", "RAWFILTNUMBER",
  "RAWFILTPRINT", "RAWFILTNAV", "RAWFILTDEL", "STREDITORCONTENTS",
  "SETSTREDITORCONTENTS", "STREDITORCURSOR", "SETSTREDITORCURSOR",
  "STREDITORINPUT", "$accept", "program", "variableType", "primVariable",
  "arrayVariable", "intStorage", "strStorage", "floatStorage", "storage",
  "extVariableList", "initedVariableLValue", "initedVariable",
  "initedVariableList", "typedInitedVariableList", "typedPrimVariable",
  "typedPrimVariableList", "typedExtVariableList", "procedureCallHead",
  "procedureCall", "paramList", "procName", "procedureDef", "endProc",
  "statementCall", "intFunctionCall", "strFunctionCall", "numExpression",
  "boolExpression", "strExpression", "genExp", "genExpList",
  "statementBlock", "statement", "varDeclaration", "globalHead",
  "globalStatement", "netGlobalHead", "netGlobalStatement",
  "importantNetGlobalHead", "importantNetGlobalStatement", "sharedHead",
  "sharedStatement", "functionCall", "fxMatrixStatement",
  "setNetDataStatement", "arrayDimEntry", "arrayDimList", "dimHead",
  "dimStatement", "dataStatement", "restoreHead", "restoreStatement",
  "gotoHead", "gotoStatement", "ifHead", "ifThenHead", "ifThenStatement",
  "ifStatement", "elseIfHead", "elseIfs", "else", "whileHead",
  "whileStatement", "repeatStatement", "forHead", "forStatement",
  "stepStatement", "nextStatement", "assignmentStatement", "readVarsList",
  "readStatement", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,   647,   648,   649,   650,   651,   652,   653,   654,
     655,   656,   657
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   403,   404,   405,   405,   405,   406,   406,   406,   406,
     407,   407,   407,   407,   408,   408,   408,   409,   409,   409,
     410,   410,   410,   411,   411,   411,   411,   411,   411,   412,
     412,   412,   412,   413,   414,   414,   414,   414,   414,   415,
     415,   416,   416,   416,   417,   418,   418,   418,   418,   419,
     419,   419,   420,   420,   420,   421,   421,   422,   422,   423,
     423,   423,   423,   424,   424,   424,   425,   425,   425,   426,
     426,   427,   427,   427,   427,   428,   428,   428,   428,   429,
     429,   429,   429,   429,   429,   429,   429,   429,   429,   429,
     429,   429,   429,   429,   429,   429,   429,   430,   430,   430,
     430,   430,   430,   430,   430,   430,   430,   430,   430,   430,
     430,   431,   431,   431,   431,   431,   431,   432,   432,   432,
     432,   433,   433,   433,   433,   433,   433,   433,   433,   433,
     433,   434,   434,   434,   435,   435,   435,   435,   435,   435,
     435,   435,   435,   435,   435,   435,   435,   435,   435,   435,
     435,   435,   435,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   444,   445,   445,   445,   446,   446,   447,
     447,   447,   447,   447,   447,   447,   448,   448,   449,   449,
     450,   451,   451,   452,   452,   453,   454,   455,   456,   457,
     457,   458,   458,   459,   460,   461,   461,   462,   462,   463,
     463,   464,   464,   465,   466,   466,   466,   467,   467,   467,
     468,   469,   469,   469,   470,   470,   470,   471,   471,   472,
     472,   473
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     1,     1,     3,     3,     1,     1,
       2,     3,     4,     1,     1,     3,     3,     3,     3,     1,
       3,     2,     2,     2,     2,     1,     3,     3,     3,     2,
       2,     2,     2,     2,     2,     4,     4,     0,     1,     3,
       3,     3,     2,     6,     2,     6,     1,     4,     4,     3,
       3,     1,     2,     4,     4,     1,     2,     4,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     3,     1,     3,     1,     1,     0,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     0,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     1,     1,     8,     3,     5,
       5,     5,     7,     7,     7,     3,     3,     3,     1,     3,
       1,     3,     3,     3,     3,     1,     3,     1,     3,     3,
       3,     3,     3,     2,     6,     3,     3,     0,     3,     0,
       3,     3,     3,     4,     6,     6,     5,     6,     6,     6,
       4,     0,     2,     2,     1,     2,     2,     4,     4,     1,
       3,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     131,     0,     0,     1,     0,     0,     6,     7,     8,     9,
       0,     0,     0,     0,   153,     0,     0,     3,     5,     4,
     161,   155,   157,   159,     0,     0,   185,     0,     0,   187,
     180,     0,     0,     0,     0,     0,     0,    23,    25,    24,
       0,     0,     0,   146,     0,   145,   164,   132,   152,     0,
     148,     0,   149,     0,   150,     0,   140,   139,   165,   166,
       0,   144,   142,     0,   151,     0,   141,   131,     0,   147,
     135,   131,   136,   137,   131,   138,   134,   143,     6,     7,
       8,     9,    10,    11,    12,    13,    54,   133,    34,     0,
       0,    39,    42,    53,     0,    80,   115,    81,    14,    17,
      20,   120,     0,     0,     0,   109,   110,     0,     0,    83,
     111,    84,    85,   113,    86,    82,   116,   118,    96,   119,
     121,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    28,   219,     0,   131,     0,     0,
      62,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    43,    41,    52,     0,   154,     0,     0,
      64,     0,    45,    58,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   178,     0,     0,     0,     0,     0,
     193,     0,     0,     0,     0,     0,     0,   117,    15,   117,
     117,    87,     0,     0,     0,    88,    72,     0,    76,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,     0,     0,    19,    18,    22,    21,    27,    26,
     190,   192,   189,   191,   202,   201,   184,   183,     0,   221,
       0,     0,     0,    61,    60,    59,    70,    69,   175,     0,
       0,     0,     0,     0,     0,     0,   168,     0,     0,     0,
       0,     0,   131,     0,    44,     0,   131,   156,   158,   160,
     162,    29,     0,    50,    51,    49,   163,   182,     0,     0,
       0,   181,   186,   188,     0,   131,   199,     0,     0,     0,
      37,    38,    35,    36,    40,   125,   127,   126,    79,   112,
       0,     0,     0,     0,    89,    90,    92,    91,    93,    97,
      99,   101,   100,   102,    98,    94,    95,     0,   114,   103,
     105,   107,   106,   108,   104,   128,   122,   129,   124,   130,
     123,   220,     0,     0,   211,   211,   211,     0,     0,     0,
       0,     0,     0,     0,   218,   217,    55,    56,     0,    47,
      48,    46,     0,     0,    30,   177,   176,   179,     0,     0,
       0,     0,     0,   203,   216,   215,   210,    74,    73,    78,
      77,     0,     0,     0,   206,     0,     0,     0,     0,   169,
     171,   170,     0,     0,     0,     0,    66,     0,     0,    31,
       0,   196,   195,   198,   131,     0,   205,   204,   213,   212,
     208,   207,   209,     0,     0,     0,     0,     0,    63,    65,
      32,     0,   194,   172,   174,   173,     0,     0,     0,   167,
      68,    67
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    35,    36,    89,   112,   113,   114,    40,   273,
      90,    91,    92,    41,   162,   163,   171,    42,    43,   164,
      44,    45,   387,    46,   115,   116,   117,   118,   119,   120,
     121,     2,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,   174,   175,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,   285,   286,
     362,    71,    72,    73,    74,    75,   376,   289,    76,   136,
      77
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -244
static const yytype_int16 yypact[] =
{
    -244,    45,   379,  -244,   716,    18,    23,    37,    62,    81,
    1199,  1239,  1311,  1351,  -244,  1859,  1953,  -244,  -244,  -244,
    -244,  -244,  -244,  -244,  1423,   849,  -244,    71,  1165,  -244,
    -244,    86,  1457,   857,    15,  1495,   121,  -244,  -244,  -244,
     111,   128,  1529,  -244,    11,  -244,  -244,  -244,  -244,    14,
    -244,    14,  -244,    14,  -244,    31,  -244,  -244,  -244,  -244,
      38,  -244,  -244,   137,  -244,   155,  -244,  -244,   838,  -244,
    -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,
    -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,   143,  1569,
     161,   167,  -244,  -244,    54,  -244,  -244,  -244,  -244,  -244,
    -244,  -244,  2275,  2275,  2275,  -244,  -244,  2358,  2403,  -244,
    -244,  -244,  -244,  -244,  -244,  -244,  -244,  1268,  -244,  1590,
    -244,   114,   204,   219,   221,   257,   273,   288,    35,    41,
     168,   183,   304,   311,  -244,   185,   187,  -244,   197,   199,
     207,    24,   321,   374,   195,   201,   203,   211,  1641,  1641,
    1641,   215,   210,  -244,  -244,  -244,  1996,  -244,    20,    77,
      67,   144,  -244,   227,   249,  1882,   234,   244,   253,   584,
    1825,   255,   263,  1681,  -244,    43,   265,   289,   439,  1715,
    -244,   574,   646,   338,   406,  1902,  1882,  2232,  -244,  2232,
    2232,   267,  1590,   515,  1042,   267,  -244,  1753,  -244,  1787,
    2275,  2275,  2275,  2275,  2275,  2275,  2275,  2275,  2275,  2275,
    2275,  2275,  2275,    19,    19,    19,    19,    19,    19,    19,
     909,  -244,   981,  1021,  -244,  -244,  -244,  -244,  -244,  -244,
    -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,   849,  -244,
     514,  1093,  1127,  -244,  -244,  -244,  -244,  -244,  -244,  2275,
      19,  2275,   116,   434,   437,   471,  -244,   250,   293,   295,
     298,   301,  -244,   259,  -244,    36,  -244,  -244,  -244,  -244,
    -244,   306,   285,  -244,  -244,  -244,  -244,  -244,   477,   572,
     361,  -244,  -244,  -244,  2047,  -244,   302,   307,   300,   312,
    -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,
      78,   112,   127,   213,   380,   380,   267,   267,  -244,  1058,
    1606,  1606,  1606,  1606,  1058,  1380,   935,    19,  -244,   330,
     330,   330,   330,   330,   330,  -244,  -244,  -244,  -244,  -244,
    -244,  -244,  2090,   322,     7,    34,     7,   647,    -5,   779,
     328,   331,   333,  2275,  -244,  -244,  -244,  -244,   706,  -244,
    -244,  -244,   706,  1882,   336,  -244,  -244,  -244,   329,   351,
     439,   353,   348,  -244,  -244,  -244,  -244,  -244,  -244,  -244,
    -244,    22,   365,   366,  -244,  2141,   372,   375,   383,  -244,
    -244,  -244,  2275,    19,  2275,   242,   389,   385,   386,  -244,
    1882,  -244,  -244,  -244,  -244,   388,  -244,  -244,  -244,  -244,
    -244,  -244,  -244,  2308,    32,  2440,  2275,  2184,  -244,  -244,
    -244,   778,  -244,  -244,  -244,  -244,  2457,   397,   398,  -244,
    -244,  -244
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -244,  -244,   -41,    13,   -59,    -2,     3,     8,   -21,  -159,
    -244,  -244,   -27,   119,  -166,  -244,  -244,  -244,  -244,  -244,
    -244,  -244,    72,  -244,  -244,  -244,     2,  -244,   -84,     6,
     129,   -65,   370,  -244,  -244,  -244,  -244,  -244,  -244,  -244,
    -244,  -244,  -244,  -244,  -244,   166,  -244,  -244,  -244,  -244,
    -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,    88,
    -244,  -244,  -244,  -244,  -244,  -244,  -243,  -244,  -244,   222,
    -244
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -215
static const yytype_int16 yytable[] =
{
      37,   173,   178,   161,   135,    38,   181,   139,   154,   182,
      39,   275,   160,   213,   170,   165,   151,    88,   192,   194,
     192,   129,   131,    37,    96,   244,    37,   380,    38,   152,
      99,    38,   169,    39,    11,   -57,    39,   350,   220,   172,
     213,    93,   317,   222,   260,     3,   299,   245,    88,   -14,
     213,   187,    82,    83,    84,    85,   189,    17,    18,    19,
      17,    18,    19,   -17,   414,   187,    37,   230,   223,   375,
     189,    38,   240,   232,   280,   281,    39,    17,    18,    19,
     231,   190,    17,    18,    19,   187,   233,   140,   -20,   188,
     189,   262,   377,   378,   141,   190,   375,   349,   263,   351,
     108,   261,   367,   137,   191,   193,   195,   -28,   220,   187,
     272,   272,   110,   222,   189,   190,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   318,
     319,   320,   321,   322,   323,   324,   368,   156,   223,   190,
     123,   125,   127,   220,   155,   220,   176,   187,   222,   221,
     222,   369,   189,   133,    78,    79,    80,    81,   187,   294,
     157,   143,   259,   189,   177,   192,   338,   192,   166,   -33,
     167,   159,   168,   223,   264,   223,    37,   190,    88,    37,
      37,    38,   271,   271,    38,    38,    39,   185,   190,    39,
      39,   293,    88,   295,   389,   296,   297,   348,   186,    88,
     234,   352,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   235,   238,   135,   184,   239,
     360,   173,   161,   241,   161,   242,   326,   248,   328,   330,
     243,   410,   249,   371,   250,   187,    37,   370,    37,   224,
     189,    38,   251,    38,   220,   257,    39,   256,    39,   222,
     220,   337,   187,   339,   225,   222,   226,   189,   265,   192,
     200,   201,   202,   203,   204,   190,   267,   365,   205,   206,
     207,   208,   209,   266,   223,   210,   268,   253,   254,   255,
     223,   343,   190,   211,   212,   269,    37,   276,   220,   204,
     359,    38,   227,   222,   272,   277,    39,   282,   192,   404,
     192,   364,   279,   406,   187,    17,    18,    19,   228,   189,
      98,    99,   100,   134,    10,    11,    12,    13,   223,   220,
     354,   283,   192,   229,   222,   344,   301,   345,   303,   411,
     346,   272,  -214,   347,   190,   187,   236,   353,   373,   363,
     189,   361,   220,   237,   366,   385,    37,   222,   213,   223,
      37,    38,   187,   246,   374,    38,    39,   189,    37,   382,
      39,   391,   383,    38,   384,   190,   271,   390,    39,   187,
     334,   336,   223,   290,   189,    82,    83,    84,    85,    -2,
       4,   399,   190,   392,   403,   394,   405,     5,   395,     6,
       7,     8,     9,    10,    11,    12,    13,   396,   397,   190,
     202,   203,   204,   271,   400,   220,   247,   401,   416,    37,
     222,    14,   407,   418,    38,   402,    15,   408,   409,    39,
     412,   420,   421,    16,   388,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,   223,    27,   220,   180,    28,
       4,   291,   222,    29,    30,    31,   357,     5,   393,     6,
       7,     8,     9,    10,    11,    12,    13,     0,    32,     0,
     331,     0,     0,     0,     0,   220,     0,   223,   220,   340,
     222,    14,   341,   222,     0,     0,    15,   284,  -197,  -197,
       0,     0,     0,    16,     0,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,   223,    27,     0,   223,    28,
       0,     0,   220,    29,    30,    31,   342,   222,   187,     0,
      33,     0,   355,   189,     0,     4,     0,     0,    32,     0,
       0,     0,     5,     0,     6,     7,     8,     9,    10,    11,
      12,    13,   223,   200,   201,   202,   203,   204,   190,   298,
       0,   205,   206,   207,   208,   209,    14,     0,   210,     0,
       0,    15,    34,     0,     0,     0,   211,   212,    16,     0,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      33,    27,   332,   333,    28,     4,     0,     0,    29,    30,
      31,     0,     5,     0,     6,     7,     8,     9,    10,    11,
      12,    13,     0,    32,    78,    79,    80,    81,    82,    83,
      84,    85,     0,   220,     0,     0,    14,   356,   222,     0,
       0,    15,    34,     0,     0,     0,   270,     0,    16,     0,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
     287,    27,     0,   223,    28,     0,     0,     0,    29,    30,
      31,     0,     0,     0,     0,    33,     0,     4,     0,     0,
       0,     0,     0,    32,     5,     0,     6,     7,     8,     9,
      10,    11,    12,    13,     0,   200,   201,   202,   203,   204,
       0,     0,     0,   205,   206,   207,   208,   209,    14,   379,
     210,     0,     0,    15,     0,     0,     0,    34,   211,   212,
      16,     0,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,     0,    27,     0,    33,    28,     4,     0,   288,
      29,    30,    31,     0,     5,     0,     6,     7,     8,     9,
      10,    11,    12,    13,     0,    32,    78,    79,    80,    81,
      82,    83,    84,    85,     0,     0,     0,     0,    14,    86,
       0,     0,     0,    15,     0,     0,     0,    34,    87,     0,
      16,     0,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,     0,    27,     0,     0,    28,     0,     0,     0,
      29,    30,    31,   386,     0,     0,     0,    33,     0,     4,
       0,     0,     0,     0,     0,    32,     5,     0,     6,     7,
       8,     9,    10,    11,    12,    13,     0,   200,   201,   202,
     203,   204,     0,     0,     0,   205,   206,   207,   208,   209,
      14,   381,   210,     0,     0,    15,     0,     0,  -200,    34,
     211,   212,    16,     0,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,     0,    27,     0,    33,    28,   179,
       0,     0,    29,    30,    31,     0,     5,     0,     6,     7,
       8,     9,    10,    11,    12,    13,     0,    32,   144,    98,
      99,   100,   134,    10,    11,    12,    13,   145,   146,   147,
      14,   148,   149,   150,     0,    15,     0,     0,     0,    34,
       0,     0,    16,     0,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,     0,    27,     0,     0,    28,     0,
       0,     0,    29,    30,    31,     0,     0,     0,     0,    33,
     325,     0,     0,    95,    96,     0,    97,    32,     0,    98,
      99,   100,   101,    10,    11,    12,     0,     0,   102,     0,
       0,     0,   103,  -117,     0,     0,     0,     0,     0,     0,
    -117,  -117,     0,     0,  -117,  -117,     0,     0,     0,     0,
       0,    34,   104,   200,   201,   202,   203,   204,     0,     0,
       0,   205,   206,   207,   208,   209,     0,     0,   210,    33,
    -117,  -117,     0,     0,     0,     0,   211,   105,   106,     0,
       0,     0,   327,     0,     0,    95,    96,     0,    97,   107,
     108,    98,    99,   100,   101,    10,    11,    12,     0,     0,
     102,   109,   110,     0,   103,  -117,     0,     0,     0,   111,
       0,    34,  -117,  -117,     0,     0,  -117,  -117,     0,     0,
       0,     0,   329,     0,   104,    95,    96,     0,    97,     0,
       0,    98,    99,   100,   101,    10,    11,    12,     0,     0,
     102,     0,  -117,  -117,   103,  -117,     0,     0,     0,   105,
     106,     0,  -117,  -117,     0,     0,  -117,  -117,     0,     0,
     213,   107,   108,     0,   104,     0,   299,     0,   214,   215,
     216,   217,   218,   109,   110,   219,   200,   201,   202,   203,
     204,   111,  -117,  -117,  -215,   206,   207,   208,   209,   105,
     106,  -215,     0,     0,   252,     0,     0,    95,    96,     0,
      97,   107,   108,    98,    99,   100,   101,    10,    11,    12,
       0,     0,   102,   109,   110,     0,   103,     0,     0,     0,
       0,   111,     0,     0,  -117,  -117,     0,     0,   335,  -117,
       0,    95,    96,     0,    97,     0,   104,    98,    99,   100,
     101,    10,    11,    12,     0,     0,   102,     0,     0,     0,
     103,     0,     0,     0,  -117,  -117,     0,     0,  -117,  -117,
       0,   105,   106,  -117,     0,     0,   138,     0,     0,     0,
     104,     0,     0,   107,   108,    98,    99,   100,   134,    10,
      11,    12,    13,     0,     0,   109,   110,     0,  -117,  -117,
       0,     0,     0,   111,     0,   105,   106,     0,     0,     0,
      94,     0,     0,    95,    96,     0,    97,   107,   108,    98,
      99,   100,   101,    10,    11,    12,     0,     0,   102,   109,
     110,     0,   103,     0,     0,     0,     0,   111,     0,     0,
    -117,     0,     0,     0,  -117,  -117,     0,     0,     0,     0,
     122,     0,   104,    95,    96,     0,    97,     0,     0,    98,
      99,   100,   101,    10,    11,    12,     0,     0,   102,     0,
    -117,     0,   103,     0,     0,     0,     0,   105,   106,     0,
    -117,     0,     0,     0,  -117,  -117,     0,     0,     0,   107,
     108,     0,   104,     0,     0,     0,   200,   201,   202,   203,
     204,   109,   110,     0,   205,   206,   207,   208,   209,   111,
    -117,   210,     0,     0,     0,     0,     0,   105,   106,   211,
     212,     0,   124,     0,     0,    95,    96,     0,    97,   107,
     108,    98,    99,   100,   101,    10,    11,    12,     0,     0,
     102,   109,   110,     0,   103,     0,     0,     0,     0,   111,
       0,     0,  -117,     0,     0,     0,  -117,  -117,     0,     0,
       0,     0,   126,     0,   104,    95,    96,     0,    97,     0,
       0,    98,    99,   100,   101,    10,    11,    12,     0,     0,
     102,     0,  -117,     0,   103,     0,     0,     0,     0,   105,
     106,     0,  -117,     0,     0,     0,  -117,  -117,     0,     0,
       0,   107,   108,     0,   104,     0,     0,     0,   200,   201,
     202,   203,   204,   109,   110,     0,   205,   206,   207,   208,
     209,   111,  -117,   210,     0,     0,     0,     0,     0,   105,
     106,     0,     0,     0,   132,     0,     0,    95,    96,     0,
      97,   107,   108,    98,    99,   100,   101,    10,    11,    12,
       0,     0,   102,   109,   110,     0,   103,     0,     0,     0,
       0,   111,     0,     0,  -117,  -117,     0,     0,   142,  -117,
       0,    95,    96,     0,    97,     0,   104,    98,    99,   100,
     101,    10,    11,    12,     0,     0,   102,     0,     0,     0,
     103,     0,     0,     0,  -117,     0,     0,     0,  -117,  -117,
       0,   105,   106,  -117,     0,     0,   153,     0,     0,     0,
     104,     0,     0,   107,   108,    78,    79,    80,    81,    82,
      83,    84,    85,     0,     0,   109,   110,     0,  -117,     0,
       0,     0,     0,   111,     0,   105,   106,     0,     0,     0,
     158,     0,     0,    95,    96,     0,    97,   107,   108,    98,
      99,   100,   101,    10,    11,    12,     0,     0,   102,   109,
     110,     0,   103,  -117,     0,     0,     0,   111,     0,     0,
    -117,     0,     0,     0,     0,  -117,     0,     0,     0,     0,
     183,     0,   104,    95,    96,     0,    97,     0,     0,    98,
      99,   100,   101,    10,    11,    12,     0,     0,   102,     0,
    -117,     0,   103,     0,     0,     0,     0,   105,   106,     0,
    -117,     0,     0,     0,  -117,  -117,     0,     0,   213,   107,
     108,     0,   104,     0,     0,     0,   214,   215,   216,   217,
     218,   109,   110,   219,   200,   201,   202,   203,   204,   111,
    -117,     0,     0,  -215,  -215,  -215,  -215,   105,   106,     0,
       0,     0,   252,     0,     0,    95,    96,     0,    97,   107,
     108,    98,    99,   100,   101,    10,    11,    12,     0,     0,
     102,   109,   110,     0,   103,     0,     0,     0,     0,   111,
       0,     0,  -117,     0,     0,     0,  -117,  -117,     0,     0,
       0,     0,   278,     0,   104,    95,    96,     0,    97,     0,
       0,    98,    99,   100,   101,    10,    11,    12,     0,     0,
     102,     0,  -117,     0,   103,     0,     0,     0,     0,   105,
     106,     0,  -117,     0,     0,     0,  -117,  -117,     0,     0,
       0,   107,   108,     0,   104,    78,    79,    80,    81,    82,
      83,    84,    85,   109,   110,     0,     0,     0,    86,     0,
       0,   111,  -117,     0,     0,     0,     0,     0,     0,   105,
     106,     0,     0,     0,   300,     0,     0,    95,    96,     0,
      97,   107,   108,    98,    99,   100,   101,    10,    11,    12,
       0,     0,   102,   109,   110,     0,   103,  -117,     0,     0,
       0,   111,     0,     0,  -117,     0,     0,     0,   302,  -117,
       0,    95,    96,     0,    97,     0,   104,    98,    99,   100,
     101,    10,    11,    12,     0,     0,   102,     0,     0,     0,
     103,  -117,     0,     0,  -117,     0,     0,     0,  -117,     0,
       0,   105,   106,  -117,     0,     0,   274,     0,     0,     0,
     104,     0,     0,   107,   108,    78,    79,    80,    81,    82,
      83,    84,    85,     0,     0,   109,   110,     0,  -117,     0,
       0,     0,     0,   111,     0,   105,   106,     0,     0,     0,
     128,     0,     0,    95,    96,     0,    97,   107,   108,    98,
      99,   100,   101,    10,    11,    12,     0,     0,   102,   109,
     110,     0,   103,     0,     0,     0,     0,   111,     0,     0,
       0,  -117,    78,    79,    80,    81,    82,    83,    84,    85,
       0,     0,   104,   292,  -117,     0,    95,    96,     0,    97,
       0,     0,    98,    99,   100,   101,    10,    11,    12,     0,
       0,   102,     0,     0,     0,   103,     0,   105,   106,     0,
       0,     0,     0,  -117,  -117,     0,     0,     0,     0,   107,
     108,     0,     0,     0,     0,   104,     0,     0,     0,     0,
       0,   109,   110,     0,   130,     0,     0,    95,    96,   111,
      97,     0,     0,    98,    99,   100,   101,    10,    11,    12,
     105,   106,   102,     0,     0,     0,   103,     0,     0,     0,
       0,     0,   107,   108,     0,  -117,     0,     0,     0,     0,
       0,     0,     0,     0,   109,   110,   104,   258,     0,     0,
      95,    96,   111,    97,     0,     0,    98,    99,   100,   101,
      10,    11,    12,     0,     0,   102,     0,     0,     0,   103,
       0,   105,   106,     0,     0,     0,     0,     0,  -117,     0,
       0,     0,     0,   107,   108,     0,     0,     0,     0,   104,
       0,     0,     0,     0,     0,   109,   110,     0,   358,     0,
       0,    95,    96,   111,    97,     0,     0,    98,    99,   100,
     101,    10,    11,    12,   105,   106,   102,     0,     0,     0,
     103,     0,     0,     0,     0,     0,   107,   108,     0,  -117,
       0,     0,     0,     0,     0,     0,     0,     0,   109,   110,
     104,   372,     0,     0,    95,    96,   111,    97,     0,     0,
      98,    99,   100,   101,    10,    11,    12,     0,     0,   102,
       0,     0,     0,   103,     0,   105,   106,     0,     0,     0,
       0,     0,  -117,     0,     0,     0,     0,   107,   108,     0,
       0,     0,     0,   104,     0,     0,     0,     0,     0,   109,
     110,     0,   398,     0,     0,    95,    96,   111,    97,     0,
       0,    98,    99,   100,   101,    10,    11,    12,   105,   106,
     102,     0,     0,     0,   103,     0,     0,     0,     0,     0,
     107,   108,     0,  -117,     0,     0,     0,     0,     0,     0,
       0,     0,   109,   110,   104,   417,     0,     0,    95,    96,
     111,    97,     0,     0,    98,    99,   100,   101,    10,    11,
      12,     0,     0,   102,     0,     0,     0,   103,  -117,   105,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107,   108,     0,     0,     0,     0,   104,     0,     0,
       0,     0,     0,   109,   110,     0,    95,    96,     0,    97,
       0,   111,    98,    99,   100,   101,    10,    11,    12,     0,
       0,   102,   105,   106,     0,   103,     0,     0,     0,     0,
       0,     0,     0,     0,   107,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,   109,   110,     0,    95,
      96,     0,    97,     0,   111,    98,    99,   100,     0,    10,
      11,    12,     0,     0,   102,     0,     0,     0,   103,     0,
     105,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   107,   108,     0,     0,     0,     0,   104,     0,
       0,     0,     0,     0,   109,   110,   200,   201,   202,   203,
     204,     0,   111,     0,   205,   206,   207,   208,   209,     0,
     413,   210,     0,   105,   106,     0,     0,     0,     0,   211,
     212,     0,     0,     0,     0,   107,   108,     0,     0,   196,
       0,     0,     0,     0,     0,     0,     0,   109,   110,     0,
       0,     0,     0,     0,     0,   111,   -71,   -71,   -71,   -71,
     -71,   197,   -71,     0,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,     0,   -71,   -71,     0,     0,     0,     0,   -71,
     -71,     0,     0,   -71,   198,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -71,
     -71,   -75,   -75,   -75,   -75,   -75,   199,   -75,     0,   -75,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,     0,   -75,   -75,
       0,     0,     0,     0,   -75,   -75,     0,     0,   -75,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   200,   201,
     202,   203,   204,     0,   -75,   -75,   205,   206,   207,   208,
     209,     0,   415,   210,     0,   200,   201,   202,   203,   204,
       0,   211,   212,   205,   206,   207,   208,   209,     0,   419,
     210,     0,     0,     0,     0,     0,     0,     0,   211,   212
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-244)))

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-215)))

static const yytype_int16 yycheck[] =
{
       2,    60,    67,    44,    25,     2,    71,    28,    35,    74,
       2,   170,     1,    18,    55,     1,     1,     4,   102,   103,
     104,    15,    16,    25,     5,     1,    28,    32,    25,    14,
      11,    28,     1,    25,    15,    24,    28,     1,    31,     1,
      18,    23,    23,    36,    24,     0,    24,    23,    35,    26,
      18,    31,    14,    15,    16,    17,    36,    46,    47,    48,
      46,    47,    48,    26,    32,    31,    68,    32,    61,    62,
      36,    68,   137,    32,    31,    32,    68,    46,    47,    48,
      45,    61,    46,    47,    48,    31,    45,     1,    26,    35,
      36,    24,   335,   336,     8,    61,    62,   263,    31,   265,
      81,    24,    24,    32,   102,   103,   104,    26,    31,    31,
     169,   170,    93,    36,    36,    61,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,    24,    26,    61,    61,
      11,    12,    13,    31,    23,    31,     9,    31,    36,    35,
      36,    24,    36,    24,    10,    11,    12,    13,    31,   186,
      32,    32,   156,    36,     9,   249,   250,   251,    49,    26,
      51,    42,    53,    61,   161,    61,   178,    61,   165,   181,
     182,   178,   169,   170,   181,   182,   178,    26,    61,   181,
     182,   185,   179,   187,   353,   189,   190,   262,    31,   186,
      32,   266,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,    32,    31,   238,    89,    32,
     285,   280,   263,    26,   265,    26,   220,    32,   222,   223,
      23,   390,    31,   317,    31,    31,   238,    24,   240,    35,
      36,   238,    31,   240,    31,    35,   238,    32,   240,    36,
      31,   249,    31,   251,    35,    36,    35,    36,    31,   343,
      18,    19,    20,    21,    22,    61,    32,   288,    26,    27,
      28,    29,    30,    24,    61,    33,    32,   148,   149,   150,
      61,    31,    61,    41,    42,    32,   288,    32,    31,    22,
     284,   288,    35,    36,   353,    32,   288,    32,   382,   383,
     384,     1,   173,    61,    31,    46,    47,    48,    35,    36,
      10,    11,    12,    13,    14,    15,    16,    17,    61,    31,
      35,    32,   406,    35,    36,    32,   197,    32,   199,   394,
      32,   390,    32,    32,    61,    31,    32,    31,   332,    32,
      36,    39,    31,    32,    32,   343,   348,    36,    18,    61,
     352,   348,    31,    32,    32,   352,   348,    36,   360,    31,
     352,    32,    31,   360,    31,    61,   353,    31,   360,    31,
     241,   242,    61,    35,    36,    14,    15,    16,    17,     0,
       1,   375,    61,    32,   382,    32,   384,     8,    40,    10,
      11,    12,    13,    14,    15,    16,    17,    32,    32,    61,
      20,    21,    22,   390,    32,    31,    32,    32,   406,   411,
      36,    32,    23,   407,   411,    32,    37,    32,    32,   411,
      32,    24,    24,    44,   352,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    61,    57,    31,    68,    60,
       1,    35,    36,    64,    65,    66,   280,     8,   360,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    79,    -1,
     238,    -1,    -1,    -1,    -1,    31,    -1,    61,    31,    35,
      36,    32,    35,    36,    -1,    -1,    37,    38,    39,    40,
      -1,    -1,    -1,    44,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    61,    57,    -1,    61,    60,
      -1,    -1,    31,    64,    65,    66,    35,    36,    31,    -1,
     131,    -1,    35,    36,    -1,     1,    -1,    -1,    79,    -1,
      -1,    -1,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    61,    18,    19,    20,    21,    22,    61,    24,
      -1,    26,    27,    28,    29,    30,    32,    -1,    33,    -1,
      -1,    37,   173,    -1,    -1,    -1,    41,    42,    44,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
     131,    57,    58,    59,    60,     1,    -1,    -1,    64,    65,
      66,    -1,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    79,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    31,    -1,    -1,    32,    35,    36,    -1,
      -1,    37,   173,    -1,    -1,    -1,    32,    -1,    44,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    61,    60,    -1,    -1,    -1,    64,    65,
      66,    -1,    -1,    -1,    -1,   131,    -1,     1,    -1,    -1,
      -1,    -1,    -1,    79,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    32,    32,
      33,    -1,    -1,    37,    -1,    -1,    -1,   173,    41,    42,
      44,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    -1,   131,    60,     1,    -1,    63,
      64,    65,    66,    -1,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    79,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    32,    23,
      -1,    -1,    -1,    37,    -1,    -1,    -1,   173,    32,    -1,
      44,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    -1,    -1,    60,    -1,    -1,    -1,
      64,    65,    66,    67,    -1,    -1,    -1,   131,    -1,     1,
      -1,    -1,    -1,    -1,    -1,    79,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      32,    32,    33,    -1,    -1,    37,    -1,    -1,    40,   173,
      41,    42,    44,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    -1,   131,    60,     1,
      -1,    -1,    64,    65,    66,    -1,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    79,     1,    10,
      11,    12,    13,    14,    15,    16,    17,    10,    11,    12,
      32,    14,    15,    16,    -1,    37,    -1,    -1,    -1,   173,
      -1,    -1,    44,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    -1,    -1,    60,    -1,
      -1,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,   131,
       1,    -1,    -1,     4,     5,    -1,     7,    79,    -1,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    19,    -1,
      -1,    -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,
      -1,   173,    43,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    -1,    33,   131,
      61,    62,    -1,    -1,    -1,    -1,    41,    68,    69,    -1,
      -1,    -1,     1,    -1,    -1,     4,     5,    -1,     7,    80,
      81,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      19,    92,    93,    -1,    23,    24,    -1,    -1,    -1,   100,
      -1,   173,    31,    32,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,     1,    -1,    43,     4,     5,    -1,     7,    -1,
      -1,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      19,    -1,    61,    62,    23,    24,    -1,    -1,    -1,    68,
      69,    -1,    31,    32,    -1,    -1,    35,    36,    -1,    -1,
      18,    80,    81,    -1,    43,    -1,    24,    -1,    26,    27,
      28,    29,    30,    92,    93,    33,    18,    19,    20,    21,
      22,   100,    61,    62,    26,    27,    28,    29,    30,    68,
      69,    33,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,
       7,    80,    81,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    19,    92,    93,    -1,    23,    -1,    -1,    -1,
      -1,   100,    -1,    -1,    31,    32,    -1,    -1,     1,    36,
      -1,     4,     5,    -1,     7,    -1,    43,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    19,    -1,    -1,    -1,
      23,    -1,    -1,    -1,    61,    62,    -1,    -1,    31,    32,
      -1,    68,    69,    36,    -1,    -1,     1,    -1,    -1,    -1,
      43,    -1,    -1,    80,    81,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    -1,    92,    93,    -1,    61,    62,
      -1,    -1,    -1,   100,    -1,    68,    69,    -1,    -1,    -1,
       1,    -1,    -1,     4,     5,    -1,     7,    80,    81,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    19,    92,
      93,    -1,    23,    -1,    -1,    -1,    -1,   100,    -1,    -1,
      31,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,
       1,    -1,    43,     4,     5,    -1,     7,    -1,    -1,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    19,    -1,
      61,    -1,    23,    -1,    -1,    -1,    -1,    68,    69,    -1,
      31,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,    80,
      81,    -1,    43,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    92,    93,    -1,    26,    27,    28,    29,    30,   100,
      61,    33,    -1,    -1,    -1,    -1,    -1,    68,    69,    41,
      42,    -1,     1,    -1,    -1,     4,     5,    -1,     7,    80,
      81,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      19,    92,    93,    -1,    23,    -1,    -1,    -1,    -1,   100,
      -1,    -1,    31,    -1,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,     1,    -1,    43,     4,     5,    -1,     7,    -1,
      -1,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      19,    -1,    61,    -1,    23,    -1,    -1,    -1,    -1,    68,
      69,    -1,    31,    -1,    -1,    -1,    35,    36,    -1,    -1,
      -1,    80,    81,    -1,    43,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    92,    93,    -1,    26,    27,    28,    29,
      30,   100,    61,    33,    -1,    -1,    -1,    -1,    -1,    68,
      69,    -1,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,
       7,    80,    81,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    19,    92,    93,    -1,    23,    -1,    -1,    -1,
      -1,   100,    -1,    -1,    31,    32,    -1,    -1,     1,    36,
      -1,     4,     5,    -1,     7,    -1,    43,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    19,    -1,    -1,    -1,
      23,    -1,    -1,    -1,    61,    -1,    -1,    -1,    31,    32,
      -1,    68,    69,    36,    -1,    -1,     1,    -1,    -1,    -1,
      43,    -1,    -1,    80,    81,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    -1,    92,    93,    -1,    61,    -1,
      -1,    -1,    -1,   100,    -1,    68,    69,    -1,    -1,    -1,
       1,    -1,    -1,     4,     5,    -1,     7,    80,    81,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    19,    92,
      93,    -1,    23,    24,    -1,    -1,    -1,   100,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
       1,    -1,    43,     4,     5,    -1,     7,    -1,    -1,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    19,    -1,
      61,    -1,    23,    -1,    -1,    -1,    -1,    68,    69,    -1,
      31,    -1,    -1,    -1,    35,    36,    -1,    -1,    18,    80,
      81,    -1,    43,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    92,    93,    33,    18,    19,    20,    21,    22,   100,
      61,    -1,    -1,    27,    28,    29,    30,    68,    69,    -1,
      -1,    -1,     1,    -1,    -1,     4,     5,    -1,     7,    80,
      81,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      19,    92,    93,    -1,    23,    -1,    -1,    -1,    -1,   100,
      -1,    -1,    31,    -1,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,     1,    -1,    43,     4,     5,    -1,     7,    -1,
      -1,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      19,    -1,    61,    -1,    23,    -1,    -1,    -1,    -1,    68,
      69,    -1,    31,    -1,    -1,    -1,    35,    36,    -1,    -1,
      -1,    80,    81,    -1,    43,    10,    11,    12,    13,    14,
      15,    16,    17,    92,    93,    -1,    -1,    -1,    23,    -1,
      -1,   100,    61,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    -1,    -1,    -1,     1,    -1,    -1,     4,     5,    -1,
       7,    80,    81,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    19,    92,    93,    -1,    23,    24,    -1,    -1,
      -1,   100,    -1,    -1,    31,    -1,    -1,    -1,     1,    36,
      -1,     4,     5,    -1,     7,    -1,    43,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    19,    -1,    -1,    -1,
      23,    24,    -1,    -1,    61,    -1,    -1,    -1,    31,    -1,
      -1,    68,    69,    36,    -1,    -1,     1,    -1,    -1,    -1,
      43,    -1,    -1,    80,    81,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    -1,    92,    93,    -1,    61,    -1,
      -1,    -1,    -1,   100,    -1,    68,    69,    -1,    -1,    -1,
       1,    -1,    -1,     4,     5,    -1,     7,    80,    81,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    19,    92,
      93,    -1,    23,    -1,    -1,    -1,    -1,   100,    -1,    -1,
      -1,    32,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    43,     1,    45,    -1,     4,     5,    -1,     7,
      -1,    -1,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    19,    -1,    -1,    -1,    23,    -1,    68,    69,    -1,
      -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    80,
      81,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    92,    93,    -1,     1,    -1,    -1,     4,     5,   100,
       7,    -1,    -1,    10,    11,    12,    13,    14,    15,    16,
      68,    69,    19,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    80,    81,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    43,     1,    -1,    -1,
       4,     5,   100,     7,    -1,    -1,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    19,    -1,    -1,    -1,    23,
      -1,    68,    69,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    -1,    92,    93,    -1,     1,    -1,
      -1,     4,     5,   100,     7,    -1,    -1,    10,    11,    12,
      13,    14,    15,    16,    68,    69,    19,    -1,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      43,     1,    -1,    -1,     4,     5,   100,     7,    -1,    -1,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    19,
      -1,    -1,    -1,    23,    -1,    68,    69,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    80,    81,    -1,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    92,
      93,    -1,     1,    -1,    -1,     4,     5,   100,     7,    -1,
      -1,    10,    11,    12,    13,    14,    15,    16,    68,    69,
      19,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      80,    81,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    43,     1,    -1,    -1,     4,     5,
     100,     7,    -1,    -1,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    19,    -1,    -1,    -1,    23,    24,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    81,    -1,    -1,    -1,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    92,    93,    -1,     4,     5,    -1,     7,
      -1,   100,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    19,    68,    69,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    92,    93,    -1,     4,
       5,    -1,     7,    -1,   100,    10,    11,    12,    -1,    14,
      15,    16,    -1,    -1,    19,    -1,    -1,    -1,    23,    -1,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    92,    93,    18,    19,    20,    21,
      22,    -1,   100,    -1,    26,    27,    28,    29,    30,    -1,
      32,    33,    -1,    68,    69,    -1,    -1,    -1,    -1,    41,
      42,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,     1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,
      -1,    -1,    -1,    -1,    -1,   100,    18,    19,    20,    21,
      22,    23,    24,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    -1,    -1,    -1,    -1,    41,
      42,    -1,    -1,    45,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      62,    18,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      -1,    -1,    -1,    -1,    41,    42,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    -1,    61,    62,    26,    27,    28,    29,
      30,    -1,    32,    33,    -1,    18,    19,    20,    21,    22,
      -1,    41,    42,    26,    27,    28,    29,    30,    -1,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   404,   434,     0,     1,     8,    10,    11,    12,    13,
      14,    15,    16,    17,    32,    37,    44,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    57,    60,    64,
      65,    66,    79,   131,   173,   405,   406,   408,   409,   410,
     411,   416,   420,   421,   423,   424,   426,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   464,   465,   466,   467,   468,   471,   473,    10,    11,
      12,    13,    14,    15,    16,    17,    23,    32,   406,   407,
     413,   414,   415,    23,     1,     4,     5,     7,    10,    11,
      12,    13,    19,    23,    43,    68,    69,    80,    81,    92,
      93,   100,   408,   409,   410,   427,   428,   429,   430,   431,
     432,   433,     1,   433,     1,   433,     1,   433,     1,   432,
       1,   432,     1,   433,    13,   411,   472,    32,     1,   411,
       1,     8,     1,   433,     1,    10,    11,    12,    14,    15,
      16,     1,    14,     1,   415,    23,    26,    32,     1,   433,
       1,   405,   417,   418,   422,     1,   416,   416,   416,     1,
     405,   419,     1,   407,   448,   449,     9,     9,   434,     1,
     435,   434,   434,     1,   433,    26,    31,    31,    35,    36,
      61,   429,   431,   429,   431,   429,     1,    23,     1,    23,
      18,    19,    20,    21,    22,    26,    27,    28,    29,    30,
      33,    41,    42,    18,    26,    27,    28,    29,    30,    33,
      31,    35,    36,    61,    35,    35,    35,    35,    35,    35,
      32,    45,    32,    45,    32,    32,    32,    32,    31,    32,
     434,    26,    26,    23,     1,    23,    32,    32,    32,    31,
      31,    31,     1,   433,   433,   433,    32,    35,     1,   432,
      24,    24,    24,    31,   406,    31,    24,    32,    32,    32,
      32,   406,   407,   412,     1,   412,    32,    32,     1,   433,
      31,    32,    32,    32,    38,   461,   462,    56,    63,   470,
      35,    35,     1,   432,   415,   432,   432,   432,    24,    24,
       1,   433,     1,   433,   429,   429,   429,   429,   429,   429,
     429,   429,   429,   429,   429,   429,   429,    23,   431,   431,
     431,   431,   431,   431,   431,     1,   432,     1,   432,     1,
     432,   472,    58,    59,   433,     1,   433,   429,   431,   429,
      35,    35,    35,    31,    32,    32,    32,    32,   434,   417,
       1,   417,   434,    31,    35,    35,    35,   448,     1,   432,
     434,    39,   463,    32,     1,   411,    32,    24,    24,    24,
      24,   431,     1,   432,    32,    62,   469,   469,   469,    32,
      32,    32,    31,    31,    31,   429,    67,   425,   425,   412,
      31,    32,    32,   462,    32,    40,    32,    32,     1,   432,
      32,    32,    32,   429,   431,   429,    61,    23,    32,    32,
     412,   434,    32,    32,    32,    32,   429,     1,   432,    32,
      24,    24
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;


/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1787 of yacc.c  */
#line 451 "basic.y"
    { (yyval.program)=CProgram::GetParsingProgram(); CProgram::GetParsingProgram()->SetCode((yyvsp[(1) - (1)].statement)); CProgram::GetParsingProgram()->SetDC(CProgram::GetParsingProgram()->GetDataStatementScope()->DataStatements()); }
    break;

  case 3:
/* Line 1787 of yacc.c  */
#line 460 "basic.y"
    { /*CProgram::GetParsingProgram()->SetReportVarNotDecl(false);*/ CProgram::GetParsingProgram()->SetDeclarationMode(CVariableSymbol::kInteger); }
    break;

  case 4:
/* Line 1787 of yacc.c  */
#line 461 "basic.y"
    { /*CProgram::GetParsingProgram()->SetReportVarNotDecl(false);*/ CProgram::GetParsingProgram()->SetDeclarationMode(CVariableSymbol::kString); }
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 462 "basic.y"
    { /*CProgram::GetParsingProgram()->SetReportVarNotDecl(false);*/ CProgram::GetParsingProgram()->SetDeclarationMode(CVariableSymbol::kFloat); }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 481 "basic.y"
    {
			(yyval.intStorage)=static_cast<CIntegerSymbol*>((yyvsp[(1) - (1)].variable));
		}
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 485 "basic.y"
    {
			(yyval.intStorage)=0L;			
			LogException_(UTBException::ThrowWithRange((yylsp[(2) - (3)]),kTBErr_IllegalExp));
		}
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 490 "basic.y"
    {
			if (CheckArrayIndexList(*CProgram::GetParsingProgram(),(yyvsp[(2) - (3)].genExp),(yylsp[(3) - (3)])))
			{
				(yyval.intStorage)=new CIntegerArrayItem(static_cast<CIntegerArraySymbol*>((yyvsp[(1) - (3)].array)),(yyvsp[(2) - (3)].genExp));
				UTBException::ThrowIfNoParserMemory((yyval.intStorage));
			}
			else
				(yyval.intStorage)=0L;
		}
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 501 "basic.y"
    {
			(yyval.strStorage)=static_cast<CStrSymbol*>((yyvsp[(1) - (1)].variable));
		}
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 505 "basic.y"
    {
			if (CheckArrayIndexList(*CProgram::GetParsingProgram(),(yyvsp[(2) - (3)].genExp),(yylsp[(3) - (3)])))
			{
				(yyval.strStorage)=new CStrArrayItem(static_cast<CStrArraySymbol*>((yyvsp[(1) - (3)].array)),(yyvsp[(2) - (3)].genExp));
				UTBException::ThrowIfNoParserMemory((yyval.strStorage));
			}
			else
				(yyval.strStorage)=0L;
		}
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 515 "basic.y"
    {
			(yyval.strStorage)=0L;			
			LogException_(UTBException::ThrowWithRange((yylsp[(2) - (3)]),kTBErr_IllegalExp));
		}
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 521 "basic.y"
    {
			(yyval.floatStorage)=static_cast<CFloatSymbol*>((yyvsp[(1) - (1)].variable));
		}
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 525 "basic.y"
    {
			if (CheckArrayIndexList(*CProgram::GetParsingProgram(),(yyvsp[(2) - (3)].genExp),(yylsp[(3) - (3)])))
			{
				(yyval.floatStorage)=new CFloatArrayItem(static_cast<CFloatArraySymbol*>((yyvsp[(1) - (3)].array)),(yyvsp[(2) - (3)].genExp));
				UTBException::ThrowIfNoParserMemory((yyval.floatStorage));
			}
			else
				(yyval.floatStorage)=0L;
		}
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 535 "basic.y"
    {
			(yyval.floatStorage)=0L;			
			LogException_(UTBException::ThrowWithRange((yylsp[(2) - (3)]),kTBErr_IllegalExp));
		}
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 542 "basic.y"
    { if (!(yyvsp[(1) - (1)].intStorage)) (yyval.storage)=0L; else { (yyval.storage)=new CPrimitiveStorage((yyvsp[(1) - (1)].intStorage)); UTBException::ThrowIfNoParserMemory((yyval.storage)); } }
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 543 "basic.y"
    { if (!(yyvsp[(1) - (1)].floatStorage)) (yyval.storage)=0L; else { (yyval.storage)=new CPrimitiveStorage((yyvsp[(1) - (1)].floatStorage)); UTBException::ThrowIfNoParserMemory((yyval.storage)); } }
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 544 "basic.y"
    { if (!(yyvsp[(1) - (1)].strStorage)) (yyval.storage)=0L; else { (yyval.storage)=new CPrimitiveStorage((yyvsp[(1) - (1)].strStorage)); UTBException::ThrowIfNoParserMemory((yyval.storage)); } }
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 545 "basic.y"
    { delete (yyvsp[(2) - (3)].genExp); (yyval.storage)=0; }
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 546 "basic.y"
    { (yyval.storage)=0; }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 547 "basic.y"
    { (yyval.storage)=0L; }
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 555 "basic.y"
    { (yyval.variableNode)=new CVariableNode((yyvsp[(1) - (1)].variable)); UTBException::ThrowIfNoParserMemory((yyval.variableNode)); }
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 556 "basic.y"
    { (yyval.variableNode)=new CVariableNode((yyvsp[(1) - (2)].array)); UTBException::ThrowIfNoParserMemory((yyval.variableNode)); }
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 557 "basic.y"
    { (yyval.variableNode)=new CVariableNode((yyvsp[(1) - (3)].variable)); UTBException::ThrowIfNoParserMemory((yyval.variableNode)); ConsData((yyval.variableNode),(yyvsp[(3) - (3)].variableNode)); }
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 558 "basic.y"
    { (yyval.variableNode)=new CVariableNode((yyvsp[(1) - (4)].array)); UTBException::ThrowIfNoParserMemory((yyval.variableNode)); ConsData((yyval.variableNode),(yyvsp[(4) - (4)].variableNode)); }
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 564 "basic.y"
    { (yyval.variable)=(yyvsp[(1) - (1)].variable); CProgram::GetParsingProgram()->PauseDeclarationMode(); }
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 570 "basic.y"
    { (yyval.variableNode)=new CVariableNode((yyvsp[(1) - (1)].variable)); UTBException::ThrowIfNoParserMemory((yyval.variableNode)); }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 573 "basic.y"
    {
			(yyval.variableNode)=0;
			FlushExp();
			yyclearin;
			LogException_(UTBException::ThrowWithRange((yylsp[(3) - (3)]),kTBErr_IllegalExp));			

			// resume declaration mode pause by the reduction of initedVariableLValue
			CProgram::GetParsingProgram()->ResumeDeclarationMode();
		}
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 583 "basic.y"
    {
			(yyval.variableNode)=0L;
			
			if (CGeneralExpressionErr::ContainsErrors((yyvsp[(3) - (3)].genExp)))
				(yyval.variableNode)=0L;
			else if ((yyvsp[(1) - (3)].variable) && !(yyvsp[(1) - (3)].variable)->IsUndeclared())
			{
				// Create the variable node
				(yyval.variableNode)=new CVariableNode((yyvsp[(1) - (3)].variable));

				Try_
				{
					UTBException::ThrowIfNoParserMemory((yyval.variableNode));
					
					(yyval.variableNode)->mInitStatement=MakeAssignmentStatement(CPrimitiveStorage((yyvsp[(1) - (3)].variable)),(yyvsp[(3) - (3)].genExp),(yylsp[(3) - (3)]));
				}
				Catch_(err)
				{
					// log the error
					delete (yyval.variableNode);	// don't leak this on error
					(yyval.variableNode)=0L;		// IMPORTANT!!
					CProgram::GetParsingProgram()->LogError(err);
				}
			}
			
			// resume declaration mode pause by the reduction of initedVariableLValue
			CProgram::GetParsingProgram()->ResumeDeclarationMode();
		}
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 612 "basic.y"
    {
			LogException_(UTBException::ThrowWithRange((yylsp[(2) - (3)]),kTBErr_IllegalExp));			
			(yyval.variableNode)=0;
		}
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 617 "basic.y"
    {
			// allow nil lists as this is a declaration
			if (CGeneralExpression::IsNullList((yyvsp[(2) - (3)].genExp)))	// list can be null (I think...)
			{
				(yyval.variableNode)=new CVariableNode((yyvsp[(1) - (3)].array)); UTBException::ThrowIfNoParserMemory((yyval.variableNode));
				delete (yyvsp[(2) - (3)].genExp);
			}
			else if (CheckArrayIndexList(*CProgram::GetParsingProgram(),(yyvsp[(2) - (3)].genExp),(yylsp[(3) - (3)])))
			{
				if (!(yyvsp[(2) - (3)].genExp))
				{
					(yyval.variableNode)=new CVariableNode((yyvsp[(1) - (3)].array)); UTBException::ThrowIfNoParserMemory((yyval.variableNode));
				}
				else
				{
					// Create an array dimensioning statement
					if ((yyvsp[(1) - (3)].array)->GetType()==CVariableSymbol::kUndeclaredArray)
					{
						// undeclared arrays already reported in lexer
						delete (yyvsp[(2) - (3)].genExp);
						(yyval.variableNode)=0;
					}
					else
					{
						CArrayDimEntry	*de=new CArrayDimEntry((yyvsp[(1) - (3)].array),(yyvsp[(2) - (3)].genExp));
						UTBException::ThrowIfNoParserMemory(de);
						
						(yyval.variableNode)=new CVariableNode((yyvsp[(1) - (3)].array));
						UTBException::ThrowIfNoParserMemory((yyval.variableNode));
						
						(yyval.variableNode)->mInitStatement=new CDimStatement(de);
						UTBException::ThrowIfNoParserMemory((yyval.variableNode)->mInitStatement);
					}
				}
			}
			else
				(yyval.variableNode)=0;
		}
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 657 "basic.y"
    { (yyval.variableNode)=ConsData((yyvsp[(1) - (3)].variableNode),(yyvsp[(3) - (3)].variableNode)); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 663 "basic.y"
    { (yyval.variableNode)=(yyvsp[(2) - (2)].variableNode); CProgram::GetParsingProgram()->SetDeclarationMode(CVariableSymbol::kUndefined); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 665 "basic.y"
    {
			(yyval.variableNode)=0L;
			LogException_(UTBException::ThrowWithRange((yylsp[(1) - (2)]),kTBErr_ExpectedATypeName));			
		}
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 670 "basic.y"
    {
			(yyval.variableNode)=0L;
			CProgram::GetParsingProgram()->SetDeclarationMode(CVariableSymbol::kUndefined);
			LogException_(UTBException::ThrowWithRange((yylsp[(2) - (2)]),kTBErr_NotAVariable));
			FlushList();
			yyclearin;
		}
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 681 "basic.y"
    { (yyval.variableNode)=new CVariableNode((yyvsp[(2) - (2)].variable)); UTBException::ThrowIfNoParserMemory((yyval.variableNode)); CProgram::GetParsingProgram()->SetDeclarationMode(CVariableSymbol::kUndefined); }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 684 "basic.y"
    { (yyval.variableNode)=ConsData((yyvsp[(1) - (3)].variableNode),(yyvsp[(3) - (3)].variableNode)); }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 685 "basic.y"
    { (yyval.variableNode)=(yyvsp[(3) - (3)].variableNode); LogException_(UTBException::ThrowWithRange((yylsp[(1) - (3)]),-10)); }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 686 "basic.y"
    { (yyval.variableNode)=(yyvsp[(1) - (3)].variableNode); LogException_(UTBException::ThrowWithRange((yylsp[(1) - (3)]),-11)); FlushList(); yyclearin; }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 690 "basic.y"
    { (yyval.variableNode)=(yyvsp[(2) - (2)].variableNode); CProgram::GetParsingProgram()->SetDeclarationMode(CVariableSymbol::kUndefined); }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 691 "basic.y"
    { (yyval.variableNode)=0L; LogException_(UTBException::ThrowWithRange((yylsp[(1) - (2)]),kTBErr_ExpectedATypeName)); }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 693 "basic.y"
    {
			CProgram::GetParsingProgram()->SetDeclarationMode(CVariableSymbol::kUndefined);
			LogException_(UTBException::ThrowWithRange((yylsp[(2) - (2)]),kTBErr_NotAVariable));
			FlushList();
			yyclearin;
			(yyval.variableNode)=0;
		}
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 708 "basic.y"
    {
			if ((yyvsp[(1) - (2)].variable)->GetType()!=CVariableSymbol::kUndeclaredPrimitive)	// if it's undefined then the error will have already been reported
				LogException_(UTBException::ThrowProcNotDefined((yylsp[(1) - (2)]),(yyvsp[(1) - (2)].variable)->GetString()));
				
			(yyval.string)=0;
		}
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 714 "basic.y"
    { (yyval.string)=(yyvsp[(1) - (2)].string); }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 715 "basic.y"
    { (yyval.string)=0; LogException_(UTBException::ThrowWithRange((yylsp[(1) - (2)]),kTBErr_MangledProcedureCall)); }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 719 "basic.y"
    {
			delete (yyvsp[(1) - (4)].string);
			(yyval.statement)=0L;
			
			LogException_(UTBException::ThrowWithRange((yylsp[(2) - (4)]),kTBErr_IllegalExp));									
		}
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 726 "basic.y"
    {
			StStrDeleter	delboy((yyvsp[(1) - (4)].string));
			if (!CGeneralExpressionErr::ContainsErrors((yyvsp[(2) - (4)].genExp)))
			{
				(yyval.statement)=new CCallProc(CProgram::GetParsingProgram(),(yyvsp[(1) - (4)].string),(yyvsp[(2) - (4)].genExp),(yylsp[(3) - (4)]));
				UTBException::ThrowIfNoParserMemory((yyval.statement));
			}
			else
			{
				delete (yyvsp[(2) - (4)].genExp);
				(yyval.statement)=0;
			}
		}
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 741 "basic.y"
    { (yyval.variableNode)=0L; }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 747 "basic.y"
    {
			StStrDeleter		delboy((yyvsp[(2) - (3)].string));
		
			if (CProgram::GetParsingProgram()->IsParserInProcedure())
			{
				LogException_(UTBException::ThrowWithRange((yylsp[(2) - (3)]),kTBErr_CantPutProcsInProcs));
				(yyval.procedureDef)=0L;
			}
			else
			{
				(yyval.procedureDef)=new CProcedure((yyvsp[(2) - (3)].string));
				UTBException::ThrowIfNoParserMemory((yyval.procedureDef));
				
				CProgram::GetParsingProgram()->PushParsingScope(&(yyval.procedureDef)->mIdentifierScope);
				CProgram::GetParsingProgram()->SetParserInProcedure((yyval.procedureDef));
			}
		}
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 765 "basic.y"
    {
			StStrDeleter		delboy((yyvsp[(2) - (3)].string));
			LogException_(UTBException::ThrowWithRange((yylsp[(3) - (3)]),kTBErr_ExpectedOpenBracket));
			(yyval.procedureDef)=0;		
		}
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 771 "basic.y"
    {
			LogException_(UTBException::ThrowWithRange((yylsp[(2) - (3)]),kTBErr_IllegalProcedureName));
			(yyval.procedureDef)=0;
		}
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 776 "basic.y"
    {
			LogException_(UTBException::ThrowWithRange((yylsp[(2) - (2)]),kTBErr_IllegalProcedureName));
			(yyval.procedureDef)=0;
		}
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 783 "basic.y"
    {
			if ((yyvsp[(1) - (6)].procedureDef))
			{
				CProgram::GetParsingProgram()->PopParsingScope();
				CProgram::GetParsingProgram()->SetParserInProcedure(0L);
				delete (yyvsp[(1) - (6)].procedureDef);
			}
			delete (yyvsp[(4) - (6)].statement);
			delete (yyvsp[(5) - (6)].statement);			
			LogException_(UTBException::ThrowWithRange((yylsp[(2) - (6)]),kTBErr_SyntaxError));
			(yyval.statement)=0L;
		}
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 796 "basic.y"
    {
			if ((yyvsp[(1) - (2)].procedureDef))
			{
				CProgram::GetParsingProgram()->PopParsingScope();
				CProgram::GetParsingProgram()->SetParserInProcedure(0L);
				delete (yyvsp[(1) - (2)].procedureDef);
			}
			LogException_(UTBException::ThrowWithRange((yylsp[(2) - (2)]),kTBErr_SyntaxError));
			(yyval.statement)=0L;		
		}
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 807 "basic.y"
    {
			if ((yyvsp[(1) - (6)].procedureDef))
			{
				LogException_((yyvsp[(1) - (6)].procedureDef)->SetParameters((yylsp[(2) - (6)]),(yyvsp[(2) - (6)].variableNode)));
				CProgram::GetParsingProgram()->AddProcDef((yyvsp[(1) - (6)].procedureDef));
				(yyvsp[(1) - (6)].procedureDef)->SetCode(ConsData((yyvsp[(4) - (6)].statement),(yyvsp[(5) - (6)].statement)));
				(yyval.statement)=0;
				CProgram::GetParsingProgram()->PopParsingScope();
				CProgram::GetParsingProgram()->SetParserInProcedure(0L);
			}
			else
			{
				delete (yyvsp[(2) - (6)].variableNode);
				delete (yyvsp[(4) - (6)].statement);
				delete (yyvsp[(5) - (6)].statement);
				(yyval.statement)=0;
			}
		}
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 828 "basic.y"
    {
			(yyval.statement)=new CEndProcStatement(0,0);
			UTBException::ThrowIfNoParserMemory((yyval.statement));
		}
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 833 "basic.y"
    {
			if (!(yyvsp[(3) - (4)].genExp) || (yyvsp[(3) - (4)].genExp)->IsNullExp() || CGeneralExpressionErr::ContainsErrors((yyvsp[(3) - (4)].genExp)))
				(yyval.statement)=new CEndProcStatement(0,0);
			else
			{
				if ((yyvsp[(3) - (4)].genExp)->GetArithExp())
					(yyval.statement)=new CEndProcStatement((yyvsp[(3) - (4)].genExp)->ReleaseArithExp(),0);
				else
					(yyval.statement)=new CEndProcStatement(0,(yyvsp[(3) - (4)].genExp)->ReleaseStrExp());
			}
			delete (yyvsp[(3) - (4)].genExp);
			UTBException::ThrowIfNoParserMemory((yyval.statement));
		}
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 847 "basic.y"
    {
			LogException_(UTBException::ThrowWithRange((yylsp[(3) - (4)]),kTBErr_IllegalExp));

			(yyval.statement)=new CEndProcStatement(0,0);
			UTBException::ThrowIfNoParserMemory((yyval.statement));
		}
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 862 "basic.y"
    {
			if (CGeneralExpressionErr::ContainsErrors((yyvsp[(2) - (3)].genExp)))
			{
				(yyval.statement)=0;
				delete (yyvsp[(2) - (3)].genExp);
			}
			else		
				(yyval.statement)=UFunctionMgr::MakeStatement((yyvsp[(1) - (3)].tokenId),(yyvsp[(2) - (3)].genExp),(yylsp[(3) - (3)]));
		}
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 872 "basic.y"
    {
			(yyval.statement)=0L;
			
			LogException_(UTBException::ThrowWithRange((yylsp[(2) - (3)]),kTBErr_IllegalExp));			
		}
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 880 "basic.y"
    {
			STextRange	range((yylsp[(1) - (1)]));
			range.startOffset=range.endOffset;
			range.endOffset++;
			(yyval.arithExp)=UFunctionMgr::MakeArithFunction((yyvsp[(1) - (1)].tokenId),0L,range,range,(yylsp[(1) - (1)]),false);
		}
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 887 "basic.y"
    {
			(yyval.arithExp)=0L; FlushExp(); yyclearin;
			
			LogException_(UTBException::ThrowWithRange((yylsp[(2) - (2)]),kTBErr_ExpectedOpenBracket));
		}
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 893 "basic.y"
    {
			if (CGeneralExpressionErr::ContainsErrors((yyvsp[(3) - (4)].genExp)))
			{
				(yyval.arithExp)=0;
				delete (yyvsp[(3) - (4)].genExp);
			}
			else
			{		
				(yyval.arithExp)=UFunctionMgr::MakeArithFunction((yyvsp[(1) - (4)].tokenId),(yyvsp[(3) - (4)].genExp),(yylsp[(2) - (4)]),(yylsp[(4) - (4)]),STextRange((yylsp[(1) - (4)]),(yylsp[(4) - (4)])),true);
			}
		}
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 905 "basic.y"
    {
			(yyval.arithExp)=0L;
			
			LogException_(UTBException::ThrowWithRange((yylsp[(3) - (4)]),kTBErr_IllegalExp));			
		}
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 913 "basic.y"
    {
			STextRange	range((yylsp[(1) - (1)]));
			range.startOffset=range.endOffset;
			range.endOffset++;
			(yyval.strExp)=UFunctionMgr::MakeStrFunction((yyvsp[(1) - (1)].tokenId),0L,range,range,(yylsp[(1) - (1)]),false);
		}
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 920 "basic.y"
    {
			(yyval.strExp)=0L; FlushExp(); yyclearin;
			
			LogException_(UTBException::ThrowWithRange((yylsp[(2) - (2)]),kTBErr_ExpectedOpenBracket));
		}
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 932 "basic.y"
    {
			if (CGeneralExpressionErr::ContainsErrors((yyvsp[(3) - (4)].genExp)))
			{
				(yyval.strExp)=0;
				delete (yyvsp[(3) - (4)].genExp);
			}
			else
			{		
				(yyval.strExp)=UFunctionMgr::MakeStrFunction((yyvsp[(1) - (4)].tokenId),(yyvsp[(3) - (4)].genExp),(yylsp[(2) - (4)]),(yylsp[(4) - (4)]),STextRange((yylsp[(1) - (4)]),(yylsp[(4) - (4)])),true);
			}
		}
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 944 "basic.y"
    {
			(yyval.strExp)=0L;
			
			LogException_(UTBException::ThrowWithRange((yylsp[(3) - (4)]),kTBErr_IllegalExp));
		}
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 962 "basic.y"
    { (yyval.arithExp)=(yyvsp[(2) - (3)].arithExp); }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 963 "basic.y"
    { StStrDeleter delboy((yyvsp[(1) - (1)].string)); TBArithFunction_(CInteger((yylsp[(1) - (1)]),(yyvsp[(1) - (1)].string))); }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 964 "basic.y"
    { StStrDeleter delboy((yyvsp[(1) - (1)].string)); TBArithFunction_(CFloat((yylsp[(1) - (1)]),(yyvsp[(1) - (1)].string))); }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 965 "basic.y"
    { (yyval.arithExp)=(yyvsp[(1) - (1)].arithExp); }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 966 "basic.y"
    { TBArithFunction_(CArithProcResult((yylsp[(1) - (1)]),false)); }
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 967 "basic.y"
    { TBArithFunction_(CArithProcResult((yylsp[(1) - (1)]),true)); }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 968 "basic.y"
    { TBMaybeArithExp1_((yyvsp[(1) - (1)].intStorage),CIntegerIdentifier((yylsp[(1) - (1)]),(yyvsp[(1) - (1)].intStorage))); }
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 969 "basic.y"
    { TBMaybeArithExp1_((yyvsp[(1) - (1)].floatStorage),CFloatIdentifier((yylsp[(1) - (1)]),(yyvsp[(1) - (1)].floatStorage))); }
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 970 "basic.y"
    { TBMaybeArithExp1_((yyvsp[(2) - (2)].arithExp),CUnaryMinusOp(STextRange((yylsp[(1) - (2)]),(yylsp[(2) - (2)])),(yyvsp[(2) - (2)].arithExp))); }
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 971 "basic.y"
    { TBMaybeArithExp1_((yyvsp[(2) - (2)].arithExp),CNotOp(STextRange((yylsp[(1) - (2)]),(yylsp[(2) - (2)])),(yyvsp[(2) - (2)].arithExp)));}
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 972 "basic.y"
    { TBMaybeArithExp2_((yyvsp[(1) - (3)].arithExp),(yyvsp[(3) - (3)].arithExp),CBinaryArithOp((yyvsp[(1) - (3)].arithExp),(yyvsp[(3) - (3)].arithExp),PLUS)); }
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 973 "basic.y"
    { TBMaybeArithExp2_((yyvsp[(1) - (3)].arithExp),(yyvsp[(3) - (3)].arithExp),CBinaryArithOp((yyvsp[(1) - (3)].arithExp),(yyvsp[(3) - (3)].arithExp),MINUS)); }
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 974 "basic.y"
    { TBMaybeArithExp2_((yyvsp[(1) - (3)].arithExp),(yyvsp[(3) - (3)].arithExp),CBinaryArithOp((yyvsp[(1) - (3)].arithExp),(yyvsp[(3) - (3)].arithExp),TIMES)); }
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 975 "basic.y"
    { TBMaybeArithExp2_((yyvsp[(1) - (3)].arithExp),(yyvsp[(3) - (3)].arithExp),CBinaryArithOp((yyvsp[(1) - (3)].arithExp),(yyvsp[(3) - (3)].arithExp),DIVIDE)); }
    break;

  case 93:
/* Line 1787 of yacc.c  */
#line 976 "basic.y"
    { TBMaybeArithExp2_((yyvsp[(1) - (3)].arithExp),(yyvsp[(3) - (3)].arithExp),CBinaryArithOp((yyvsp[(1) - (3)].arithExp),(yyvsp[(3) - (3)].arithExp),POWER)); }
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 977 "basic.y"
    { TBMaybeArithExp2_((yyvsp[(1) - (3)].arithExp),(yyvsp[(3) - (3)].arithExp),CBinaryLogicOp((yyvsp[(1) - (3)].arithExp),(yyvsp[(3) - (3)].arithExp),AND)); }
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 978 "basic.y"
    { TBMaybeArithExp2_((yyvsp[(1) - (3)].arithExp),(yyvsp[(3) - (3)].arithExp),CBinaryLogicOp((yyvsp[(1) - (3)].arithExp),(yyvsp[(3) - (3)].arithExp),OR)); }
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 988 "basic.y"
    { TBMaybeArithExp2_((yyvsp[(1) - (3)].arithExp),(yyvsp[(3) - (3)].arithExp),CBinaryLogicOp((yyvsp[(1) - (3)].arithExp),(yyvsp[(3) - (3)].arithExp),EQUALS)); }
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 989 "basic.y"
    { TBMaybeArithExp2_((yyvsp[(1) - (3)].arithExp),(yyvsp[(3) - (3)].arithExp),CBinaryLogicOp((yyvsp[(1) - (3)].arithExp),(yyvsp[(3) - (3)].arithExp),NEQ)); }
    break;

  case 99:
/* Line 1787 of yacc.c  */
#line 990 "basic.y"
    { TBMaybeArithExp2_((yyvsp[(1) - (3)].arithExp),(yyvsp[(3) - (3)].arithExp),CBinaryLogicOp((yyvsp[(1) - (3)].arithExp),(yyvsp[(3) - (3)].arithExp),LT)); }
    break;

  case 100:
/* Line 1787 of yacc.c  */
#line 991 "basic.y"
    { TBMaybeArithExp2_((yyvsp[(1) - (3)].arithExp),(yyvsp[(3) - (3)].arithExp),CBinaryLogicOp((yyvsp[(1) - (3)].arithExp),(yyvsp[(3) - (3)].arithExp),LTE)); }
    break;

  case 101:
/* Line 1787 of yacc.c  */
#line 992 "basic.y"
    { TBMaybeArithExp2_((yyvsp[(1) - (3)].arithExp),(yyvsp[(3) - (3)].arithExp),CBinaryLogicOp((yyvsp[(1) - (3)].arithExp),(yyvsp[(3) - (3)].arithExp),GT)); }
    break;

  case 102:
/* Line 1787 of yacc.c  */
#line 993 "basic.y"
    { TBMaybeArithExp2_((yyvsp[(1) - (3)].arithExp),(yyvsp[(3) - (3)].arithExp),CBinaryLogicOp((yyvsp[(1) - (3)].arithExp),(yyvsp[(3) - (3)].arithExp),GTE)); }
    break;

  case 103:
/* Line 1787 of yacc.c  */
#line 994 "basic.y"
    { TBMaybeArithExp2_((yyvsp[(1) - (3)].strExp),(yyvsp[(3) - (3)].strExp),CBinaryLogicOp((yyvsp[(1) - (3)].strExp),(yyvsp[(3) - (3)].strExp),EQUALS)); }
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 995 "basic.y"
    { TBMaybeArithExp2_((yyvsp[(1) - (3)].strExp),(yyvsp[(3) - (3)].strExp),CBinaryLogicOp((yyvsp[(1) - (3)].strExp),(yyvsp[(3) - (3)].strExp),NEQ)); }
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 996 "basic.y"
    { TBMaybeArithExp2_((yyvsp[(1) - (3)].strExp),(yyvsp[(3) - (3)].strExp),CBinaryLogicOp((yyvsp[(1) - (3)].strExp),(yyvsp[(3) - (3)].strExp),LT)); }
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 997 "basic.y"
    { TBMaybeArithExp2_((yyvsp[(1) - (3)].strExp),(yyvsp[(3) - (3)].strExp),CBinaryLogicOp((yyvsp[(1) - (3)].strExp),(yyvsp[(3) - (3)].strExp),LTE)); }
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 998 "basic.y"
    { TBMaybeArithExp2_((yyvsp[(1) - (3)].strExp),(yyvsp[(3) - (3)].strExp),CBinaryLogicOp((yyvsp[(1) - (3)].strExp),(yyvsp[(3) - (3)].strExp),GT)); }
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 999 "basic.y"
    { TBMaybeArithExp2_((yyvsp[(1) - (3)].strExp),(yyvsp[(3) - (3)].strExp),CBinaryLogicOp((yyvsp[(1) - (3)].strExp),(yyvsp[(3) - (3)].strExp),GTE)); }
    break;

  case 109:
/* Line 1787 of yacc.c  */
#line 1000 "basic.y"
    { TBArithFunction_(CInteger((yylsp[(1) - (1)]),"1")); }
    break;

  case 110:
/* Line 1787 of yacc.c  */
#line 1001 "basic.y"
    { TBArithFunction_(CInteger((yylsp[(1) - (1)]),"0")); }
    break;

  case 111:
/* Line 1787 of yacc.c  */
#line 1010 "basic.y"
    { TBStrFunction_(CStrProcResult((yylsp[(1) - (1)]))); }
    break;

  case 112:
/* Line 1787 of yacc.c  */
#line 1011 "basic.y"
    { (yyval.strExp)=(yyvsp[(2) - (3)].strExp); }
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 1012 "basic.y"
    { TBMaybeStrExp1_((yyvsp[(1) - (1)].strStorage),CStrIdentifier((yylsp[(1) - (1)]),(yyvsp[(1) - (1)].strStorage))); }
    break;

  case 114:
/* Line 1787 of yacc.c  */
#line 1013 "basic.y"
    { TBMaybeStrExp2_((yyvsp[(1) - (3)].strExp),(yyvsp[(3) - (3)].strExp),CStrConcatOp((yyvsp[(1) - (3)].strExp),(yyvsp[(3) - (3)].strExp))); }
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 1014 "basic.y"
    { StStrDeleter delboy((yyvsp[(1) - (1)].string)); TBStrFunction_(CStrLiteral((yylsp[(1) - (1)]),(yyvsp[(1) - (1)].string))); }
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 1015 "basic.y"
    { (yyval.strExp)=(yyvsp[(1) - (1)].strExp); }
    break;

  case 117:
/* Line 1787 of yacc.c  */
#line 1025 "basic.y"
    { TBGeneralExp_(CGeneralExpression()); }
    break;

  case 118:
/* Line 1787 of yacc.c  */
#line 1026 "basic.y"
    { TBGenExpOrError_((yyvsp[(1) - (1)].arithExp),CGeneralExpression((yyvsp[(1) - (1)].arithExp))); }
    break;

  case 119:
/* Line 1787 of yacc.c  */
#line 1027 "basic.y"
    { TBGenExpOrError_((yyvsp[(1) - (1)].strExp),CGeneralExpression((yyvsp[(1) - (1)].strExp))); }
    break;

  case 120:
/* Line 1787 of yacc.c  */
#line 1028 "basic.y"
    { TBGeneralExp_(CGeneralExpressionErr()); }
    break;

  case 121:
/* Line 1787 of yacc.c  */
#line 1031 "basic.y"
    { (yyval.genExp)=(yyvsp[(1) - (1)].genExp); }
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 1032 "basic.y"
    { (yyval.genExp)=(yyvsp[(1) - (3)].genExp); if ((yyvsp[(1) - (3)].genExp)) (yyvsp[(1) - (3)].genExp)->AppendExpression(CGeneralExpression::kComma,(yylsp[(2) - (3)]),(yyvsp[(3) - (3)].genExp)); else (yyval.genExp)=(yyvsp[(3) - (3)].genExp); }
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 1033 "basic.y"
    { (yyval.genExp)=(yyvsp[(1) - (3)].genExp); if ((yyvsp[(1) - (3)].genExp)) (yyvsp[(1) - (3)].genExp)->AppendExpression(CGeneralExpression::kTo,(yylsp[(2) - (3)]),(yyvsp[(3) - (3)].genExp)); else (yyval.genExp)=(yyvsp[(3) - (3)].genExp); }
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 1034 "basic.y"
    { (yyval.genExp)=(yyvsp[(1) - (3)].genExp); if ((yyvsp[(1) - (3)].genExp)) (yyvsp[(1) - (3)].genExp)->AppendExpression(CGeneralExpression::kSemiColon,(yylsp[(2) - (3)]),(yyvsp[(3) - (3)].genExp)); else (yyval.genExp)=(yyvsp[(3) - (3)].genExp); }
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 1035 "basic.y"
    { TBGeneralExp_(CGeneralExpressionErr()); LogException_(UTBException::ThrowWithRange((yylsp[(1) - (3)]),kTBErr_IllegalExp)); }
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 1036 "basic.y"
    { TBGeneralExp_(CGeneralExpressionErr()); LogException_(UTBException::ThrowWithRange((yylsp[(1) - (3)]),kTBErr_IllegalExp)); }
    break;

  case 127:
/* Line 1787 of yacc.c  */
#line 1037 "basic.y"
    { TBGeneralExp_(CGeneralExpressionErr()); LogException_(UTBException::ThrowWithRange((yylsp[(1) - (3)]),kTBErr_IllegalExp)); }
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 1038 "basic.y"
    { TBGeneralExp_(CGeneralExpressionErr()); LogException_(UTBException::ThrowWithRange((yylsp[(3) - (3)]),kTBErr_IllegalExp)); FlushExp(); yyclearin;}
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 1039 "basic.y"
    { TBGeneralExp_(CGeneralExpressionErr()); LogException_(UTBException::ThrowWithRange((yylsp[(3) - (3)]),kTBErr_IllegalExp)); FlushExp(); yyclearin;}
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 1040 "basic.y"
    { TBGeneralExp_(CGeneralExpressionErr()); LogException_(UTBException::ThrowWithRange((yylsp[(3) - (3)]),kTBErr_IllegalExp)); FlushExp(); yyclearin;}
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 1048 "basic.y"
    { (yyval.statement)=0L; }
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 1049 "basic.y"
    { (yyval.statement)=ConsData((yyvsp[(1) - (2)].statement),(yyvsp[(2) - (2)].statement)); }
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 1050 "basic.y"
    { LogException_(UTBException::ThrowWithRange((yylsp[(2) - (3)]),kTBErr_SyntaxError));}
    break;

  case 153:
/* Line 1787 of yacc.c  */
#line 1057 "basic.y"
    { (yyval.statement)=0L; }
    break;

  case 154:
/* Line 1787 of yacc.c  */
#line 1067 "basic.y"
    {
			if ((yyvsp[(1) - (2)].variableNode))	// var list can be nil if there were errors in parsing it
			{
				(yyval.statement)=ExtractInitStatements((yyvsp[(1) - (2)].variableNode));
				delete (yyvsp[(1) - (2)].variableNode);
			}
			else
				(yyval.statement)=0L;
		}
    break;

  case 155:
/* Line 1787 of yacc.c  */
#line 1077 "basic.y"
    { /*CProgram::GetParsingProgram()->SetReportVarNotDecl(false);*/ }
    break;

  case 156:
/* Line 1787 of yacc.c  */
#line 1080 "basic.y"
    {
			if ((yyvsp[(2) - (3)].variableNode))
			{
				(yyval.statement)=ExtractInitStatements((yyvsp[(2) - (3)].variableNode));
				CProgram::GetParsingProgram()->AddGlobals((yyvsp[(2) - (3)].variableNode),(yylsp[(1) - (3)]),false,false); /* store all globals in a list in the program */
			}
			else
				(yyval.statement)=0L;
		}
    break;

  case 157:
/* Line 1787 of yacc.c  */
#line 1090 "basic.y"
    { /*CProgram::GetParsingProgram()->SetReportVarNotDecl(false);*/ }
    break;

  case 158:
/* Line 1787 of yacc.c  */
#line 1093 "basic.y"
    {
			if ((yyvsp[(2) - (3)].variableNode))
			{
				(yyval.statement)=ExtractInitStatements((yyvsp[(2) - (3)].variableNode));
				CProgram::GetParsingProgram()->AddGlobals((yyvsp[(2) - (3)].variableNode),(yylsp[(1) - (3)]),true,false); /* store all globals in a list in the program */
			}
			else
				(yyval.statement)=0L;
		}
    break;

  case 159:
/* Line 1787 of yacc.c  */
#line 1103 "basic.y"
    { /*CProgram::GetParsingProgram()->SetReportVarNotDecl(false);*/ }
    break;

  case 160:
/* Line 1787 of yacc.c  */
#line 1106 "basic.y"
    {
			if ((yyvsp[(2) - (3)].variableNode))
			{
				(yyval.statement)=ExtractInitStatements((yyvsp[(2) - (3)].variableNode));
				CProgram::GetParsingProgram()->AddGlobals((yyvsp[(2) - (3)].variableNode),(yylsp[(1) - (3)]),true,true); /* store all globals in a list in the program */
			}
			else
				(yyval.statement)=0L;
		}
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 1120 "basic.y"
    {
			// Must be in a procedure to use shared (error will get logged in sharedStatement)
			if (CProgram::GetParsingProgram()->IsParserInProcedure())
				CProgram::GetParsingProgram()->PauseParsingScope();
/*			CProgram::GetParsingProgram()->SetReportVarNotDecl(false); */
		}
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 1128 "basic.y"
    {
			if (CProgram::GetParsingProgram()->IsParserInProcedure())
				CProgram::GetParsingProgram()->ResumeParsingScope(&CProgram::GetParsingProgram()->GetCurrentlyParsingProc()->mIdentifierScope);

			LogException_(UTBException::ThrowWithRange((yylsp[(2) - (3)]),kTBErr_SyntaxError));
			(yyval.statement)=0L;
		}
    break;

  case 163:
/* Line 1787 of yacc.c  */
#line 1136 "basic.y"
    {
			(yyval.statement)=0L;

			// Must be in a procedure and must also not have declared any variables which are not global.
			if (!CProgram::GetParsingProgram()->IsParserInProcedure())
				LogException_(UTBException::ThrowWithRange((yylsp[(1) - (3)]),kTBErr_SharedMustBeUsedInAProcedure));
			else
			{		
				// Push the scope back and enter all variables as guests
				CIdentifierScope		*scope=&CProgram::GetParsingProgram()->GetCurrentlyParsingProc()->mIdentifierScope;
				
				CProgram::GetParsingProgram()->ResumeParsingScope(scope);

				for (CVariableNode *node=(yyvsp[(2) - (3)].variableNode); node; node=node->TailData())
				{
					// Check if a parameter has the same name, if so we can't share it
					CVariableSymbol		*symbol;
					
					symbol=scope->VarTable()->Exists(node->mSymbol->GetString());
					
					// If the symbol already exists and it's not a guest (ie a global) then it must be a parameter
					// or a previously declared variable. Neither can be shared.
					if (symbol && !scope->VarTable()->IsGuest(symbol))
					{
						if (CProgram::GetParsingProgram()->GetCurrentlyParsingProc()->IsParameter(symbol))
							LogException_(UTBException::ThrowWithRange((yylsp[(2) - (3)]),kTBErr_CantShareParam));
						else						
							LogException_(UTBException::ThrowWithRange((yylsp[(2) - (3)]),kTBErr_AttemptToShareDeclaredVar));

						continue;	// skip this one
					}
					
					scope->VarTable()->EnterGuest(node->mSymbol);
				}
			}
						
			delete (yyvsp[(2) - (3)].variableNode);			
		}
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 1178 "basic.y"
    {  TBStatement_(CCanvasFXStatement(static_cast<CIntegerArraySymbol*>((yyvsp[(2) - (8)].array)),(yyvsp[(5) - (8)].arithExp),(yyvsp[(7) - (8)].arithExp))); }
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 1180 "basic.y"
    { (yyval.statement)=0L; LogException_(UTBException::ThrowWithRange((yylsp[(2) - (3)]),kTBErr_IllegalExp)); }
    break;

  case 169:
/* Line 1787 of yacc.c  */
#line 1183 "basic.y"
    { TBStatement_(CSetNetDataStatement((yyvsp[(2) - (5)].variable),(yyvsp[(4) - (5)].arithExp))); }
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 1185 "basic.y"
    { TBStatement_(CSetNetDataStatement((yyvsp[(2) - (5)].variable),(yyvsp[(4) - (5)].arithExp))); }
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 1187 "basic.y"
    { TBStatement_(CSetNetDataStatement((yyvsp[(2) - (5)].variable),(yyvsp[(4) - (5)].strExp))); }
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 1189 "basic.y"
    {
								if (CheckArrayIndexList(*CProgram::GetParsingProgram(),(yyvsp[(3) - (7)].genExp),(yylsp[(4) - (7)])))
								{
									TBStatement_(CSetNetDataStatement((yyvsp[(2) - (7)].array),(yyvsp[(6) - (7)].arithExp),(yyvsp[(3) - (7)].genExp)));
								}
							}
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 1196 "basic.y"
    {
								if (CheckArrayIndexList(*CProgram::GetParsingProgram(),(yyvsp[(3) - (7)].genExp),(yylsp[(4) - (7)])))
								{
									TBStatement_(CSetNetDataStatement((yyvsp[(2) - (7)].array),(yyvsp[(6) - (7)].arithExp),(yyvsp[(3) - (7)].genExp)));
								}
							}
    break;

  case 174:
/* Line 1787 of yacc.c  */
#line 1203 "basic.y"
    {
								if (CheckArrayIndexList(*CProgram::GetParsingProgram(),(yyvsp[(3) - (7)].genExp),(yylsp[(4) - (7)])))
								{
									TBStatement_(CSetNetDataStatement((yyvsp[(2) - (7)].array),(yyvsp[(6) - (7)].strExp),(yyvsp[(3) - (7)].genExp)));
								}
							}
    break;

  case 175:
/* Line 1787 of yacc.c  */
#line 1210 "basic.y"
    { (yyval.statement)=NULL; LogException_(UTBException::ThrowWithRange((yylsp[(2) - (3)]),kTBErr_IllegalExp)); }
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 1219 "basic.y"
    {
		// if they use an undeclared variable it will be logged by the lexer, now we must sensibly parse the remaining expression
		if ((yyvsp[(1) - (3)].array)->GetType()==CVariableSymbol::kUndeclaredArray)
		{
			delete (yyvsp[(2) - (3)].genExp);
			(yyval.arrayEntry)=0;
		}
		else if (CheckArrayIndexList(*CProgram::GetParsingProgram(),(yyvsp[(2) - (3)].genExp),(yylsp[(3) - (3)])))
		{
			(yyval.arrayEntry)=new CArrayDimEntry((yyvsp[(1) - (3)].array),(yyvsp[(2) - (3)].genExp));
			UTBException::ThrowIfNoParserMemory((yyval.arrayEntry));
		}
		else
			(yyval.arrayEntry)=0L;
	}
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 1235 "basic.y"
    {
		(yyval.arrayEntry)=0L;
		LogException_(UTBException::ThrowWithRange((yylsp[(2) - (3)]),kTBErr_IllegalExp));		
	}
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 1242 "basic.y"
    { (yyval.arrayEntry)=ConsData((yyvsp[(1) - (3)].arrayEntry),(yyvsp[(3) - (3)].arrayEntry)); }
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 1244 "basic.y"
    { CProgram::GetParsingProgram()->SetInDimStatement(true); }
    break;

  case 181:
/* Line 1787 of yacc.c  */
#line 1247 "basic.y"
    {
		if (!(yyvsp[(2) - (3)].arrayEntry))
			(yyval.statement)=0L;
		else
		{
			(yyval.statement)=new CDimStatement((yyvsp[(2) - (3)].arrayEntry));
			UTBException::ThrowIfNoParserMemory((yyval.statement));
		}
		CProgram::GetParsingProgram()->SetInDimStatement(false);
	}
    break;

  case 182:
/* Line 1787 of yacc.c  */
#line 1258 "basic.y"
    {
		(yyval.statement)=0L;
		LogException_(UTBException::ThrowWithRange((yylsp[(2) - (3)]),kTBErr_IllegalExp));
	}
    break;

  case 183:
/* Line 1787 of yacc.c  */
#line 1265 "basic.y"
    {
			(yyval.statement)=0L;
			if (CGeneralExpressionErr::ContainsErrors((yyvsp[(2) - (3)].genExp)))
				delete (yyvsp[(2) - (3)].genExp);
			else if ((yyvsp[(2) - (3)].genExp))
			{
				CLabelTable::GetCurrentLabelTable()->DataStatementCreated((yyvsp[(2) - (3)].genExp));
				CProgram::GetParsingProgram()->GetDataStatementScope()->AddDataStatement((yyvsp[(2) - (3)].genExp));
			}
		}
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 1276 "basic.y"
    {
			(yyval.statement)=0L;
			LogException_(UTBException::ThrowWithRange((yylsp[(2) - (3)]),kTBErr_IllegalExp));
		}
    break;

  case 185:
/* Line 1787 of yacc.c  */
#line 1283 "basic.y"
    {
			CProgram::GetParsingProgram()->SetWantLabels(true);
		}
    break;

  case 186:
/* Line 1787 of yacc.c  */
#line 1288 "basic.y"
    {
			StStrDeleter		delboy((yyvsp[(2) - (3)].string));
			CProgram::GetParsingProgram()->SetWantLabels(false);
			(yyval.statement)=new CRestoreStatement((yyvsp[(2) - (3)].string),*CProgram::GetParsingProgram(),(yylsp[(2) - (3)]));
			UTBException::ThrowIfNoParserMemory((yyval.statement));
		}
    break;

  case 187:
/* Line 1787 of yacc.c  */
#line 1297 "basic.y"
    {
			CProgram::GetParsingProgram()->SetWantLabels(true);
		}
    break;

  case 188:
/* Line 1787 of yacc.c  */
#line 1302 "basic.y"
    {
			StStrDeleter		delboy((yyvsp[(2) - (3)].string));
			CProgram::GetParsingProgram()->SetWantLabels(false);
			(yyval.statement)=new CGotoStatement((yyvsp[(2) - (3)].string),*CProgram::GetParsingProgram(),(yylsp[(2) - (3)]));
			UTBException::ThrowIfNoParserMemory((yyval.statement));
		}
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 1333 "basic.y"
    {
			CArithExpression	*exp=CheckSingleNumExp((yyvsp[(2) - (3)].genExp),(yylsp[(2) - (3)]));
						
			if (exp)
				TBStatement_(CConditionalBlock(false,exp));
			else
				(yyval.conditionalBlock)=0L;
		}
    break;

  case 190:
/* Line 1787 of yacc.c  */
#line 1342 "basic.y"
    {
			LogException_(UTBException::ThrowWithRange((yylsp[(2) - (3)]),kTBErr_ExpectedNumExp));
			(yyval.conditionalBlock)=0;
		}
    break;

  case 191:
/* Line 1787 of yacc.c  */
#line 1348 "basic.y"
    {
			CArithExpression	*exp=CheckSingleNumExp((yyvsp[(2) - (3)].genExp),(yylsp[(2) - (3)]));
						
			if (exp)
			{
				// an statement gets its line num by taking 1 from the line count
				// this is because it expects the ENDLINE token to have been parsed, which
				// causes the line num to be increased. With an if then, the ENDLINE has not
				// been parsed by when the expression is contructed, therefore we need to
				// add one to the line number stored by the parsed expression so far.
				gLineno++;
				TBStatement_(CConditionalBlock(false,exp));
				gLineno--;
			}
			else
				(yyval.conditionalBlock)=0L;
		}
    break;

  case 192:
/* Line 1787 of yacc.c  */
#line 1366 "basic.y"
    {
			LogException_(UTBException::ThrowWithRange((yylsp[(2) - (3)]),kTBErr_ExpectedNumExp));
			(yyval.conditionalBlock)=0;	
		}
    break;

  case 193:
/* Line 1787 of yacc.c  */
#line 1372 "basic.y"
    {
			if ((yyvsp[(1) - (2)].conditionalBlock))
			{
				// we don't need endif breaks and a surrounding statement block for
				// a simple ifThenStatement
				(yyvsp[(1) - (2)].conditionalBlock)->SetSubStatements((yyvsp[(2) - (2)].statement));
				(yyval.statement)=(yyvsp[(1) - (2)].conditionalBlock);
			}
			else
			{
				delete (yyvsp[(2) - (2)].statement);
				(yyval.statement)=0;
			}
		}
    break;

  case 194:
/* Line 1787 of yacc.c  */
#line 1388 "basic.y"
    {
			if ((yyvsp[(1) - (6)].conditionalBlock))
			{
				CConditionalBlock	*&conditionalsList=(yyvsp[(1) - (6)].conditionalBlock);
				
				// set the sub statements of the conditional block
				conditionalsList->SetSubStatements((yyvsp[(2) - (6)].statement));
				
				// append the remainder of the ifstruct
				conditionalsList->Append((yyvsp[(3) - (6)].statement));
				
				// Now we have a list of conditional blocks, the if and each of the end ifs
				// Apply end if breaks to each so that if one executes it jumps out of the
				// if statement thus avoiding executing the other conditionals
				AppendEndIfBreaks(conditionalsList);

				if ((yyvsp[(3) - (6)].statement))
					(yyvsp[(3) - (6)].statement)->Append((yyvsp[(4) - (6)].statement));
				else
					conditionalsList->Append((yyvsp[(4) - (6)].statement));
				
				// Finally construct a statement block to enclose all the if statements
				// This groups together the conditionals and gives them somewhere to
				// jump out of when one of them finishes.
				(yyval.statement)=new CStatementBlock(false,conditionalsList);
				UTBException::ThrowIfNoParserMemory((yyval.statement));
			}
			else
			{
				(yyval.statement)=0L;
				delete (yyvsp[(1) - (6)].conditionalBlock);
				delete (yyvsp[(3) - (6)].statement);
				delete (yyvsp[(4) - (6)].statement);
			}
		}
    break;

  case 195:
/* Line 1787 of yacc.c  */
#line 1436 "basic.y"
    {
			CArithExpression	*exp=CheckSingleNumExp((yyvsp[(2) - (3)].genExp),(yylsp[(2) - (3)]));
			
			if (exp)
				TBStatement_(CConditionalBlock(false,exp));
			else
				(yyval.conditionalBlock)=0;
		}
    break;

  case 196:
/* Line 1787 of yacc.c  */
#line 1445 "basic.y"
    {
			LogException_(UTBException::ThrowWithRange((yylsp[(2) - (3)]),kTBErr_ExpectedNumExp));
			(yyval.conditionalBlock)=0L;
		}
    break;

  case 197:
/* Line 1787 of yacc.c  */
#line 1450 "basic.y"
    { (yyval.statement)=0L; }
    break;

  case 198:
/* Line 1787 of yacc.c  */
#line 1452 "basic.y"
    {
			(yyval.statement)=(yyvsp[(1) - (3)].conditionalBlock);
			
			if ((yyvsp[(1) - (3)].conditionalBlock))
			{
				(yyvsp[(1) - (3)].conditionalBlock)->SetSubStatements((yyvsp[(2) - (3)].statement));
				(yyvsp[(1) - (3)].conditionalBlock)->Append((yyvsp[(3) - (3)].statement));
			}
			else
			{
				delete (yyvsp[(2) - (3)].statement);
				delete (yyvsp[(3) - (3)].statement);
			}
		}
    break;

  case 199:
/* Line 1787 of yacc.c  */
#line 1469 "basic.y"
    { (yyval.statement)=0L; }
    break;

  case 200:
/* Line 1787 of yacc.c  */
#line 1470 "basic.y"
    { TBStatement_(CStatementBlock(false,(yyvsp[(3) - (3)].statement))); }
    break;

  case 201:
/* Line 1787 of yacc.c  */
#line 1478 "basic.y"
    {
			CArithExpression	*exp=CheckSingleNumExp((yyvsp[(2) - (3)].genExp),(yylsp[(2) - (3)]));
			
			if (exp)
				TBStatement_(CConditionalBlock(true,exp));
			else
			{
				(yyval.conditionalBlock)=0;
			}
		}
    break;

  case 202:
/* Line 1787 of yacc.c  */
#line 1489 "basic.y"
    {
			LogException_(UTBException::ThrowWithRange((yylsp[(2) - (3)]),kTBErr_ExpectedNumExp));
			(yyval.conditionalBlock)=0;
		}
    break;

  case 203:
/* Line 1787 of yacc.c  */
#line 1495 "basic.y"
    {
			if ((yyvsp[(1) - (4)].conditionalBlock))
			{
				(yyval.statement)=(yyvsp[(1) - (4)].conditionalBlock);
				(yyvsp[(1) - (4)].conditionalBlock)->SetSubStatements((yyvsp[(2) - (4)].statement));
				
				// Append the goto condition instruction to the end of the statement
				// block.
				CStatement		*gotoS=new CJumpStatement((yyval.statement));
				UTBException::ThrowIfNoParserMemory(gotoS);
				
				(yyvsp[(1) - (4)].conditionalBlock)->AppendSubStatement(gotoS);
			}
			else
			{
				(yyval.statement)=0;
				delete (yyvsp[(2) - (4)].statement);
			}
		}
    break;

  case 204:
/* Line 1787 of yacc.c  */
#line 1528 "basic.y"
    {
			CArithExpression	*exp=CheckSingleNumExp((yyvsp[(5) - (6)].genExp),(yylsp[(5) - (6)]));
			
			if (exp)
			{
				CStatementBlock	*block;
				
				(yyval.statement)=block=new CStatementBlock(true,(yyvsp[(3) - (6)].statement));
				UTBException::ThrowIfNoParserMemory((yyval.statement));
				
				// Now add the conditional jump which gives the looping action
				CStatement		*condJump=new CConditionalJump(exp,block,false);
				UTBException::ThrowIfNoParserMemory(condJump);
				
				block->AppendSubStatement(condJump);
			}
			else
			{
				(yyval.statement)=0;
				delete (yyvsp[(3) - (6)].statement);
			}
		}
    break;

  case 205:
/* Line 1787 of yacc.c  */
#line 1551 "basic.y"
    {
			LogException_(UTBException::ThrowWithRange((yylsp[(5) - (6)]),kTBErr_ExpectedNumExp));
			delete (yyvsp[(3) - (6)].statement);
			(yyval.statement)=0;
		}
    break;

  case 206:
/* Line 1787 of yacc.c  */
#line 1563 "basic.y"
    {
			CStatementBlock	*block;
			
			(yyval.statement)=block=new CStatementBlock(true,(yyvsp[(3) - (5)].statement));
			UTBException::ThrowIfNoParserMemory((yyval.statement));
			
			// Now add the jump which gives the looping action
			CStatement		*jump=new CJumpStatement(block);
			UTBException::ThrowIfNoParserMemory(jump);
			
			block->AppendSubStatement(jump);												
		}
    break;

  case 207:
/* Line 1787 of yacc.c  */
#line 1582 "basic.y"
    {
			LogException_(UTBException::ThrowWithRange((yylsp[(4) - (6)]),kTBErr_IllegalExp));
			(yyval.forStatement)=0;
			delete (yyvsp[(2) - (6)].storage);
		}
    break;

  case 208:
/* Line 1787 of yacc.c  */
#line 1588 "basic.y"
    {
			LogException_(UTBException::ThrowBadForLoopIndex((yylsp[(2) - (6)])));
			delete (yyvsp[(4) - (6)].genExp);
			(yyval.forStatement)=0;
		}
    break;

  case 209:
/* Line 1787 of yacc.c  */
#line 1594 "basic.y"
    {
			Try_
			{
				if (!CGeneralExpressionErr::ContainsErrors((yyvsp[(4) - (6)].genExp)))
				{
					UFunctionMgr::SimpleTypeCheck("ata",(yyvsp[(4) - (6)].genExp),(yylsp[(5) - (6)]));
										
					// Check storage
					CIntegerStorage		*store=(yyvsp[(2) - (6)].storage) ? (yyvsp[(2) - (6)].storage)->mIntStore : 0;

					if (!store)
					{
						if ((yyvsp[(2) - (6)].storage)) // if store is defined then it's in error, otherwise it must have been boshed by an earlier parse error and shouldn't be reported again
							LogException_(UTBException::ThrowBadForLoopIndex((yylsp[(2) - (6)])));
						(yyval.forStatement)=0L;
					}
					else
					{
						CArithExpression *from=(yyvsp[(4) - (6)].genExp)->ReleaseArithExp();
						CArithExpression *to=(yyvsp[(4) - (6)].genExp)->TailData()->ReleaseArithExp();

						TBStatement_(CForStatement(store,from,to,(yyvsp[(5) - (6)].arithExp)));						
					}

					delete (yyvsp[(2) - (6)].storage);						
					delete (yyvsp[(4) - (6)].genExp);						
				}
				else
					(yyval.forStatement)=0L;
			}
			Catch_(err)
			{
				CProgram::GetParsingProgram()->LogError(err);
				delete (yyvsp[(2) - (6)].storage);
				delete (yyvsp[(4) - (6)].genExp);
				(yyval.forStatement)=0L;
			}			
		}
    break;

  case 210:
/* Line 1787 of yacc.c  */
#line 1634 "basic.y"
    {
			if ((yyvsp[(1) - (4)].forStatement))
			{
				// if the next statement contains an identifier check it matches
				// if it's an array index we can't statically check it as the array could
				// be indexed by a variable which would get out of its face quickly.
				bool				mismatch=false;
																	
				if ((yyvsp[(3) - (4)].intStorage))	// if next statement var is specified
				{
					CIntegerStorage		*indexVar=(yyvsp[(1) - (4)].forStatement)->GetIndexStorage();
					CIntegerArrayItem	*indexArray=dynamic_cast<CIntegerArrayItem*>(indexVar);
					CIntegerArrayItem	*nextArray=dynamic_cast<CIntegerArrayItem*>((yyvsp[(3) - (4)].intStorage));

					// if both arrays
					if (indexArray && nextArray)
						mismatch = nextArray->GetArray()!=indexArray->GetArray();
					else
						mismatch = indexVar!=(yyvsp[(3) - (4)].intStorage);

					if (mismatch)
						LogException_(UTBException::ThrowForLoopIdentifierMismatch((yylsp[(3) - (4)])));
				}
			
				if (!mismatch)
				{
					(yyval.statement)=(yyvsp[(1) - (4)].forStatement);
					(yyvsp[(1) - (4)].forStatement)->SetSubStatements(*CProgram::GetParsingProgram()->GetVarTable(),(yyvsp[(2) - (4)].statement));
				}
				else
				{
					delete (yyvsp[(1) - (4)].forStatement),
					delete (yyvsp[(2) - (4)].statement);
					(yyval.statement)=0L;
				}
			}
			else
			{
				delete (yyvsp[(2) - (4)].statement);
				(yyval.statement)=0l;
			}
		}
    break;

  case 211:
/* Line 1787 of yacc.c  */
#line 1678 "basic.y"
    { (yyval.arithExp)=0L; }
    break;

  case 212:
/* Line 1787 of yacc.c  */
#line 1680 "basic.y"
    {
			(yyval.arithExp)=CheckSingleNumExp((yyvsp[(2) - (2)].genExp),(yylsp[(2) - (2)]));
		}
    break;

  case 213:
/* Line 1787 of yacc.c  */
#line 1684 "basic.y"
    {
			LogException_(UTBException::ThrowWithRange((yylsp[(2) - (2)]),kTBErr_IllegalExp));
			FlushExp();
			yyclearin;
		}
    break;

  case 214:
/* Line 1787 of yacc.c  */
#line 1691 "basic.y"
    { (yyval.intStorage)=0L; }
    break;

  case 215:
/* Line 1787 of yacc.c  */
#line 1693 "basic.y"
    {
			if ((yyvsp[(2) - (2)].storage))
			{
				if ((yyvsp[(2) - (2)].storage)->GetType()!=CVariableSymbol::kInteger)
				{
					(yyval.intStorage)=0;
					LogException_(UTBException::ThrowBadForLoopIndex((yylsp[(2) - (2)])));
				}
				else
					(yyval.intStorage)=(yyvsp[(2) - (2)].storage)->mIntStore;
				
				delete (yyvsp[(2) - (2)].storage);
			}
			else
				(yyval.intStorage)=0;
		}
    break;

  case 216:
/* Line 1787 of yacc.c  */
#line 1710 "basic.y"
    {
			LogException_(UTBException::ThrowBadForLoopIndex((yylsp[(2) - (2)])));
			FlushExp();
			yyclearin;
		}
    break;

  case 217:
/* Line 1787 of yacc.c  */
#line 1727 "basic.y"
    {
							if ((yyvsp[(1) - (4)].storage))
							{
								(yyval.statement)=0;
								if (!CGeneralExpressionErr::ContainsErrors((yyvsp[(3) - (4)].genExp)))								
									LogException_((yyval.statement)=MakeAssignmentStatement(*(yyvsp[(1) - (4)].storage),(yyvsp[(3) - (4)].genExp),(yylsp[(3) - (4)])));
								delete (yyvsp[(1) - (4)].storage);
							}
							else
							{
								delete (yyvsp[(3) - (4)].genExp);
								(yyval.statement)=0;
							}
						}
    break;

  case 218:
/* Line 1787 of yacc.c  */
#line 1747 "basic.y"
    {
							(yyval.statement)=0;
							LogException_(UTBException::ThrowWithRange((yylsp[(3) - (4)]),kTBErr_IllegalExp));
							delete (yyvsp[(1) - (4)].storage);
						}
    break;

  case 219:
/* Line 1787 of yacc.c  */
#line 1753 "basic.y"
    { TBStatement_(CReadStatement((yyvsp[(1) - (1)].storage))); }
    break;

  case 220:
/* Line 1787 of yacc.c  */
#line 1754 "basic.y"
    { TBStatement_(CReadStatement((yyvsp[(1) - (3)].storage))); (yyval.statement)->Append((yyvsp[(3) - (3)].statement)); }
    break;

  case 221:
/* Line 1787 of yacc.c  */
#line 1757 "basic.y"
    { (yyval.statement)=(yyvsp[(2) - (3)].statement); }
    break;


/* Line 1787 of yacc.c  */
#line 5005 "basic.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2050 of yacc.c  */
#line 1759 "basic.y"


int				gRepeatToken=-1;
YYSTYPE			gRepeatValue;
SBisonTokenLoc	gRepeatLoc;

// ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
//		¥ PatchedLex
// ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
// Wraps around the normal lex, can fake a token into the input stream. Faking a token is needed to
// push back a token that has already been matched by the lexer.
int PatchedLex()
{
	int		result=0;

	if (gRepeatToken>=0)
	{
		result=gRepeatToken;
		gRepeatToken=-1;
		yylloc=gRepeatLoc;
		basiclval=gRepeatValue;
	}
	else
		result=basiclex();
	
	return result;
}

// ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
//		¥ FlushList
// ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
// Drops tokens until an end line, unbalanced close bracket.
void FlushList()
{
	SInt32		bracket=0,sqbracket=0;
	int			token;
	bool		done=false;
	YYSTYPE		wasVal=basiclval;
	SBisonTokenLoc	wasLoc=yylloc;

	while (!done)
	{
		switch (token=basiclex())
		{
			case OPENSQBRACKET:
				sqbracket++;
				break;
		
			case OPENBRACKET:
				bracket++;
				break;
			
			case CLOSEBRACKET:
			case CLOSESQBRACKET:
				if (token==CLOSEBRACKET)
					bracket--;
				else
					sqbracket--;
				if ((bracket<=0) && (sqbracket<=0))
				{
					gRepeatToken=token;
					done=true;
				}
				break;
				
			case ENDLINE:
			case 0:	// EOF
				gRepeatToken=token;
				done=true;
				break;
		}
	}
	
	gRepeatLoc=yylloc;
	gRepeatValue=basiclval;
	
	// restore loc and values
	basiclval=wasVal;
	yylloc=wasLoc;
}


// ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
//		¥ FlushExp
// ÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑÑ
// Drops tokens until an end line, unbalanced close bracket or seperator in an attempt to skip an expression with an error
// in it. Returns the seperator to the input stream by way of a patched version of lex which is able to fake a token.
void FlushExp()
{
	SInt32		bracket=0,sqbracket=0;
	int			token;
	bool		done=false;
	YYSTYPE		wasVal=basiclval;
	SBisonTokenLoc	wasLoc=yylloc;

	while (!done)
	{
		switch (token=basiclex())
		{
			case OPENSQBRACKET:
				sqbracket++;
				break;
		
			case OPENBRACKET:
				bracket++;
				break;
			
			case CLOSEBRACKET:
			case CLOSESQBRACKET:
				if (token==CLOSEBRACKET)
					bracket--;
				else
					sqbracket--;
			case COMMA:
			case SEMICOLON:
			case TO:
				if ((bracket<=0) && (sqbracket<=0))
				{
					gRepeatToken=token;
					done=true;
				}
				break;
				
			case ENDLINE:
			case 0:	// EOF
				gRepeatToken=token;
				done=true;
				break;
		}
	}
	
	gRepeatLoc=yylloc;
	gRepeatValue=basiclval;
	
	// restore loc and values
	basiclval=wasVal;
	yylloc=wasLoc;
}

int yyerror(char * s)
{
//	LogException_(UTBException::ThrowWithRange(yylloc,kTBErr_UnmatchedSyntaxError));
//	SignalPStr_("\pUncategorised syntax error, logging...");
	
	return 1;	// continue
}
