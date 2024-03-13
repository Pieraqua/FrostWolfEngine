#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <conio.h>
using namespace std;

#include "SystemOutput.h"
#include "config.h"

class SystemInput
{
public:
	static SystemInput* getInstance();

	void pause() { cin.ignore(); };
	// Retorna os comandos digitados pelo usuario
	 vector<string> getUserInput();
	 // Retorna a proxima tecla que o usuario apertar
	 char getKeyPressed();

protected:
	SystemInput();
	static SystemInput* systemInputModuleSingleton;
};

