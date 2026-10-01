#include <iostream>
#include <vector>
using namespace std;

// Função que ordena o vetor usando Selection Sort
void selectionSort(vector<int>& A) {
    int n = A.size(); // Recupera o tamanho do vetor
    int menor, i, j;  // Variáveis auxiliares

    // Percorre o vetor até o penúltimo elemento
    for (i = 0; i <= n - 2; i++) {
        menor = i; // Considera o elemento atual como o menor

        // Percorre a parte ainda não ordenada
        for (j = i + 1; j <= n - 1; j++) {
            // Verifica se encontrou um elemento menor
            if (A[j] < A[menor]) {
                menor = j; // Guarda o índice do menor elemento
            }
        }

        // Troca o elemento atual com o menor encontrado
        int aux = A[i];
        A[i] = A[menor];
        A[menor] = aux;
    }
}

int main() {
    int n;

    // Lê a quantidade de elementos
    cin >> n;

    vector<int> A(n);

    // Lê os elementos do vetor
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Ordena o vetor
    selectionSort(A);

    // Exibe o vetor ordenado
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << A[i];
    }

    cout << "\n";

    return 0;
}