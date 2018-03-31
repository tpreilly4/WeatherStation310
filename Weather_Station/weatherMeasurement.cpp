//weatherMeasurement.cpp

#include "stdafx.h"
#include "weatherMeasurement.h"
#include "wind.h"
#include "temperature.h"

using namespace std;

// Loads weather measurement objects (@params wind and temperature) into a single object, weatherMeasurement.
// Returns that.
weatherMeasurement weatherMeasurement::toWeatherMeasurement(wind wind, temperature temp) 
{
	weatherMeasurement newWeatherMeasurement;
	newWeatherMeasurement.wm_wind = wind;
	newWeatherMeasurement.wm_temperature = temp;

	return(newWeatherMeasurement);
}