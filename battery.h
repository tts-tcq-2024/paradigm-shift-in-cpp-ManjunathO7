#ifndef BATTERY_H
#define BATTERY_H

#include <string>
using namespace std;

struct RangeResult {
    bool inRange;
    string message;
};

void checkWarning(float value, float min, float max, const string& parameter, string& message);
bool isMax(float value, float maxThreshold);
bool isMin(float value, float minThreshold);
RangeResult isParametersinRange(float value, float min, float max, const string& parameter);
RangeResult isChargeRateOk(float chargeRate);

#endif
