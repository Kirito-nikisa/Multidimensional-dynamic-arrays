#include <iostream>
using namespace std;

void addRow(int**& array, int& rows, int cols, int* newRow) {
    int** newArray = new int* [rows + 1];
    for (int i = 0; i < rows; ++i) {
        newArray[i] = array[i];
    }
    newArray[rows] = new int[cols];
    for (int j = 0; j < cols; ++j) {
        newArray[rows][j] = newRow[j];
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

    addRow(array, rows, cols, newRow);

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
