#include <stdio.h>

int collantz(int n) {
    if (n % 2 == 0)
        return n / 2;
    else
        return n * 3 + 1;
}
int length(int n) {
    int len = 1;
    while (n != 1) {
        n = collantz(n);
        len++;
    }
    return len;
}
int main() {
    int n = 0;
    printf("%d\n", length(n));
    return 0;
}
