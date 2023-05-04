#pragma warning(disable:4996)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

using namespace std;

void menu(int col, int row, char& answer, int& p) {

    do {

        cout << "Введите направление: \n[1] - Направо\n[2] - Налево\n[3] - Вверх\n[4] - Вниз\n";
        cin >> answer;

    } while (answer != '1' && answer != '2' && answer != '3' && answer != '4');


    if (answer == '3' || answer == '4') {

        do {

            cout << "\nВведите сдвиг [1-" << row << "]\n";
            cin >> p;

        } while (p < 1 || p > row);

    }
    else {

        do {

            cout << "\nВведите сдвиг [1-"<<col<<"]\n";
            cin >> p;

        } while (p < 1 || p > col);

    }
}

void show(int** arr, int row, int col) {

    for (int i = 0; i < row; i++) {

        cout << endl;

        for (int j = 0; j < col; j++) {

            cout << arr[i][j] << "\t";

        }
    }

    cout << "\n\n";
}

void up(int** arr, int row, int col) {

    int* tmp = new int[col];

    for (int j = 0; j < col; j++) {

        tmp[j] = arr[0][j];

    }

    for (int i = 0; i < row - 1; i++) {
        for (int j = 0; j < col; j++) {

            arr[i][j] = arr[i + 1][j];

        }
    }

    for (int j = 0; j < col; j++) {

        arr[row - 1][j] = tmp[j];

    }

    delete[] tmp;
}

void down(int** arr, int row, int col) {

    int* tmp = new int[col];

    for (int j = 0; j < col; j++) {

        tmp[j] = arr[row - 1][j];

    }


    for (int i = row - 1; i > 0; i--) {
        for (int j = 0; j < col; j++) {

            arr[i][j] = arr[i - 1][j];

        }
    }

    for (int j = 0; j < col; j++) {

        arr[0][j] = tmp[j];

    }

    delete[] tmp;
}

void left(int** arr, int row, int col) {

    int* tmp = new int[row];

    for (int i = 0; i < row; i++) {

        tmp[i] = arr[i][0];

    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col - 1; j++) {

            arr[i][j] = arr[i][j + 1];

        }
    }

    for (int i = 0; i < row; i++) {

        arr[i][col - 1] = tmp[i];

    }

    delete[] tmp;
}

void right(int** arr, int row, int col) {

    int* tmp = new int[row];

    for (int i = 0; i < row; i++) {

        tmp[i] = arr[i][col - 1];

    }

    for (int i = 0; i < row; i++) {
        for (int j = col - 1; j > 0; j--) {

            arr[i][j] = arr[i][j - 1];

        }
    }

    for (int i = 0; i < row; i++) {

        arr[i][0] = tmp[i];

    }

    delete[] tmp;
}

void main() {

    setlocale(0, "");
    srand(time(NULL));

    char action; int pos;

    int row = 3, col = 3;
    int** arr = new int* [row];

    arr[0] = new int[col] {5, 2, 3};
    arr[1] = new int[col] {5, 2, 3};
    arr[2] = new int[col] {5, 2, 3};

    show(arr, row, col);

    void(*act)(int**, int, int) = show;

    menu(row, col, action, pos);

    switch (action)
    {
    case'1':
        act = right;
        break;
    case'2':
        act = left;
        break;
    case'3':
        act = up;
        break;
    case'4':
        act = down;
        break;
    }

    for (int i = 0; i < pos; i++)
    {
        act(arr, row, col);
    }

    show(arr, row, col);

    for (int i = 0; i < row; i++) delete[] arr[i]; {

        delete[] arr;

    }
}
