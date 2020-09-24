#include <stdio.h>

int main() {
	int i=0,nizA[10],a,nizB[10],nizC[20],duzina_a,duzina_b,suma,brojac=0;
	printf("Unesite elemente niza A: ");
	do{
		scanf("%d",&a);
		if(a!=-1){
			nizA[i]=a;
			i++;
		}
		else break;
	}
	while(a!=-1 && i<10);
	duzina_a=i;
	printf("Unesite elemente niza B: ");
	i=0;
	do{
		scanf("%d",&a);
		if(a!=-1){
			nizB[i]=a;
			i++;
		}
		else break;
	}
	while(a!=-1 && i<10);
	duzina_b=i;
	suma=duzina_b+duzina_a;
	for(i=0;i<duzina_a;i++){
		nizC[i]=nizA[i];
	}
	for(i=duzina_a;i<suma;i++){
		nizC[i]=nizB[brojac];
		brojac++;
	}
	
	printf("Niz C glasi: ");
	for(i=0;i<suma;i++){
		if(i==suma-1){
			printf("%d",nizC[i]);
		}
		else{
		printf("%d,",nizC[i]);
		}
		
	}
	return 0;
}
