#include <stdio.h>
#define n 10

int main() {
	//printf("Tutorijal 5, Zadatak 1");
	int niz[n], i, suma_parnih=0, min, max,suma=0;
	float prosjek=0,prosjek_p=0,j=0;
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
	if(j!=0){
	prosjek_p=(float)suma_parnih/j;
	}
	prosjek=(float)suma/n;
	printf("Srednja vrijednost unesenih brojeva je %.2f.",prosjek);
	printf("\nSrednja vrijednost parnih brojeva je %.2f.",prosjek_p);
	printf("\nNajveci element je %d a najmanji %d.",max,min);
	return 0;
}
