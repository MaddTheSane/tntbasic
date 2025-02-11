// Copyright �2005, 2006 Freescale Semiconductor, Inc.
// Please see the License for the specific language governing rights and
// limitations under the License.
// ===========================================================================
//	UConditionalDialogs.h		PowerPlant 2.2.2	�1998-2005 Metrowerks Inc.
// ===========================================================================

#ifndef _H_UConditionalDialogs
#define _H_UConditionalDialogs
#pragma once

#include <PP_Prefix.h>
#include <LFileTypeList.h>
#ifndef __MACH__
#include <Navigation.h>
#endif

#if PP_Uses_Pragma_Import
	#pragma import on
#endif

PP_Begin_Namespace_PowerPlant

/*
	08/20/2011	RL Aurbach
	Deprecate Conditional Dialogs, since we only use Navigation Services and
	no longer support the Classic Environment.

namespace UClassicDialogs {				// Forward Declarations
	class	LFileChooser;
	class	LFileDesignator;
}

namespace UNavServicesDialogs {
	class	LFileChooser;
	class	LFileDesignator;
}

// ---------------------------------------------------------------------------

namespace UConditionalDialogs {

	bool	UseNavServices();
	void	SetTryNavServices( UInt32 inMinVersion );

	#include <UStandardDialogs.i>

	class	LFileChooser {
		public:
			#include <LFileChooser.i>

		protected:
			UClassicDialogs::LFileChooser*		mClassicChooser;
			UNavServicesDialogs::LFileChooser*	mNavServicesChooser;
	};

	class	LFileDesignator {
		public:
			#include <LFileDesignator.i>

		protected:
			UClassicDialogs::LFileDesignator*		mClassicDesignator;
			UNavServicesDialogs::LFileDesignator*	mNavServicesDesignator;
	};
}

/*/
	#include <UNavServicesDialogs.h>
/**/

PP_End_Namespace_PowerPlant

#if PP_Uses_Pragma_Import
	#pragma import reset
#endif

#endif
