#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARG 1024

struct Node {
  char* name;
  struct Node *next;
}Node;
typedef struct Node * Pnode;

int parse(char * line, char ** argv, char * delimiter) {
  int argc = 0;//counter of components
  char * token = strtok(line, delimiter);//token holder
  while (token != NULL) {
    argv[argc++] = token; //store token
    token = strtok(NULL, delimiter);
  }
  argv[argc] = NULL;
  return argc;
}

Pnode create_node(char* data){
  Pnode new_node;
  new_node = (struct Node *)malloc(sizeof(Node));
  
  (*new_node).name = data;
  (*new_node).next = NULL;
  return new_node;
}

int search_node(Pnode head, char* data){
  int i=0;
  
  Pnode tmp;
  tmp = head;
  while(tmp != NULL){
    if (strcmp(tmp->name, data) == 0) {
            // If the string is found, return its index
            return i;
      }
    i+=1;
    tmp = tmp->next;
  } 
  return i;
}



void printft(Pnode head, int from, int to){
    Pnode tmp = head;
    int i = 0;
    while(from > 0 && tmp != NULL){
      tmp = tmp->next;
      from -= 1;
    }
    
    while(to > 0 && tmp != NULL){
      printf("%s\n", tmp->name);
      tmp = tmp->next;
      to -= 1;
    }
}
int main(){
    char* line;
    char* line2;
    size_t llen=0;
    char** mat1;
    mat1 = malloc(sizeof(char**)*MAX_ARG);
    
    getline(&line, &llen, stdin);
    int l1s = parse(line, mat1 , " \n");
    
    Pnode head1;
    Pnode prev;
    
    head1 = create_node(*(mat1));
    prev = head1;
    Pnode tmp;
    
    for(int i= 1; *(mat1+i) != NULL; i++){
        tmp = create_node(*(mat1+i));
        (*prev).next = tmp;
        
        prev = tmp;
    }
    
    
    //new list
    char ** mat2;
    mat2 = malloc(sizeof(char**)*MAX_ARG);
    getline(&line2, &llen, stdin);
    int l2s = parse(line2, mat2 , " \n");
    
    Pnode head2;
    
    head2 = create_node(*(mat2));
    prev = head2;
    
    for(int i= 1; *(mat2+i) != NULL; i++){
        tmp = create_node(*(mat2+i));
        (*prev).next = tmp;
        
        prev = tmp;
    }
    
    char* cond;
    cond = malloc(sizeof(char*));
    
    scanf("%s", cond);
    
    if(!strcmp(cond,"nao")){//se igual
          printft(head1, 0, l1s);
          printft(head2, 0, l2s);
          
    }else{
        int pos = search_node(head1, cond);
        printft(head1, 0, pos);
        printft(head2, 0, l2s);
        printft(head1, pos, l1s);
        
        
        //print segunda na posição da lista após encontrar o node cuja data = cond
    
    
    }
    
    
    
    
    
    

    
    free(mat1);
    free(mat2);
    free(line);
    
    
    

}
