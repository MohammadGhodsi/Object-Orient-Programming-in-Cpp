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
    void setbig_int_(int*);
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
    big_int_ = new int[int_lenght_];
        
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

void BiggerInt::display()
{
    if (int_lenght_ == 0)
    {
        cout<<"No value was assigned to this parameter!";
    }

    else
    {
        for (int i = 0; i < int_lenght_; i++)
        {
            cout<< big_int_[i];
        }

        cout<<endl;
        
    }


}

void BiggerInt::setbig_int_(int* big)
{
    big_int_ = big;
}

void BiggerInt::setint_lenght_(int len)

{
    int_lenght_ = len;
}

int* BiggerInt::getbig_int_()
{
    return big_int_;

}

int BiggerInt::getint_lenght_()
{
    return int_lenght_;
}

int& BiggerInt::operator[](int index)
{
    if (index >= int_lenght_)
    {
        cout<< "It is out of array index!";
    }
    exit(0);

    return big_int_[index];

}


BiggerInt BiggerInt::operator++()
{
    for (int i = 0; i < int_lenght_; i++)
    {
        ++big_int_[i];
    }

    return *this;
}


BiggerInt BiggerInt::operator++(int)
{
    BiggerInt copy = *this;
    for (int i = 0; i < int_lenght_; i++)
    {
        big_int_[i]++;
    }

    return copy;
}

BiggerInt BiggerInt::operator--()
{
    for (int i = 0; i < int_lenght_; i++)
    {
        --big_int_[i];
    }

    return *this;
}

BiggerInt BiggerInt::operator--(int)
{
    BiggerInt copy = *this;
    for (int i = 0; i < int_lenght_; i++)
    {
        big_int_[i]--;
    }
    return copy;
}

int main()
{

    int arr1[5] = {1 ,2 ,3 ,4 ,5};
    int arr2[4] = {6,7,8,9};

    BiggerInt e1(arr1,5);
    BiggerInt e2(arr2,4);

    cout << "Array 1:";
    e1.display();

    cout << "Array 2:";
    e2.display();

    cout << "Using pre-increment on Array 1:";
    (++e1).display();

    cout << "Using pre-increment on Array 2:";
    (++e2).display();

    cout << "After post-increment o Array 2:";
    (e2++).display();

    cout << "Using post-decrement on Array 1:";
    (e2--).display();


}










