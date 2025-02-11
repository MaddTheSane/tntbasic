// Modified by Mark Tully 11/6/06 to work directly with Mach rather than doing so indirectly via function ptrs.

#ifndef RL_DISPLAY
#define RL_DISPLAY

#include <new>
#include <stdlib.h>
#include "RezLib.h"


class RetraceProc;
class RLDisplay
{
	public:
		virtual OSStatus	GetCurrentDrawingInfo( RLDrawInfo *info ) const = 0;	
		virtual OSStatus	GetCurrentScreenSetting( RLInfo *info ) const = 0;
		virtual UInt32		GetColorDepthsAtThisResolution( void ) const = 0;
		virtual OSStatus	GetGamma( RLGammaTable *gamma ) const = 0;
		virtual RLInfo		*GetResolutionList( unsigned long *listCount ) const = 0;
		virtual	void		DisposeResolutionList( RLInfo *list ) const = 0;
		virtual OSStatus	SaveIconPositions( Handle *desktopInfo ) const = 0;


		virtual OSStatus	AcquireDesktop( WindowRef *window, const RGBColor *background ) = 0;
		virtual OSStatus	ReleaseDesktop( void ) = 0;
		virtual OSStatus	SetColorDepth( UInt32 newColorDepth ) = 0;
		virtual OSStatus	SetGamma( const RLGammaTable *gamma ) = 0;
		virtual OSStatus	SetResolution( long opaqueModeID ) = 0;
		virtual OSStatus	SetResolutionAndColorDepth( long opaqueModeID, UInt32 newColorDepth ) = 0; 
		virtual OSStatus	RestoreIconPositions( Handle desktopInfo ) const = 0;

		virtual OSStatus		WaitForVerticalRetrace( void ) = 0;
		virtual RetraceProc *InstallVerticalRetraceProcedure( VerticalRetraceProcPtr proc, long userData ) = 0;
		virtual RetraceProc *EmulateVBL( UInt32 refresh, VerticalRetraceProcPtr proc, long userData ) = 0;
		virtual OSStatus	DisposeVerticalRetraceProcedure( RetraceProc *proc ) = 0;

		virtual GDHandle	GetDisplay( OSStatus *error ) const = 0;

		void 				*operator new( size_t size ) throw (OSStatus) { void *ptr = (void*) NewPtr( size ); if( ! ptr ) throw OSStatus(rlOutOfMemory); return ptr; }
		void				operator delete( void *ptr){ if( ptr) DisposePtr( Ptr( ptr ) ); }	

		virtual				~RLDisplay();

	protected:
							RLDisplay( const Rect *where ) throw (OSStatus) {where;}
		

	private:
		RLDisplay			&operator=(const RLDisplay &display ){ display; return *( (RLDisplay*) NULL);}
	
};


RLDisplay *MakeNewRLDisplay( const Rect *where ) throw (OSStatus);


class RetraceProc
{
	public:
		
		virtual void		RetraceFunction();			
		RLDisplay			*GetOwner( void ) const { return owner; }

		void 				*operator new( size_t size ) throw (OSStatus) { void *ptr = (void*) NewPtr( size ); if( ! ptr ) throw OSStatus(rlOutOfMemory); return ptr; }
		void				operator delete( void *ptr){ if( ptr) DisposePtr( Ptr( ptr ) ); }	

		virtual				~RetraceProc();
		
	protected:	
							RetraceProc( RLDisplay *owner, VerticalRetraceProcPtr proc, long userData ) throw (OSStatus);
							
		VerticalRetraceProcPtr	proc;
		long				userData;
		RLDisplay			*owner;								

};

#endif //RL_DISPLAY