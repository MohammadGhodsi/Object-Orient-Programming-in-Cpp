#include <iostream>

using namespace std;

class Account 
{
    protected:
        int accountNumber;
        float accountBalance;
    
    public:
        Account(int num, float balance) : accountNumber(num) , accountBalance(balance)
        {}

        int getAccountNumber() const 
        {
            return accountNumber;
        }

        float getAccountBalance() const
        {
            return accountBalance;
        }

        virtual void Debit(float amount) = 0;
        virtual void Credit(float amount) = 0;

        virtual void Print()
        {
            cout << "Account Number:" << accountNumber << endl;
            cout << "Account Balance:" << accountBalance << endl;
        }

        virtual ~Account()
        {}


};

