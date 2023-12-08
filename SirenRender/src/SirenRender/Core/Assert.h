#pragma once
 #include "SirenRender/Core.h"
 #include "SirenRender/Log.h"

#define SR_ENABLE_ASSERTS 0

#ifdef SR_DEBUG
	#define ZH_ENABLE_ASSERTS
#endif

#if SR_ENABLE_ASSERTS
	#define SR_CORE_ASSERTS(x, ...) {if(!(x)) {SR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SR_ASSERTS(x, ...) {if (!(x)) { SR_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define SR_CORE_ASSERTS(x, ...)
	#define SR_ASSERTS(x, ...)
#endif