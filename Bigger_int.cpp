#include <iostream>
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

    BiggerInt operator++(); // for pre increasing
    BiggerInt operator--(); // for pre decreasing
    BiggerInt operator++(int); //  for post increasing
    BiggerInt operator--(int); // for post decreasing

};

BiggerInt::BiggerInt () 

{

    big_int_ = nullptr;
    int_lenght_ = 0;

}

BiggerInt::BiggerInt(const int* obj, int size)

{

    int_lenght_ = size;
    big_int_ = new int[int_lenght_];
    for (int i=0; i < int_lenght_; i++)
    {

        big_int_[i] = obj[i];

    }

}

BiggerInt::BiggerInt(const BiggerInt& obj)
{

    int_lenght_ = obj.int_lenght_;
    big_int_ = new int[obj.int_lenght_];

    for (int i = 0; i < int_lenght_; i++)
    {
        big_int_[i] = obj.big_int_[i];
    }
        

}

    BiggerInt BiggerInt::operator=(const BiggerInt& c)
{
    if (this == &c)
    {
        return *this;
    }

    if (big_int_ != nullptr)
    {
        delete[] big_int_;
    }

    int_lenght_ = c.int_lenght_;
    big_int_ = new int[int_lenght_]
        
    for (int i = 0; i < int_lenght_; i++)
    {
        big_int_[i] = c.big_int_[i];
    }

    return *this;
        
}

BiggerInt::~BiggerInt()
{
    delete[] big_int_;
}







