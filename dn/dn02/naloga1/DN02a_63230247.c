#include <stdbool.h>
#include <stdio.h>

int main() {
    int i = 0;
    int pravilno = '1';
    int predznak = 0;
    int nicle = 0;
    while (true) {

        int st = getchar();
        if (!(st == '0' || st == '1' || st == '2' || st == '3' || st == '4' ||
              st == '5' || st == '6' || st == '7' || st == '8' || st == '9' ||
              st == '+' || st == '-' || st == ' ')) {

            pravilno = '0';
        }

        if (st == '+' || st == '-') {
            if (i > 0)
                pravilno = '0';
            predznak++;
        } else if (i == 0 && st == '0') {
            nicle = 1;
        } else if (st == ' ') {
            if (nicle == 1 && i > 1) {
                pravilno = '0';
            }
            if (i == 1 && predznak == 1)
                pravilno = '0';
            putchar(pravilno);
            i = -1;
            predznak = 0;
            pravilno = '1';
            nicle = 0;
        } else if (st == '\n') {
            if (nicle == 1 && i > 1) {
                pravilno = '0';
            }
            if (i == 1 && predznak == 1)
                pravilno = '0';
            putchar(pravilno);
            break;
        }
        i++;
    }
    putchar('\n');
    return 0;
}
