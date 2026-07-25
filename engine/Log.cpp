
/*
Implementation of the Log class
*/
#include "Log.h"

#include <iostream>


void Log::Write(const std::string& level, const std::string& message)
{
	std::cout << "[" << level << "]" << " : " << message << std::endl;
}


void Log::Info(const std::string & message)
{
	Write("INFO" ,message);
}
void Log::Warning(const std::string& message)
{
	Write("WARNING", message);
}
void Log::Error(const std::string& message)
{
	Write("ERROR", message);
}




