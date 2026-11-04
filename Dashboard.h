#ifndef DASHBOARD
#define DASHBOARD
#include "AlarmController.h"
    class Dashboard{
        public: 
             void generateDashboard (bool credentials, int adcStatus, int adcID, int ADCMode, AlarmController& alarmStatus, int Inventory,char userInput);
        private:
          bool credentials; 


    };  
#endif 