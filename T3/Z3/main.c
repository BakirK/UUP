#include <stdio.h>

int main() {
	int i,n;
	printf("Unesite broj n: ");
	scanf("%d",&n);
	for(i=n;i>=1;i--){
		if((i%5==0) || (i%7==0) || (i%11==0)){
			printf("%i\n",i);
		}
	}
	return 0;
}
