#include <stdio.h>
#include <stdlib.h>

void izpis(int indeks, int n, char c1, char c2, char *niz) {
    if (n > 0) {
        for (char i = c1; i <= c2; i++) {
            niz[indeks] = i;
            niz[indeks+1] = '\0';
            printf("%s\n", niz);
            n--;
            izpis(indeks + 1, n, i, c2, niz);
        }
    }
}

int main() {
    int n;
    char c1, c2;
    char *niz = calloc(21, sizeof(char));
    scanf("%d %c %c", &n, &c1, &c2);
    izpis(0, n, c1, c2, niz);
    return 0;
}
