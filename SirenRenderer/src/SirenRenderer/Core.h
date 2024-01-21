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

namespace SirenRenderer
{
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}