class Account {
    private:
        int accNo;
        char name[50];
        int pin;
        double balance;
    
    public:
        void createAccount();
        void showAccount();
        void deposit(double);
        void withdraw(double);
        int getAccNo() const;
        int getPin() const;
        double getBalance() const;

};