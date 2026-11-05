// Interactive driver for the Manual Override module: type commands to call it by hand.
// Build: g++ -std=c++17 -I.. ../ManualOverride.cpp interactive_ManualOverride.cpp -o interactive_ManualOverride
#include "ManualOverride.h"
#include <iostream>
#include <string>
using namespace std;

static void printHelp() {
    cout << "Commands:" << endl
         << "  alarm              toggle the alarm override" << endl
         << "  adc <id> <mode>    set ADC override (mode 0 = OFF, 1 = ON)" << endl
         << "  status <id>        show override mode of one ADC" << endl
         << "  alarmstatus        show whether the alarm is overridden" << endl
         << "  help               show this list" << endl
         << "  quit               exit" << endl;
}

int main() {
    ManualOverride mo;
    string cmd;

    printHelp();
    while (true) {
        cout << "> ";
        if (!(cin >> cmd) || cmd == "quit") {
            break;
        }

        if (cmd == "alarm") {
            mo.toggleManualOverrideAlarm();
        } else if (cmd == "adc") {
            int id, mode;
            if (cin >> id >> mode) {
                mo.toggleManualOverrideADC(id, mode);
            } else {
                cout << "Usage: adc <id> <mode>" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
        } else if (cmd == "status") {
            int id;
            if (cin >> id) {
                cout << "ADC " << id << " mode = "
                     << (mo.getADCMode(id) == ManualOverride::ON ? "ON" : "OFF") << endl;
            } else {
                cout << "Usage: status <id>" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
        } else if (cmd == "alarmstatus") {
            cout << "Alarm override = " << (mo.isAlarmOverridden() ? "ON (silenced)" : "OFF") << endl;
        } else if (cmd == "help") {
            printHelp();
        } else {
            cout << "Unknown command: " << cmd << " (type help)" << endl;
        }
    }
    return 0;
}
