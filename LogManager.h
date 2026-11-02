#ifndef LOGMANAGER
#define LOGMANAGER
#include "Log.h"
    class LogManager{
        public: 
            Log generateLogReport(int adcID, int loginID, int ceredentials); 
            void storeLogADC(int adcId, char medicineLog, int time );
            void storeLogAccess(int adcID, int loginID, int time); 
        private:
            int adcID; 
            int loginID; 
            int time; 
            Log ADCstoredLogs[100];
            


    };  
#endif 