#include "Log.h"
#include <iostream>
using namespace std;
template <typename E>
Log<E>::Log(){
    numOfEntries = 0;
}
template <typename E>
Log<E>::Log(int adcID, int loginID, int time){
    addLogEntry(adcID, loginID, time);
}
template <typename E>
void Log<E>::addLogEntry(E value){
    entries[numOfEntries] = value;
    numOfEntries++;
}

template <typename E>
E Log<E>::getLogEntry(int index){
    if (index < numOfEntries){
        return entries[index];
    }
    else{
        cout << "Invalid log entry index." << endl;
        return -1; // Return -1 to indicate an invalid index
    }
}

    


