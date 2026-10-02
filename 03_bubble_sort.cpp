#include <iostream>
#include <chrono>
using namespace std;

void bubbleSort(int A[], int n) {
    // Vetor com 0 ou 1 elemento já está ordenado
    if (n <= 1) {
        return;
    }
    bool houveTroca = true;
    int j = n - 2;

    while (houveTroca) {
        houveTroca = false;

        for (int i = 0; i <= j; i++) {
            if (A[i + 1] < A[i]) {
                int aux = A[i];
                A[i] = A[i + 1];
                A[i + 1] = aux;

                houveTroca = true;
            }
        }

        j--;
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

    cout << "MELHORES CASOS - BUBBLE SORT\n";
    cout << "Tamanho,Tempo_ns\n";

    for (int size = START_SIZE; size <= END_SIZE; size += STEP) {

        if (size == 0) {
            cout << "0,0\n";
            continue;
        }

        long long totalDuration = 0;

        for (int t = 0; t < TRIALS; t++) {

            // Cria um vetor já ordenado
            int* A = new int[size];

            for (int i = 0; i < size; i++) {
                A[i] = i;
            }

            // Começa a medir somente a ordenação
            auto start = chrono::high_resolution_clock::now();

            bubbleSort(A, size);

            // Termina a medição
            auto end = chrono::high_resolution_clock::now();

            totalDuration +=
                chrono::duration_cast<chrono::nanoseconds>
                (end - start).count();

            delete[] A;
        }

        // Calcula a média das execuções
        cout << size << "," << totalDuration / TRIALS << "\n";
    }


    // =========================
    // PIOR CASO
    // =========================

    cout << "\nPIORES CASOS - BUBBLE SORT\n";
    cout << "Tamanho,Tempo_ns\n";

    for (int size = START_SIZE; size <= END_SIZE; size += STEP) {

        if (size == 0) {
            cout << "0,0\n";
            continue;
        }

        long long totalDuration = 0;

        for (int t = 0; t < TRIALS; t++) {

            // Cria um vetor em ordem decrescente
            int* A = new int[size];

            for (int i = 0; i < size; i++) {
                A[i] = size - i;
            }

            // Começa a medir somente a ordenação
            auto start = chrono::high_resolution_clock::now();

            bubbleSort(A, size);

            // Termina a medição
            auto end = chrono::high_resolution_clock::now();

            totalDuration +=
                chrono::duration_cast<chrono::nanoseconds>
                (end - start).count();

            delete[] A;
        }

        // Calcula a média das execuções
        cout << size << "," << totalDuration / TRIALS << "\n";
    }

    return 0;
}