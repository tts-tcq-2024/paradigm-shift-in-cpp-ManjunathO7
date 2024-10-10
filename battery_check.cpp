#include "battery.h"
#include "battery_check.h"
#include <iostream>
using namespace std;

bool batteryCheck(float temperature, float soc, float chargeRate) {
    RangeResult temperatureResult = isParametersinRange(temperature, 0, 45, "Temperature ");
    RangeResult socResult = isParametersinRange(soc, 20, 80, "State of charge ");
    RangeResult chargeRateResult = isChargeRateOk(chargeRate);
    
    printWarnings(temperatureResult, socResult, chargeRateResult);
    
    return temperatureResult.inRange && socResult.inRange && chargeRateResult.inRange;
}

void printWarnings(const RangeResult& temperatureResult, const RangeResult& socResult, const RangeResult& chargeRateResult) {
    if (!temperatureResult.message.empty()) {
        cout << temperatureResult.message;
    }
    if (!socResult.message.empty()) {
        cout << socResult.message;
    }
    if (!chargeRateResult.message.empty()) {
        cout << chargeRateResult.message;
    }
}
