#include <stdbool.h>
#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    bool beri = true;
    int meja;
    while (beri) {
        scanf("%d", &meja);
        if (meja == -1) {
            b = (a + b) / 2 - 1;
        }
        if (meja == 1) {
            a = (a + b) / 2 + 1;
        }
        if (meja == 0) {
            beri = false;
        }
        if (b < a)
            break;
    }
    if (b < a) {
        printf("PROTISLOVJE\n");
    } else if (a == b) {
        printf("%d\n", a);
    } else {
        printf("%d %d\n", a, b);
    }
    return 0;
}
