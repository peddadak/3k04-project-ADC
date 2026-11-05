#ifndef DASHBOARD
#define DASHBOARD
#include "AlarmController.h"
#include "ADCInputHandler.h"
    class Dashboard{
        public: 
             void generateDashboard (bool credentials, int adcStatus, int adcID, int ADCMode, AlarmController& alarmStatus, ADCInputHandler& adcInput, char userInput);
        private:
          bool credentials; 


    };  
#endif 