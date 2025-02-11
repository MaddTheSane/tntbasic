// Copyright �2005, 2006 Freescale Semiconductor, Inc.
// Please see the License for the specific language governing rights and
// limitations under the License.
// ===========================================================================
//	UStandardDialogs.h			PowerPlant 2.2.2	�1998-2005 Metrowerks Inc.
// ===========================================================================

#ifndef _H_UStandardDialogs
#define _H_UStandardDialogs
#pragma once

#include <PP_Macros.h>

	// You should use the alias PP_StandardDialogs to qualify
	// calls to standard dialog functions. This alias will map
	// to an implementation namespace based on the setting of
	// the PP_StdDialogs_Option preprocessor symbol.
	//
	// The file UStandardDialogs.i contains the function declarations

/*
	08/20/2011	RL Aurbach
	Change the functioning of UStandardDialogs to ignore the PP_StdDialogs_Option
	parameter and always use Navigation Services. We no longer support the
	Classic environment.
	
	In addition, we will change the API so as to add support for the new 
	Navigation Services APIs introduced in 10.4 and where possible.

#if	PP_StdDialogs_Option == PP_StdDialogs_NavServicesOnly
								// Always use Navigation Services
	#include <UNavServicesDialogs.h>
	namespace PP_StandardDialogs = PP_PowerPlant::UNavServicesDialogs;

#elif PP_StdDialogs_Option == PP_StdDialogs_Conditional
								// Use Nav Services if available,
								//   otherwise use Classic
	#include <UConditionalDialogs.h>
	namespace PP_StandardDialogs = PP_PowerPlant::UConditionalDialogs;

#else							// Use Classic implementation
	#include <UClassicDialogs.h>
	namespace PP_StandardDialogs = PP_PowerPlant::UClassicDialogs;
#endif

/*/
	#include <UNavServicesDialogs.h>
	namespace PP_StandardDialogs = PP_PowerPlant::UNavServicesDialogs;
/**/


PP_Begin_Namespace_PowerPlant

	// Parameter values for AskSaveChanges()

const bool	SaveWhen_Closing	= false;
const bool	SaveWhen_Quitting	= true;

PP_End_Namespace_PowerPlant

#endif
