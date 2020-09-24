#include <stdio.h>

int main() {
	int broj,i,a=0;
	printf("Unesite broj: ");
	scanf("%d",&broj);
	if(broj<=0){
			printf("Broj nije prirodan.\n");
			return 0;
		}
	else{
		if(broj==1){
			printf("Broj nije ni prost ni slozen.");
		}
		else{
			for(i=2;i<broj;i++){
				if((broj%i)==0){
					printf("Broj je slozen.");
					a++;
					break;
				}
			}
			if(a==0){
				printf("Broj je prost.");
			}
		}
		return 0;
	}
}
