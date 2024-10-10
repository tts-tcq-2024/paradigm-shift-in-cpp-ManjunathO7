#include "battery.h"
#include <iostream>
using namespace std;

bool isMax(float value, float maxValue) { return value > maxValue; }
bool isMin(float value, float minValue) { return value < minValue; }
bool findLowThreshold(float value, float min, float tolerance){ return value > min&& value <= min + tolerance; }
bool findHighThreshold(float value, float max, float tolerance) { return value >= max - tolerance && value < max; }

void checkWarning(float value, float min, float max, const string& argument, string& message) {
    float tolerance = 0.05 * max;
    bool low_threshold = findLowThreshold(value, min, tolerance);
    bool max_threshold = findHighThreshold(value, max, tolerance);
    if (low_threshold) {
        message += "Warning: " + argument + " approaching discharge imit.\n";
    }
    else if (max_threshold) {
        message += "Warning: " + argument + " approaching peak-charge limit.\n";
    }
}

RangeResult isParametersinRange(float value, float min, float max, const string& argument) {
    RangeResult result;
    result.inRange = true;
    result.message = "";
    checkWarning(value, min, max, argument, result.message);
    if (isMin(value, min)) {
        result.message += argument + " too low.\n";
        result.inRange = false;
    }
    else if (isMax(value, max)) {
        result.message += argument + " too high.\n";
        result.inRange = false;
    }
    return result;
}

RangeResult isChargeRateOk(float chargeRate) {
    RangeResult result;
    result.inRange = true;
    result.message = "";
    checkWarning(chargeRate, 0, 0.8, "Charge Rate ", result.message);
    if (isMax(chargeRate, 0.8)) {
        result.message += "Charge Rate out of range.\n";
        result.inRange = false;
    }
    return result;
}
