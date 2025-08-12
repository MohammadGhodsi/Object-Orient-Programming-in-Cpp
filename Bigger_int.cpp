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

    void display();
    void setbig_int(int*);
    void setint_lenght_(int);
    int* getbig_int_();
    int getint_lenght_();
    int& operator[](int);

}



