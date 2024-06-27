#include <iostream>
using namespace std;

void addRowToFront(int**& array, int& rows, int cols, int* newRow) {
    int** newArray = new int* [rows + 1];
    newArray[0] = new int[cols];
    for (int j = 0; j < cols; ++j) {
        newArray[0][j] = newRow[j];
    }
    for (int i = 0; i < rows; ++i) {
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

    addRowToFront(array, rows, cols, newRow);

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
