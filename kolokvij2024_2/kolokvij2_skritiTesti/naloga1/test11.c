
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

const int NASLEDNJE[] = {61, 34, 79, 97, 83, 57, 31, 56, 80, 75, 47, 22, 5, 41, 35, 55, 78, 16, 0, 3, 98, 39, 17, 85, 18, 62, 63, 6, 94, 4, 86, 58, 46, 27, 20, 29, 28, 30, 45, 59, 33, 77, 32, 37, 99, 15, 43, 89, 8, 13, 100, 92, 76, 50, 14, 36, 65, 24, 1, 54, 96, 66, 90, 88, 82, 2, 81, 38, 19, 60, 95, 53, 49, 25, 52, 67, 40, 68, 21, 93, 69, 26, 73, 87, 9, 42, 51, 91, 71, 74, 48, 10, 12, 70, 7, 23, 72, 11, 84, 64};
const int PREJSNJE[] = {18, 58, 65, 19, 29, 12, 27, 94, 48, 84, 91, 97, 92, 49, 54, 45, 17, 22, 24, 68, 34, 78, 11, 95, 57, 73, 81, 33, 36, 35, 37, 6, 42, 40, 1, 14, 55, 43, 67, 21, 76, 13, 85, 46, 100, 38, 32, 10, 90, 72, 53, 86, 74, 71, 59, 15, 7, 5, 31, 39, 69, 0, 25, 26, 99, 56, 61, 75, 77, 80, 93, 88, 96, 82, 89, 9, 52, 41, 16, 2, 8, 66, 64, 4, 98, 23, 30, 83, 63, 47, 62, 87, 51, 79, 28, 70, 60, 3, 20, 44};
const int RANDOM[] = {9, 7, 21, 4, 33, 15, 48, 20, 49, 10, 59, 32, 73, 80, 74, 59, 11, 44, 14, 23, 7, 71, 38, 64, 78, 49, 68, 19, 80, 52, 56, 27, 20, 38, 77, 48, 90, 40, 7, 93, 4, 54, 51, 79, 89, 75, 49, 11, 97, 42, 95, 58, 21, 30, 36, 16, 71, 61, 90, 80, 45, 58, 83, 44, 32, 17, 60, 7, 3, 13, 86, 19, 72, 53, 89, 49, 65, 70, 51, 14, 77, 93, 83, 68, 40, 43, 24, 75, 1, 2, 57, 24, 68, 7, 61, 73, 27, 84, 19, 73};
const int N = sizeof(NASLEDNJE) / sizeof(NASLEDNJE[0]);
const int ZACETEK = 44;

int main() {
    Vozlisce** v = calloc(N + 1, sizeof(Vozlisce*));
    for (int i = 0; i < N; i++) {
        v[i] = calloc(1, sizeof(Vozlisce));
    }

    for (int i = 0; i < N; i++) {
        v[i]->naslednje = v[NASLEDNJE[i]];
        v[i]->prejsnje = v[RANDOM[i]];
    }

    nastavi(v[ZACETEK]);

    for (int i = 0; i < N; i++) {
        printf("%d", v[i]->naslednje == v[NASLEDNJE[i]]);
    }
    printf("\n");

    for (int i = 0; i < N; i++) {
        printf("%d", v[i]->prejsnje == v[PREJSNJE[i]]);
    }
    printf("\n");

    for (int i = 0; i < N; i++) {
        free(v[i]);
    }
    free(v);

    return 0;
}
