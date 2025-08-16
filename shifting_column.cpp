#include <iostream>

using namespace std;

template <typename T>

T range(T* array , int rows , int columns)
{
    T min = array[0][0];
    T max = array[0][0];


    for (int i=0;i< rows;++i)
    {
        for (int j=0; j<columns;++j)
        {
            if(array[i][j] < min)
            {
                min = array[i][j];
            }

            if(array[i][j] > max)
            {
                max = array[i][j];
            }

        }
    }

    return ((max - min) / static_cast<T>(4)) + min;

}
















