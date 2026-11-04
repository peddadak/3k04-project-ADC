#include "ADCInputHandler.h"
#include <iostream>
using namespace std;
 int ADCInputHandler::getStatus(int adcID){
    for (int i = 0; i < 100; i++){
        if (ADCids[i] == adcID){
            return status[i];
        }
    }



 };
 int ADCInputHandler::getMedicineLog(int adcID){
    for (int i = 0; i < 100; i++){
        if (ADCids[i] == adcID){
            return medicineLog[i];
        }
    }



 };
int ADCInputHandler::getInventory(int adcID){
    for (int i = 0; i < 100; i++){
        if (ADCids[i] == adcID){
            return inventory[i];
        }
    }

};

