#include <stdio.h>
#include <math.h>

int main() {
	//printf("ZSR 2, Zadatak 1");
	double korjen,broj;
	
	printf("Unesi broj: ");
	scanf("%lf",&broj);
	
	korjen=sqrt(sqrt(broj));
	
	printf("\n4 korjen broja %lf je: %.10lf",broj,korjen);
	return 0;
}
