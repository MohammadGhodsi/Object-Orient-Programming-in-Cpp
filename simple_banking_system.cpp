#include <iostream>
using namespace std;

class Account {
private:
    int AN;  // Account Number
    int AB;  // Account Balance

public:
    Account() : AN(0), AB(0) {}  // Default constructor to initialize values

    int getAN() {
        return AN;
    }

    int getAB() {
        return AB;
    }

    void setAN(int acn) {
        AN = acn;
    }

    void setAB(int acb) {
        AB = acb;
    }

    virtual void Print() {
        cout << "Account Number : " << AN << endl
             << "Account Balance : " << AB << endl;
    }

    virtual void Credit(float) {
        // Intentionally empty; to be overridden in derived classes
    }

    virtual void Debit(float) {
        // Intentionally empty; to be overridden in derived classes
    }

    virtual ~Account() {
        cout << "Account destroyed !!" << endl;
    }
};

class CurrentAccount : public Account {
private:
    int SC;  // Service Charges
    int MB;  // Minimum Balance

public:
    CurrentAccount() {
        SC = 100;   // Default service charges
        MB = 1000;  // Default minimum balance
        setAN(123); // Example Account Number (optional)
        setAB(2000); // Example initial balance (optional)
    }

    void Print() {
        Account::Print();
        cout << "Service Charges : " << SC << endl
             << "Minimum Balance : " << MB << endl;
    }

    void Credit(float amount) {
        setAB(getAB() + amount);
    }

    void Debit(float amount) {
        if (amount <= getAB()) {
            setAB(getAB() - amount);
            if (getAB() < MB) {
                setAB(getAB() - SC);
            }
        }
    }

    ~CurrentAccount() {
        cout << "Current Account destroyed !!" << endl;
    }
};

class SavingAccount : public Account {
private:
    int IR;  // Interest Rate

public:
    SavingAccount() {
        IR = 5;      // Default interest rate
        setAN(456);  // Example Account Number (optional)
        setAB(1500); // Example initial balance (optional)
    }

    void Print() {
        Account::Print();
        cout << "Interest Rate : " << IR << endl;
    }

    void Credit(float amount) {
        setAB(getAB() + amount);
    }

    void Debit(float amount) {
        if (amount <= getAB()) {
            setAB(getAB() - amount);
        }
    }

    ~SavingAccount() {
        cout << "Saving Account destroyed !!" << endl;
    }
};

int main() {
    // Array of pointers to Account base class to hold polymorphic objects
    Account** alist = new Account*;

    alist = new SavingAccount;
    alist = new CurrentAccount;
    alist = new Account;

    // Print all accounts using polymorphic behavior
    for (int i = 0; i < 3; i++) {
        alist[i]->Print();
        cout << endl;
    }

    // Credit 50 to the SavingAccount
    alist->Credit(50);

    // Debit 333 from the base Account (won't affect since Debit is empty in Account)
    alist->Debit(333);

    cout << "After Credit and Debit operations:\n" << endl;

    // Print again all accounts after transactions
    for (int i = 0; i < 3; i++) {
        alist[i]->Print();
        cout << endl;
    }

    // Delete all allocated objects and the array itself
    for (int i = 0; i < 3; i++) {
        delete alist[i];
    }
    delete[] alist;

    return 0;
}
