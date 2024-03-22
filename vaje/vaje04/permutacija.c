#include <stdio.h>
#include <stdbool.h>

int stevila[1000000];
bool videno[1000000];

int main()
{
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i<n; i++) {
        scanf("%d", &stevila[i]);
        printf("%d",stevila[i]);
    }
    bool permutacija = true;
    for (int i = 0;i<n;i++) {
        if(videno[stevila[i]] || stevila[i]<0 || stevila[i]>=n){
            permutacija = false;
            printf("\n Napaka je: %d\n", stevila[i]);
        }
        videno[stevila[i]] = true;
    }
    permutacija?printf("n\nDA\n"):printf("\nNE\n");
    return 0;
}

