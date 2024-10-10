#include "battery.h"
#include "battery_check.h"
#include <iostream>
using namespace std;

bool batteryCheck(float temperature, float soc, float chargeRate) {
    RangeResult temperatureResult = isParametersinRange(temperature, 0, 45, "Temperature ");
    RangeResult socResult = isParametersinRange(soc, 20, 80, "State of charge ");
    RangeResult chargeRateResult = isChargeRateOk(chargeRate);

    if (!temperatureResult.message.empty()) cout << temperatureResult.message;
    if (!socResult.message.empty()) cout << socResult.message;
    if (!chargeRateResult.message.empty()) cout << chargeRateResult.message;

    return temperatureResult.inRange && socResult.inRange && chargeRateResult.inRange;
}
