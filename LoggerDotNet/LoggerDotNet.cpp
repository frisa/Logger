#include "stdafx.h"
#include "LoggerDotNet.h"

void LoggerDotNet::CLog::log(Logger::TLogLevel level, String ^ message)
{
	Logger::Log().log(level) << (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(message).ToPointer();
}
