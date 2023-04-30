#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int SelectionSort(int n, int v[]){
    int i, j, min, x;
    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++)
            if (v[j] < v[min]) min = j;
        x = v[i]; v[i] = v[min]; v[min] = x;
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
    SelectionSort(n, v);
    clock_t funcEnd = clock();
    printf("Took %f milliseconds\n", (((float)(funcEnd-funcStart) / (CLOCKS_PER_SEC/1000))));
    return 0;
}