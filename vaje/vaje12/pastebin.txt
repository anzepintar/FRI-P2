#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DOLZINA_IMENA 101

int indeksMinimuma(int* t, int n) {
	int iMin = -1;
	for(int i = 0; i < n; i++) {
		if(t[i] >= 0 && (iMin < 0 || t[i] < t[iMin])) {
			iMin = i;
		}
	}
	return iMin;
}

int main() {
	int stVhodnihDatotek;
	scanf("%d", &stVhodnihDatotek);
	
	//ustvarimo tabelo za imena datotek
	char* imeDatoteke = malloc(MAX_DOLZINA_IMENA * sizeof(char));
	
	//odpremo vhodne datoteke 
	FILE** vhodi = malloc(stVhodnihDatotek * sizeof(FILE*));
	for(int i = 0; i < stVhodnihDatotek; i++) {
		scanf("%s", imeDatoteke);
		vhodi[i] = fopen(imeDatoteke, "r");
	}
	scanf("%s", imeDatoteke);
	FILE* izhod = fopen(imeDatoteke, "w");
	
	// blok[i]: nazadanje prebrani element iz datoteke vhod[i]
	// oziroma -1, če smo pri tej datoteki že prispeli do konca 
	int* blok = malloc(stVhodnihDatotek * sizeof(int));
	
	int stKoncanih = 0;
	
	//iz vsake datoteke preberemo prvi element in ga prepišemo v pripadajočo celico bloka
	//če je datoteka prazna, vpišemo -1
	for(int i = 0; i < stVhodnihDatotek; i++){
		if(fscanf(vhodi[i], "%d", &blok[i]) < 0) {
			blok[i] = -1;
			stKoncanih++;			
		} 
	}
	
	while(stKoncanih < stVhodnihDatotek) {
		//izpišemo najmanjši element bloka (brez upoštevanja -1)
		int iMin = indeksMinimuma(blok, stVhodnihDatotek);
		fprintf(izhod, "%d\n", blok[iMin]);
		//izpisani element nadomestimo z naslednjim številom iz datoteke
		//vhodi[iMin] oziroma z -1, če smo pri tej datoteki prišli do konca
		if(fscanf(vhodi[iMin], "%d", &blok[iMin]) < 0) {
			blok[iMin] = -1;
			stKoncanih++;
		}
		
	}
	
	for(int i = 0; i < stVhodnihDatotek; i++) {
		fclose(vhodi[i]);
	}
	fclose(izhod);
	free(imeDatoteke);
	free(vhodi);
	return 0;
}


_________________________



#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* vhod = fopen(argv[1], "rt");
    FILE* izhod = fopen(argv[2], "wt");

    char* vrstica = NULL;
    size_t alokacija = 0;

    int najDolzina = 0;
    char* najVrstica = NULL;

    while (getline(&vrstica, &alokacija, vhod) >= 0) {
        int dolzina = strlen(vrstica);
        if (dolzina > najDolzina) {
            najDolzina = dolzina;
            free(najVrstica);
            najVrstica = malloc((dolzina + 1) * sizeof(char));
            strcpy(najVrstica, vrstica);
        }
    }
    free(vrstica);

    fprintf(izhod, "%s", najVrstica);
    free(najVrstica);

    fclose(vhod);
    fclose(izhod);

    return 0;
}
