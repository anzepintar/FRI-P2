#include <stdio.h>

int stevila[1000000];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &stevila[i]);
    }

    int maxVsota = -100000;
    int vsota = 0;
    for (int i = 0; i < n; i++) {
        vsota = stevila[i] + vsota;
        if (vsota > maxVsota) {
            maxVsota = vsota;
        }
        if (vsota < 0) {
            vsota = 0;
        }
    }

    printf("%d\n", maxVsota);
    return 0;
}
