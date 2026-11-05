#include "Login.h"
#include <iostream>
using namespace std;
Login :: Login() {
     numOfRegisteredIDs = 0;
}

int Login::checkLoginCreds(int loginID){
     for (int i = 0; i < numOfRegisteredIDs; i++){
          if (registeredIDs[i][0] == loginID){
               return registeredIDs[i][1]; // Return the role
          }
     }
     return -1; // Return -1 if login ID is not found
}

void Login::addRegisteredID(int loginID, int role){
     for (int i = 0; i < numOfRegisteredIDs; i++){
          if(registeredIDs[i][0] == loginID){
               cout << "Login ID already registered." << endl;
               return;
          }
     }
     if (numOfRegisteredIDs < 100){
          registeredIDs[numOfRegisteredIDs][0] = loginID;
          registeredIDs[numOfRegisteredIDs][1] = role;
          numOfRegisteredIDs++;
     }
     else{
           cout << "Maximum number of registered IDs reached." << endl;
     }
     
}


    


