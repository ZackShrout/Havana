#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace Havana
{
	class HAVANA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return clientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};
}

// Core log macros
#define HV_CORE_TRACE(...) ::Havana::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HV_CORE_INFO(...)  ::Havana::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HV_CORE_WARN(...)  ::Havana::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HV_CORE_ERROR(...) ::Havana::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HV_CORE_FATAL(...) ::Havana::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define HV_TRACE(...) ::Havana::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HV_INFO(...)  ::Havana::Log::GetClientLogger()->info(__VA_ARGS__)
#define HV_WARN(...)  ::Havana::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HV_ERROR(...) ::Havana::Log::GetClientLogger()->error(__VA_ARGS__)
#define HV_FATAL(...) ::Havana::Log::GetClientLogger()->fatal(__VA_ARGS__)
