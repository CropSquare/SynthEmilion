#pragma once

#include "pluginterfaces\base\fplatform.h"

#define MAJOR_VERSION_STR "0"
#define MAJOR_VERSION_INT 0

#define SUB_VERSION_STR "0"
#define SUB_VERSION_INT 0

#define RELEASE_NUMBER_STR "1"
#define RELEASE_NUMBER_INT 1

#define BUILD_NUMBER_STR "1" // Build number to be sure that each result could identified.
#define BUILD_NUMBER_INT 1

// Version with build number (example "1.0.3.342")
#define FULL_VERSION_STR MAJOR_VERSION_STR "." SUB_VERSION_STR "." RELEASE_NUMBER_STR "." BUILD_NUMBER_STR

// Version without build number (example "1.0.3")
#define VERSION_STR MAJOR_VERSION_STR "." SUB_VERSION_STR "." RELEASE_NUMBER_STR

// HERE you have to define your plug-in, company name, email and web
#define stringPluginName		"SynthEmilion"

#define stringOriginalFilename	"SynthEmilion.vst3"
#if SMTG_PLATFORM_64
#define stringFileDescription	stringPluginName" SynthEmilion vst (64Bit)"
#else
#define stringFileDescription	stringPluginName" SynthEmilion vst"
#endif
#define stringCompanyName		"CropSquare\0"
#define stringCompanyWeb		"https://github.com/CropSquare/SynthEmilion"
#define stringCompanyEmail		"mailto:jpgrandgirard@gmail.com"

#define stringLegalCopyright	"© 2018 CropSuare"
#define stringLegalTrademarks	"GPL v3"
