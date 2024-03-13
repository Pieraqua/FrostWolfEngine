#include "ViewportOutput.h"


void ViewportOutput::printViewports()
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

void ViewportOutput::printLogo()
{
    FILE* viewport;
    fopen_s(&viewport, FROSTWOLFLOGO_FILE, "r");
    char s[1024];

    HANDLE      H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(H, { 0,0 });

    if (viewport)
    {
        while ((fgets(s, sizeof s, viewport)) != NULL) {
            printf("%s", s);
        }

    }
    else printf("ERROR");
}

void ViewportOutput::setMainViewport(const char* imagePath)
{
    strcpy_s(mainImagePath, imagePath);
}

ViewportOutput* ViewportOutput::getInstance()
{
    if (systemOutputModule == NULL)
        systemOutputModule = new ViewportOutput();

    return (ViewportOutput*)systemOutputModule;
}

void ViewportOutput::printMainViewport()
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

void ViewportOutput::printUserCommands()
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

void ViewportOutput::printLog(COORD pos)
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


void ViewportOutput::printToLog(string data)
{
    messageLog.addLog(data);
}


ViewportOutput::ViewportOutput() : messageLog(23,19), SystemOutput()
{
    setMainViewport(MAIN_VIEWPORT_FILE);
}