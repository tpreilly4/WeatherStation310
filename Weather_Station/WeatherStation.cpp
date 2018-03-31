//  WeatherStation.cpp : A simple weather station, relying mainly on user input for stats.
//	As per project 9, support for multiple languages (English, Pig Latin) has been added.
//	
//	Tom Reilly
//	CS 310 01
//	Project 8

#include "stdafx.h"
#include <string>
#include <sstream>
#include <iostream>
#include <regex>
#include "temperature.h"
#include "valid_input.h"
#include "wind.h"
#include "weatherMeasurement.h"
#include "str_server.h"
using namespace std;

// Returns an int 'historyLength' which indicates how long the history array of weatherMeasurements 
// in main will be. The user is prompted for this integer after compiling.
int setHistoryArrayLength()
{
	StringServer obj;

	int historyLength;
	string inputHistoryLength;
	string validateLength = "\\d{0,6}";

	// Prompts user for 'historyLength' value. 
	// Loops until input is valid. Must be a digit. Can not exceed 999999 and can not be less than 0.
	do {
		cout << obj.translation["<HistoryLengthPrompt1>"] << endl;
		cout << obj.translation["<HistoryLengthPrompt2>"] << " ";
		cin >> inputHistoryLength;
	} while (!valid_input(inputHistoryLength, validateLength));

	stringstream(inputHistoryLength) >> historyLength;
	system("CLS");

	return (historyLength);
}

// Asks user to name the weather station, returns it. No input validation required.
string setName()
{
	StringServer obj;
	obj.getFile();
	string name;
	cout << obj.translation["<NamePrompt1>"] << endl;
	cout << obj.translation["<NamePrompt2>"] << " ";
	getline(cin, name);
	cout << endl;
	system("CLS");
	return(name);
}

// Displays a text-based menu for the user to read. Gives the user options for 'menuChoice'.
// Loops until input is valid. Only allows for input of '1', '2', '3', or '4'. Returns user's selection via 'menuChoice'.
int menu(string stationName) {

	StringServer obj;
	string inputMenuChoice;
	int menuChoice;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << obj.translation["<WelcomeMessage1>"] << endl << endl;
	cout << obj.translation["<WelcomeMessage2>"] << stationName << obj.translation["<WelcomeMessage2.5>"] << endl;
	cout << obj.translation["<WelcomeMessage3>"] << endl << endl;
	cout << obj.translation["<DisplayMenu1>"] << endl;
	cout << obj.translation["<DisplayMenu2>"] << endl;
	cout << obj.translation["<DisplayMenu3>"] << endl;
	cout << obj.translation["<DisplayMenu4>"] << endl << endl;

	do {
		cout << obj.translation["<InputMenuChoice>"] << " ";
		cin >> inputMenuChoice;
	} while (!valid_input(inputMenuChoice, "[1234]"));

	stringstream(inputMenuChoice) >> menuChoice;

	return(menuChoice);
}

int main()
{
	StringServer obj;
	// Boring value initializations.
	temperature t;
	t.value = NULL;
	wind w;

	// Sets the name of the weather station through the setName function.
	string stationName = setName();

	// Creates and populates dynamic history array of length 'historyLength', which is input by the user
	// via the setHistoryArrayLength function.
	// Starts a place-holding variable 'historyIndex' at 0 which is used to access elements of the array.
	weatherMeasurement* history = NULL;
	int historyLength = setHistoryArrayLength();
	int historyIndex = 0;
	history = new weatherMeasurement[historyLength];
	// Generates array of user-defined size 'historyLength' using empty weatherMeasurement values.
	for (int i = 0; i < historyLength; i++) 
	{
		history[i] = history[i].toWeatherMeasurement(w,t);
	}

	int menuChoice = 0;
	// Do-while loop initiates and loops menu interface until 4 is input.
	do
	{
		//passes stationName for cosmetic purposes. 
		menuChoice = menu(stationName);

		/*	Switch statement allows for functional text-controlled menu.
		An input value of '1' allows for inputting weather stats.
		An input value of '2' prints input weather stats. If none have been entered, program will suggest doing so and break to menu.
		An input value of '3' prints the 4 preceding weather stats, from most recent to oldest.
		An input value of '4' closes the program by failing to satisfy do-while condition.
		All other input values ask for a retry using either 1, 2, or 3. */
		switch (menuChoice)
		{
		case 1:
			system("CLS");
			// Check if input will exceed array space. If it does, shift elements down and leave last index empty.
			// Not an if-else because we still want the new input values to be added to the history array after shifting elements.
			if (historyIndex > historyLength - 1)
			{
				for (int k = 0; k < historyLength - 1; k++)
				{
					history[k] = history[k + 1];
				}
				history[historyLength - 1].wm_temperature.value = NULL;
				historyIndex--;
			}
			// Re-populate history array at historyIndex with user inputted values. Increment historyIndex.
			t = t.setTemperature();
			history[historyIndex].wm_temperature.value = (t.value);

			w.speed = w.setWindSpeed().speed;
			history[historyIndex].wm_wind.speed = (t.value);

			w.direction = w.setWindDirection().direction;
			history[historyIndex].wm_wind.direction = w.direction;

			historyIndex++;

			system("CLS");
			break;

		case 2:
			// Checks if there were any inputs. It is sufficient to check only the temperature value 
			// of the history array since temperature values must be input with wind values concurrently.
			if (t.value != NULL)
			{	
				system("CLS");
				cout << obj.translation["<DisplayCurrentWeather1>"] << " " << t.value << obj.translation["<DisplayCurrentWeather1.5>"] << endl;
				cout << obj.translation["<DisplayCurrentWeather2>"] << " " << w.speed << " MPH " << w.direction << ".\n\n";
				break;
			}
			else
			{
				system("CLS");
				cout << obj.translation["<NoInputFound>"] << endl << endl;
				break;
			}

		case 3:
			system("CLS");
			cout << obj.translation["<DisplayWeatherHistory1>"] << " " << historyLength << endl << endl;

			// For-loop iterates through history array and prints each value in the order they were input.
			for (int i = historyLength - 1; i >= 0; i--)
			{
				if (history[i].wm_temperature.value != NULL)
				{
					cout << obj.translation["<DisplayWeatherHistory2>"] << " " << i + 1 << endl;
					cout << obj.translation["<DisplayWeatherHistory3>"] << " " << history[i].wm_temperature.value << endl;
					cout << obj.translation["<DisplayWeatherHistory4>"] << " " << history[i].wm_wind.speed << endl;
					cout << obj.translation["<DisplayWeatherHistory5>"] << " " << history[i].wm_wind.direction << endl;
					cout << endl;
				}
			}
			break;

		default:
			cout << obj.translation["<DisplayWeatherHistory5>"] << endl << endl;
			break;
		}

	} while (menuChoice != 4); //quit when menuChoice = 4

	return 0;
}