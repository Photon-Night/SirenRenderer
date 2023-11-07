#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"


//Core log macros
#define SR_CORE_TRACE(...)   ::SirenRender::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SR_CORE_INFO(...)    ::SirenRender::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SR_CORE_WARN(...)	 ::SirenRender::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SR_CORE_ERROR(...)	 ::SirenRender::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SR_CORE_FATAL(...)	 ::SirenRender::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define SR_TRACE(...)		 ::SirenRender::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SR_INFO(...)		 ::SirenRender::Log::GetClientLogger()->info(__VA_ARGS__)
#define SR_WARN(...)		 ::SirenRender::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SR_ERROR(...)		 ::SirenRender::Log::GetClientLogger()->error(__VA_ARGS__)
#define SR_FATAL(...)		 ::SirenRender::Log::GetClientLogger()->fatal(__VA_ARGS__)

namespace SirenRender
{
	class SIREN_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger(){return s_ClientLogger;}
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};	
}


