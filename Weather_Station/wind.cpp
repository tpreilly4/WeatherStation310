//wind.cpp

#include "stdafx.h"
#include "wind.h"
#include "valid_input.h"
#include "str_server.h"
#include <string>
#include <sstream>
#include <iostream>
#include <regex>

using namespace std;

// Asks user for windSpeed.
// Loops until valid. Only accepts input of digits between -999 and 999.
wind wind::setWindSpeed()
{
	StringServer obj;
	string validateWindSpeed = "\\d{1,3}";
	string input;
	wind windSpeed;
	windSpeed.speed = 0;
	do {
		cout << obj.translation["<InputWindSpeed>"] << " ";
		cin.ignore();
		cin >> input;
	} while (!valid_input(input, validateWindSpeed));

	stringstream(input) >> windSpeed.speed;
	return windSpeed;
}

// Asks user for temperature.
// Loops until valid. Only accepts input of .
wind wind::setWindDirection()
{
	StringServer obj;
	string validateWindDirection = "[NSEW]|[nsew]|(NE)|(NW)|(SE)|(SW)|(ne)|(nw)|(se)|(sw)";
	string input;
	wind windDirection;
	windDirection.direction = "";
	do {
		cout << obj.translation["<InputWindDirection>"] << " ";
		cin.ignore();
		cin >> input;
	} while (!valid_input(input, validateWindDirection));

	stringstream(input) >> windDirection.direction;
	return windDirection;
}