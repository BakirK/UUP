#include <stdio.h>

int main() {
	double niz[100][100], suma=0, prosjek=0, suma_red=0, prosjek_red;
	double prosjek_kolona, suma_kolona=0;
	int i, m, n, j, s, k; 
	do{
		printf("Unesite vrijednosti M i N: ");
		scanf("%d %d",&m,&n);
		if(m>100 || n>100 || m<1 || n<1){
			printf("Vrijednosti su van opsega!\n");
		}
	}
	while(m>100 || n>100 || m<1 || n<1);
	printf("Unesite clanove matrice:\n");
	for(i=0;i<m;i++){
		//printf("i:%d\n",i);
		for(j=0;j<n;j++){
			//printf("j:%d\n",j);
			scanf("%lf",&niz[i][j]);
		}	
	}
	
	//suma cijele matrice
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			suma+=niz[i][j];
		}	
	}
	
	prosjek=suma/(m*n);
	
	//izbacivanje reda
	for(i=0;i<m;i++){
		suma_red=0;
		for(j=0;j<n;j++){
			suma_red+=niz[i][j];
		}	
		prosjek_red=suma_red/n;
		//printf("\nprosjek_red:%.1f prosjek:%.1lf",prosjek_red,prosjek);
		if(prosjek_red>prosjek){
			//printf("i:%d j:%d\n",i,j);
			for(s=i;s<m-1;s++){
				for(k=0;k<n;k++){
					niz[s][k]=niz[s+1][k];
				}
			}
			i--;
			m--;
		}
	}
	
	//izvacivanje kolone
	for(j=0;j<n;j++){
		suma_kolona=0;
		for(i=0;i<m;i++){
			suma_kolona+=niz[i][j];
		}	
		prosjek_kolona=suma_kolona/m;
		
		if(prosjek_kolona>prosjek){
			for(k=j;k<n-1;k++){
				for(s=0;s<m;s++){
					niz[s][k]=niz[s][k+1];
				}
			}
			j--;
			n--;
		}
	}
	printf("Nakon izbacivanja matrica glasi:\n");
	//print
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%6.1f",niz[i][j]);
		}
		printf("\n");
	}
	
	
	
	
	
	return 0;
}
