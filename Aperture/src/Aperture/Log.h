#pragma once

#include <memory>
#include "core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Aperture {
	class AE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private: 
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Macros For Core Logging
#define AE_CORE_TRACE(...)  ::Aperture::Log::GetClientLogger()->trace(__VA_ARGS__);
#define AE_CORE_INFO(...)  ::Aperture::Log::GetClientLogger()->info(__VA_ARGS__);
#define AE_CORE_WARN(...)  ::Aperture::Log::GetClientLogger()->warn(__VA_ARGS__);
#define AE_CORE_ERROR(...)  ::Aperture::Log::GetClientLogger()->error(__VA_ARGS__);
#define AE_CORE_FATAL(...)  ::Aperture::Log::GetClientLogger()->fatal(__VA_ARGS__);

// Macros For Client Logging
#define AE_TRACE(...)		::Aperture::Log::GetClientLogger()->trace(__VA_ARGS__);
#define AE_INFO(...)		::Aperture::Log::GetClientLogger()->info(__VA_ARGS__);
#define AE_WARN(...)		::Aperture::Log::GetClientLogger()->warn(__VA_ARGS__);
#define AE_ERROR(...)		::Aperture::Log::GetClientLogger()->error(__VA_ARGS__);
#define AE_FATAL(...)		::Aperture::Log::GetClientLogger()->fatal(__VA_ARGS__);
