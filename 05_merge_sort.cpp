#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

// Junta dois vetores já ordenados em um único vetor ordenado
void intercala(vector<int>& L, vector<int>& R, vector<int>& A) {
    int nL = L.size();
    int nR = R.size();

    int i = 0;
    int j = 0;
    int k = 0;

    // Enquanto ainda houver elementos nos dois vetores,
    // compara os elementos atuais e coloca o menor em A
    while (i < nL && j < nR) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }

        k++;
    }

    // Copia os elementos que sobraram em L
    while (i < nL) {
        A[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos que sobraram em R
    while (j < nR) {
        A[k] = R[j];
        j++;
        k++;
    }
}

// Divide o vetor, ordena as duas partes e depois intercala
void mergesort(vector<int>& A) {
    int n = A.size();

    // Se tiver 0 ou 1 elemento, já está ordenado
    if (n < 2) {
        return;
    }

    // Encontra o meio do vetor
    int mid = n / 2;

    // Cria os vetores da esquerda e da direita
    vector<int> L(mid);
    vector<int> R(n - mid);

    // Copia a primeira metade para L
    for (int i = 0; i < mid; i++) {
        L[i] = A[i];
    }

    // Copia a segunda metade para R
    for (int i = mid; i < n; i++) {
        R[i - mid] = A[i];
    }

    // Ordena recursivamente as duas partes
    mergesort(L);
    mergesort(R);

    // Junta as duas partes já ordenadas
    intercala(L, R, A);
}

int main() {

    const int START_SIZE = 0;
    const int END_SIZE = 20000;
    const int STEP = 1000;
    const int TRIALS = 5;

    // =====================================================
    // MELHOR CASO
    // =====================================================

    cout << "MELHOR CASO - MERGE SORT" << endl;
    cout << "Tamanho,Tempo_ns" << endl;

    for (int size = START_SIZE; size <= END_SIZE; size += STEP) {

        long long totalDuration = 0;

        for (int trial = 0; trial < TRIALS; trial++) {

            vector<int> A(size);

            // Vetor já ordenado
            for (int i = 0; i < size; i++) {
                A[i] = i;
            }

            auto inicio = chrono::high_resolution_clock::now();

            mergesort(A);

            auto fim = chrono::high_resolution_clock::now();

            totalDuration +=
                chrono::duration_cast<chrono::nanoseconds>(
                    fim - inicio
                ).count();
        }

        long long media = totalDuration / TRIALS;

        cout << size << "," << media << endl;
    }

    // =====================================================
    // PIOR CASO
    // =====================================================

    cout << endl;
    cout << "PIOR CASO - MERGE SORT" << endl;
    cout << "Tamanho,Tempo_ns" << endl;

    for (int size = START_SIZE; size <= END_SIZE; size += STEP) {

        long long totalDuration = 0;

        for (int trial = 0; trial < TRIALS; trial++) {

            vector<int> A(size);

            // Vetor em ordem decrescente
            for (int i = 0; i < size; i++) {
                A[i] = size - i;
            }

            auto inicio = chrono::high_resolution_clock::now();

            mergesort(A);

            auto fim = chrono::high_resolution_clock::now();

            totalDuration +=
                chrono::duration_cast<chrono::nanoseconds>(
                    fim - inicio
                ).count();
        }

        long long media = totalDuration / TRIALS;

        cout << size << "," << media << endl;
    }

    return 0;
}