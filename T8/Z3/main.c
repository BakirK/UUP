#include <stdio.h>

float maxtemp(float niz[],int n) {
	float max;
	int i;
	max=niz[0];
	for(i=0;i<n;i++){
		if(niz[i]>max){
			max=niz[i];
		}
	}
	return max;
}

float prtemp(float niz[],int n) {
	float suma=0,prosjek;
	int i;
	for(i=0;i<n;i++){
		suma+=niz[i];
	}
	prosjek=suma/n;
	return prosjek;
}

int main() {
	int n,i;
	float niz[100],max,avg;
	printf("Unesite broj mjerenja: ");
	scanf("%d",&n);
	printf("Unesite temperature: ");
	for(i=0;i<n;i++){
		scanf("%f",&niz[i]);
	}
	max=maxtemp(&niz[0],n);
	avg=prtemp(&niz[0],n);
	printf("Maksimalna temperatura: %.1f\n",max);
	printf("Prosjecna temperatura: %.1f",avg);
	
	return 0;
}
