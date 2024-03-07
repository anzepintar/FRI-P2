#include <stdio.h>

int obrni(int n, int st0) {
    int obrnjeno = 0;
    while (n > 0) {
        obrnjeno = obrnjeno * 10 + n % 10;
        n = n / 10;
    }
    int potenca = 1;
    for (int i = 0; i < st0; i++) {
        potenca = potenca * 10;
    }
    return obrnjeno * potenca;
}

void izpis(int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        izpis(n / 10);
    putchar(n % 10 + '0');
}

int main() {
    int a;
    int aPredznak = 1;
    int aPotenca = 1;
    int i = 0;
    int st0a = 0;
    while (0 == 0) {
        i++;
        int n = getchar();
        if (n == ' ') {
            break;
        }
        if (n == '-')
            aPredznak = -1;
        else {
            if (n == '0') {
                st0a++;
            } else {
                st0a = 0;
            }
            a = a + (n - '0') * aPotenca;
            aPotenca = aPotenca * 10;
        }
    }
    a = obrni(a, st0a) * aPredznak;

    int b;
    int bPredznak = 1;
    int bPotenca = 1;
    int j = 0;
    int st0b = 0;
    while (0 == 0) {
        j++;
        int n = getchar();
        if (n == ' ' || n == '\n') {
            break;
        }
        if (n == '-') {
            bPredznak = -1;
        } else {
            if (n == '0') {
                st0b++;
            } else {
                st0b = 0;
            }
            b = b + (n - '0') * bPotenca;
            bPotenca = bPotenca * 10;
        }
    }
    b = obrni(b, st0b) * bPredznak;

    int sum = a + b;

    izpis(sum);
    putchar('\n');

    return 0;
}
