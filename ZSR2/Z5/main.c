#include <stdio.h>

int main() {
	int n, half,i,j,l,d;
	printf("unesi n ");
	scanf("%d",&n);
	if(n&1){
		half=n/2;
	}
	else{
		half=(n/2);
	}
	l=half;
	d=half;
	for(i=0;i<=half;i++){
		for(j=0;j<n;j++){
			if(i==half){
					printf("*");
			}
			else if((j==l) || (j==d)){
				printf("*");
			}
			else{
				printf(" ");
			}
		}
		d++;
		l--;
		printf("\n");
	}
	for(i=half+1;i<n;i++){
		if(i==n-1){
			for(j=0;j<n;j++){
				printf("*");
			}
		}
		else{
			for(j=0;j<n;j++){
				if(j==0 || j==n-1){
					printf("*");
				}
				else printf(" ");
			}
		}
		printf("\n");
	}
	
	
	return 0;
}
