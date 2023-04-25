#include <stdio.h>
#include <math.h> 
 
int main() {
 
    double A, B, C;
    
    scanf("%lf\n", &A);
    scanf("%lf\n", &B);
    scanf("%lf", &C);
    
    double delta = (B*B) - (4*A*C);
    
    double divs = 2*A;
    double r1 = (-B + sqrt(delta))/divs;
    double r2 = (-B - sqrt(delta))/divs;
    
    if(delta <= 0 || divs == 0){
        printf("Impossivel calcular\n");
    } else {
        printf("R1 = %.5lf\nR2 = %.5lf\n", r1, r2);
    }
 
    return 0;
}
