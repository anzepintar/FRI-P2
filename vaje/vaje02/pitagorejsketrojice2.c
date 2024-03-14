// ko uporabljaš math.h moraš imeti -ml pri gcc
#include <math.h>
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
        for (int a = 1; a < c; a++) {
            int bna2 = c * c - a * a;
            // ce je b celo število je abc pitagorejska trojica
            int b = round(sqrt(bna2));
            if (b * b == bna2) {
                stevilo++;
                break;
            }
        }
    }
    printf("%d\n", stevilo);
    return 0;
}
