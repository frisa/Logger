#include "stdafx.h"
#include "LoggerDotNet.h"

void LoggerDotNet::CLog::log(LogLevel level, String ^ message)
{
	Logger::Log().log(static_cast<Logger::TLogLevel>(level)) 
		<< static_cast<char*>(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(message).ToPointer());
}
