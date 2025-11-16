#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <iomanip> 

#include <clocale>

using namespace std;

const int SIZE = 5;

void fillArray(double arr[SIZE][SIZE]);

void printArray(double arr[SIZE][SIZE]);

double sumPositiveAboveDiagonal(double arr[SIZE][SIZE]);

int main() {

    setlocale(LC_ALL, "Ukrainian");

    srand(time(NULL));

    // Оголошуємо матрицю 5x5 
    double matrix[SIZE][SIZE];

    fillArray(matrix);

    cout << "Згенерована матриця " << SIZE << "x" << SIZE << ":" << endl;
    printArray(matrix);

    double sum = sumPositiveAboveDiagonal(matrix);

    cout << "\nСума додатних елементiв над головною дiагоналлю: " << sum << endl;

    return 0;
}


void fillArray(double arr[SIZE][SIZE]) {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            arr[i][j] = (rand() % 100) - 50.0;
        }
    }
}

void printArray(double arr[SIZE][SIZE]) {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Використовуємо setw() для акуратного форматування стовпців
            cout << setw(8) << fixed << setprecision(1) << arr[i][j];
        }
        cout << endl;
    }
}

double sumPositiveAboveDiagonal(double arr[SIZE][SIZE]) {
    double sum = 0.0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (j > i && arr[i][j] > 0) {
                sum += arr[i][j];
            }
        }
    }
    return sum; 
}