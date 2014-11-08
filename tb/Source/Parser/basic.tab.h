/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison interface for Yacc-like parsers in C
   
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
/* Line 2053 of yacc.c  */
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


/* Line 2053 of yacc.c  */
#line 483 "basic.tab.h"
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
