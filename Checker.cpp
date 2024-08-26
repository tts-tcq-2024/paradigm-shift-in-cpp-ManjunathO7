#include <assert.h>
#include <iostream>
using namespace std;

bool isArgumentsinRange(float value, float min,float max,const string& argument)
{
    if (value < min)
    {
      cout<< argument << "too low.\n";
      return false;
    }
    else if (value > max)
    {
      cout<< argument << "too high.\n";
      return false;
    }
    return true;
}

bool ChargeRateIsOk(float chargeRate)
{
  if(chargeRate>0.8)
  {
    cout<<"Charge Rate out of range";
    return false;
  }
  return true;
}
bool batteryIsOk(float temperature, float soc, float chargeRate)
{
  bool temperatureOk = isArgumentsinRange(temperature,0,45,"Temperature ");
  bool socOk = isArgumentsinRange(soc,0,45,"Soc ");
  bool ChargeRateOk = ChargeRateIsOk(chargeRate);

  return temperatureOk && socOk && ChargeRateOk;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
