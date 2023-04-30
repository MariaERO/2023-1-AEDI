#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int separate(int p, int r, int v[]){
    int c, j, k, t;
    c = v[r]; j = p;
    for (k = p; /*A*/ k < r; k++)
        if (v[k] <= c) {
            t = v[j], v[j] = v[k], v[k] = t;
            j++;
        }
    v[r] = v[j], v[j] = c;
    return j;
}

int quickSort(int p, int r, int v[]){
    int j;
    if (p < r) {
        j = separate(p, r, v);
        quickSort(p, j - 1, v);
        quickSort(j + 1, r, v);
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
    quickSort(0, n, v);
    clock_t funcEnd = clock();
    printf("Took %f milliseconds\n", (((float)(funcEnd-funcStart) / (CLOCKS_PER_SEC/1000))));
    return 0;
}