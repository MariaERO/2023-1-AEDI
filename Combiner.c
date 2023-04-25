#include <stdio.h>
 
int main() {
    
    int N;
    char str1[51], str2[51];
    int is1fin, is2fin;
    scanf("%d", &N);
    
    
    while(N>0){
        scanf("%s", str1);
        scanf("%s", str2);
        is1fin = 0;
        is2fin = 0;
        
        for(int i=0; str1[i] != '\0' || str2[i] != '\0'; i++){
            if(is1fin==1 || str1[i] == '\0'){
                is1fin = 1;
                printf("%c", str2[i]);
            }
            else if(is2fin==1 || str2[i] == '\0'){
                is2fin = 1;
                printf("%c", str1[i]);
            }
            else{
                printf("%c", str1[i]);
                printf("%c", str2[i]);
                
            }
           
            
        }
        N--;
        
        printf("\n");
    }
 
    return 0;
}
