#include <stdbool.h>
#include <stdio.h>

int MEMO[1001][1001][11];
int SMO_ZE[1001][1001][11];

int maxSkupnaCena(int *prostornine, int *cene, int v, int n, int k, int ix) {

    if (ix == n) {
        return 0;
    }
    if (SMO_ZE[ix][v][k]) {
        return MEMO[ix][v][k];
    }

    // 1. možnost: predmeta z indeksom ix ne dodamo v nahrbtnik
    int najCena = maxSkupnaCena(prostornine, cene, v, n, k, ix + 1);

    // 2. možnost: predmet z indeksom ix dodamo v nahrbtnik
    if (prostornine[ix] <= v && (k > 0 || (prostornine[ix] % 2 == 0))) {
        if (prostornine[ix] % 2 == 1) {
            k--;
        }
        int c = cene[ix] + maxSkupnaCena(prostornine, cene, v - prostornine[ix],
                                         n, k, ix + 1);
        if (c > najCena) {
            najCena = c;
        }
    }

    SMO_ZE[ix][v][k] = true;
    MEMO[ix][v][k] = najCena;

    return najCena;
}

int main() {
    // v - volumen nahrbtnika, n - število predmetov
    int v, n, k;
    scanf("%d\n%d\n%d", &v, &n, &k);
    for (int i = 0; i < n; i++) {
    }
    // int* prostornine = malloc(n*sizeof(int));
    int prostornine[n];
    // int* cene = malloc(n*sizeof(int));
    int cene[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &prostornine[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &cene[i]);
    }

    printf("%d\n", maxSkupnaCena(prostornine, cene, v, n, k, 0));
    // free(prostornine);
    // free(cene);
    return 0;
}
