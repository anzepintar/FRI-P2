#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv) {
    FILE *datIN = fopen(argv[1], "rt");
    char *tabela[100][100];
    char vrstica[1000];
    char *locilo = ";";
    int a = 0;
    int ba = 0;
    while (fgets(vrstica, sizeof(vrstica), datIN)) {
        int b = 0;
        char *beseda = strtok(vrstica, locilo);

        while (beseda != NULL) {
            tabela[a][b] = malloc(strlen(beseda));
            strcpy(tabela[a][b], beseda);
            beseda = strtok(NULL, locilo);
            b++;
        }
        // da dobiš število besed prve vrstice
        if (a == 0) {
            ba = b;
        }
        a++;
    };
    a--;
    // izpis
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < ba; j++) {
            printf("%s ", tabela[i][j]);
        }
        printf("\n");
    }
    // memory free
    fclose(datIN);
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < ba && tabela[i][j] != NULL; j++) {
            free(tabela[i][j]);
        }
    }

    return 0;
}
