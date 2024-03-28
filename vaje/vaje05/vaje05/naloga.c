
#include <stdio.h>
#include <stdlib.h>

#include "naloga.h"

int vsota(int *zac, int *kon) {
    int sum = 0;
    for (int *i = zac; i <= kon; i++) {
        sum += *i;
    }

    return sum;

    /*

    int rezultat = 0;
    int* p= zac;
    while(p<=kon){
        rezultat += *p;
        p++;
    }
    retun rezultat;
    */
}

void indeksInKazalec(int *t, int *indeks, int **kazalec) {
    if (*indeks == -1) {
        *indeks = t - *kazalec;
    } else {
        *kazalec = t + *indeks;
    }
}

void frekvenceCrk(char *niz, int **frekvence) {
    int *t = (int *)calloc(26, sizeof(int));
    *frekvence = t;
    char *i = niz;
    while (*i != '\0') {
        if (*i >= 97) {
            int indeks = *i - 97;
            t[indeks]++;
        } else {
            int indeks = *i - 65;
            t[indeks]++;
        }
        i++;
    }

    /*while(*(niz+i)!='\0'){
        if(*(niz+i)>=97){
            *(niz+i)=*(niz+i)-97;
            t[*(niz+i)]++;
        }
        else if(*(niz+i)>=65){
            *(niz+i)=*(niz+i)-65;
            t[*(niz+i)]++;
        }
        i++;
    }*/
}

#ifndef test

int main() {
    int t[] = {3, 2, 4, 2, 6, 8, 2, 8, 5};
    printf("%d\n", vsota(t, t));
    printf("%d\n", vsota(t, t + 8));
    printf("%d\n", vsota(t + 2, t + 3));
    return 0;
}

#endif
