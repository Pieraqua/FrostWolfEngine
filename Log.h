#pragma once

#include <deque>
#include <string>
using namespace std;

// ringbuffer log implementation
class Log
{
	const int width;
	const int height;
	int start;
	int end;

	string* log;

public:
	Log(int width, int height);
	~Log();

	// Return current amount of messages in log
	int getSize();

	void clear() { end = start; }
	string at(int);
	void addLog(string);
};

