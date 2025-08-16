#include <iostream>

using namespace std;

template <typename T>

T range(T** array , int rows , int columns)
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

template <typename T>
void shift_columns(T** array , int rows , int columns)
{

    for (int i = 0; i < rows; ++i)
    {
        T temp = array[i][0];
        for (int j=0; j < columns - 1; ++j)
        {
            array[i][j] = array[i][j + 1];
        }

        array[i][columns - 1] = temp;

    }
    
}

int main()
{
    const int rows = 3;
    const int columns = 3;
    int matrix[rows][columns] = {{1,2,3} , {4,5,6},{7,8,9}};
    int** dynamic_matrix = new int* [rows];
    for (int i=0 ; i< rows; ++i)
    {
        dynamic_matrix[i] = new int[columns];
        for (int j = 0; j < columns; ++j)
        {
            dynamic_matrix[i][j] = matrix[i][j];
        }
    }

    cout<< "Range of matrix:" << range(dynamic_matrix , rows, columns) << endl;

    shift_columns(dynamic_matrix , rows , columns);

    cout << "Shifted matrix:"<< endl;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            cout << dynamic_matrix[i][j] << "  ";
        }

        cout << endl;
        
    }

    // Deleting the memory of matrixes

    for (int i=0; i <rows; ++i)
    {
        delete[] dynamic_matrix[i];
    }

    delete[] dynamic_matrix;

    return 0;
    
}
















