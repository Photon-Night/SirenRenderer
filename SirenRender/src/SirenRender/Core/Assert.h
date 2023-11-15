#pragma once
 #include "SirenRender/Core.h"
 #include "SirenRender/Log.h"

 #ifdef SR_ENABLE_ASSERT
	#define SR_CORE_ASSERT(x, ...) {if(!(x)) {SR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SR_ASSERT(x, ...) {if (!(x)) { SR_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define SR_CORE_ASSERT(x, ...)
	#define SR_ASSERT(x, ...)
#endif