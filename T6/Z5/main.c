#include <stdio.h>

int main() {
	//printf("Tutorijal 6, Zadatak 5");
	int niz[10][10],i,j,min;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			scanf("%d",&niz[i][j]);
		}
	}
	
	min=niz[1][1];
	for(i=0;i<10;i++){
		if(niz[i][i]<min){
			min=niz[i][i];
		}
	}
	printf("%d",min);
	return 0;
}
