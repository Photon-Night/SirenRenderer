#pragma once
#ifdef SR_PLATFORM_WINDOWS
	#ifdef SR_BUILD_DLL
		#define SIREN_API __declspec(dllexport)
	#else 
		#define SIREN_API __declspec(dllimport)
	#endif // SR_BUILD_DLL
#else
	#error Siren only support Windows!
#endif // 

#define BIT(x) (1 << x)