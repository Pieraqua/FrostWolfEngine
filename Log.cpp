#include "Log.h"

Log::Log(int width, int height) : width(width), height(height)
{
	log = new string[height];
	end = 0;
	start = 0;
}

Log::~Log()
{
	delete[] log;
}

int Log::getSize()
{
	return end > start ? end - start : height - start + end;
}

string Log::at(int index)
{
	if (index > getSize()) return "";
	return log[start + index < height ? start + index : end - (getSize() - index)];
}

void Log::addLog(string new_log)
{
	int found_newline = 0;
	while (new_log.find('\n') != -1 || new_log.size() > width) {
		// Erase last in line
		if (end == start) start++;

		found_newline = new_log.find('\n');

		if (found_newline != -1) {
			log[end++] = new_log.substr(0, found_newline);
			new_log = new_log.substr(found_newline + 1, new_log.size() - found_newline);
		}
		else
		{
			found_newline = new_log.substr(0, width).rfind(' ');
			if (found_newline == -1) found_newline = width;
			log[end++] = new_log.substr(0, found_newline);
			new_log = new_log.substr(found_newline + 1, new_log.size() - found_newline);
		}
		// loop
		if (start >= height) start = 0;
		if (end >= height) end = 0;
	}

	// Erase last in line
	if (end == start) start++;
	log[end++] = new_log;
	// loop
	if (start >= height) start = 0;
	if (end >= height) end = 0;
}
