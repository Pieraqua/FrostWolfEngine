#include "SystemInput.h"


SystemInput* SystemInput::systemInputModuleSingleton = nullptr;

SystemInput* SystemInput::getInstance()
{
	if (systemInputModuleSingleton == nullptr)
		systemInputModuleSingleton = new SystemInput();

	return systemInputModuleSingleton;
}

vector<string> SystemInput::getUserInput()
{
	vector<string> ans;
	char user_ans_char[90];
	string current_ans;
	int pos = 0;

	cin.getline(user_ans_char, 90);
	current_ans = user_ans_char;

	if (user_ans_char[0] == '\n')
		return ans;

	while (pos != -1)
	{
		pos = current_ans.find(' ');


		if (pos == current_ans.size())
		{
			ans.push_back(current_ans);
		}
		else if (pos != -1 && pos != 0)
		{
			ans.push_back(current_ans.substr(0, pos));
			current_ans = current_ans.substr(pos + 1, current_ans.size() - pos);
		}
		else if (pos == 0)
		{
			if (current_ans.size() > 0)
			{
				break;
			}
			else
			{
				current_ans = current_ans.substr(1, current_ans.size() - 1);
			}
		}
		else if (pos == -1 && current_ans.size() > 0)
		{
			ans.push_back(current_ans);
		}
	}

#ifdef _DEBUG_INPUT
	for (unsigned int i = 0; i < ans.size(); i++)
	{
		string debug_msg = "SystemInput - getUserInput - " + to_string(i) + ": " + ans.at(i);
		SystemOutput::getInstance()->printToConsole(debug_msg, SystemOutput::outputLevel::DEBUG);
	}
#endif
	return ans;
}

char SystemInput::getKeyPressed()
{
	return _getch();
}

SystemInput::SystemInput()
{
}
