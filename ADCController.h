#ifndef ADCCONTROLLER
#define ADCCONTROLLER
class ADCController
{
    public: 
        void setManualMode(int i);
        void openDoors();
        void closeDoors();
        int getMode() { return mode; }

    private: 
        int mode = 0; // 0 = automatic, 1 = manual
        


};
#endif

