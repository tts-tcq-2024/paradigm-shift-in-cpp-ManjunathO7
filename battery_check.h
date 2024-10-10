#ifndef BATTERY_CHECK_H
#define BATTERY_CHECK_H

#include <string>
#include "battery.h"
using namespace std;

bool batteryCheck(float temperature, float soc, float chargeRate);
void printTemperatureWarning(const RangeResult& temperatureResult);
void printSocWarning(const RangeResult& socResult);
void printChargeRateWarning(const RangeResult& chargeRateResult);

#endif
