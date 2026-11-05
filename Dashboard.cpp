#include "Dashboard.h"
#include <iostream>
#include <string> 
using namespace std;
  void Dashboard::generateDashboard(int credentials, int adcID, int adcMode, AlarmController& alarmStatus, LogManager& logManager, char UserInput, int LoginID, int time){
      string status; 
      string mode; 
      string alarm; 
      int recentInventory;
      if(credentials!= -1){
        
         Log <int> inventoryLog = logManager.generateInventoryLogReport(adcID, LoginID, credentials); // Variables to store the logs for inventory, status, and medicine 
         Log<char*> medicineLog = logManager.generateMedicineLogReport(adcID, LoginID, credentials);
         Log<int> statusLog = logManager.generateStatusLogReport(adcID, LoginID, credentials); 
        switch(UserInput){
         
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


          

            if(adcMode == 0){
              mode ="Automatic";
            }
            else {
                mode = "Manual"; 
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


            

            if(inventoryLog.getNumOfEntries() > 0){ // Similar to status
             recentInventory = inventoryLog.getLogEntry(inventoryLog.getNumOfEntries() - 1);
             cout<<"Inventory:" << recentInventory <<endl; 

         }
          else{
             cout<<"Inventory: No data received from ADC yet"<<endl; 
          }
           if(alarmStatus.isAlarmActive(adcID)){// Check the alarm status for the ADC 
                        cout << "THERE IS AN ACTIVE FAULT AT THIS ADC PLEASE RESOLVE THE ISSUE!" << endl;

           }
            cout<<"********************************"<<endl; 
              break;
          case '2':
              logManager.storeLogAccess(adcID, LoginID, time); // Store a sample access log entry
              cout << "******Log Report******" << endl;
              // Need to see how the medicine log function is implemented
              if(medicineLog.getNumOfEntries() >0){
                for(int i = medicineLog.getNumOfEntries()-1; i >= 0; i--){ // latest entry first
                    if (statusLog.getLogEntry(i) == 1) {
                        cout << medicineLog.getLogEntry(i) << " Quantity: " << inventoryLog.getLogEntry(i)  << endl; 
                    }
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

    


