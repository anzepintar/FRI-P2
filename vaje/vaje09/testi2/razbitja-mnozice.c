#include <stdio.h>
#include <stdlib.h>

int razbitje(int n, int sum, int *tab, int indeks, int *rezultat) {
    sum = sum - tab[indeks];
    if (sum == 0) {
        printf("{");
        for (int k = 0; k < n; k++) {
            printf("%d, ", rezultat[k]);
        }
        printf("}\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        rezultat[indeks] = tab[indeks];
        razbitje(n, sum, tab, i, rezultat);
    }

    return 0;
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
    int *rezultat = calloc(n + 1, sizeof(int));
    razbitje(n, sum / 2, tab, 0, rezultat);
    return 0;
}
