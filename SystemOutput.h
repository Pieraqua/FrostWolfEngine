#pragma once

#include <string>
#include <iostream>
#include <stdbool.h>
using namespace std;

#include <Windows.h>
#include "config.h"

class SystemOutput
{
public:
	enum class outputLevel {
		INFO = 0,
		WARNING,
		DEBUG,
		ERR,
		levelNum
	};

	void printToConsole(string data, outputLevel level);
	void setConsoleOutputEnabled(outputLevel level, bool val);
	bool levelEnabled(outputLevel level);
	static SystemOutput* getInstance();
	int cls();
	void printViewports();
	void printLogo();
	void setMainViewport(const char* imagePath);

protected:
	SystemOutput();
	~SystemOutput();
	static SystemOutput* systemOutputModule;

private:
	char mainImagePath[256];

	void printMainViewport();
	void printUserCommands();
	void printLog(COORD);
	const string levelName[(int)outputLevel::levelNum] = { "INFO","WARNING", "DEBUG", "ERROR" };
	bool enabled[(int)outputLevel::levelNum] = { true,true,true,true };
};


