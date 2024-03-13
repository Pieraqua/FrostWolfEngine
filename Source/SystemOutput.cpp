#include <windows.h>
using namespace std;

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

SystemOutput::~SystemOutput()
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


int SystemOutput::cls()
{   // limpa a tela no windows, do jeito oficial
    CONSOLE_SCREEN_BUFFER_INFO      info;
    HANDLE      H = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD       origem = { 0,0 };
    int         total;
    if (H == INVALID_HANDLE_VALUE) return -1;
    GetConsoleScreenBufferInfo(H, &info);
    int r = FillConsoleOutputCharacter(H, (TCHAR)' ',
        info.dwSize.X * info.dwSize.Y,
        origem, (LPDWORD)&total);
    int s = FillConsoleOutputAttribute(
        H, info.wAttributes,
        info.dwSize.X * info.dwSize.Y,
        origem, (LPDWORD)&total);
    SetConsoleCursorPosition(H, origem);
    return 0;
}
