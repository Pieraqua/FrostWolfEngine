#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

#include "SystemOutput.h"
#include "config.h"

class SystemInput
{
public:
	static SystemInput* getInstance();

	 vector<string> getUserInput();

protected:
	SystemInput();
	static SystemInput* systemInputModuleSingleton;
};

