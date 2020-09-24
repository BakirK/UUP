#include <stdio.h>

int main() {
	int i,j,n=8;
	for(j=0;j<10;j++){
		printf("*");
	}
	//printf("\n");
	for(i=1;i<10-1;i++){
		printf("\n");
		for(j=0;j<10;j++){
			if(j==n){
				printf("*");
			}
			else{
				printf(" ");
			}
		}
		
		n--;
	}
	printf("\n");
	for(j=0;j<10;j++){
		printf("*");
	}
	return 0;
}
