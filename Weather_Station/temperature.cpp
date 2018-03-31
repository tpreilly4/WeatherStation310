//temperature.cpp

#include "stdafx.h"
#include "temperature.h"
#include "valid_input.h"
#include "str_server.h"
#include <string>
#include <sstream>
#include <iostream>
#include <regex>

using namespace std;

// Asks user for temperature.
// Loops until valid. Only accepts input of digits between -999 and 999.
temperature temperature::setTemperature()
{
	StringServer obj;
	string validateTemperature = "(-?\\d{1,3})";
	string input;
	temperature temp;
	temp.value = 0;

	do {
		cout << obj.translation["<InputTemperature>"] << " ";
		cin.ignore();
		cin >> input;
	} while (!valid_input(input, validateTemperature));

	stringstream(input) >> temp.value;
	return temp;
}