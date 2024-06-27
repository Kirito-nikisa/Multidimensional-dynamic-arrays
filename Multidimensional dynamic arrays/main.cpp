#include <iostream>
using namespace std;

void deleteRowAtPosition(int**& array, int& rows, int cols, int position) {
    if (position < 0 || position >= rows) {
        cout << "Invalid position!" << endl;
        return;
    }

    int** newArray = new int* [rows - 1];
    for (int i = 0; i < position; ++i) {
        newArray[i] = array[i];
    }
    for (int i = position + 1; i < rows; ++i) {
        newArray[i - 1] = array[i];
    }
    delete[] array[position];
    delete[] array;
    array = newArray;
    --rows;
}

int main() {
    int rows = 3;
    int cols = 3;

    int** array = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            array[i][j] = i * cols + j + 1;
        }
    }

    cout << "Initial array:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    int position = 1;

    deleteRowAtPosition(array, rows, cols, position);

    cout << "Updated array:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
