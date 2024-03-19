#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

long obrni(long n) {
    long obrnjeno = 0;
    while (n != 0) {
        long tmp = n % 10;
        obrnjeno = obrnjeno * 10 + tmp;
        n = n / 10;
    }
    return obrnjeno;
}

bool jePalindrom(long n) { return (n == obrni(n)); }

bool jeLychrelovo(long n, int k) {
    do {
        n = n + obrni(n);
        k--;
    } while (!jePalindrom(n) && n < 1e17L && k > 0);

    return jePalindrom(n);
}

int main() {
    /*   long testno;
       scanf("%d", &testno);

       if(jeLychrelovo(testno)){
           printf("ly\n");
       }
       else{
           printf("ni ly\n");
       }
   */
    // k - število iteracij, a - zgornja meja, b - spodnja meja
    int k, a, b;
    scanf("%d %d %d", &k, &a, &b);
    int steviloLySt = 0;
    for (int i = a; i < b; i++) {
        if (!jeLychrelovo(i, k))
            steviloLySt++;
    }
    printf("%d\n", steviloLySt);
    return 0;
}
