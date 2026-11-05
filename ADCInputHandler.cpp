#include "ADCInputHandler.h"
#include <iostream>

using namespace std;

ADCInputHandler::ADCInputHandler() {
    // Initialize the ADCInputHandler if needed
    numOfADCs = 0; // Initialize the number of ADCs to 0
}

Log<int> ADCInputHandler::getStatus(int adcID){
    if (adcID >= 0 && adcID < numOfADCs) {
        return status[adcID]; 
    }
    else{
        cout << "Invalid ADC ID." << endl;
        return Log<int>(); // Return an empty log or handle the error as needed
    }


};
Log<char*> ADCInputHandler::getMedicineLog(int adcID){
    if (adcID >= 0 && adcID < numOfADCs) {
        return medicineLog[adcID]; 
    }
    else{
        cout << "Invalid ADC ID." << endl;
        return Log<char*>(); // Return an empty log or handle the error as needed
    }



};
Log<int> ADCInputHandler::getInventory(int adcID){
    if (adcID >= 0 && adcID < numOfADCs) {
        return inventory[adcID]; 
    }
    else{
        cout << "Invalid ADC ID." << endl;
        return Log<int>(); // Return an empty log or handle the error as needed
    }
};

