#include "Utils.h"

string Utils::to_lower(string str)
{
    string ans = "";
    for (int i = 0; i < str.length(); i++)
        ans.push_back(tolower(str.at(i)));
    return ans;
}
