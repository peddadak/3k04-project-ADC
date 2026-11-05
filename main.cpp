#include <iostream>
using namespace std;
#include "Log.h"
#include "LogManager.h"
#include "Dashboard.h"
#include "AlarmController.h"
#include "ADCInputHandler.h"
#include "ADCController.h"
#include "ManualOverride.h"
#include "Login.h"
#include "InputHandler.h"
int main() {
    // Create instances of the necessary classes
    LogManager logManager;
    Dashboard dashboard;
    AlarmController alarmController;
    ADCInputHandler adcInputHandler;
    ADCController adcController;
    ManualOverride manualOverride;
    Login login;
    InputHandler inputHandler;

    // Example usage of the classes
    int adcID = 0; // Example ADC ID
    int loginID = 123; // Example login ID
    int credentials = 1; // Example credentials (1 for valid, -1 for invalid)


    login.addRegisteredID(loginID, credentials); // Add a registered login ID for testing
    login.addRegisteredID(456, 2); // Add another registered login ID for testing
    adcInputHandler.addADC(); // Add an ADC for testing
   int cred =  login.checkLoginCreds(loginID); // Check login credentials
    // Generate a status log report
    logManager.storeLogADC(adcID, 1, "MedicineA", 1234567890, 50); // Store a sample log entry
    logManager.storeLogADC(adcID, 0, "MedicineB", 1234567891, 30); // Store another sample log entry
    //logManager.storeLogADC(adcID, 1, "MedicineC", 1234567892, 20); // Store another sample log entry
    // Log<int> statusLogReport = logManager.generateStatusLogReport(adcID, loginID, credentials);
    alarmController.registerADC(adcID); // Register the ADC with the AlarmController
    if (logManager.generateStatusLogReport(adcID, loginID, cred).getNumOfEntries() > 0) {
        int lastStatus = logManager.generateStatusLogReport(adcID, loginID, cred).getLogEntry(logManager.generateStatusLogReport(adcID, loginID, cred).getNumOfEntries() - 1);
        alarmController.report(adcID, lastStatus); // Report the last status to the AlarmController
    }
    // Generate a dashboard
    char userInput = '1'; // Example user input for generating dashboard
    dashboard.generateDashboard(cred, adcID, 0, alarmController, logManager, userInput, loginID, 1234567890);

    return 0;
}