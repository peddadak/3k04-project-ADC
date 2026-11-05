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
    adcInputHandler.addADC(); // Add an ADC for testing
   int cred =  login.checkLoginCreds(loginID); // Check login credentials
    // Generate a status log report
    Log<int> statusLogReport = logManager.generateStatusLogReport(adcID, loginID, credentials);
    
    // Generate a dashboard
    char userInput = '2'; // Example user input for generating dashboard
    dashboard.generateDashboard(cred, 1, adcID, 0, alarmController, adcInputHandler, userInput);

    return 0;
}