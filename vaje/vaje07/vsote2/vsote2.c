#include <stdio.h>
#include <stdlib.h>

void izpisi(int *cleni, int stClenov) {
    for (int i = 0; i < stClenov; i++) {
        if (i != 0)
            printf(" + ");
        printf("%d", cleni[i]);
    }
    printf("\n");
}

long steviloNacinov(int vsota, int najSest, int *cleni, int stClenov) {
    if (vsota == 0) {
        izpisi(cleni, stClenov);
        return 1;
    }
    if (vsota < 0 || najSest <= 0)
        return 0;
    // vsote, ki vsebujejo najSest
    cleni[stClenov] = najSest;
    long z = steviloNacinov(vsota - najSest, najSest, cleni, stClenov + 1);
    // vsote, pri katerih so vsi členi manjši od najSest, ne dodamo v tabelo
    long brez = steviloNacinov(vsota, najSest - 1, cleni, stClenov);
    return z + brez;
}

int main() {
    int n = 0;
    int k = 0;
    int *cleni = malloc(n * sizeof(int));
    scanf("%d %d", &n, &k);
    steviloNacinov(n, k, cleni, 0);
    // printf("Število nacinov za %d, kjer k = %d je %ld.\n", n, k,
    // steviloNacinov(n, k, cleni, 0));
    return 0;
}
