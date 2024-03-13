#include "Log.h"

Log::Log(int width, int height) : width(width), height(height)
{

}

int Log::getSize()
{
	return log.size();
}

string Log::at(int index)
{
	return log.at(index);
}

void Log::addLog(string new_log)
{
	int end = 0;
	char* aux_log = new char[width + 1];

	aux_log[0] = '\0';
	for (char c : new_log)
	{
		if (c == '\n')
		{
			aux_log[end] = '\0';
			end = 0;

			while (log.size() >= height)
				log.pop_back();
			log.push_front(string(aux_log));
			continue;
		}

		aux_log[end++] = c;
		if (end == width)
		{
			aux_log[end] = '\0';
			end = 0;
			while (log.size() >= height)
				log.pop_back();
			log.push_front(string(aux_log));
			continue;
		}
	}

	delete[](aux_log);
}
