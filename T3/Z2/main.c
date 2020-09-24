#include <stdio.h>

int main() {
	int broj,suma=0,i;
	for(;suma<=100;){
	printf("Unesite broj: ");
	scanf("%d",&broj);
	suma+=broj;
	}
	printf("Suma je: %d",suma);
	return 0;
	
}
