#include <iostream>
#include <vector>
#include <chrono>

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
    const int TRIALS = 5;
    const int START_SIZE = 0;
    const int END_SIZE = 20000;
    const int STEP = 1000;

    // =========================
    // MELHOR CASO
    // =========================

    cout << "MELHORES CASOS - INSERTION SORT\n";
    cout << "Tamanho,Tempo_ns\n";

    for (int size = START_SIZE; size <= END_SIZE; size += STEP) {

        if (size == 0) {
            cout << "0,0\n";
            continue;
        }

        long long totalDuration = 0;

        for (int t = 0; t < TRIALS; t++) {

            // Cria um vetor já ordenado
            vector<int> A(size);

            for (int i = 0; i < size; i++) {
                A[i] = i;
            }

            // Começa a medir somente o tempo da ordenação
            auto start = chrono::high_resolution_clock::now();

            insertionSort(A);

            // Termina a medição
            auto end = chrono::high_resolution_clock::now();

            totalDuration +=
                chrono::duration_cast<chrono::nanoseconds>
                (end - start).count();
        }

        // Calcula a média das execuções
        cout << size << "," << totalDuration / TRIALS << "\n";
    }


    // =========================
    // PIOR CASO
    // =========================

    cout << "\nPIORES CASOS - INSERTION SORT\n";
    cout << "Tamanho,Tempo_ns\n";

    for (int size = START_SIZE; size <= END_SIZE; size += STEP) {

        if (size == 0) {
            cout << "0,0\n";
            continue;
        }

        long long totalDuration = 0;

        for (int t = 0; t < TRIALS; t++) {

            // Cria um vetor em ordem decrescente
            vector<int> A(size);

            for (int i = 0; i < size; i++) {
                A[i] = size - i;
            }

            // Começa a medir
            auto start = chrono::high_resolution_clock::now();

            insertionSort(A);

            // Termina a medição
            auto end = chrono::high_resolution_clock::now();

            totalDuration +=
                chrono::duration_cast<chrono::nanoseconds>
                (end - start).count();
        }

        // Calcula a média das execuções
        cout << size << "," << totalDuration / TRIALS << "\n";
    }

    return 0;
}