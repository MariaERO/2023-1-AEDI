#include <stdio.h>

int main() {
    char code[50], c;
    int N;
    int iter;
    
    scanf("%d", &iter);
    
    while(iter>0){
        
        scanf("%s", code);
        scanf("%d", &N);
        
        for (int i = 0; code[i] != '\0'; i++) {
          c = code[i];

          if (c >= 'A' && c <= 'Z') {
            c = 'A' + ((c - 'A' - N + 26) % 26);
          }
          printf("%c", c);
        }
    
    printf("\n");
    
        iter--;
   }
    
    return 0;
}






