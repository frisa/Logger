// LoggerDotNetClient.cpp : main project file.

#include "stdafx.h"
#include "..\LoggerLib\Log.h"

using namespace System;
using namespace LoggerDotNet;

int main(array<System::String ^> ^args)
{
	CLog::logFilePath = "c:\\log\\WinTrace.log";
	CLog::logLevel = Logger::TLogLevel::logDEBUG;
	CLog::log(Logger::TLogLevel::logDEBUG, __FUNCTION__ + " started");
    return 0;
}
