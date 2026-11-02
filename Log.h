#ifndef LOG
#define LOG

    class Log{
        public: 
            Log();
            Log(int adcID, int loginID, int time);
            Log(int adcID, int time, char medicineLog);
            void addLogLoginEntry(int adcID, int loginID, int time);
            void addLogMedicineEntry(int adcID, int time, char medicineLog);
            int* getLogEntry(int index);
            int getNumOfEntries() { return numOfEntries; }
        private:
            int numOfEntries;
            int entries[100][4];


    };  
#endif 