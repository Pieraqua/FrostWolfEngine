#pragma once
#include "SystemOutput.h"

// SystemOutput with main, log and command viewports
class ViewportOutput :
    public SystemOutput
{
public:
	void printToLog(string data);
	void printViewports();
	void printLogo();
	void setMainViewport(const char* imagePath);
	static ViewportOutput* getInstance();

private:
	ViewportOutput();
	void printMainViewport();
	void printUserCommands();
	void printLog(COORD);
	char mainImagePath[256];
	Log messageLog;
};

