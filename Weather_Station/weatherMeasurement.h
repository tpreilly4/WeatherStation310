//weatherMeasurement.h

#pragma once

#include "temperature.h"
#include "wind.h"

using namespace std;

class weatherMeasurement {
public:
	wind wm_wind;
	temperature wm_temperature;

	weatherMeasurement toWeatherMeasurement(wind w, temperature t);
};