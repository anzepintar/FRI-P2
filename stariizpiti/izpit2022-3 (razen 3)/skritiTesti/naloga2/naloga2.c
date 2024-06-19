
/*
Ro"cno poganjanje testnih programov (npr. test01.c):

gcc -Dtest test01.c naloga2.c
./a.out

Samodejno testiranje:

export name=naloga2
make test

Testni primeri:

01: primer iz besedila
02..04: ena sama vrstica
05..06: vsaka neprazna vrstica je naslovna
07..10: splo"sni primeri

Datoteke:

test*.c: testni program (prebere testne podatke, pokli"ce va"so funkcijo in
izpi"se rezultat) test*.dat: testni podatki test*.out: pri"cakovani izhod
testnega programa test*.res: dejanski izhod testnega programa (pri poganjanju z
make)
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "naloga2.h"

// Lahko dodate "se kak #include, pomo"zno funkcijo ipd.

//============================================================================

void vstaviH1(Vozlisce *zacetek) {
    Vozlisce *a = NULL;
    Vozlisce *b = zacetek;
    Vozlisce *c = zacetek->naslednje;
    while (b != NULL) {
        if ((a == NULL || a->niz[0] == '\0') &&
            (c == NULL || c->niz[0] == '\0') && (b->niz[0] != '\0')) {
            char *h1s = "<h1>";
            char *h1e = "</h1>";
            char temp[1100];
            strcat(temp, h1s);
            strcat(temp, b->niz);
            strcat(temp, h1e);
            strcpy(b->niz, temp);
        }
        a = b;
        b = c;
        if (c != NULL) {
            c = c->naslednje;
        }
    }
}

//============================================================================

// Vrstici z #ifndef in #endif pustite pri miru!

#ifndef test

int main() { return 0; }

#endif
