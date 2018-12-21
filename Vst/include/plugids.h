#pragma once

namespace SQU {
namespace Vst {

// HERE you have to define new unique class ids: for processor and for controller
// you can use GUID creator tools like https://www.guidgenerator.com/
static const Steinberg::FUID MyProcessorUID (0xaf2e317b, 0xf5b44dd5, 0x84d95f9a, 0x0091d060);
static const Steinberg::FUID MyControllerUID (0x9f89d401, 0xd9c54aa5, 0xa70003c, 0x427281185);

//------------------------------------------------------------------------
} // namespace Vst
} // namespace Vst
