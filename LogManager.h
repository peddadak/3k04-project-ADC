#ifndef LOGMANAGER
#define LOGMANAGER
#include "Log.h"
    class LogManager{
        public: 
            void generateLogReport(int adcID, int loginID); 
            void storeLogADC(int adcId, char medicineLog, int time );
            void storeLogAccess(int adcID, int loginID, int time); 
        private:
            int adcID; 
            int loginID; 
            int time; 
            Log storedLogs[100];
            


    };  
#endif 