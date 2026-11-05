#ifndef LOGIN
#define LOGIN
    class Login{
        public: 
            Login();
            int checkLoginCreds(int loginID);
            void addRegisteredID(int loginID, int role); // test func assume come preloaded

        private:
            int numOfRegisteredIDs;
            int registeredIDs[100][2];


    };  
#endif 