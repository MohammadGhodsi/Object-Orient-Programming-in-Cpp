#include <iostream>

using namespace std;

template <class T , int N>

class Sequence 
{
    private :
        T memblock[N];

    public :

       void setmember(int x, T value)
       {

            memblock[x] = value;
       }

       T getmember(int x)
       {
        return memblock[x];
       }


};

int main()
{
    Sequence<int,5> myint;
    Sequence<double , 5> mydouble;

    myint.setmember(0,100);
    mydouble.setmember(3,3.15);

    cout <<myint.getmember(0) << endl;
    cout << mydouble.getmember(3) << endl;

    return 0;
}






