#ifndef MANUALOVERRIDE
#define MANUALOVERRIDE
    class ManualOverride{
        public: 
            ManualOverride toggleManualOverrideADC(int adcID, int mode);
            ManualOverride toggleManualOverrideAlarm();

        private:
            int adcID; 
            int mode; 


    };  
#endif 