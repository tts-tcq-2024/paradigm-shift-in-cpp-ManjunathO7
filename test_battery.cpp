#include "battery_check.h"
#include <assert.h>
#include <iostream>
using namespace std;

int main() {
    assert(batteryCheck(25, 70, 0.7) == true);
    assert(batteryCheck(50, 85, 0) == false);

    // Testing State of Charge (SoC) warnings
    batteryCheck(40, 21, 0.7); //soc is approaching discharge limit
    batteryCheck(25, 79, 0.7); //soc is approaching peak-charge limit
    batteryCheck(30, 81, 0.7); //soc out of range

    // Testing Temperature warnings
    batteryCheck(1, 70, 0.7); //Temperature is approaching discharge limit
    batteryCheck(44, 70, 0.7); //Temperature is approaching peak-charge limit
    batteryCheck(47, 70, 0.7); //Temperature out of range

    // Testing Charge Rate warnings
    batteryCheck(25, 70, 0.9); //ChargeRate out of range.
    batteryCheck(25, 70, 0.78); // Charge Rate approaching peak-charge limit
    batteryCheck(25, 70, -1);  //no warnings

     //Edge test cases:
    batteryCheck(40, 25, 0.7);   // SoC slightly above low warning , temperature slightly below high warning

    return 0;
}
