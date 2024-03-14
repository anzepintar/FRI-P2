#include <stdbool.h>
#include <stdio.h>

int main() {
    int sm, zm;
    // ce ne initializiramo lahko dobimo kar koli kot stevilo
    int stevilo = 0;

    // %d - digit, %c - char, %s - sting, %f - float, %e, %g
    scanf("%d %d", &sm, &zm);
    // & se uporablja za dostop do pomnilniškega prostora
    // c^2= a^2 + b^2
    for (int c = sm; c <= zm; c++) {
        bool trojica = false;
        for (int a = 1; a < c; a++) {
            for (int b = a + 1; b < c; b++) {
                if (a * a + b * b == c * c) {
                    stevilo++;
                    trojica = true;
                    break;
                }
            }
            if (trojica)
                break;
        }
    }
    printf("%d\n", stevilo);
    return 0;
}
