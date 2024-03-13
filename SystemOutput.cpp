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

SystemOutput::SystemOutput() : messageLog(25,19)
{
    setMainViewport(MAIN_VIEWPORT_FILE);
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

void SystemOutput::printToLog(string data)
{
    messageLog.addLog(data);
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

void SystemOutput::printViewports()
{
    cls();
    fputs("\x1b[?25l", stdout);
    HANDLE      H = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { 0, 20 };
    SetConsoleCursorPosition(H, pos);
    printUserCommands();
    pos = { 0,0 };
    SetConsoleCursorPosition(H, pos);
    printMainViewport();
    pos = { 59, 0 };
    SetConsoleCursorPosition(H, pos);
    printLog(pos);

    pos = { 0, 25 };
    SetConsoleCursorPosition(H, pos);
}

void SystemOutput::printLogo()
{
    FILE* viewport;
    fopen_s(&viewport, FROSTWOLFLOGO_FILE, "r");
    char s[1024];

    HANDLE      H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(H, {0,0});

    if (viewport)
    {
        while ((fgets(s, sizeof s, viewport)) != NULL) {
            printf("%s", s);
        }

    }
    else printf("ERROR");
}

void SystemOutput::setMainViewport(const char* imagePath)
{
    strcpy_s(mainImagePath, imagePath);
}

void SystemOutput::printMainViewport()
{
    FILE* viewport;
    fopen_s(&viewport, mainImagePath, "r");
    char s[1024];

    if (viewport)
    {
        while ((fgets(s, sizeof s, viewport)) != NULL) {
            printf("%s", s);
        }

    }
    else printf("ERROR");
}

void SystemOutput::printUserCommands()
{
    FILE* viewport;
    fopen_s(&viewport, USER_COMMAND_VIEWPORT_FILE, "r");
    char s[1024];

    if (viewport)
    {
        while ((fgets(s, sizeof s, viewport)) != NULL) {
            printf("%s", s);
        }

    }
    else printf("ERROR");
}

void SystemOutput::printLog(COORD pos)
{
    FILE* viewport;
    fopen_s(&viewport, LOG_VIEWPORT_FILE, "r");
    char s[1024];
    HANDLE      H = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD init_pos = pos;

    if (viewport)
    {
        while ((fgets(s, sizeof s, viewport)) != NULL) {
            SetConsoleCursorPosition(H, pos);
            printf("%s", s);
            pos.Y++;
        }

        pos = init_pos;
        pos.X++;
        pos.Y++;

        for (int i = 0; i < messageLog.getSize(); i++)
        {
            SetConsoleCursorPosition(H, pos);
            printf("%s", (messageLog.at(i).c_str()));
            pos.Y++;
        }


    }
    else printf("ERROR");
}
