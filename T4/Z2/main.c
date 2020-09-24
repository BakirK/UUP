#include <stdio.h>

int main() {
	//printf("Tutorijal 4, Zadatak 2");
	int i,j,a,b;
	printf("Unesite stranice pravougaonika a,b: ");
	scanf("%d,%d",&a,&b);
	for(i=1;i<=b;i++){
		if(i==1 || i==b){
			for(j=1;j<=a;j++){
				{
					if(j==1 || j==a){
						printf("+");
					}
					else printf("-");
					
				}
			}
		}
		else{
				for(j=1;j<=a;j++){
				
					if(j==1 || j==a){
						printf("|");
					}
					else printf(" ");
				}
			}
			printf("\n");
			
	}
		
	
	return 0;
}