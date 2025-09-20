#include <stdio.h>
#include <stdbool.h>

//Establecemos una función que determine los números primos con la ayuda de bool
    bool Primo(int n)
{
if(n <= 1 ) return false;
if(n == 2 ) return true;

   for(int i=2; i*i<=n; i++) {
   if( n%i == 0) return false;

 } return true;
}
//Determinamos el rango de 1 a 100, donde se muestre todos los números primos dentro de el rango
int main()
{
    printf("-----------LOS NÚMEROS PRIMOS DEL 1 AL 100-----------\n");

    for(int i = 1; i <= 100; i++){
        if(Primo(i)){
            printf("%d ", i);
        }
    }


    return 0;
}
