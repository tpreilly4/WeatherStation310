//valid_input.cpp

#include "stdafx.h"
#include "valid_input.h"
#include <string>
#include <sstream>
#include <iostream>
#include <regex>

using namespace std;

// Validates input using regular expressions
// Params accepting user input and it's respective validation regex in the function call
bool valid_input(string input, string validation)
{
	const char* test = input.c_str();
	regex re(validation);
	cmatch match;
	if (regex_match(test, match, re))
		return true;
	else
		return false;
}