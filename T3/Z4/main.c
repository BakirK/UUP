#include <stdio.h>

int main() {
	//printf("Tutorijal 3, Zadatak 4");
	int i,n,j;
	printf("Unesite broj n: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i%2==0){
			printf("* ");
			}
			if(i%2!=0){
		printf(" *");
			}
	}
	printf("\n");
	}
	return 0;
}
