#include <assert.h>
#include <iostream>
using namespace std;

bool isMax(float value,float maxThreshold){
    if(value > maxThreshold){
        return true;
    }
    return false;
}
bool isArgumentsinRange(float value, float min,float max,const string& argument)
{
    if (value < min)
    {
      cout<< argument << "too low.\n";
      return false;
    }
    else if (isMax(value,max)
    {
      cout<< argument << "too high.\n";
      return false;
    }
    return true;
}

bool ChargeRateIsOk(float chargeRate)
{
  if(isMax(chargeRate,0.8)
  {
    cout<<"Charge Rate out of range";
    return false;
  }
  return true;
}
bool batteryIsOk(float temperature, float soc, float chargeRate)
{
  bool temperatureOk = isArgumentsinRange(temperature,0,45,"Temperature ");
  bool socOk = isArgumentsinRange(soc,20,85,"State of charge ");
  bool ChargeRateOk = ChargeRateIsOk(chargeRate);

  return temperatureOk && socOk && ChargeRateOk;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
