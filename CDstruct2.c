#include <stdio.h>

typedef struct CD{
  char name;
  int date, month, year;
  double price;
  int membersNum;
  char prod;
};

int main(){
  struct CD *ceedee;
  ceedee tbl[10];
  int i, n;
  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf("%s", &tbl[i].name);
    scanf("%d", &tbl[i].date);
    scanf("%d", &tbl[i].month);
    scanf("%d", &tbl[i].year);
    scanf("%lf", &tbl[i].price);
    scanf("%d", &tbl[i].membersNum);
    scanf("%s", &tbl[i].prod);
  };
  
  
  return 0;
}
