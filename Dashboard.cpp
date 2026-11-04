#include "Dashboard.h"
#include <iostream>
#include <string> 
using namespace std;
  void Dashboard::generateDashboard(bool credentials, int adcStatus, int adcID, int adcMode, AlarmController& alarmStatus, int Inventory, char UserInput){
      string status; 
      string mode; 
      string alarm; 
      if(credentials){
        switch(UserInput){
          case '1':
           if(adcStatus == 0){
              status ="Faulty";
          }
          else if(adcStatus == 1){
              status = "Operational"; 
          }
          else{
              status = "Not Received"; 
          }

            if(adcMode == 0){
              mode ="Manual";
          }
          else {
              mode = "Automatic"; 
          }
          if(alarmStatus.isAlarmActive(adcID)){
              alarm = "On";
          }
          else{
              alarm = "Off";
          }

            cout << " ******Dashboard Generated******" << endl;
            cout<<"ADC_Information"<<endl;
            cout<<"********************************"<<endl; 
            cout<<"ADC_ID" <<adcID<<endl; 
            cout<<"ADC_Status:"<<status<<endl; 
            cout <<"ADC_Mode:"<<mode<<endl; 
            cout <<"Alarm_Status:"<<alarm<<endl; 
            cout<<"Inventory:"<<Inventory<<endl; 
            cout<<"********************************"<<endl; 
              break;
          case '2':
              cout << "******Log Report******" << endl;
              // Need to see how the medicine log function is implemented
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

    


