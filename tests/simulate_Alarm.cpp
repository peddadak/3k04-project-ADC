// Alarm simulator: stands in for the physical ADCs by sending fake status reports.
// Build: g++ -std=c++17 -I.. ../AlarmController.cpp ../InputHandler.cpp simulate_Alarm.cpp -o simulate_Alarm
#include "AlarmController.h"
#include "InputHandler.h"
#include <iostream>
using namespace std;

static const int SIM_ADC = 1;   // ADC the simulated reports come from

static void printHelp() {
    cout << "Simulated ADC " << SIM_ADC << ":" << endl
         << "  9  trigger alarm (ADC reports FAULT)" << endl
         << "  0  clear alarm   (ADC reports NORMAL)" << endl
         << "  s  show alarm state" << endl
         << "  h  show this list" << endl
         << "  q  quit" << endl;
}

int main() {
    AlarmController alarm;
    InputHandler input;
    alarm.registerADC(SIM_ADC);

    printHelp();
    while (true) {
        cout << "> ";
        char c = input.getInput();
        if (!cin || c == 'q') {
            break;
        }

        if (c == '9') {
            alarm.report(SIM_ADC, AlarmController::FAULT);
        } else if (c == '0') {
            alarm.report(SIM_ADC, AlarmController::NORMAL);
        } else if (c == 's') {
            cout << "State: " << (alarm.getState() == AlarmController::State::AlarmTrigger ? "AlarmTrigger" : "Idle")
                 << ", ADC " << SIM_ADC << " alarm " << (alarm.isAlarmActive(SIM_ADC) ? "ON" : "OFF")
                 << ", displayed " << (alarm.isDisplayed(SIM_ADC) ? "yes" : "no") << endl;
        } else if (c == 'h') {
            printHelp();
        } else {
            cout << "Unknown input: " << c << " (type h)" << endl;
        }
    }
    return 0;
}
