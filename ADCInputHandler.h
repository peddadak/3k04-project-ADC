#ifndef ADCINPUTHANDLER
#define ADCINPUTHANDLER

class ADCInputHandler
{
    public: 
        int getStatus(int adcID); 
        int getMedicineLog(int adcID);
        int getInventory(int adcID);
    private: 
        int ADCids[100]; 
        int status[100]; 
        int medicineLog[100];
        int inventory[100];





};





#endif 