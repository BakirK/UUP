#include <stdio.h>

int faktorijel(int n){
	int i,suma=1;
	for(i=1;i<=n;i++){
		suma*=i;
	}
	return suma;
}


int main(){
	int n, i;
	float suma=0, x;
	printf("Unesite broj n u intervalu [1, 12]: ");
	scanf("%d",&n);
	printf("Unesite realan broj x: ");
	scanf("%f",&x);
	for(i=1;i<=n;i++){
		suma+=(float)x/faktorijel(i);
	}
	printf("Suma od 1 do %d za x = %.3f je %.3f",n,x,suma);
	return 0;
}
