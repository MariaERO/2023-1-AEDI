#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intercal(int p, int q, int r, int v[]){
    int i, j, k, *w;
    w = malloc ((r-p) * sizeof (int));
    i = p; j = q; k = 0;
    while (i < q && j < r) {
        if (v[i] <= v[j]) w[k++] = v[i++];
        else w[k++] = v[j++];
    }
    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];
    for (i = p; i < r; i++) v[i] = w[i-p];
    free (w);
}

int mergeSort(int p, int r, int v[]){
    if (p < r - 1) {
        int q = (p + r)/2;
        mergeSort(p, q, v);
        mergeSort(q, r, v);
        intercal(p, q, r, v);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int v[n];
    srand(time(NULL));

    // insert random values to an empty n positions vector
    for(int j = 0; j < n; j++){
        // define r as a random num between 0 and 20
        int r = (rand() % 20);
        v[j] = r;
    }

    clock_t funcStart = clock();
    mergeSort(0, n, v);
    clock_t funcEnd = clock();
    printf("Took %f milliseconds\n", (((float)(funcEnd-funcStart) / (CLOCKS_PER_SEC/1000))));
    return 0;
}