//wind.h

#pragma once
#include "stdafx.h"
#include <string>

using namespace std;

class wind{
public:
	float speed;
	string direction;

	wind setWindSpeed();
	wind setWindDirection();
};
