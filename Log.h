#ifndef LOG
#define LOG

template <typename E>
    class Log{
        public: 
            Log();
            Log(int adcID, int loginID, int time);
            Log(int adcID, int time, char medicineLog);
            void addLogEntry(E value);
            E getLogEntry(int index);
            int getNumOfEntries() { return numOfEntries; }
        private:
            int numOfEntries;
            E entries[100];


    };  
#endif 