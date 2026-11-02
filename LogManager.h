#ifndef LOGMANAGER
#define LOGMANAGER
    class LogManager{
        public: 
            LogManager(int adcID, int loginID); 
        private:
            int adcID; 
            int loginID; 
            int registeredIDs[100][2];


    };  
#endif 