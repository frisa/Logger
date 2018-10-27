// LoggerClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\LoggerLib\Log.h"

using namespace Logger;

int main()
{
	const int count = 3;
	Log().logLevel = logDEBUG;
	char* pFilePath = "c:\\log\\WinTrace.log";
	Log().plogFilePath = pFilePath;
	Log().log(logERROR) << "logged";
	Log().log(logWARNING) << "logged";
	Log().log(logINFO) << "logged";
	Log().log(logDEBUG) << "logged";
	for (int i = 0; i != count; ++i)
	{
		Log().log(logDEBUG) << "the counter i = " << i;
	}
	return 0;
}

