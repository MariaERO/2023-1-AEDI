#include <stdio.h>
 
void printres(int n, int res){
    if(res == 0){
        printf("Instância %d\nNAO\n", n);
    } else{
        printf("Instância %d\nSIM\n", n);
    }
}
 
int main() {
 
    int n;
    scanf("%d", &n);
    
    int sol[9][9], i, j;
    
    int sum, element, res, counter=0;
   
    while(counter<n){
        res = 1;
        sum=0;
        for(i=0; 8 >= i; i++){
            for(j=0; 8 >= j; j++){
                scanf("%d", &sol[i][j]);
            }
        }
        
        for(i=0; 8 >= i; i++){
            sum = 0;
            for(j=0; 8 >= j; j++){
                element = sol[i][j];
                sum = sum + element;
            }
            if(sum!=45){
              res = 0;
            }
        }
        sum = 0;
         for(i=0; 8 >= i; i++){
            sum = 0;
            for(j=0; 8 >= j; j++){
                element = sol[j][i];
                sum = sum + element;
            }
            if(sum!=45){
              res = 0;
            }
        }
        
        printres(counter+1, res);
        puts("");
       
        counter++;
    }
 
    return 0;
}
