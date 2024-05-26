#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    FILE *datIN = fopen(argv[1], "rt");
    FILE *datOUT = fopen(argv[2], "wt");
    int najdol = 0;
    char najvrstica[1000001];      // zaradi \0
    char trenutnavrstica[1000001]; // zaradi \0
    // getline:
    // getline(&vrstica, &alokacija, vhod) vrstica na NULL, alokacija na 0, sam
    // naredi, obvezno sporstiti pomnilnik
    while (fgets(trenutnavrstica, sizeof(trenutnavrstica), datIN)) {
        int trenutnadol = strlen(trenutnavrstica);
        if (trenutnadol > najdol) {
            strcpy(najvrstica, trenutnavrstica);
            najdol = trenutnadol;
        }
    }
    fprintf(datOUT, "%s", najvrstica);

    fclose(datIN);
    fclose(datOUT);
    return 0;
}
