#include "pch.h"
#include "Logger.h"
#include "Time.h"

Logger::Logger(std::string name)
{
	this->name = name;
}

void Logger::Log(LoggerGroup group, std::string message)
{
	//std::cout << i << std::endl;
	//std::cout << message << std::endl;
	
	std::cout << (int)Time::GetTimeMs() << " [" << LoggerName[group] << "]-";
	std::cout<< name << ": " << message << std::endl;
}
