#include "Log.h"
#include <iostream>
using namespace std;
Log::Log(){
    numOfEntries = 0;
}
Log::Log(int adcID, int loginID, int time){
    addLogLoginEntry(adcID, loginID, time);
}
Log::Log(int adcID, int time, char medicineLog){
    addLogMedicineEntry(adcID, time, medicineLog);
}
void Log::addLogLoginEntry(int adcID, int loginID, int time){
    entries[numOfEntries][0] = adcID;
    entries[numOfEntries][2] = loginID;
    entries[numOfEntries][3] = time;
    numOfEntries++;
}
void Log::addLogMedicineEntry(int adcID, int time, char medicineLog){
    entries[numOfEntries][0] = adcID;
    entries[numOfEntries][1] = medicineLog;
    entries[numOfEntries][3] = time;
    numOfEntries++;
}
int* Log::getLogEntry(int index){
    if (index < numOfEntries){
        return entries[index];
    }
    else{
        cout << "Invalid log entry index." << endl;
        return nullptr;
    }
}

    


