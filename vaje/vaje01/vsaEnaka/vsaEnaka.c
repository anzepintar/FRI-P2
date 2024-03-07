#include <stdbool.h>
#include <stdio.h>

int main() {
    int n = getchar() - '0';
    getchar();

    bool vsaEnaka = true;
    int a = -1;

    for (int i = 0; i < n; i++) {
        int st = getchar() - '0';
        getchar();
        if (i == 0) {
            a = st;
        } else if (st != a) {
            vsaEnaka = false;
        }
    }
    putchar(vsaEnaka ? '1' : '0');
    putchar('\n');
    return 0;
}
