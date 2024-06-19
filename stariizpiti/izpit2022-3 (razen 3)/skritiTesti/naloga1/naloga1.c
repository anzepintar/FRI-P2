
/*
Ro"cno testiranje (npr. za primer 01):

gcc naloga1.c
./a.out vhod01.pgm 150 izhod01.pgm
cmp izhod01.pgm ref01.pgm

Samodejno testiranje:

export name=naloga1
make test

Lahko si pomagate tudi s programom hexdump:

hexdump -C datoteka.pgm

Testni primeri:

01: primer iz besedila
02..07: vsaka pika je bodisi 0 bodisi 255
08..12: splo"sni primeri

Testne datoteke:

test*.par: argumenti ukazne vrstice
vhod*.pgm: vhodna slika
ref*.pgm: pri"cakovana izhodna slika
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Lahko dodate "se kak #include, pomo"zno funkcijo ipd.

//============================================================================
int main(int argc, char *argv[]) {
    FILE *datIN = fopen(argv[1], "rb");
    FILE *datOUT = fopen(argv[3], "wb");
    int prag;
    sscanf(argv[2], "%d", &prag);
    char *format = malloc(2 * sizeof(char));
    fscanf(datIN, "%s", format);
    int w, h, a255;
    fscanf(datIN, "%d %d %d", &w, &h, &a255);
    fgetc(datIN);
    printf("%d, %s, %d, %d, %d", prag, format, w, h, a255);
    fprintf(datOUT, "%s\n%d %d\n%d\n", format, w, h, a255);
    unsigned char a;
    while (fscanf(datIN, "%c", &a) != EOF) {
        if (a >= prag) {
            a = 255;
        } else {
            a = 0;
        }
        fputc(a, datOUT);
    }
    fclose(datIN);
    fclose(datOUT);
    return 0;
}
