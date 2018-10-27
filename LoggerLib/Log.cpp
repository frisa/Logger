#include "Log.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <thread>
#include <process.h>
#include <Windows.h>

using namespace Logger;

Log::Log()
{
}

TLogLevel Log::logLevel = logDEBUG;
char* Log::plogFilePath = "c:\\log\\WinTrace.log";

std::ostringstream& Log::log(TLogLevel level)
{
	auto time = std::chrono::system_clock::now();
	std::time_t t = std::chrono::system_clock::to_time_t(time);
	std::tm buf;
	localtime_s(&buf, &t);

	std::thread::id this_id = std::this_thread::get_id();

	TCHAR szAppPath[MAX_PATH] = L"";
	GetModuleFileName(0, szAppPath, MAX_PATH);
	
	std::wstring wstrAppName;
	wstrAppName = szAppPath;
	std::string strAppName(wstrAppName.begin(), wstrAppName.end());
	strAppName = strAppName.substr(strAppName.rfind("\\") + 1);

	m_os << "[" << strAppName << "][" << _getpid() << "][" << this_id << "]" << std::put_time(&buf, "%c");
	m_os << " " << getLevelStr(level) << ": ";
	//m_os << std::string(level > logDEBUG ? 0 : '\0', '\t');
	m_msgLevel = level;
	return m_os;
}

std::string Log::getLevelStr(TLogLevel level) const
{
	switch (level)
	{
	case logERROR:
	{
		return "E";
		break;
	}
	case logWARNING:
	{
		return "W";
		break;
	}
	case logINFO:
	{
		return "I";
		break;
	}
	case logDEBUG:
	{
		return "D";
		break;
	}
	default:
	{
		return "";
	}
	}
	return std::string();
}

Log::~Log()
{
	if (m_msgLevel <= Log::logLevel)
	{
		FILE * pFile;
		errno_t errVal;
		errVal = fopen_s(&pFile, plogFilePath, "a");
		if (0 == errVal)
		{
			m_os << std::endl;
			fprintf(pFile, "%s", m_os.str().c_str());
			fclose(pFile);
		}
	}
}

