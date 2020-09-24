#include <stdio.h>

int main() {
	int a,b,i,j;
	float suma=0,niz[100][100];
	printf("Unesite dimenzije matrice: ");
	scanf("%d %d",&a,&b);
	printf("Unesite elemente matrice: "); 
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			scanf("%f",&niz[i][j]);
		}
	}
	
	for(i=0;i<a;i++){
		if(i==0 || i==a-1){
			for(j=0;j<b;j++){
				suma+=niz[i][j];
			}
		}
	}
	
	for(i=1;i<a-1;i++){
			for(j=0;j<b;j++){
				if(j==0 || j==b-1){
					suma+=niz[i][j];
				}
			}
	}
	printf("Suma elemenata na rubu je %.2f",suma); 
	
	
	return 0;
}
