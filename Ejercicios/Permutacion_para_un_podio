/*
  El programa cuenta las diferentes formas de ordenar un podio entre n corredores.
  Se calcula gracias a la formula de permutación sin repeticion:
  n!/(n-k)!
*/
#include <stdio.h>

int sacarFactorial(int);
int formulaPermutacion(int);

int main()
{
    int corredores;
    int total;
    printf("Ingresa el total de corredores:\n");
    scanf("%d", &corredores );
    total = formulaPermutacion(corredores);
    printf("Existen %d formas en las que se formar un podio.", total);
 
    return 0;
}

int sacarFactorial(int numero){
    int factorial=1;
    for( ; numero > 0 ; numero--){
        factorial=numero*factorial;
    }
return factorial; 
}

int formulaPermutacion(int m){
    int permutacion = sacarFactorial(m) / sacarFactorial(m-3);
return permutacion;
    
}
