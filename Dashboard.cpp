#include "Dashboard.h"
#include <iostream>
#include <string> 
using namespace std;
  void Dashboard::generateDashboard(bool credentials, int adcStatus, int adcID, int adcMode, int alarmStatus, int Inventory){
      string status; 
      string mode; 
      string alarm; 
      if(credentials){
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
        
        
          if(alarmStatus == 0){
            alarm ="Off";
        }
        else {
            alarm = "On"; 
        }

        cout << " ******Dashboard Generated******" << endl;
        cout<<"ADC_Information"<<endl;
        cout<<"********************************"<<endl; 
        cout<<"ADC_ID" <<adcID<<endl; 
        cout<<"ADC_Status:"<<status<<endl; 
        cout <<"ADC_Mode:"<<mode<<endl; 
        cout<<"Inventory:"<<Inventory<<endl; 
        cout <<"Alarm_Status:"<<alarm<<endl; 
        cout<<"********************************"<<endl; 
      }
      else{
        cout<<"Invalid Credentials"<<endl; 
      }

  };

    


