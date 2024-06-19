#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *ime = argv[1];
    int x, y;
    sscanf(argv[2], "%d", &x);
    sscanf(argv[3], "%d", &y);
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
    int indeks = x * w * 3 + y * 3;
    printf("%d %d %d", vsebina[indeks], vsebina[indeks + 1],
           vsebina[indeks + 2]);

    return 0;
}
