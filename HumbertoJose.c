#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main() {
 
    int num1, num2;
    
    scanf("%d", &num1);
    scanf("%d", &num2);
    
    int numsum = num1 + num2;
    char numsumStr[51];
    sprintf(numsumStr, "%d", numsum);
    
    for(int i=0; numsumStr[i] != '\0'; i++){
        if(numsumStr[i] == '0'){
            // memmove(&numsumStr[i], &numsumStr[i + 1], strlen(numsumStr) - i);
            continue;
        } else {
            printf("%c", numsumStr[i]);
        }
    }
    puts("");
    return 0;
}
