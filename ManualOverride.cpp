#include "ManualOverride.h"
#include <iostream>
using namespace std;
     void ManualOverride::toggleManualOverrideADC(int adcID, int mode){
        // Pre: mode is OFF (0) or ON (1)
        if (mode != OFF && mode != ON) {
           cout << "Invalid override mode " << mode << " for ADC " << adcID << endl;
           return;
        }
        // Post: adcMode[adcID] = mode
        adcMode[adcID] = mode;
        cout << "ADC " << adcID << " manual override " << (mode == ON ? "ON" : "OFF") << endl;
     }
     void ManualOverride::toggleManualOverrideAlarm(){
        // Post: alarmOverride' = not alarmOverride
        alarmOverride = !alarmOverride;
        cout << "Alarm manual override " << (alarmOverride ? "ON (silenced)" : "OFF") << endl;
     }
     int ManualOverride::getADCMode(int adcID) const {
        if (adcMode.count(adcID) > 0) {
           return adcMode.at(adcID);
        }
        return OFF;
     }
     bool ManualOverride::isAlarmOverridden() const {
        return alarmOverride;
     }