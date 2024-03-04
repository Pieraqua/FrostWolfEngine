#include "SystemOutput.h"

SystemOutput* SystemOutput::systemOutputModule = nullptr;;

void SystemOutput::printToConsole(string data, outputLevel level) {

	if (levelEnabled(level))
	{
		cout << levelName[(int)level] << ": " << data << "\n";
	}

}

SystemOutput::SystemOutput()
{
}

bool SystemOutput::levelEnabled(outputLevel level)
{
	return enabled[(int)level];
}

SystemOutput* SystemOutput::getInstance()
{
	if (systemOutputModule == NULL)
		systemOutputModule = new SystemOutput();

	return systemOutputModule;
}

void SystemOutput::setConsoleOutputEnabled(outputLevel level, bool val)
{
	const string enabled_name[] = { "disabled", "enabled" };
	if (level > outputLevel::INFO && level < outputLevel::levelNum) {
		string infostr = "Level " + levelName[(int)level] + " " + enabled_name[val];
		printToConsole(infostr, outputLevel::INFO);
		enabled[(int)level] = val;
	}
}

