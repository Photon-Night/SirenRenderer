#pragma once
#ifdef SR_PLATFORM_WINDOWS
#if SR_DYNAMIC_LINK
	#ifdef SR_BUILD_DLL
		#define SIREN_API __declspec(dllexport)
	#else 
		#define SIREN_API __declspec(dllimport)
	#endif // SR_BUILD_DLL
#else
	#define SIREN_API
#endif
#else
	#error Siren only support Windows!
#endif // 

#define BIT(x) (1 << x)

#define SR_BIND_EVENT_FUNC(fn) std::bind(&fn, this, std::placeholders::_1)