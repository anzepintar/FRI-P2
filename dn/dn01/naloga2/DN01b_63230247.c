#include <stdio.h>

void izpis(int n) {
    if (n / 10)
        izpis(n / 10);
    putchar(n % 10 + '0');
}
int main() {
    int stevec = 0;
    int zacetek = 0;
    int same0 = 1;
    while (0 == 0) {
        int n = getchar();
        if (n == '\n') {
            break;
        }
        n = n - '0';
        if (n == 1) {
            zacetek = 1;
        }
        if (zacetek == 1) {
            stevec++;
            if (stevec > 1 && n == 1) {
                same0 = 0;
            }
        }
    }
    if (same0 == 1)
        stevec = stevec - 1;
    izpis(stevec);
    putchar('\n');
    return 0;
}
