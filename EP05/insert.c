#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int insertionSort(int n, int v[]){
    int i, j, x;
    for (j = 1; j < n; j++) {
        x = v[j];
        for (i = j-1; i >= 0 && v[i] > x; i--)
            v[i+1] = v[i];
        v[i+1] = x;
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
    insertionSort(n, v);
    clock_t funcEnd = clock();
    printf("Took %f milliseconds\n", (((float)(funcEnd-funcStart) / (CLOCKS_PER_SEC/1000))));
    return 0;
}