
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "naloga.h"

int steviloZnakov(char *niz, char znak) {
    int st = 0;
    for (int i = 0; i < strlen(niz); i++) {
        if (niz[i] == znak) {
            st++;
        }
    }
    return st;
}

char *kopirajDoZnaka(char *niz, char znak) {
    /*int dolzinaNiza = strlen(niz);
    char *pZnak = strchr(niz, znak);

    int dolzinaPodniza = (pZnak == NULL) ? (dolzinaNiza) : (pZnak - niz);

    char *kopija = malloc((dolzinaPodniza + 1) * sizeof(char));

    strncpy(kopija, niz, dolzinaPodniza);

    kopija[dolzinaPodniza] = '\0';
    return kopija;
*/
    char *zacetek = niz;
    char *konec = strchr(niz, znak);
    int dolzina = konec-zacetek;
    char* vrni;
    if (konec != NULL) {
            vrni = malloc((dolzina+1)*sizeof(char));

        strncpy(vrni, zacetek, dolzina);
        vrni[dolzina]='\0';

    } else {
        vrni = malloc((strlen(niz)+1)*sizeof(char));
        /*printf("aa");
        printf("%s vrni\n", vrni);
        printf("%s niz\n", niz);
        strncpy(vrni, niz, 10);*/
        vrni[strlen(niz)]='\0';

    }
    //printf("%s",konec);
    return vrni;
}

char **razcleni(char *niz, char locilo, int *stOdsekov) {
    int stOds = steviloZnakov(niz, locilo) + 1;
    char **tab = malloc(stOds * sizeof(char *));
    for (int i = 0; i < stOds; i++) {
        tab[i] = kopirajDoZnaka(niz, locilo);
        niz += strlen(tab[i]) +1;
    }
        return tab;
    *stOdsekov = stOds;
    return tab;
}

#ifndef test

int main() {
    char *test1 = "abcdefghiaa3421dfwafsaadfdadfassdfaa";
    printf("%d\n", steviloZnakov(test1, 'a'));
    printf("%s\n", kopirajDoZnaka(test1, '1')); // vrne abc....a342
    // printf("%s\n", kopirajDoZnaka(test1, '0')); // ne vsebuje tega znaka,
    // vrne cel niz

    return 0;
}

#endif
