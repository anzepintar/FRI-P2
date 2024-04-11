#include <stdbool.h>
#include <stdio.h>

bool SMO_ZE[401][401];
long MEMO[401][401];

long steviloNacinov(int vsota, int najSest) {
    if (najSest > vsota)
        najSest = vsota;
    if (vsota == 0)
        return 1;
    if (najSest <= 0 || vsota < 0)
        return 0;
    if (SMO_ZE[vsota][najSest]) {
        return MEMO[vsota][najSest];
    }
    long z = steviloNacinov(vsota - najSest, najSest);
    long brez = steviloNacinov(vsota, najSest - 1);
    SMO_ZE[vsota][najSest] = true;
    MEMO[vsota][najSest] = z + brez;
    return z + brez;
}

int main() {
    int n = 0;
    int k = 0;
    scanf("%d %d", &n, &k);
    printf("Število nacinov za %d, kjer k = %d je %ld.\n", n, k,
           steviloNacinov(n, k));
    return 0;
}
