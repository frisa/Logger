// LoggerDotNet.h

#pragma once
#include "ManagedObject.h"
#include "..\LoggerLib\Log.h"

using namespace System;
using namespace System::Text;

namespace LoggerDotNet
{
	public enum class LogLevel
	{
		logNOTHING = 0,
		logERROR = 1,
		logWARNING = 2,
		logINFO = 3,
		logDEBUG = 4,
	};

	public ref class CLog : ManagedObject<Logger::Log>
	{
	public:
		CLog() : ManagedObject(new Logger::Log()) {};
		static void log(LogLevel level, String^ message);
		static property String^ logFilePath
		{
		public:
			String^ get()
			{
				return gcnew String(Logger::Log::plogFilePath);
			}
			void set(String^ value)
			{
				Logger::Log::plogFilePath = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(value).ToPointer();
			}
		}
		static property LogLevel logLevel
		{
		public:
			    LogLevel get()
				{
					return static_cast<LogLevel>( Logger::Log::logLevel);
				}
			void set(LogLevel value)
				{
				Logger::Log::logLevel = static_cast<Logger::TLogLevel>(value);
				}
		}
	};
}