#include <stdio.h>

int main() {
    int n = getchar() - '0';
    int max1 = -1;
    int max2 = -1;
    for (int i = 0; i < n; i++) {
        getchar();
        int a = getchar() - '0';
        if (a > max1) {
            max2 = max1;
            max1 = a;
        } else if (a > max2) {
            max2 = a;
        }
    }
    putchar(max2 + '0');
    putchar('\n');
    return 0;
}
