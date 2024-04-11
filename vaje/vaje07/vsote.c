#include <stdio.h>

long steviloNacinov(int vsota, int najSest) {
    if (vsota == 0)
        return 1;
    if (najSest <= 0 || vsota < 0)
        return 0;
    long z = steviloNacinov(vsota - najSest, najSest);
    long brez = steviloNacinov(vsota, najSest - 1);
    return z + brez;
}

int main() {
    int n = 0;
    int k = 0;
    scanf("%d %d", &n, &k);
    printf("Število nacinov za %d, kjer k = %d je %ld\n.", n, k,
           steviloNacinov(n, k));
    return 0;
}
