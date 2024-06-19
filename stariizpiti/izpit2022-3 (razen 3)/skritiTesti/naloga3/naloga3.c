
/*
Ro"cno poganjanje testnih programov (npr. test01.c):

gcc -Dtest test01.c naloga3.c
./a.out

Samodejno testiranje:

export name=naloga3
make test

Testni primeri:

01: primer iz besedila
02..05: vsi elementi tabele so med seboj enaki
06..10: splo"sni primeri

Testne datoteke:

test*.c: testni program (prebere testne podatke, pokli"ce va"so funkcijo in
izpi"se rezultat) test*.dat: testni podatki test*.out: pri"cakovani izhod
testnega programa test*.res: dejanski izhod testnega programa (pri poganjanju z
make)
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "naloga3.h"

// Lahko dodate "se kak #include, pomo"zno funkcijo ipd.

//============================================================================

Vozlisce *drevo(int n, int *podatki) {
    if (n == 0)
        return NULL;
    Vozlisce *root = malloc(sizeof(Vozlisce));
    root->podatek = podatki[0];
    podatki[0] = -1;
    int *novipodatkiL = malloc((n - 1) * sizeof(int));
    int *novipodatkiD = malloc((n - 1) * sizeof(int));

    if (novipodatkiL == NULL || novipodatkiD == NULL) {
        // Handle malloc failure
        free(root);
        free(novipodatkiL);
        free(novipodatkiD);
        return NULL;
    }

    for (int i = 0; i < n - 1; i++) {
        novipodatkiL[i] = podatki[i + 1];
        novipodatkiD[i] = podatki[i + 1];
    }

    root->levo = drevo(n - 1, novipodatkiL);
    root->desno = drevo(n - 1, novipodatkiD);

    free(novipodatkiL);
    free(novipodatkiD);

    return root;
}

//============================================================================

// Vrstici z #ifndef in #endif pustite pri miru!

#ifndef test

int main() {
    // Tole dopolnite, "ce "zelite funkcijo lastnoro"cno preveriti.
    // V tem primeru program po"zenite preprosto kot
    // gcc naloga3.c
    // ./a.out
    return 0;
}

#endif
