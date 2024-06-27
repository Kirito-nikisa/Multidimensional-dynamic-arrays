#include <iostream>
using namespace std;

void addRowAtPosition(int**& array, int& rows, int cols, int* newRow, int position) {
    if (position < 0 || position > rows) {
        cout << "Invalid position!" << endl;
        return;
    }

    int** newArray = new int* [rows + 1];
    for (int i = 0; i < position; ++i) {
        newArray[i] = array[i];
    }
    newArray[position] = new int[cols];
    for (int j = 0; j < cols; ++j) {
        newArray[position][j] = newRow[j];
    }
    for (int i = position; i < rows; ++i) {
        newArray[i + 1] = array[i];
    }
    delete[] array;
    array = newArray;
    ++rows;
}

int main() {
    int rows = 2;
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

    int newRow[] = { 7, 8, 9 };
    int position = 1;

    addRowAtPosition(array, rows, cols, newRow, position);

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
