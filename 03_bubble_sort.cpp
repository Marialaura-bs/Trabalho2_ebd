#include <iostream>
using namespace std;

void bubbleSort(int A[], int n) {
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

    int n;

    cin >> n;

    int A[n];

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    bubbleSort(A, n);

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    return 0;
}