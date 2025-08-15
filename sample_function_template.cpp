#include <iostream>

using namespace std;

template <typename T>

bool IsEqualTo(T a,T b)
{
    return a==b;


}

int main()
{
    int num1 = 5; 
    int num2 = 10;

    float num3 = 6.14;
    float num4 = 6.14;

    char ch1 = 'A';
    char ch2 = 'a';

    cout << "Are both Numerical values the same?" << IsEqualTo(num1,num2) << endl;

    cout << "Are both float values the same?" << IsEqualTo(num3,num4) << endl;

    cout << "Are both character the same?" << IsEqualTo(ch1,ch2) << endl;

    return 0;
}



