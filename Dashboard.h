#ifndef DASHBOARD
#define DASHBOARD
#include "AlarmController.h"
#include "LogManager.h"
    class Dashboard{
        public: 
             void generateDashboard (bool credentials, int adcStatus, int adcID, int ADCMode, AlarmController& alarmStatus, LogManager& adcInput, char userInput, int LoginID);
        private:
          bool credentials; 


    };  
#endif 