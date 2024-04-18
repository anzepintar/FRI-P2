#include <stdbool.h>
#include <stdio.h>

int MEMO[1001][1001];
int SMO_ZE[1001][1001];

int maxSkupnaCena(int *prostornine, int *cene, int v, int n, int ix) {

    if (ix == n) {
        return 0;
    }
    if (SMO_ZE[ix][v])
        return MEMO[ix][v];
    // 1. možnost: predmeta z indeksom ix ne dodamo v nahrbtnik
    int najCena = maxSkupnaCena(prostornine, cene, v, n, ix + 1);
    // 2. možnost: predmet z indeksom ix dodamo v nahrbtnik
    if (prostornine[ix] <= v) {
        int c = cene[ix] + maxSkupnaCena(prostornine, cene, v - prostornine[ix],
                                         n, ix + 1);
        if (c > najCena) {
            najCena = c;
        }
    }
    SMO_ZE[ix][v] = true;
    MEMO[ix][v] = najCena;

    return najCena;
}

int main() {
    // v - volumen nahrbtnika, n - število predmetov
    int v, n;
    scanf("%d\n%d", &v, &n);
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

    printf("%d\n", maxSkupnaCena(prostornine, cene, v, n, 0));
    // free(prostornine);
    // free(cene);
    return 0;
}
