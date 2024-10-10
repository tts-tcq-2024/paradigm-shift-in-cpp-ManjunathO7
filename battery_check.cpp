#include "battery.h"
#include "battery_check.h"
#include <iostream>
using namespace std;

bool batteryCheck(float temperature, float soc, float chargeRate) {
    RangeResult temperatureResult = isParametersinRange(temperature, 0, 45, "Temperature ");
    RangeResult socResult = isParametersinRange(soc, 20, 80, "State of charge ");
    RangeResult chargeRateResult = isChargeRateOk(chargeRate);
    
    printTemperatureWarning(temperatureResult);
    printSocWarning(socResult);
    printChargeRateWarning(chargeRateResult);

    return temperatureResult.inRange && socResult.inRange && chargeRateResult.inRange;
}
void printTemperatureWarning(const RangeResult& temperatureResult){
    if (!temperatureResult.message.empty()) {
        cout << temperatureResult.message;
    }
}
void printSocWarning(const RangeResult& socResult){
    if (!socResult.message.empty()) {
        cout << socResult.message;
    }
}
void printChargeRateWarning(const RangeResult& chargeRateResult)
{
    if (!chargeRateResult.message.empty()) {
        cout << chargeRateResult.message;
    }
}
