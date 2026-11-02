#ifndef LOG
#define LOG

    class Log{
        public: 
            Log();
            Log(int adcID, int loginID, int time);
            Log(int adcID, int time, char medicineLog);
        private:
            void addLogAddressEntry(int adcID, int loginID, int time);
            void addLogMedicineEntry(int adcID, int time, char medicineLog);
            int numOfEntries;
            int entries[100][4];


    };  
#endif 