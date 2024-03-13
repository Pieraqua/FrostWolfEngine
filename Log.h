#pragma once

#include <deque>
#include <string>
using namespace std;

class Log
{
	const int width;
	const int height;

	deque<string> log;

public:
	Log(int width, int height);

	// Retorna o numero de mensagens atual do log
	int getSize();

	void clear() { log.clear(); }
	string at(int);
	void addLog(string);
};

