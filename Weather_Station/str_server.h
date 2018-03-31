//str_server.h

#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

class StringServer {
public:
	static map<string, string> translation;
	void getFile();
};