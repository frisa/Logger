// LoggerDotNet.h

#pragma once
#include "ManagedObject.h"
#include "..\LoggerLib\Log.h"

using namespace System;
using namespace System::Text;

namespace LoggerDotNet
{
	public ref class CLog : ManagedObject<Logger::Log>
	{
	public:
		CLog() : ManagedObject(new Logger::Log()) {};
		static void log(Logger::TLogLevel level, String^ message);
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
		static property Logger::TLogLevel logLevel
		{
		public:
			Logger::TLogLevel get()
				{
					return Logger::Log::logLevel;
				}
			void set(Logger::TLogLevel value)
				{
				Logger::Log::logLevel = value;
				}
		}
	};
}