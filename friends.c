#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  char* name;
  struct Node *next;
}Node;
typedef struct Node * Pnode;

Pnode create_node(char* data){
  Pnode node;
  node = (struct Node *)malloc(sizeof(Node));
  
  (*node).name = data;
  (*node).next = NULL;
  return node;
}

/*void printList(Pnode *prev){
  while(prev != NULL){
    printf("%s\n",(*prev).name);
    prev = (*prev).next;
  }
}
*/
void insertMiddle(){
  
}


int main() {
  Pnode head;
  Pnode newF;
  Pnode prev;
  head = NULL;
  char holder[100];
  
  Pnode head2;
  Pnode newF2;
  Pnode prev2;
  head2 = NULL;
  char holder2[100];
  
  char recomF[10];
  
  //old list
  scanf("%s", holder);
  int fcounter = 1;
  head = create_node(holder);
  
  scanf("%s" , holder);
  prev = head;
  
  while(holder!= NULL){
    newF = create_node(holder);
    (*prev).next = newF;
    
    
    scanf("%s" , holder);
    prev = newF;
  
    fcounter+=1;
}
  
  //new list
  scanf("%s", holder2);
  int fcounter2 = 1;
  head2 = create_node(holder2);
  
  scanf("%s" , holder2);
  prev2 = head2;
  
  while(holder2!= NULL){
    newF2 = create_node(holder2);
    (*prev2).next = newF2;
    
    
    scanf("%s" , holder2);
    prev2 = newF2;
  
    fcounter2+=1;
  }
  
  scanf("%s", recomF);
  
  if(recomF == "nao"){
    for(int i = 0; i<(fcounter) && i<(fcounter2); i++){
      (*prev).next = head2;
      //printList(prev);
    }
  }
  
  return 0;
}



(*((*head).next).next).name

Jones Pedro Carlos Lucas
Juca Valdineia Jovander
Carlos
