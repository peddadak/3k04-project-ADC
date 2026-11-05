#ifndef DASHBOARD
#define DASHBOARD
#include "AlarmController.h"
#include "LogManager.h"
    class Dashboard{
        public: 
             void generateDashboard (bool credentials, int adcID, int ADCMode, AlarmController& alarmStatus, LogManager& adcInput, char userInput, int LoginID, int time);
        private:
          bool credentials; 


    };  
#endif 