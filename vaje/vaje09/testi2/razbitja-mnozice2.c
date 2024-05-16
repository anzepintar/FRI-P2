#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void razbitja(int *mnozica, int stElementov, int kolikoSe, bool *dodano,
              int nasIndeks) {
    if (kolikoSe < 0)
        return;

    if (kolikoSe == 0) {

        printf("{");
        bool prvic = true;
        for (int i = 0; i < stElementov; i++) {
            if (dodano[i]) {
                if (prvic) {
                    printf("%d", mnozica[i]);
                }
                printf(", %d", mnozica[i]);
            }
            printf("}\n");
        }
    }
    for (int i = nasIndeks; i < stElementov; i++) {
        if (mnozica[i] < kolikoSe) {
            dodano[i] = true;
            razbitja(mnozica, stElementov, kolikoSe, dodano, i + 1);
            dodano[i] = false;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int *tab = calloc(n + 1, sizeof(int));
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tab[i]);
        sum += tab[i];
    }
    bool *dodadno = calloc(n + 1, sizeof(bool));

    razbitja(tab, n, sum / 2, dodadno, 0);
    free(tab);
    free(dodadno);
    return 0;
}
