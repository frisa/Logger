#pragma once
#include <sstream>

namespace Logger
{
	enum TLogLevel
	{
		logNOTHING = 0,
		logERROR = 1,
		logWARNING = 2,
		logINFO = 3,
		logDEBUG = 4,
	};

	class Log
	{
	public:
		Log();
		~Log();
		static char* plogFilePath;
		__declspec(dllexport) static TLogLevel logLevel;
		__declspec(dllexport) std::ostringstream& log(TLogLevel level = logINFO);

	protected:
		std::ostringstream m_os;

	private:
		Log(const Log&);
		std::string getLevelStr(TLogLevel level) const;

	private:
		TLogLevel m_msgLevel;
	};
}



