//str_server.cpp

#include "stdafx.h"
#include <string>
#include <map>
#include <regex>
#include "valid_input.h"
#include "str_server.h"

using namespace std;
map<string, string> StringServer::translation;

void StringServer::getFile() {
	string s;
	string inputChoice;
	int choice = 0;
	ifstream file;
	
	// Control loop asking user to choose a language.
	do 
	{
		cout << "1: English \n2: Pig Latin \nPlease enter 1 or 2: ";
		getline(cin, inputChoice);
		stringstream(inputChoice) >> choice;
	}while (choice != 1 && choice != 2);

	system("CLS");

	// Switch statement adds file to stream.
	switch (choice)
	{
	// Case 1 handles a user choice of English. The file containing English map (eng.txt) will be opened here.
	case 1:
		system("CLS");
		file.open("eng.txt");
		if (file.fail())
		{
			cout << "Cannot open file." << endl;
		}
		break;
	// Case 2 handles a user choice of Pig Latin. The file containing Pig Latin map (piglat.txt) will be opened here.
	case 2:
		file.open("piglat.txt");
		if (file.fail())
		{
			cout << "Cannot open file." << endl;
		}
		break;
	// The default case should never be reached, but was left here just in case.
	default:
		cout << "Error in switch getFile() statement";
		break;
	}

	/*
	 * While the file is accessible by the stream, read its lines.
	 * If the end of the file is reached, close it and clear the stream.
	 * In the file, look for a key, which is a substring of a line in the form: <key>~ 
	 * Everything after that key but before the next line is stored in translation[], 
	 * with an index equal to its key. 
	 */
	while (file.good()) 
	{
		if (file.eof())
		{
			file.close();
			file.clear();
			break;
		}

		getline(file, s);
		string key = s.substr(0, s.find("~"));
		string value = s.substr(s.find("~") + 1);
		translation[key] = value;
	}
}