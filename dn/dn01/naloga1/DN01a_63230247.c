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
int dobiStevilo() {
    int st = 0;
    int predznak = 1;
    int potenca = 1;
    int i = 0;
    int st0 = 0;
    while (0 == 0) {
        i++;
        int n = getchar();
        if (n == ' ' || n == '\n') {
            break;
        }
        if (n == '-') {
            predznak = -1;
        } else {
            if (n == '0') {
                st0++;
            } else {
                st0 = 0;
            }
            st = st + (n - '0') * potenca;
            potenca = potenca * 10;
        }
    }
    st = obrni(st, st0) * predznak;
    return st;
}

int main() {
    int a = dobiStevilo();
    int b = dobiStevilo();
    int sum = a + b;

    izpis(sum);
    putchar('\n');

    return 0;
}
