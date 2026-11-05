#include "ADCController.h"
#include <iostream>
using namespace std;

  void ADCController::setManualMode(int i){
    if (i >= 0 && i <= 1) {
        mode = i;
    } else {
        cout << "Invalid mode. Please enter 0 for automatic or 1 for manual." << endl;
    }


  };
  void ADCController::openDoors(){
    // Code to open the doors of the ADC
    if (mode == 1) {
        // opens the doors 
        // does nothing if the doors are already open
    } else {
        cout << "Cannot open doors in automatic mode." << endl;
    }

  };
  void ADCController::closeDoors(){
    // Code to close the doors of the ADC
    // if doors are already closed, do nothing
     if (mode == 1) {
        // closes the doors 
        // does nothing if the doors are already closed
    } else {
        cout << "Cannot close doors in automatic mode." << endl;
    }

  };