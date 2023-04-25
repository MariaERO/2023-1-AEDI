#include <stdio.h>

typedef struct CD{
  char name;
  int date, month, year;
  double price;
  int membersNum;
  char prod;
};

int main(){
  struct CD ceedee[10];
  int i, n;
  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf("%s", &ceedee[i].name);
    scanf("%d", &ceedee[i].date);
    scanf("%d", &ceedee[i].month);
    scanf("%d", &ceedee[i].year);
    scanf("%lf", &ceedee[i].price);
    scanf("%d", &ceedee[i].membersNum);
    scanf("%s", &ceedee[i].prod);
  };
  
  
  return 0;
}
