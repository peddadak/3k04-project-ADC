#include "LogManager.h"
#include <iostream>
using namespace std;
Log LogManager::generateLogReport(int adcID, int loginID, int credentials){
   if (credentials != 0){
        return ADCstoredLogs[adcID];
    }
    else{
            cout << "Invalid credentials. Cannot generate log report." << endl;
            return Log();
    }
    
}

    


