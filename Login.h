#ifndef LOGIN
#define LOGIN
    class Login{
        public: 
            Login();
            int checkLoginCreds(int loginID);
            void addRegisteredID(int loginID, int role);

        private:
            int numOfRegisteredIDs;
            int registeredIDs[100][2];


    };  
#endif 