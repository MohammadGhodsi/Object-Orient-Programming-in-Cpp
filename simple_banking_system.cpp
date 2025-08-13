#include <iostream>
using namespace std;

class Account
{
private:
    int AN, AB; // AN = Account Number (integer) , AB = Account Balance (integer)
public:
   
    int getAN()
    {
        return AN;
    }
    int getAB()
    {
        return AB;
    }
    void setAN(int acn)
    {
        AN = acn;
    }
    void setAB(int acb)
    {
        AB = acb;
    }
    virtual void Print()
    {
        cout << "Account Number : " << AN << endl << "Account Balance :" << AB << endl;
    }

    virtual void Credit()
    {

    }
    virtual void Debit()
    {

    }

    virtual ~Account() 
    {
        cout << "Account deleted!" << endl;
    }

};

class CurrentAccount : public Account
{
    private:
       int SC , MB;  //SC = Service Charges (int) , MB = Minimum Balance (int)

    public:
        CurrentAccount()
        {
            SC = 100; //Default charge
            MB = 1000; //Defualt minimum balance
        }

    void Print()
    {
        Account::Print(); //Overriding Print() class
        cout << "Service Charges :" << SC << endl << MB << endl;

    }

    void Credit(float amount)
    {
        setAB(getAB() + amount);
    }

    void Debit(float amount)
    {
        if (amount <= getAB())
        {
            setAB(getAB() - amount);
        }

        if (getAB() < MB) 
        {
            setAB(getAB() - SC);
        }
    }

    ~CurrentAccount()
    {
        cout << "Current Account has been removed!" << endl;
    }

    
    class SavingAccount : public Account
    {
        private:
            int Interest_rate; 

        public :
            SavingAccount()
            {
                Interest_rate = 5;
            }    
        
        void Print()
        {
            Account::Print();
            cout << "Interest Rate :" << Interest_rate << endl;

        }    

        void Credit(float amount)
        {
            setAB(getAB() + amount);
        }

        void Debit(float amount)
        {

            if (amount <= getAB())
            {
                setAB(getAB() - amount);
            }

        }

        ~SavingAccount()
        {
            cout<< "Saving account destroyed !" << endl;
        }


        int main()
        {

            Account

        }



    }
    
};

