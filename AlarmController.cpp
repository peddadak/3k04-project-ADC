#include "AlarmController.h"
#include <iostream>
using namespace std;

  // Registers an ADC with the controller so its reports will be accepted.
  void AlarmController::registerADC(int id){
    registeredADCs.insert(id);
  }

  // Receives a status report from an ADC, stores its ID and status,
  // and updates the alarm accordingly.
  void AlarmController::report(int id, int status){
    adcID = id;
    adcStatus = status;
    toggleAlarm();
  }

  // Turns the alarm flag and display on or off for the reporting ADC
  // based on its status (fault or normal), then updates the controller state.
  void AlarmController::toggleAlarm(){
    // Pre: adcID is in registeredADCs
    if (registeredADCs.count(adcID) == 0) {
      cout << "ADC " << adcID << " is not registered" << endl;
      return;
    }
    // Post: adcStatus = 0 (fault)  => alarm flag on,  shown on display
    //       adcStatus = 1 (normal) => alarm flag off, not shown
    if (adcStatus == FAULT) {
      alarmFlag[adcID] = 1;
      adcDisplay[adcID] = true;
    } else if (adcStatus == NORMAL) {
      alarmFlag[adcID] = 0;
      adcDisplay[adcID] = false;
    } else {
      cout << "Invalid status " << adcStatus << " from ADC " << adcID << endl;
      return;
    }
    // Keep the state in sync with the flags (invariant)
    toggleMode();
  }

  // Checks all ADCs and sets alarmDetected if any of them has an active alarm.
  void AlarmController::testAlarm(){
    // Detect whether any ADC has an active alarm
    alarmDetected = false;
    for (auto const& flag : alarmFlag) {
      if (flag.second == 1) {
        alarmDetected = true;
        cout << "Alarm detected from ADC " << flag.first << endl;
      }
    }
  }

  // Switches the controller between AlarmTrigger and Idle depending on
  // whether any alarm is currently active.
  void AlarmController::toggleMode(){
    // Pre: adcID is in registeredADCs
    if (registeredADCs.count(adcID) == 0) {
      return;
    }
    // Post: some alarm flag = 1 => state = AlarmTrigger
    //       all alarm flags = 0 => state = Idle
    testAlarm();
    if (alarmDetected) {
      state = State::AlarmTrigger;
    } else {
      state = State::Idle;
    }
    cout << "Alarm state: " << (state == State::AlarmTrigger ? "AlarmTrigger" : "Idle") << endl;
  }

  AlarmController::State AlarmController::getState() const {
    return state;
  }

  bool AlarmController::isAlarmActive(int id) const {
    auto it = alarmFlag.find(id);
    return it != alarmFlag.end() && it->second == 1;
  }

  bool AlarmController::isDisplayed(int id) const {
    auto it = adcDisplay.find(id);
    return it != adcDisplay.end() && it->second;
  }

  bool AlarmController::getAlarmDetected() const {
    return alarmDetected;
  }