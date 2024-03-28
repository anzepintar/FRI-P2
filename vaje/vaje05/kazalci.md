# Kazalci in nizi

## Kazalci

Kazalci kažejo nek naslovni prostor

```c
int * p;

*p = 3;

p // lokacija na kateri je vrednost 3 -> npr. 10000
*p // vrednost na naslovu -> npr. 3
&p // lokacija na kateri je kazalec p -> npr. 20000

```

Obstajajo tudi dvojni Kazalci. 
Če damo na primer `*r = p`, lahko dostopamo do vrednosti v `p` z `**r`.

```c
int* t = (int*) malloc(5*sizeof(int)); // rezervira prostor za 5 int (5*4Byte)
free(t); // sprostitev prostora


int* r = (int*) calloc(5, sizeof(int)); // rezervira prostor za 6 int (5*4Byte) in jih nastavi na 0

free(r);

```

## Nizi

```c
char* niz = "CETRTEK";

/*
|C|E|T|R|T|E|K|\0| -> dolzina je 7, \n moramo dodati sami
*/

```


