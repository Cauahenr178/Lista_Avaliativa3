#include <stdio.h>

int main(){
    
  int numMeses;
    double investimentoInicial, taxaJuros;

    scanf("%d", &numMeses);
    scanf("%lf", &investimentoInicial);
    scanf("%lf", &taxaJuros); 
    
    double montante = 0;
     for (int i = 1; i <= numMeses; i++) {
        montante += investimentoInicial;
        montante *= (1 + taxaJuros);
           printf("Montante ao fim do mes %d: R$ %.2lf\n", i, montante);
    
}

    return 0;
}
