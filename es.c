#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool is_prime(int n) {
    if (n <= 1) {
        return false;  // 0 and 1 are not prime numbers
    }

    for (int i = 2;  i <n; ++i) {
        if (n % i == 0) {
            return false;  // n is divisible by i, so it's not prime
        }
        else
         return true;  // n is not divisible by any number between 2 and sqrt(n)
    }

   
}
int* create_array(int taille){
    int *T;
    int i;
    srand(time(NULL));
    T=malloc(sizeof(int)*taille);
    for(i=0;i<taille;i++){
        T[i]=rand()%10;
    }
    return T;
}

int main() {
    int number;
    int n=10;
    int *T;
    int i;
    printf("Enter a number: ");
    scanf("%d", &number);

    if (is_prime(number)) {
        printf("%d is a prime number.\n", number);
    } else {
        printf("%d is not a prime number.\n", number);
    }

    T=malloc(sizeof(int)*n);
    T=create_array(n);
    for(i=0;i<n;i++){
       printf("%d ",T[i]);
    }
    free(T);
   
    





    return 0;
}

