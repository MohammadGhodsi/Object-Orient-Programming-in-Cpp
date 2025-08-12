include<iostream>
using namespace std;

class BiggerInt {

    private:
    int* big_int_;
    int int_lenght_;

    public:
    BiggerInt();
    BiggerInt(const int* obj, int size);
    BiggerInt(const BiggerInt& obj);
    BiggerInt operator=(const BiggerInt& c);
    ~BiggerInt();

    

}

