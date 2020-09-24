#include <stdio.h>
#define n 400

int main() {
	//printf("Tutorijal 5, Zadatak 4");
	int i=0, niz[n],a,j,pet=0,sedam=0,jedanaest=0;
	printf("Unesite brojeve: ");
	do{
		scanf("%d",&a);
		if(a!=-1){
			niz[i]=a;
			i++;
		}
	}
	while(a!=-1);
	for(j=0;j<i;j++){
		if(niz[j]%5==0){
			pet++;
		}
		if(niz[j]%7==0){
			sedam++;
		}
		if(niz[j]%11==0){
			jedanaest++;
		}
	}
	printf("\nDjeljivih sa 5: %d",pet);
	printf("\nDjeljivih sa 7: %d",sedam);
	printf("\nDjeljivih sa 11: %d",jedanaest);
	
	
	return 0;
}
