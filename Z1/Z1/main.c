#include <stdio.h>

int main() {
	int sarajevo_temp, bihac_temp, mostar_temp;
	char sarajevo_padavine, bihac_padavine, mostar_padavine;
	int anja_s=0, anja_b=0, anja_m=0, elma_s=0, elma_b=0, elma_m=0, una_s=0, una_b=0, una_m=0;
	printf("Unesite prognozu za Sarajevo: \n");
	printf("Temperatura: ");
	scanf("%d",&sarajevo_temp);
	do{
		printf("Padavine (D/N): ");
		scanf(" %c",&sarajevo_padavine);
		if(sarajevo_padavine!='D' && sarajevo_padavine!='d' && sarajevo_padavine !='n' && sarajevo_padavine!='N')
		{
			printf("Pogresan unos.\n");
		}
	}
	while(sarajevo_padavine!='D' && sarajevo_padavine!='d' && sarajevo_padavine !='n' && sarajevo_padavine!='N');
	
	printf("Unesite prognozu za Mostar: \n");
	printf("Temperatura: ");
	scanf("%d",&mostar_temp);
	do{
		printf("Padavine (D/N): ");
		scanf(" %c",&mostar_padavine);
		if(mostar_padavine!='D' && mostar_padavine!='d' && mostar_padavine!='n' && mostar_padavine!='N')
		{
			printf("Pogresan unos.\n");
		}
	}
	while(mostar_padavine!='D' && mostar_padavine!='d' && mostar_padavine!='n' && mostar_padavine!='N');
	
	printf("Unesite prognozu za Bihac: \n");
	printf("Temperatura: ");
	scanf("%d",&bihac_temp);
	do{
		printf("Padavine (D/N): ");
		scanf(" %c",&bihac_padavine);
		if(bihac_padavine!='D' && bihac_padavine!='d' && bihac_padavine!='n' && bihac_padavine!='N')
		{
			printf("Pogresan unos.\n");
		}
	}
	while(bihac_padavine!='D' && bihac_padavine!='d' && bihac_padavine!='n' && bihac_padavine!='N');
	
	
	
	
	//anja
	if((sarajevo_padavine=='n' || sarajevo_padavine=='N') || (sarajevo_temp<=0 && (sarajevo_padavine=='d' || sarajevo_padavine=='D'))){
		anja_s++;
	}
	if((bihac_padavine=='n' || bihac_padavine=='N') || (bihac_temp<=0 && (bihac_padavine=='d' || bihac_padavine=='D'))){
		anja_b++;
	}
	if((mostar_padavine=='n' || mostar_padavine=='N') || (mostar_temp<=0 && (mostar_padavine=='d' || mostar_padavine=='D'))){
		anja_m++;
	}
	
	//elma
	if(sarajevo_temp<=30 && sarajevo_temp>=-5){
		elma_s++;
	}
	if(bihac_temp<=30 && bihac_temp>=-5){
		elma_b++;
	}
	if(mostar_temp<=30 && mostar_temp>=-5){
		elma_m++;
	}
	
	//una
	if((sarajevo_temp>20 || sarajevo_temp<5) && (sarajevo_padavine=='n' || sarajevo_padavine=='N') ){
		una_s++;
	}
	if((bihac_temp>20 || bihac_temp<5) && (bihac_padavine=='n' || bihac_padavine=='N') ){
		una_b++;
	}
	if((mostar_temp>20 || mostar_temp<5) && (mostar_padavine=='n' || mostar_padavine=='N') ){
		una_m++;
	}
	
	if(una_s==1 && anja_s==1 && elma_s==1) printf ("Drugarice idu u Sarajevo.");
	else if(una_m==1 && anja_m==1 && elma_m==1) printf ("Drugarice idu u Mostar.");
	else if(una_b==1 && anja_b==1 && elma_b==1) printf ("Drugarice idu u Bihac.");
	//sarajevo parovi od 2
	else if(una_s==0 && anja_s==1 && elma_s==1) printf ("Anja i Elma mogu u Sarajevo.");
	else if(una_s==1 && anja_s==0 && elma_s==1) printf ("Elma i Una mogu u Sarajevo.");
	else if(una_s==1 && anja_s==1 && elma_s==0) printf ("Anja i Una mogu u Sarajevo.");
	//mostar parovi od 2
	else if(una_m==0 && anja_m==1 && elma_m==1) printf ("Anja i Elma mogu u Mostar.");
	else if(una_m==1 && anja_m==0 && elma_m==1) printf ("Elma i Una mogu u Mostar.");
	else if(una_m==1 && anja_m==1 && elma_m==0) printf ("Anja i Una mogu u Mostar.");
	//bihac parovi od 2
	else if(una_b==0 && anja_b==1 && elma_b==1) printf ("Anja i Elma mogu u Bihac.");
	else if(una_b==1 && anja_b==0 && elma_b==1) printf ("Elma i Una mogu u Bihac.");
	else if(una_b==1 && anja_b==1 && elma_b==0) printf ("Anja i Una mogu u Bihac.");

	else printf("Ne odgovara niti jedan grad.");
//printf("\nuna_m:%d elma_m:%d anja_m:%d",una_m,elma_m,anja_m);


	
	return 0;
}
