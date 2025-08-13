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
        SC , MB;  //SC = Service Charges (int) , MB = Minimum Balance (int)
        

    
};

