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








