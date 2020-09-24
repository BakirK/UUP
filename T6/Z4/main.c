#include <stdio.h>

int main() {
	int i=0,niz[10],a,n,duzina,j;
	printf("Unesite elemente niza: ");
	do{
		scanf("%d",&a);
		if(a!=-1){
			niz[i]=a;
			i++;
		}
		else break;
	}
	while(a!=-1 && i<10);
	
	printf("Unesite element koji treba izbaciti: ");
	scanf("%d",&n);
	duzina=i;
		for(i=0;i<duzina;i++){
			if(niz[i]==n){
				for(j=i;j<duzina-1;j++){
					niz[j]=niz[j+1];
				}
				i--;
				duzina--;
			}
		}

	printf("Novi niz glasi: ");
	for(i=0;i<duzina;i++){
		if(i==duzina-1){
			printf("%d",niz[i]);	
		}
		else{
		printf("%d,",niz[i]);
		}
	}
	
	return 0;
}
