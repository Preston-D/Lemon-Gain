//------------------------------------------------------------------------
// Copyright(c) 2023 Lemon Live Studios.
//------------------------------------------------------------------------

#pragma once

#include "pluginterfaces/base/funknown.h"
#include "pluginterfaces/vst/vsttypes.h"

namespace LemonLive {
//------------------------------------------------------------------------
static const Steinberg::FUID kLemon_GainProcessorUID (0xD3154247, 0x6D98515B, 0x88EF6647, 0xB35E9098);
static const Steinberg::FUID kLemon_GainControllerUID (0xE9F93E9E, 0x7E355EA4, 0xAF18A8AA, 0xC592E560);

#define Lemon_GainVST3Category "Fx"

//------------------------------------------------------------------------
} // namespace LemonLive
