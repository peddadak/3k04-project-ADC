#ifndef ALARM_CONTROLLER_H
#define ALARM_CONTROLLER_H

#include <map>
#include <set>

// Module: Alarm Controller
// Secret: how alarm flags are stored and how the alarm state is decided.
class AlarmController {
public:
    enum class State { Idle, AlarmTrigger };

    // ADC status encoding: fault (0), normal (1)
    static const int FAULT  = 0;
    static const int NORMAL = 1;

    // Setup: add an ADC to the list of registered ADCs
    void registerADC(int id);

    // Called by the ADC Input Handler when an ADC reports its status
    void report(int id, int status);

    void toggleAlarm();
    void testAlarm();
    void toggleMode();

    // Read-only access for other modules (e.g. Dashboard)
    State getState() const;
    bool isAlarmActive(int id) const;
    bool isDisplayed(int id) const;
    bool getAlarmDetected() const;

private:
    int adcStatus = NORMAL;           // 0 = fault, 1 = normal
    int adcID = 0;                    // which ADC is reporting
    std::set<int> registeredADCs;     // valid ADC IDs
    std::map<int, int> alarmFlag;     // alarm_flag[ADCid]
    std::map<int, bool> adcDisplay;   // adc_Display[ADCid]
    bool alarmDetected = false;       // set by testAlarm()
    State state = State::Idle;        // Idle or AlarmTrigger
};

#endif