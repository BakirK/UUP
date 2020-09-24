#include <stdio.h>

int main() {
	int niz[101]={}, i, a;
	printf("Unesite brojeve:\n");
	while(1)
	{
		scanf("%d",&a);
		if(a==-1){
			break;
		}
		if(a<0 || a>100){
			printf("Brojevi moraju biti izmedju 0 i 100!\n");
			continue;
		}
		niz[a]++;
	}
	for(i=0;i<101;i++){
		if(niz[i]!=0){
			printf("\nBroj %d se javlja %d puta.",i,niz[i]);
		}
	}
	return 0;
}
