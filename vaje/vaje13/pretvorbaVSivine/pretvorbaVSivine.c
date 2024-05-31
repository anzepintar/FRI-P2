#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *ime = argv[1];
    char *imeizhoda = argv[2];
    // printf("%s %d %d\n", ime, x, y);
    FILE *datIN = fopen(ime, "rb");
    char *format = malloc(sizeof(char) * 5);
    fscanf(datIN, "%s", format);
    int w, h;
    fscanf(datIN, "%d %d", &w, &h);
    int a255;
    fscanf(datIN, "%d", &a255);
    fgetc(datIN);

    unsigned char *vsebina = malloc(sizeof(unsigned char) * w * h * 3);
    fread(vsebina, sizeof(unsigned char), w * h * 3, datIN);
    unsigned char *novaVsebina = malloc(sizeof(unsigned char) * w * h);
    int dol = w * h;
    int i = 0;
    while (i < dol) {
        int barva = vsebina[3 * i]*30 + vsebina[3 * i + 1]*59 + vsebina[3 * i + 2]*11;
        barva = barva/100;
        novaVsebina[i] = barva;
        i++;
    }
 /*   for (int j = 0; j < 6; j++) {
        printf("%d ", novaVsebina[j]);
    }*/

    FILE *datOUT = fopen(imeizhoda, "wb");
    fprintf(datOUT, "%s\n", "P5");
    fprintf(datOUT, "%d %d\n%d\n", w, h, 255);
    fwrite(novaVsebina, sizeof(unsigned char), w*h, datOUT);

    return 0;
}
