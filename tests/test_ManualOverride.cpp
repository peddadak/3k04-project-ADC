// Standalone test driver for the Manual Override module.
// Build: g++ -std=c++17 -I.. ../ManualOverride.cpp test_ManualOverride.cpp -o test_ManualOverride
#include "ManualOverride.h"
#include <iostream>
using namespace std;

static int passed = 0;
static int failed = 0;

static void check(bool condition, const char* name) {
    if (condition) {
        passed++;
        cout << "[PASS] " << name << endl;
    } else {
        failed++;
        cout << "[FAIL] " << name << endl;
    }
}

int main() {
    // Initial state
    {
        ManualOverride mo;
        check(mo.getADCMode(1) == ManualOverride::OFF, "unknown ADC defaults to OFF");
        check(!mo.isAlarmOverridden(), "alarm override starts OFF");
    }

    // Valid ADC toggles
    {
        ManualOverride mo;
        mo.toggleManualOverrideADC(1, ManualOverride::ON);
        check(mo.getADCMode(1) == ManualOverride::ON, "ADC 1 set to ON");
        mo.toggleManualOverrideADC(1, ManualOverride::OFF);
        check(mo.getADCMode(1) == ManualOverride::OFF, "ADC 1 set back to OFF");
    }

    // ADCs are independent
    {
        ManualOverride mo;
        mo.toggleManualOverrideADC(1, ManualOverride::ON);
        check(mo.getADCMode(2) == ManualOverride::OFF, "setting ADC 1 does not affect ADC 2");
    }

    // Invalid mode is rejected and state is unchanged (precondition)
    {
        ManualOverride mo;
        mo.toggleManualOverrideADC(3, ManualOverride::ON);
        mo.toggleManualOverrideADC(3, 5);
        check(mo.getADCMode(3) == ManualOverride::ON, "invalid mode 5 leaves ADC 3 unchanged");
        mo.toggleManualOverrideADC(4, -1);
        check(mo.getADCMode(4) == ManualOverride::OFF, "invalid mode -1 on new ADC leaves it OFF");
    }

    // Alarm toggle flips each call
    {
        ManualOverride mo;
        mo.toggleManualOverrideAlarm();
        check(mo.isAlarmOverridden(), "first alarm toggle -> ON");
        mo.toggleManualOverrideAlarm();
        check(!mo.isAlarmOverridden(), "second alarm toggle -> OFF");
    }

    // Alarm and ADC overrides don't interfere
    {
        ManualOverride mo;
        mo.toggleManualOverrideAlarm();
        check(mo.getADCMode(1) == ManualOverride::OFF, "alarm toggle does not affect ADC modes");
        mo.toggleManualOverrideADC(1, ManualOverride::ON);
        check(mo.isAlarmOverridden(), "ADC toggle does not affect alarm override");
    }

    cout << endl << passed << " passed, " << failed << " failed" << endl;
    return failed == 0 ? 0 : 1;
}
