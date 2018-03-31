//valid_input.h

#pragma once
#include "stdafx.h"
#include <string>

using namespace std;

class valid {
public:
	string input;
	string validation;
};

bool valid_input(string input, string validation);