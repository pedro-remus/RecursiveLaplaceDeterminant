#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

//
//
//  ESSE PROGRAMA CALCULA O DETERMINANTE DE UMA MATRIZ NxN PELO MÉTODO DE LAPLACE UTILIZANDO UM ALGORITMO RECURSIVO
//
//

int** matrizReduzida(int**matriz, int i, int j, int n) {  // retorna a matriz "nova" retirando a linha "i" e a coluna "j" da matriz "matriz"
    n = n - 1;
    int ** nova = new int*[n];
    for (int i = 0; i < n; i++)
        nova[i] = new int[n];
    for (int k = 0; k < n; k++)
        for (int l = 0; l < n; l++) {
            if (k >= i) {
                if (l >= j)
                    nova[k][l] = matriz[k+1][l+1];
                else
                    nova [k][l] = matriz[k+1][l];
            } else {
                if (l >= j)
                    nova[k][j] = matriz[k][l+1];
                else
                    nova[k][l] = matriz[k][l];
            }
        }
    return nova;     
}

int determinante(int** matriz, int n) {
    int det = 0; 
    int sinal;
    if (n == 1) {
        int valor = matriz[0][0];
        delete[] matriz[0];
        delete[] matriz;
        return valor;
    }
    for (int j = 0; j < n; j++) {  // para cada elemento da primeira linha de uma matriz
        if (j % 2 == 0)
            sinal = 1;
        else
            sinal = -1;
        int**nova = matrizReduzida(matriz, 0, j, n);
        det += sinal * (matriz[0][j]) * determinante(nova, n - 1);  // O determinante é igual a soma dos cofatores de uma linha
    }
    for (int i = 0; i < n; i++)
        delete[] matriz[i];
    delete[] matriz;
    return det;
}

void imprimirMatriz(int** matriz, int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "|";
        for (int j = 0; j < n; j++) {
            cout << right << setw(4) << matriz[i][j] << " ";
        }
        cout << "\b";
        cout << right << setw(4) << "|" << endl;
    }
    cout << endl;
}

int main() {
    cout << "\n\tCalculadora de Determinantes.\n\n";
    cout << "Digite o tamanho da Matriz: ";
    int n;
    cin >> n;
    int** matriz = new int*[n];
    cout << "Insira a matriz separando elementos de mesma linha com espaco e finalizando a linha com enter:\n\n";
    for (int i = 0; i < n; i++)
        matriz[i] = new int[n];
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            matriz[i][j] = num;
        }
    }
    cout << "\nPara a matriz M:" << endl;
    imprimirMatriz(matriz, n);
    cout << "DET (M) = " << determinante(matriz, n) << "\n\n";
    return 0;
}