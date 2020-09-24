#include <stdio.h>

int main() {
	int niz[10][10],i,j,min,max,red_max=0,red_min=0,temp[10];
	printf("Unesite elemente matrice: ");
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			scanf("%d",&niz[i][j]);
		}
	}
	min=niz[0][0];
	max=niz[0][0];
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(niz[i][j]>max){
				max=niz[i][j];
				red_max=i;
			}
			if(niz[i][j]<min){
				min=niz[i][j];
				red_min=i;
			}
				
		}
	}
	
	if(red_max==red_min){
		printf("Najmanji i najveci element se nalaze u istom redu.");
		return 0;
	}
	else{
			for(j=0;j<10;j++){
				temp[j]=niz[red_min][j];
			}
			i=red_max;
			for(j=0;j<=10;j++){
				niz[red_min][j]=niz[red_max][j];
			}
			for(j=0;j<10;j++){
				niz[red_max][j]=temp[j];
			}
			printf("Nakon zamjene matrica glasi:\n");
			for(i=0;i<10;i++){
				for(j=0;j<10;j++){
					if(j==10-1){
						printf("%d",niz[i][j]);
					}
					else{
					printf("%d ",niz[i][j]);	
					}
				}
				printf("\n");
			}
				
			
		
		
	}
	
	
	
	return 0;
}
