#pragma once
#include <Windows.h>
#include <string>

enum LoggerGroup
{
	LOG_ERROR,
	LOG_WARNING,
	LOG_INFO
};

inline const char * LoggerName[] =
{
	"ERROR",
	"WARNING",
	"INFO"
};

class Logger
{
public:
	Logger(std::string name);
	void Log(LoggerGroup group, std::string message);
	//void Log(LoggerGroup group, const char* message);
	std::string name;
};