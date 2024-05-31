
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga2
 * make test
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// po potrebi dopolnite ...

int main(int argc, char **argv) {
    FILE *datIN = fopen(argv[1], "rt");
    FILE *datOUT = fopen(argv[2], "wt");
    int m;
    sscanf(argv[3], "%d", &m);
    char vrstica[100][100][101];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(datIN, "%s", vrstica[i][j]);
        }
    }
    char vhod[argc][100];
    for (int i = 0; i < argc - 4; i++) {
        strcpy(vhod[i], argv[i + 4]);
        // fprintf(datOUT, "%s\n", vhod[i]);
    }
    bool prvi = true;
    for (int i = 0; i < m; i++) {
        int k = 0;
        for (int j = 0; j < m; j++) {
            if (strcmp(vhod[k], vrstica[0][j]) == 0) {
                if (prvi) {
                    fprintf(datOUT, "%s", vrstica[i][j]);
                    prvi = false;
                } else {
                    fprintf(datOUT, ",%s", vrstica[i][j]);
                }
                k++;
            }
        }
        fprintf(datOUT, "\n");
        prvi = true;
    }
    return 0;
}
