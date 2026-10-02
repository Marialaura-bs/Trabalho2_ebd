#include <iostream>
#include <chrono>
using namespace std;

// Função responsável por dividir o vetor em duas regiões
// e colocar o pivô em sua posição correta
int particao(int A[], int l, int r) {

    // Escolhe o último elemento como pivô
    int x = A[r];

    // Começa uma posição antes do início do intervalo
    int i = l - 1;

    // Percorre o vetor até o elemento anterior ao pivô
    for (int j = l; j <= r - 1; j++) {

        // Verifica se A[j] é menor ou igual ao pivô
        if (A[j] <= x) {

            // Avança a região dos elementos menores ou iguais ao pivô
            i++;

            // Troca A[i] com A[j]
            int aux = A[i];
            A[i] = A[j];
            A[j] = aux;
        }
    }

    // Coloca o pivô entre as duas regiões
    int aux = A[i + 1];
    A[i + 1] = A[r];
    A[r] = aux;

    // Retorna a posição final do pivô
    return i + 1;
}


// Função responsável pelo Quick Sort
void quicksort(int A[], int l, int r) {

    // Verifica se existem pelo menos dois elementos no intervalo
    if (l < r) {

        // Divide o vetor e encontra a posição do pivô
        int q = particao(A, l, r);

        // Ordena recursivamente a parte esquerda
        quicksort(A, l, q - 1);

        // Ordena recursivamente a parte direita
        quicksort(A, q + 1, r);
    }
}

// =====================================================
// GERA O MELHOR CASO
// =====================================================
void geraMelhorCaso(int inicio, int fim, int A[], int& pos) {

    // Caso base: não há elementos
    if (inicio > fim) {
        return;
    }

    // Escolhe o elemento do meio como pivô
    int meio = (inicio + fim) / 2;

    // Gera recursivamente a parte esquerda
    geraMelhorCaso(inicio, meio - 1, A, pos);

    // Gera recursivamente a parte direita
    geraMelhorCaso(meio + 1, fim, A, pos);

    // Coloca o pivô no final da sequência
    A[pos] = meio;
    pos++;
}

// =====================================================
// PROGRAMA PRINCIPAL
// =====================================================
int main() {

    const int START_SIZE = 0;
    const int END_SIZE = 20000;
    const int STEP = 1000;
    const int TRIALS = 5;

    // =================================================
    // MELHOR CASO
    // =================================================

    cout << "MELHOR CASO - QUICK SORT" << endl;
    cout << "Tamanho,Tempo_ns" << endl;

    for (int size = START_SIZE; size <= END_SIZE; size += STEP) {

        long long totalDuration = 0;

        for (int trial = 0; trial < TRIALS; trial++) {

            int* A = new int[size];

            // Gera o vetor do melhor caso
            int pos = 0;
            geraMelhorCaso(0, size - 1, A, pos);

            auto inicio = chrono::high_resolution_clock::now();

            // Ordena o vetor
            quicksort(A, 0, size - 1);

            auto fim = chrono::high_resolution_clock::now();

            totalDuration +=
                chrono::duration_cast<chrono::nanoseconds>(
                    fim - inicio
                ).count();

            delete[] A;
        }

        long long media = totalDuration / TRIALS;

        cout << size << "," << media << endl;
    }

    // =================================================
    // PIOR CASO
    // =================================================

    cout << endl;
    cout << "PIOR CASO - QUICK SORT" << endl;
    cout << "Tamanho,Tempo_ns" << endl;

    for (int size = START_SIZE; size <= END_SIZE; size += STEP) {

        long long totalDuration = 0;

        for (int trial = 0; trial < TRIALS; trial++) {

            int* A = new int[size];

            // Gera o vetor do pior caso:
            // elementos em ordem crescente
            for (int i = 0; i < size; i++) {
                A[i] = i;
            }

            auto inicio = chrono::high_resolution_clock::now();

            // Ordena o vetor
            quicksort(A, 0, size - 1);

            auto fim = chrono::high_resolution_clock::now();

            totalDuration +=
                chrono::duration_cast<chrono::nanoseconds>(
                    fim - inicio
                ).count();

            delete[] A;
        }

        long long media = totalDuration / TRIALS;

        cout << size << "," << media << endl;
    }

    return 0;
}