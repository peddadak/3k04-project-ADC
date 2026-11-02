#ifndef MANUALOVERRIDE
#define MANUALOVERRIDE
    class ManualOverride{
        public: 
            void toggleManualOverrideADC(int adcID, int mode);
            void toggleManualOverrideAlarm();

        private:
            int adcID; 
            int mode; 


    };  
#endif 