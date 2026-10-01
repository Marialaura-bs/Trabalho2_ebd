#include <iostream>
#include <vector>

using namespace std;

// Ordena os elementos do vetor usando o Insertion Sort.
void insertionSort(vector<int>& A) {
    int n = A.size();

    // Percorre a parte ainda não ordenada do vetor.
    for (int i = 1; i < n; i++) {

        // Guarda o elemento que será inserido na posição correta.
        int key = A[i];

        // Começa a procurar a posição a partir do último elemento ordenado.
        int holePos = i - 1;

        // Desloca para a direita os elementos maiores que key.
        while (holePos >= 0 && key < A[holePos]) {
            A[holePos + 1] = A[holePos];

            // Continua a procura em direção ao início do vetor.
            holePos--;
        }

        // Insere key na posição correta.
        A[holePos + 1] = key;
    }
}

int main() {
    int n;

    // Lê a quantidade de elementos do vetor.
    cin >> n;

    // Cria o vetor com n elementos.
    vector<int> A(n);

    // Lê os elementos do vetor.
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Ordena o vetor utilizando o Insertion Sort.
    insertionSort(A);

    // Exibe o vetor ordenado.
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << A[i];
    }

    cout << "\n";

    return 0;
}