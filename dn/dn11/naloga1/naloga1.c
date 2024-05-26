
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "naloga1.h"

Vozlisce *zdesetkaj(Vozlisce *zacetek, int k) {
    Vozlisce *a = zacetek;
    int i = 1;
    bool prvi = true;
    while (a->naslednje != NULL) {

        if (i % k == 0) {
            if (prvi) {
                zacetek = a;
                prvi = false;
            }
            a = a->naslednje->naslednje;
        } else {
            a = a->naslednje;
        }

        i++;
    }
    return zacetek;
}

#ifndef test

int main() {
    return 0;
}

#endif
