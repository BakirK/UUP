#include <stdio.h>
#define NSP1 90.0 //NSP1-DONJA GRANICA NORMALNOG SIST. PRITISKA
#define NSP2 120.0 //NSP1-GORNJA GRANICA NORMALNOG SIST. PRITISKA
#define NDP1 60.0 //NSP1-DONJA GRANICA NORMALNOG SIST. PRITISKA
#define NDP2 80.0 //NSP1-GORNJA GRANICA NORMALNOG SIST. PRITISKA
#define n_puls1 55
#define n_puls2 100

int main() {
	//printf("Tutorijal 2, Zadatak 2 \n");
	printf("Dobrodosli kod Vaseg kucnog ljekara! \n");
	float SP,DP,puls;
	printf("Unesite sistolicki, dijastolicki pritisak i puls: ");
	scanf("%f %f %f",&SP,&DP,&puls);
	if(SP>=NSP1 && SP<=NSP2){
		printf("SP: normalan");
	}
	else {
		printf("SP: nije normalan");
	}
	if(DP>=NDP1 && DP<=NDP2){
		printf("\nDP: normalan");
	}
	else {
		printf("\nDP: nije normalan");
	}
	if(puls>=n_puls1 && puls<=n_puls2){
		printf("\nPuls: normalan");
	}
	else {
		printf("\nPuls: nije normalan");
	}
	return 0;
}
