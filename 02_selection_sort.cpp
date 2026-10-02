#include <iostream>
#include <vector>
#include <chrono>
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
    const int TRIALS = 5;
    const int START_SIZE = 0;
    const int END_SIZE = 20000;
    const int STEP = 1000;

    // =========================
    // MELHOR CASO
    // =========================

    cout << "MELHORES CASOS - SELECTION SORT\n";
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

            // Começa a medir o tempo da ordenação
            auto start = chrono::high_resolution_clock::now();

            selectionSort(A);

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

    cout << "\nPIORES CASOS - SELECTION SORT\n";
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

            selectionSort(A);

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