#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int vsotaPravihDeliteljev(int st) {
    int vsota = 0;

    for (int i = 1; i <= sqrt(st); i++) {
        if (st % i == 0) {
            vsota += i;
            if (st / i != i && st / i != st) {
                vsota += st / i;
            }
        }
    }
    return vsota;
}

int main() {
    int n;
    scanf("%d", &n);
    int kandidat = vsotaPravihDeliteljev(n);

    if (vsotaPravihDeliteljev(kandidat) == n) {
        printf("%d\n", kandidat);
    } else {
        printf("NIMA\n");
    }
    return 0;
}
