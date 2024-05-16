#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void razbitja2(int* mnozica, int n, int kolikoSe, bool* dodano, int ix){
    if(kolikoSe < 0){
        return;
    }
    
    if(kolikoSe == 0){
    //print
        bool prvic = true;
        printf("{");
        for(int i = 0; i < n; i++){
            if(dodano[i]){
                if(!prvic){
                    printf(", ");
                }
                printf("%d", mnozica[i]);
                prvic = false;
            }
        }
        printf("}\n");
        return;
    }
    
    for(int i = ix; i < n; i++){
        if(mnozica[i] <= kolikoSe){
            dodano[i] = true;
            razbitja(mnozica, n, kolikoSe - mnozica[i], dodano, i + 1);
            dodano[i] = false;
        }
    
    }

}



void razbitja(int* mnozica, int n, int kolikoSe, bool* dodano, int ix){
    if(ix > n){
        return;
    }
    
    if(kolikoSe == 0){
    //print
        bool prvic = true;
        printf("{");
        for(int i = 0; i < n; i++){
            if(dodano[i]){
                if(!prvic){
                    printf(", ");
                }
                printf("%d", mnozica[i]);
                prvic = false;
            }
        }
        printf("}\n");
        return; // to je manjkalo v tisti kodi na tabli
    }
    
    if(mnozica[ix] <= kolikoSe){
        dodano[ix] = true;
        razbitja(mnozica, n, kolikoSe - mnozica[ix], dodano, ix + 1);
        dodano[ix] = false;
    }
    razbitja(mnozica, n, kolikoSe, dodano, ix + 1);
    

}

int main(){

    int n= 0;
    scanf("%d", &n);
    
    int* mnozica = malloc(n * sizeof(int));
    int vsota = 0;
    
    for(int i = 0; i < n; i++){
        scanf("%d", &mnozica[i]);
        vsota += mnozica[i];
    }

    
    bool* dodano = calloc(n, sizeof(bool));
    dodano[0] = true;
    //printf("%d", vsota/2 - mnozica[0]);
    razbitja(mnozica, n, vsota/2 - mnozica[0], dodano, 1);
    
    free(dodano);
    free(mnozica);


    return 0;
}
