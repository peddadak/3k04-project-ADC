#include "LogManager.h"
#include <iostream>
using namespace std;
Log<int> LogManager::generateLogReport(int adcID, int loginID, int credentials){
   if (credentials != 0){
        return ADCstoredLogs[adcID][0];
    }
    else{
            cout << "Invalid credentials. Cannot generate log report." << endl;
            return ADCstoredLogs[0][0]; // Return an empty log or handle the error as needed
    }
    
}

Log<char*> LogManager::generateMedicineLogReport(int adcID, int loginID, int credentials){
   if (credentials != 0){
        return ADCstoredMedicineLogs[adcID][0];
    }
    else{
            cout << "Invalid credentials. Cannot generate log report." << endl;
            return ADCstoredMedicineLogs[0][0]; // Return an empty log or handle the error as needed
    }
    
}

void LogManager::storeLogADC(int adcId, int status, char* medicineID, int time, int inventory){
    ADCstoredLogs[adcId][0].addLogEntry(status);
    ADCstoredLogs[adcId][1].addLogEntry(inventory);
    ADCstoredLogs[adcId][2].addLogEntry(time);
    ADCstoredLogs[adcId][3].addLogEntry(-1);
    ADCstoredMedicineLogs[adcId][0].addLogEntry(medicineID);
}


void LogManager::storeLogAccess(int adcID, int loginID, int time){
    ADCstoredLogs[adcID][0].addLogEntry(-1);
    ADCstoredLogs[adcID][1].addLogEntry(-1);
    ADCstoredLogs[adcID][2].addLogEntry(time);
    ADCstoredLogs[adcID][3].addLogEntry(loginID);
}