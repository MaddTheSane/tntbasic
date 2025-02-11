/*
//	RezLib.h
//
//  � Ian R Ollmann (iano@cco.caltech.edu)	2000
//		All Rights Reserved
//
//	Please see accompanying documentation for duplication, distribution and licensing terms.
//
//	Version 1.1
*/

#ifndef REZ_LIB
#define REZ_LIB

typedef void* 		BackBufferRef;
typedef void* 		VideoFrameRef;
typedef void* 		MouseRef;
typedef void* 		InvalidRegionRef;
typedef long		ScreenRef;	
typedef long		RetraceToken;
typedef pascal void (*VerticalRetraceProcPtr)(  long userData);			
typedef pascal void (*VideoFrameCompletionProcPtr)( VideoFrameRef frame, void *userData );			
			

const BackBufferRef	kNoBackBufferRef = 0;
const VideoFrameRef	kNoVideoFrameRef = 0;
const ScreenRef		kNoScreen = 0;
const RetraceToken	kNoRetraceProcInstalled = 0;
const MouseRef		kNoMouseRef = 0;


typedef struct
{
	UInt32		resolutionID;		/*unique identifier for this rez/color depth combo	*/
	UInt32		refreshRate;		/*16.16 fixed point in Hz							*/
	UInt32		height;				/*height in pixels									*/
	UInt32		width;				/*width in pixels									*/
	UInt32		colorDepths;		/*colordepths allowed at this rez in bits -- i.e. if 8 and 32 bit color depths were alowed, the value would be 8 | 32 = 40 (=0x00000028). GetCurrentScreenSetting returns only the color depth currently in use.   */
	UInt16		flags;				/*See RLInfo flags below							*/
	Boolean		isSafe;				/*True if the resolution is known to function correctly. If false, it may still work, but you need to test.	*/
	char		rlInfoType;			/*Reserved for later use. Pass 0 here.				*/
	Str31		name;				/*Name of the this setting as a pascal string		*/
}RLInfo;

typedef struct
{
	Ptr			baseAddr;
	UInt32		rowBytes;
	UInt32		bitsPerPixel;
	Rect		bounds;
	UInt32		reserved;			/*Unused. Pass 0 here*/
}RLDrawInfo;

const int kGammaTableEntryCount = 256;
typedef struct
{
	float		red[kGammaTableEntryCount];				/* values in the range 0...1.0 */
	float		green[kGammaTableEntryCount];			/* values in the range 0...1.0  */
	float		blue[kGammaTableEntryCount];			/* values in the range 0...1.0  */
}RLGammaTable;

typedef struct
{
	BackBufferRef	sourceData;			/* buffer where the pixel data resides */
	Rect			sourceRect;			/* The bounds of the source data to copy to the screen in backbufer coordinates */
	Rect			destinationRect;	/* The onscreen coordinates for the pixels. */
	UInt16			z;					/* How far the layer is from the player. Larger numbers are closer */
	UInt16			flags;		
}RLVideoLayer;

/* RLVideoLayerFlags */
enum
{
	rlIgnoreLayer = 			 	1,	/* Set this bit if you would like the layer to be ignored (not blit) for the video frame */
	rlVideoLayerFlagReserved1 = 	2,	
	rlVideoLayerFlagReserved2 = 	4,	
	rlVideoLayerFlagReserved3 = 	8,	
	rlVideoLayerFlagReserved4 = 	16,	
	rlVideoLayerFlagReserved5 = 	32,	
	rlVideoLayerFlagReserved6 = 	64,	
	rlVideoLayerFlagReserved7 = 	128,	
	rlVideoLayerFlagReserved8 = 	256,	
	rlVideoLayerFlagReserved9 = 	512,	
	rlVideoLayerFlagReserved10 = 	1024,	
	rlVideoLayerFlagReserved11 = 	2048,	
	rlVideoLayerFlagReserved12 = 	4096,	
	rlVideoLayerFlagReserved13 = 	8192,	
	rlVideoLayerFlagReserved14 = 	16384,	
	rlVideoLayerFlagReserved15 = 	32768	
};


/* RLDisplay error types				*/
/* Note that these are positive in value. Occasionally, MacOS error types (negative) will be returned as well.	*/
enum
{
	rlDisplayManager2NotAvailable = 1,		/*DisplayManager 2.0 or better not available				*/
	rlDirectDisplayAPINotAvailable = 2,		/*Under OS X, the Direct Display API (part of CoreGraphics) could not be loaded */
	rlDataExtractorNotAvailable = 3,		/*The Data Extractor bundle could not be found. 			*/
	rlInvalidDisplayLocation = 4,			/*The location provided does not correspond to a display	*/
	rlUnableToFetchModeList = 5,			/*The library was not able to determine what resolutions are available for this display 	*/
	rlColorDepthNotAvailable = 6,			/*The color depth that you requested is not available 		*/
	rlRezNotFound = 7,						/*The resolution that you requested was not found			*/
	rlOutOfMemory = 8,						/*Insufficient free memory to complete task					*/
	rlInvalidScreenRef = 9,					/*The ScreenRef passed did not correspond to a valid ScreenRef 	*/
	rlSwitchRezNoLongerAvailable = 10,		/*SwitchRes has been deactivated */
	rlScreenHasNoRefreshRate = 11,			/*The display device does not have a classical refresh frequency. It might be a LCD display. */
	rlFrameIsDrawing = 12,					/*Planned for version 1.2 for backbuffer / blitting support*/
	rlInvalidBackBufferRef = 13,
	rlInvalidIndex = 14,
	rlInputSprocketNotAvailable = 15,
	rlFunctionNotAvailable = 16,
	rlInvalidParameter = 17
};


/* RLInfo flags		*/
enum
{
	rlDisplayModeIsStretched = 		1,		/*Set if the resolution is distorted. (e.g. 1024x768 stretched to fit a 1200x768 display) */
	rlDisplayModeRequresPanning = 	2,		/*Set if the entire resolution cannot fit on the screen at the same time -- panning is required. */
	rlDisplayModeInterlaced = 		4,
	rlDisplayModeFlagReserved3 = 	8,
	rlDisplayModeFlagReserved4 = 	16,
	rlDisplayModeFlagReserved5 = 	32,
	rlDisplayModeFlagReserved6 = 	64,
	rlDisplayModeFlagReserved7 = 	128,
	rlDisplayModeFlagReserved8 = 	256,
	rlDisplayModeFlagReserved9 = 	512,
	rlDisplayModeFlagReserved10 = 	1024,
	rlDisplayModeFlagReserved11 = 	2048,
	rlDisplayModeFlagReserved12 = 	4096,
	rlDisplayModeFlagReserved13 = 	8192,
	rlDisplayModeFlagReserved14 = 	16384,
	rlDisplayModeFlagReserved15 = 	32768,
	
	rlDisplayModeMatchingBits = rlDisplayModeIsStretched | rlDisplayModeRequresPanning | rlDisplayModeInterlaced
};


#ifdef __cplusplus
extern "C" {
#endif

				
/* The ScreenRef is a opaque pointer to a class that handles one display.
// You can choose which display by providing a rect in global coordinates. The display that 
// covers the largest part of the rect will be the one returned. If you pass NULL,
// the main display will be used.					*/
ScreenRef	NewScreenRef( const Rect *where, OSStatus *error );											
void		DisposeScreenRef( ScreenRef display );

/* GetDisplayList returns an array of displays as their bounding rectangles in global coordinates.
// DisposeDisplayList should be used to dispose of the display list when you are done with it	*/
Rect		*GetDisplayList( unsigned long *listEntryCount );
void		DisposeDisplayList( Rect *list );

/* Returns the current resolution and color depth being used by the display. The colorDepths field will
// only contain the depth currently in use, not all available at this resolution. For that, use 
// GetColorDepthsAtThisResolution																		*/
OSStatus	GetCurrentSetting( ScreenRef screen, RLInfo *info );

/* Returns all of the color depths available at the current resolution. If 32 and 8 bit color are available,
// you wll get back 32 | 8 = 40  (0x28) as a result														*/
UInt32		GetColorDepthsAtThisResolution( ScreenRef screen );

/* Returns an array of RLInfo structs of size *listEntryCount, that lists all of the display resolutions available
// on this display. Each ColorDepths field lists all of the color depths available at that resolution in the 
// style of GetColorDepthsAtThisResolution(). Note that on OS X, if you change the current resolution or color depth
// this list may become invalid and you will need to get a new one.	(Sorry, this is a feature that we inherit from
// Apples DirectDisplay API.)													*/
RLInfo		*GetResolutionList( ScreenRef screen, unsigned long *listEntryCount );

/* When you are finished with the RLInfo array provided by GetResolutionList(), dispose of it using this function.	*/
void		DisposeResolutionList( ScreenRef screen, RLInfo *list );

/* SetColorDepth sets the display color depth to the color depth that you provide. 						*/
OSStatus		SetColorDepth( ScreenRef screen, UInt32 colorDepth );

/* SetResolution sets the display resolution to the rez that you provide. The resolutionID comes from the first entry in the RLInfo struct.	
// The current color depth will be preserved.	If it cant be preserved, this call will return an error.			*/
OSStatus		SetResolution( ScreenRef screen, UInt32 resolutionID );

/* SetResolutionAndColorDepth simultaneously sets the color depth and resolution ID						*/
OSStatus		SetResolutionAndColorDepth( ScreenRef screen, UInt32 resolutionID, UInt32 colorDepth );

/* Show a dialog box that asks the user whether the new resolution is working. 		*/
OSStatus 		AskIfNewResolutionWorks( ScreenRef screen );		/* returns rlRezNotFound if the new rez doesn't work. noErr otherwise 	*/

/* Get drawing parameters for writing directly to the screen buffer					*/
OSStatus		GetCurrentScreenDrawingInfo( ScreenRef screen, RLDrawInfo *info );

/* wait for the display to finish drawing this frame and then return			*/
OSStatus		WaitForVerticalRetrace( ScreenRef screen );	/* Note: may be extremely wasteful of CPU time on OS 8/9 */

/* Install a callback function that is called each time the display finishes drawing a video frame	*/
RetraceToken	InstallVerticalRetraceProcedure( ScreenRef screen, VerticalRetraceProcPtr proc, long userData ); /* Only one proc per display  */

/* Uninstall a callback installed by InstallVerticalRetraceProcedure()	*/
void			DisposeVerticalRetraceProcedure( RetraceToken token );

/* Copy the current gamma table being used by the display into gamma	*/
OSStatus		GetGamma( ScreenRef screen, RLGammaTable *gamma );

/* copy the gamma table to the one used by the display	*/
OSStatus		SetGamma( ScreenRef screen, const RLGammaTable *gamma );

/* Do a gamma fade to the color provided over the time period desired	*/
OSStatus		FadeToColor( ScreenRef screen, const RGBColor *color, float seconds );

/* Do a gamma fade to the gamma table provided over the time period desired	*/
OSStatus		FadeToGamma( ScreenRef screen, const RLGammaTable *gamma, float seconds );

/* Switch to full screen mode: hide the menu bar, floating windows, block out other windows, etc.	*/
OSStatus		AcquireDesktop( ScreenRef screen, WindowRef *window, const RGBColor *background );

/* Revert to the normal windowing mode	*/
OSStatus		ReleaseDesktop( ScreenRef screen );



/*	+-------------------+
	| New in RezLib 1.1 |
	+-------------------+	*/

/* For saving and restoring the current desktop state -- so that icons dont move around too much */
/* RestoreDesktop releases the handle. It is not safe to copy the handle and use it again. */
/* In some environments, these functions may have no effect. */
OSStatus		SaveIconPositions( ScreenRef screen, Handle *desktopInfo );
OSStatus		RestoreIconPositions( ScreenRef screen, Handle desktopInfo );

/* These functions will fade multiple monitors simultaneously		*/
/* Do a gamma fade to the color provided over the time period desired	*/
OSStatus		FadeToColorMultiple( ScreenRef *screen, unsigned int count, const RGBColor *color, float seconds );

/* Do a gamma fade to the gamma table provided over the time period desired	*/
OSStatus		FadeToGammaMultiple( ScreenRef *screen, unsigned int count, const RLGammaTable *gammaList, float seconds );

/* 	Emulate a refresh rate -- useful for cases where the video driver doesn't support VBL. 
//	The refresh rate below will be formatted as 16.16 fixed. 
// 	Note that this function is not present in versions of RezLib 1.1 before 1.1.9 alpha 0 (a.k.a 1.1a9). 
//	Please see version numbering notes below for a mistake I made for 1.1 nomenclature. 			*/

RetraceToken 	EmulateVerticalRetraceProcedure( ScreenRef screen, UInt32	refreshRate, VerticalRetraceProcPtr proc, long userData );



/* Returns the version number of RezLib. 
// A small note about version numbers in RezLib 1.1.  I mistakenly put the non-release number in as the third revision number, 
// rather than as the non release number. Thus, version 1.1a9 will appears as follows in the NumVersion struct:
//
//		{ 1, 0x19, alphaStage, 0 }
//
//	So by MacOS convention, what I have been calling 1.1a9 is really 1.1.9 alpha 0, and the final 1.1 revision is 
//	1.1.10 finalStage 0.			*/

OSStatus		GetRezLibVersion( NumVersion	*version );

/* Since GetRezLibVersion is itself only introduced in version 1.1 (sorry!), you
	should use this macro to test to see if it is available first: */
#ifdef __cplusplus
    inline pascal Boolean IsRezLibVersionInfoAvailable() { return ( (void*) kUnresolvedCFragSymbolAddress != GetRezLibVersion ); }
#else
	#define IsRezLibVersionInfoAvailable()	( (void*) kUnresolvedCFragSymbolAddress != GetRezLibVersion )
#endif




// Proposed for RezLib 1.2 -- suggestions welcome! 
// Note that some of these may be active in earlier versions of RezLib. Prior to 1.2, they are for experimental purposes only.
//                                                                      ------------------------------------------------------

/*
MouseRef		AcquireMouse( OSStatus *error );
Point			ReadMouseDelta( MouseRef mouse );
OSStatus		SetMousePosition( MouseRef mouse, const Point *globalPosition );
void			ReleaseMouse( MouseRef mouse );


// Make the VBL task under 9 run as a MP task, rather than at interrupt level. Is this going to break anyone's code?

// Better support for acquiring multiple displays at once. 

//A offscreen drawing surface and AltiVec accelerated blitters for use with full screen games
BackBufferRef		CreateBackBuffer( UInt32 height, UInt32 width, UInt32 colorDepth, OSStatus *error );				//The globalBounds is the rect in screen coordinates that the back buffer is to correspond to. Pass NULL for a back buffer the size of the entire screen. 
void				DisposeBackBuffer( BackBufferRef buffer );
GWorldPtr			CreateGWorldForBackBuffer( BackBufferRef buffer, OSStatus *error );						//This GWorld is external to RezLib, created created as a shim to access the back buffer using Quickdraw. RezLib doesn't use it, and will never adjust the current port / GWorld. Delete it at any time using DisposeGWorld(). The GWorld will break when the back buffer is deleted. 
void				GetBackBufferDrawingInfo( BackBufferRef buffer, RLDrawInfo *info );						//Info for directly drawing to the back buffer. This is the low level alternative to CreateGWorldForBackBuffer().
void				ZeroBackBuffer( BackBufferRef buffer );
*/
/* 
 *	RezLib 1.2 provides an asynchronous blitter optimized for blitting from back buffer to the screen.
 *	It should only be used when the desktop has been acquired. You start by creating a new VideoFrame
 * 	using CreateNewVideoFrame(). Each video frame has associated with it a number of rectangular video 
 *	pixel layers. These layers do not have to cover the whole screen and may overlap with each other 
 *	in any way. Each pixel layer points to a rectangular area in a back buffer. Position the layers
 *	to position backbuffer pixels relative to each other, invalidate the dirty regions and then blit.
 *
 *	In the simplest possible implementation, you have one back buffer with one layer in it. You simply
 *	draw the new frame to the backbuffer, invalidate the dirty areas, then FlushFrameToScreen() in a loop. 
 *
 *	In a more complex implementation, one might have multiple layers moving relative to one another.
 *	Keeping layers separate allows you to avoid a lot of copying with scrolling games. Rather than 
 *	move the background around all the time, just use a larger back buffer and move the edges of the 
 *	layer around in it. Multiple layers may point to the same backbuffer. This is handy if you need to 
 *	"wrap" from one edge of the back buffer to the other edge.
 *
 *	This feature is not intended to be used with large numbers of layers. For example, it does not in
 *	itself constitute a sprite engine, though one could be written to this API. It would be too slow. 
 *	However you could use a sprite engine to render sprites into a layer and use this to blit them to 
 *	the screen afterwards. It is intended to be used with a small number of large layers.
 *
 *	It is important to keep your back buffers containing correct video information. Dirty regions may
 *	grow to encompass "clean" regions around them. You must wait until a video frame is done blitting 
 *	to the screen before modifying any of the back buffers it uses.
 *
 *	FlushFrameToScreenAsync queues up the frame to be played after the next VBL period. You may have 
 *	multiple frames queue up. Frames queued on the same ScreenRef will be shown in the order that 
 *	they were queued, one per VBL period.
 *
 *	Video frames may be reused after they have been flushed to the screen. 
 *
 *	The FlushFrameToScreenAsync completion callback must be MP safe. All of the functions that take or
 *  return a VideoFrameRef or InvalidRegionRef may be called in the completion callback or other MP task. 
 *	You may change the pixels in a back buffer provided that another frame is not currently queued up to 
 * 	use them. They are not safe to call reentrantly, however.
 *
 *	These routines are AltiVec accelerated on G4 and MP accelerated on MP machines (and both on G4-MP).
 */
 /*
VideoFrameRef		CreateNewVideoFrame( ScreenRef frameDestination, int layerCount );
OSStatus			DestroyVideoFrame( VideoFrameRef frame );
OSStatus			ReadVideoLayerInfo( VideoFrameRef frame, RLVideoLayer *layerInfo, int index );
OSStatus			SetVideoLayerInfo( VideoFrameRef frame, const RLVideoLayer *newInfo, int index );
OSStatus			FlushFrameToScreen( VideoFrameRef frame, InvalidRegionRef *invalRgn );	
OSStatus			FlushFrameToScreenAsync(	VideoFrameRef frame, 
												InvalidRegionRef *invalRgn,
												VideoFrameCompletionProcPtr completionNotifier, 
												void *userData );	//The behavior of any changes made to the back buffer between when this is called and the completion Proc is called is undefined. Behavior when the desktop is not acquired is undefined.

InvalidRegionRef	NewInvalidRegion( VideoFrameRef frame );
OSStatus			DestroyInvalidRegion( InvalidRegionRef rgn );
OSStatus			ClearInvalidRegion( InvalidRegionRef rgn );
OSStatus 			AddRectListToInvalidRegion( InvalidRegionRef rgn, const Rect *invalidRects, UInt32 rectCount );			//Pass a NULL list to invalidate the whole buffer, otherwise invalidRects is a pointer to an array of rects to invalidate. RezLib uses a fine grained blitter optimized for complex dirty regions. Many small rects are just fine! 
OSStatus 			AddPointListToInvalidRegion( InvalidRegionRef rgn, const Point *invalidPoints, UInt32 ptCount );		//Pass a NULL list to invalidate the whole buffer, otherwise invalidRects is a pointer to an array of rects to invalidate. RezLib uses a fine grained blitter optimized for complex dirty regions. Many small rects are just fine! 
InvalidRegionRef	InvalidRegionUnion( InvalidRegionRef rgn1, InvalidRegionRef rgn2  );

*/
//Some sort of easy OpenGL setup stuff? -- hazy on this one
//OSStatus		RLSetupOpenGL( ScreenRef screen, .... );

//Probably should do something about 64 bit compatability at some point. Probably best to wait for Apple to 
//show the way.




#ifdef __cplusplus
}
#endif

#endif /* REZ_LIB */