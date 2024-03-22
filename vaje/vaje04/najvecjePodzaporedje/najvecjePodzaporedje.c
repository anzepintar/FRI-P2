#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int maxVsota = -100000;
    int vsota = 0;
    for (int i = 0; i < n; i++) {
        int st;
        scanf("%d", &st);
        vsota = st + vsota;
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
