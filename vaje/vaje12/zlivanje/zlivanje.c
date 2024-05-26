#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    char *ime = malloc(101 * sizeof(char));
    FILE **datIN = malloc(n * sizeof(FILE *));
    for (int i = 0; i < n; i++) {
        scanf("%s", ime);
        datIN[i] = fopen(ime, "rt");
    }
    scanf("%s", ime);
    FILE *datOUT = fopen(ime, "wt");

    int *prvi = malloc(n * sizeof(int));
    int stevec = 0;
    for (int i = 0; i < n; i++) {
        int a;
        int b = fscanf(datIN[i], "%d", &a);
        if (b > 0) {
            prvi[i] = a;
        } else {
            prvi[i] = -1;
            stevec++;
        }
    }
    //   fprintf(datOUT, "n %d, stevec%d", n, stevec);
    while (stevec < n) {
        int min = 0;
        int trenutno = 1;
        int i = 0;
        int minI = 0;
        while (i < n) {
            trenutno = prvi[i];
            if (trenutno != -1 && trenutno < min) {
                min = trenutno;
                minI = i;
            }
            i++;
        }
        fprintf(datOUT, "%d\n", min);

        int b = fscanf(datIN[minI], "%d", &prvi[minI]);
        if (b < 0) {
            prvi[minI] = -1;
            stevec++;
        }
    }
    for (int i = 0; i < n; i++) {
        fclose(datIN[i]);
    }
    fclose(datOUT);
    free(ime);
    free(datIN);
    free(prvi);
    return 0;
}
