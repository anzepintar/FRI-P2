#include <stdio.h>
void combs(int *a, int n, int k, int f) {
    if (f == 0) {
        for (int i = 0; i < n; i++) {

            printf("%d", a[i]);
        }
        printf("\n");
        return;
    } else {
        for (int i = 0; i < k; i++) {
            a[f - 1] = i;
            combs(a, n, k, f - 1);
        }
        return;
    }
}

int main() {
    int c[100];
    combs(c, 7, 3, 7);
    return 0;
}
