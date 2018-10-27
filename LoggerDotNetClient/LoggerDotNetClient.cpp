// LoggerDotNetClient.cpp : main project file.

#include "stdafx.h"

using namespace System;
using namespace LoggerDotNet;

int main(array<System::String ^> ^args)
{
	CLog::logFilePath = "c:\\log\\WinTrace.log";
	CLog::logLevel = LogLevel::logDEBUG;
	CLog::log(LogLevel::logDEBUG, __FUNCTION__ + " started");
    return 0;
}
