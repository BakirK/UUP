#include <stdio.h>

float maxtemp(float niz[]) {
	float max;
	int i;
	max=niz[0];
	for(i=0;i<8;i++){
		if(niz[i]>max){
			max=niz[i];
		}
	}
	return max;
}

float prtemp(float niz[]) {
	float suma=0,prosjek;
	int i;
	for(i=0;i<8;i++){
		suma+=niz[i];
	}
	prosjek=suma/8;
	return prosjek;
}

int main() {
	int i;
	float niz[8],max,prosjek;
	printf("Unesite temperature: ");
	for(i=0;i<8;i++){
		scanf("%f",&niz[i]);
	}
	max=maxtemp(&niz[0]);
	prosjek=prtemp(&niz[0]);
	printf("Maksimalna temperatura: %.1f\n",max);
	printf("Prosjecna temperatura: %.1f",prosjek);
	
	return 0;
}
