#ifndef BATTERY_CHECK_H
#define BATTERY_CHECK_H

#include <string>
#include "battery.h"
using namespace std;

bool batteryCheck(float temperature, float soc, float chargeRate);
void printWarnings(const RangeResult& temperatureResult, const RangeResult& socResult, const RangeResult& chargeRateResult);

#endif
