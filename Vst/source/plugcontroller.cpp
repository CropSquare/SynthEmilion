#include "../include/plugcontroller.h"
#include "../include/plugids.h"

#include "base/source/fstreamer.h"
#include "pluginterfaces/base/ibstream.h"

namespace SQU {
namespace Vst {

//-----------------------------------------------------------------------------
Steinberg::tresult PLUGIN_API PlugController::initialize (FUnknown* context)
{
	Steinberg::tresult result = EditController::initialize (context);
	if (result == Steinberg::kResultTrue)
	{
		//---Create Parameters------------
	}
	return Steinberg::kResultTrue;
}

//------------------------------------------------------------------------
Steinberg::tresult PLUGIN_API PlugController::setComponentState (Steinberg::IBStream* state)
{
	// we receive the current state of the component (processor part)
	// we read our parameters and bypass value...
	if (!state)
		return Steinberg::kResultFalse;

	// TODO set state

	return Steinberg::kResultOk;
}

//------------------------------------------------------------------------
} // namespace Vst
} // namespace SQU
