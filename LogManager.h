#ifndef LOGMANAGER
#define LOGMANAGER
#include "Log.h"
    class LogManager{
        public: 
            Log<int> generateLogReport(int adcID, int loginID, int ceredentials); 
            Log<char*> generateMedicineLogReport(int adcID, int loginID, int credentials);
            void storeLogADC(int adcId, int status, char* medicineID, int time, int inventory);
            void storeLogAccess(int adcID, int loginID, int time); 
        private:
            int adcID; 
            int loginID; 
            int time; 
            Log<int> ADCstoredLogs[100][4];// 0 = status, 1 = inventory, 2 = time, 3 = loginID
            Log<char*> ADCstoredMedicineLogs[100][1];// 0 = medicineID
            


    };  
#endif 