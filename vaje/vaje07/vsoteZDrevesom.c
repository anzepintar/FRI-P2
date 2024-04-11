#include <stdio.h>

void printNivo(int n){
	for(int i = 0; i < n; i++) {
		printf("   ");
	}
}

int nacini(int ciljnaVsota, int najSumand, int nivo) {
	if(ciljnaVsota == 0) return 1;
	if(najSumand <= 0 || ciljnaVsota < 0) return 0;
	
	printNivo(nivo);
	printf("nacini(%d, %d)\n", ciljnaVsota - najSumand, najSumand);
	int z = nacini(ciljnaVsota - najSumand, najSumand, nivo + 1);
	
	printNivo(nivo);
	printf("nacini(%d, %d)\n", ciljnaVsota, najSumand - 1);
	int brez = nacini(ciljnaVsota, najSumand - 1, nivo + 1);
	return z + brez;
}


int main() {
	int ciljnaVsota, najSumand;
	scanf("%d%d", &ciljnaVsota, &najSumand);
	printf("%d\n", nacini(ciljnaVsota, najSumand, 0));
	return 0;
}
