#ifndef DASHBOARD
#define DASHBOARD
#include "AlarmController.h"
#include "LogManager.h"
    class Dashboard{
        public: 
             void generateDashboard (int credentials, int adcID, int ADCMode, AlarmController& alarmStatus, LogManager& adcInput, char userInput, int LoginID, int time);
        private:
          int credentials; 


    };  
#endif 