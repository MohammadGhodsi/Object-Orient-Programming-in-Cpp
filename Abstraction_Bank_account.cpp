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



class CurrentAccount : public Account
{
    private:
        float servicecharges;
        float minBalance; 
    
    public:
        CurrentAccount(int num, float balance, float charges, float minBal) : Account(num,balance) , servicecharges(charges) , minBalance(minBal)
        {

        }
       
    void Debit(float amount) override
    {
        if (amount <= getAccountBalance())
        {
            accountBalance -= amount;
        }

        else
        {
            cout << "Insufficient balance!" << endl;
        }

    }

    void Credit(float amount) override
    {
        accountBalance += amount;
        
        if (accountBalance <= minBalance)
        {
            accountBalance -= servicecharges;
        }
 
    }

    void Print() override
    {
        Account::Print();
        cout << "Minimum balance in the bank" << minBalance << endl;
        cout << "Service charges fee" << servicecharges << endl;
    }

    class SavingAccount : public Account
    {
        private:
            float interestRate;

        public:
            SavingAccount(int num, float balance , float rate) : Account(num , balance) , interestRate(rate) 
            {

            }

        void Debit(float amount) override
        {
            if (amount <= getAccountBalance())
            {
                accountBalance -= amount;
            }
            else
            {
                cout << "Insufficient balance" << endl;
            }

        }

        void Credit(float amount) override
        {
            accountBalance += amount;
        }

        void Print() override
        {
            Account::Print();
            cout << "Interest Rate :" << interestRate << endl;
        }

    }

};



