#ifndef DASHBOARD
#define DASHBOARD
#include "ADCInputHandler.h"
#include "InputHandler.h"
    class Dashboard{
        public: 
             void generateDashboard (bool credentials, int adcStatus, int adcID, int ADCMode, int alarmStatus, int Inventory);
        private:
          bool credentials; 


    };  
#endif 