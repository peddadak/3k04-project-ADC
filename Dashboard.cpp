#include "Dashboard.h"
#include <iostream>
#include <string> 
using namespace std;
  void Dashboard::generateDashboard(bool credentials, int adcStatus, int adcID, int adcMode, AlarmController& alarmStatus, ADCInputHandler& adcInput, char UserInput){
      string status; 
      string mode; 
      string alarm; 
      int recentInventory;
      if(credentials){
        switch(UserInput){
          Log <int> inventoryLog = adcInput.getInventory(adcID); // Variables to store the logs for inventory, status, and medicine 
          Log<char*> medicineLog = adcInput.getMedicineLog(adcID);
          Log<int> statusLog = adcInput.getStatus(adcID); 
          case '1':
           if(statusLog.getNumOfEntries() > 0){// check if there are any entries in the log 
                int lastStatus = statusLog.getLogEntry(statusLog.getNumOfEntries() - 1);// Get the last entry for the recent data 
                if(lastStatus == 0){
                    status ="Faulty";
                }
                else if(lastStatus == 1){
                    status = "Operational"; 
                }
                else{
                    status = "Not Received"; 
                }
            }
            else{ //If there are no entries, no data 
                status = "No data received  from ADC yet"; 
            }


          if(inventoryLog.getNumOfEntries() > 0){ // Similar to status
             recentInventory = inventoryLog.getLogEntry(inventoryLog.getNumOfEntries() - 1);
         }
          else{
             recentInventory = 0; 
          }

            if(adcMode == 0){
              mode ="Manual";
          }
          else {
              mode = "Automatic"; 
          }


          if(alarmStatus.isAlarmActive(adcID)){// Check the alarm status for the ADC 
              alarm = "On";
          }
          else{
              alarm = "Off";
          }
            cout << " ******Dashboard Generated******" << endl;
            cout<<"ADC_Information"<<endl;
            cout<<"********************************"<<endl; 
            cout<<"ADC_ID" <<adcID <<endl; 
            cout<<"ADC_Status:"<<status<<endl; 
            cout <<"ADC_Mode:"<<mode<<endl; 
            cout <<"Alarm_Status:"<<alarm<<endl; 
            cout<<"Inventory:" << recentInventory <<endl; 
            cout<<"********************************"<<endl; 
              break;
          case '2':
              cout << "******Log Report******" << endl;
              // Need to see how the medicine log function is implemented
              if(medicineLog.getNumOfEntries() >0){
                for(int i = 0; i < medicineLog.getNumOfEntries(); i++){
                    cout << i + 1 << ". " << medicineLog.getLogEntry(i) << endl; 
                }
              }
              else{
                cout << "No medicine log entries available."<<endl; 
              }

              break;
          default:
              cout << "Invalid Input. Please enter 1 or 2." << endl;
              return;
        }
      }
      
       

      else{
        cout<<"Invalid Credentials"<<endl; 
      }

  };

    


