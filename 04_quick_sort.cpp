int particao(int A[], int l, int r) {

    int x = A[r];
    int i = l - 1;

    for (int j = l; j <= r - 1; j++) {

        if (A[j] <= x) {

            i++;

            int aux = A[i];
            A[i] = A[j];
            A[j] = aux;
        }
    }

    int aux = A[i + 1];
    A[i + 1] = A[r];
    A[r] = aux;

    return i + 1;
}