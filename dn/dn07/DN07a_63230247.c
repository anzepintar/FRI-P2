#include <stdio.h>
#include <stdlib.h>

int visina(int n, int *a, int *b, int koren) {
    if (koren == 0)
        return 0;
    else {
        int levo = visina(n, a, b, koren);
        int desno = visina(n, a, b, koren);
        return 1 + (levo > desno ? levo : desno);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int *a = calloc(n, sizeof(int));
    int *b = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }
    printf("%d\n", visina(n, a, b, 1));
    /*for (int i = 0; i<n; i++) {
        printf("%d %d\n", a[i], b[i]);
    }*/
    free(a);
    free(b);
    return 0;
}
