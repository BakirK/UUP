#include <stdio.h>
#define n 10

int main() {
	//printf("Tutorijal 5, Zadatak 1");
	int niz[n], i, suma_parnih=0, min, max,suma=0;
	float prosjek,prosjek_p,j;
	for(i=0;i<n;i++){
		printf("Unesite %d. cijeli broj: ",i+1);
		scanf("%d",&niz[i]);
		if(i==0){
			min=niz[i];
			max=niz[i];
		}
		if(niz[i]>max)max=niz[i];
		if(niz[i]<min)min=niz[i];
		if(niz[i]%2==0){
			suma_parnih+=niz[i];
			j++;
		}
		suma+=niz[i];
	}
	prosjek_p=(float)suma_parnih/j;
	prosjek=(float)suma/n;
	printf("Srednja vrijednost unesenih brojeva je %g",prosjek_p);
	printf("\nSrednja vrijednost parnih brojeva je %g",prosjek);
	printf("\nNajveci element je %d a najmanji %d.",min,max);
	return 0;
}
