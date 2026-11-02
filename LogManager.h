#ifndef LOGMANAGER
#define LOGMANAGER
#include "ADCInputHandler.h"
    class LogManager{
        public: 
            void generateLogReport(int adcID, int loginID); 
            void storeLogADC(int adcId, char medicineLog, int time );
            void storeLogAccess(int adcID, int loginID, int time); 
        private:
            int adcID; 
            int loginID; 
            int time; 
            int registeredIDs[100][2];


    };  
#endif 