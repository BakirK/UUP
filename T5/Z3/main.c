#include <stdio.h>
#define n 5

int main() {
	//printf("Tutorijal 5, Zadatak 3");
	int i;
	double a[n], b[n], c[n];
	printf("Unesite clanove niza A: ");
	for(i=0;i<n;i++){
		scanf("%lf ",&a[i]);
	}
	printf("Unesite clanove niza B: ");
	for(i=0;i<n;i++){
		scanf("%lf ",&b[i]);
	}
	for(i=0;i<n;i++){
		c[i]=2*a[i]+b[i];
	}
	printf("Niz A glasi:");
	for(i=0;i<n;i++){
		if(i==n-1)printf(" %.2lf",a[i]);
		else printf(" %.2lf,",a[i]);
	}
	printf("\nNiz B glasi:");
	for(i=0;i<n;i++){
		if(i==n-1)printf(" %.2lf",b[i]);
		else printf(" %.2lf,",b[i]);
	}
	printf("\nNiz C glasi:");
	for(i=0;i<n;i++){
		if(i==n-1)printf(" %.2lf",c[i]);
		else printf(" %.2lf,",c[i]);
	}
	
	
	return 0;
}
