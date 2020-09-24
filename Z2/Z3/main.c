#include <stdio.h>

int IsSorted(int rez[], int n){
	int i;
	for(i=0;i<n-1;i++){
		if(rez[i]>rez[i+1]){
			return 0;
		}
	}
	return 1;
}
int main() {
	int n,i,niz[100],rez[100],x,a=-1;
	printf("Unesite N: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&niz[i]);
	}
	for(x=0;x<4294967295;x++){
		for(i=0;i<n;i++){
			rez[i]=x^niz[i];
		}
		a=IsSorted(&rez[0], n);
		if(a==1){
			printf("X=%d",x);
			return 0;
			//break;
		}
	}
	if(a==0){
			printf("X=-1");
		}
		printf("\n");
	for(i=0;i<n;i++){
		printf("rez:%d",rez[i]);
	}
	return 0;
}