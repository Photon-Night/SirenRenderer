#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"


//Core log macros
#define SR_CORE_TRACE(...)   ::SirenRenderer::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SR_CORE_INFO(...)    ::SirenRenderer::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SR_CORE_WARN(...)	 ::SirenRenderer::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SR_CORE_ERROR(...)	 ::SirenRenderer::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SR_CORE_FATAL(...)	 ::SirenRenderer::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define SR_TRACE(...)		 ::SirenRenderer::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SR_INFO(...)		 ::SirenRenderer::Log::GetClientLogger()->info(__VA_ARGS__)
#define SR_WARN(...)		 ::SirenRenderer::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SR_ERROR(...)		 ::SirenRenderer::Log::GetClientLogger()->error(__VA_ARGS__)
#define SR_FATAL(...)		 ::SirenRenderer::Log::GetClientLogger()->fatal(__VA_ARGS__)

namespace SirenRenderer
{
	class SIREN_API Log
	{
	public:
		static void Init();
		inline static Ref<spdlog::logger>& GetClientLogger(){return s_ClientLogger;}
		inline static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};	
}


