#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Kee6
{

	class KEE6_API Logger
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

#define K6_CORE_TRACE(...)    ::Kee6::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define K6_CORE_INFO(...)     ::Kee6::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define K6_CORE_WARN(...)     ::Kee6::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define K6_CORE_ERROR(...)    ::Kee6::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define K6_CORE_CRITICAL(...) ::Kee6::Logger::GetCoreLogger()->critical(__VA_ARGS__)

#define K6_TRACE(...)         ::Kee6::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define K6_INFO(...)          ::Kee6::Logger::GetClientLogger()->info(__VA_ARGS__)
#define K6_WARN(...)          ::Kee6::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define K6_ERROR(...)         ::Kee6::Logger::GetClientLogger()->error(__VA_ARGS__)
#define K6_CRITICAL(...)      ::Kee6::Logger::GetClientLogger()->critical(__VA_ARGS__)

