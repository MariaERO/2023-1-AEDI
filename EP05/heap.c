#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int heapify(int m, int v[]){
    int t, f = 2;
    while /*X*/ (f <= m) {
        if (f < m && v[f] < v[f+1]) ++f;
        if (v[f/2] >= v[f]) break;
        t = v[f/2]; v[f/2] = v[f]; v[f] = t;
        f *= 2;
    }
}

int heapInsert(int m, int v[]){
    int f = m+1;
    while /*X*/ (f > 1 && v[f/2] < v[f]) {
        int t = v[f/2]; v[f/2] = v[f]; v[f] = t;
        f = f/2;
    }
}

int heapSort(int n, int v[]){
    int m;
    for (m = 1; m < n; m++)
        heapInsert(m, v);
    for (m = n; /*X*/ m > 1; m--) {
        int t = v[1]; v[1] = v[m]; v[m] = t;
        heapify(m-1, v);
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
    heapSort(n, v);
    clock_t funcEnd = clock();
    printf("Took %f milliseconds\n", (((float)(funcEnd-funcStart) / (CLOCKS_PER_SEC/1000))));
    return 0;
}