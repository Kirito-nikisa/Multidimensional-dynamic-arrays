#include <iostream>
using namespace std;

void addColumnAtPosition(int**& array, int rows, int& cols, int* newColumn, int position) {
    if (position < 0 || position > cols) {
        cout << "Invalid position!" << endl;
        return;
    }

    int** newArray = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        newArray[i] = new int[cols + 1];
        for (int j = 0; j < position; ++j) {
            newArray[i][j] = array[i][j];
        }
        newArray[i][position] = newColumn[i];
        for (int j = position; j < cols; ++j) {
            newArray[i][j + 1] = array[i][j];
        }
    }
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;
    array = newArray;
    ++cols;
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

    int newColumn[] = { 7, 8, 9 };
    int position = 1;

    addColumnAtPosition(array, rows, cols, newColumn, position);

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
