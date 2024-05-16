
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "naloga.h"

int vsotaI(Vozlisce *zacetek) {
    Vozlisce *a = zacetek;
    int sum = 0;
    while (a != NULL) {
        sum += a->podatek;
        a = a->naslednje;
    }
    return sum;
}

int vsotaR(Vozlisce *zacetek) {
    // preveri če kazalec začetek sploh kaj vsebuje
    if (zacetek == NULL) {
        return 0;
    }
    return vsotaR(zacetek->naslednje) + zacetek->podatek;
}

Vozlisce *vstaviUrejenoI(Vozlisce *zacetek, int element) {
    Vozlisce *a;
    Vozlisce *predA = NULL;
    if (zacetek != NULL) {
        a = zacetek;
        while (a != NULL && a->podatek < element) {
            predA = a;
            a = a->naslednje;
        }
    }
    Vozlisce *novo = malloc(sizeof(Vozlisce));
    novo->podatek = element;
    if (zacetek != NULL) {
        novo->naslednje = a;
    }
    if (predA != NULL) {
        predA->naslednje = novo;
    }
    if (zacetek != NULL) {
        return (zacetek->podatek < novo->podatek) ? zacetek : novo;
    }
    return novo;
}

Vozlisce *vstaviUrejenoR(Vozlisce *zacetek, int element) {
    if (zacetek == NULL || element <= zacetek->podatek) {
        Vozlisce *novo = malloc(sizeof(Vozlisce));
        novo->podatek = element;
        novo->naslednje = zacetek;
        return novo;
    }

    zacetek->naslednje = vstaviUrejenoR(zacetek->naslednje, element);
    return zacetek;

    // samo sprehod po seznamu
    // if (zacetek == NULL || element <= zacetek->podatek) {return zacetek;}
    // zacetek->naslednje = vstaviUrejenoR(zacetek->naslednje, element);
    // return zacetek;
}

#ifndef test

int main() { return 0; }

#endif
