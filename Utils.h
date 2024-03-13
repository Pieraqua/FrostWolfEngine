#pragma once
#include <cstdlib>
#include <string>
using namespace std;

class Utils
{
public:
	static void set_rand_seed(unsigned int seed) { srand(seed); }
	// Rolls a x-sided die
	static int rolldx(int x) { return rand() % x; }	
	static string to_lower(string str);
	static char to_lower(char c);
};

