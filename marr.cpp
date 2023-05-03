#pragma warning(disable:4996)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

using namespace std;
void addArr(int** arr, int Row, int Col,int ind) {

    for (int i = 0; i < Row; i++) {

        auto nR = new int[Col + 1];
        int buffer = 0;

        for (int j = 0; j < Col; j++) {
            if (j == ind) {
                nR[buffer] = 0;
                buffer++;
            }
            nR[buffer] = arr[i][j];
            buffer++;
        }

        delete[] arr[i];
        arr[i] = nR;
    }

}
void delArr(int** arr, int Row, int Col, int ind) {

    for (int i = 0; i < Row; i++) {

        auto nR = new int[Col - 1];
        int buffer = 0;

        for (int j = 0; j < Col; j++) {
            if (j != ind) {
                nR[buffer] = arr[i][j];
                buffer++;
            }
            
        }

        delete[] arr[i];
        arr[i] = nR;
    }

}
int main()
{
    setlocale(0, "");
    srand(time(NULL));

    int row = 5;
    int col = 5;
    int** arr = new int* [row];
    for (int i = 0; i < row; i++) {
        arr[i] = new int[col];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j] = 1;
        }
    }
    cout << "Массив:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    
    addArr(arr,row,col,1); col++;

    cout << "\nНовый Массив:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < row; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    row = 5;
    col = 5;
    int** arr2 = new int* [row];
    for (int i = 0; i < row; i++) {
        arr2[i] = new int[col];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr2[i][j] = 1;
        }
    }
    cout << "Массив:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr2[i][j] << " ";
        }
        cout << "\n";
    }
    delArr(arr2, row, col, 2); col--;

    cout << "\nНовый Массив:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr2[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < row; i++) {
        delete[] arr2[i];
    }
    delete[] arr2;



}
