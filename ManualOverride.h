#ifndef MANUAL_OVERRIDE_H
#define MANUAL_OVERRIDE_H

#include <map>

// Module: Manual Override
// Secret: how override settings are stored.
class ManualOverride {
public:
    static const int OFF = 0;   // ADC runs normally
    static const int ON  = 1;   // ADC under manual override

    void toggleManualOverrideADC(int adcID, int mode);
    void toggleManualOverrideAlarm();

    int getADCMode(int adcID) const;
    bool isAlarmOverridden() const;

private:
    std::map<int, int> adcMode;     // override mode for each ADC
    bool alarmOverride = false;     // true = alarm manually silenced
};

#endif