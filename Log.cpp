#include "Log.h"
#include <iostream>
#include <stdexcept>
using namespace std;
template <typename E>
Log<E>::Log(){
    numOfEntries = 0;
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
       
        throw std::runtime_error("Invalid log entry index." );

      
    }
}
template class Log<int>; 
template class Log<char*>; 
    


