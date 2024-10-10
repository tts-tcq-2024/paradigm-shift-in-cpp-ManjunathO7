#include "battery_check.h"
#include <assert.h>
#include <iostream>
using namespace std;

int main() {
    assert(batteryCheck(25, 70, 0.7) == true);
    assert(batteryCheck(50, 85, 0) == false);

    // Testing State of Charge (SoC) warnings
    batteryCheck(40, 21, 0.7);
    batteryCheck(25, 79, 0.7);

    //// Testing Temperature warnings
    batteryCheck(1, 70, 0.7);
    batteryCheck(44, 70, 0.7);

    // Testing Charge Rate warnings
    batteryCheck(25, 70, 0.76);

     //Edge test cases:
    batteryCheck(40, 25, 0.7);   // SoC slightly above low warning , temperature slightly below high warning

    return 0;
}
