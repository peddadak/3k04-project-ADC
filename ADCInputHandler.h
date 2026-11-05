#ifndef ADCINPUTHANDLER
#define ADCINPUTHANDLER
#include "Log.h"

class ADCInputHandler
{
    public: 
        ADCInputHandler();
        void addADC() { numOfADCs++; } // test func assume come preloaded
        Log<int> getStatus(int adcID); 
        Log<char*> getMedicineLog(int adcID);
        Log<int> getInventory(int adcID);
        int getNumOfADCs() { return numOfADCs; }
        Log<int> status[100];  //For testing
    private: 
        int numOfADCs;
        
      
        Log<char*> medicineLog[100];
        Log<int> inventory[100];





};





#endif 