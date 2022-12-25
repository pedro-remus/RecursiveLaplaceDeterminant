#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

//
//
//  THIS PROGRAM CALCULATES THE DETERMINANT OF A NxN MATRIX BY LAPLACE EXPANSION, USING RECURSIVE ALGORITHM
//
//

int** reducedMatrix(int**matrix, int i, int j, int n) {  // returns the matrix "newMatrix" removing row "i" and column "j" from the matrix "matrix"
    n = n - 1;
    int **  newMatrix= new int*[n];
    for (int i = 0; i < n; i++)
        newMatrix[i] = new int[n];
    for (int k = 0; k < n; k++)
        for (int l = 0; l < n; l++) {
            if (k >= i) {
                if (l >= j)
                    newMatrix[k][l] = matrix[k+1][l+1];
                else
                    newMatrix[k][l] = matrix[k+1][l];
            } else {
                if (l >= j)
                    newMatrix[k][j] = matrix[k][l+1];
                else
                    newMatrix[k][l] = matrix[k][l];
            }
        }
    return newMatrix;     
}

int determinant(int** matrix, int n) {
    int det = 0; 
    int sign;
    if (n == 1) {
        int valor = matrix[0][0];
        delete[] matrix[0];
        delete[] matrix;
        return valor;
    }
    for (int j = 0; j < n; j++) {  // for each element in the first row of a matrix
        if (j % 2 == 0)
            sign = 1;
        else
            sign = -1;
        int**newMatrix = reducedMatrix(matrix, 0, j, n);
        det += sign * (matrix[0][j]) * determinant(newMatrix, n - 1);  // The determinant is equal to the sum of the cofactors
    }
    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;
    return det;
}

void printMatrix(int** matrix, int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "|";
        for (int j = 0; j < n; j++) {
            cout << right << setw(4) << matrix[i][j] << " ";
        }
        cout << "\b";
        cout << right << setw(4) << "|" << endl;
    }
    cout << endl;
}

int main() {
    cout << "\n\tDeterminant Caculator.\n\n";
    cout << "Type the matrix order: ";
    int n;
    cin >> n;
    int** matrix = new int*[n];
    cout << "Insert the matrix spacing elements from the same row and ending a row with enter:\n\n";
    for (int i = 0; i < n; i++)
        matrix[i] = new int[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            matrix[i][j] = num;
        }
    }
    cout << "\nFor the matrix M:" << endl;
    printMatrix(matrix, n);
    cout << "DET (M) = " << determinant(matrix, n) << "\n\n";
    return 0;
}