#include <stdio.h>

int pascal(int x, int y){
	if(x==1 || x==y || y==1){
		return 1;
	}
	return pascal(x-1,y) + pascal(x-1,y-1);
}


int main() {
	int niz[100][100], i, j, n, m=0;
	printf("Unesite n: \n");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		m++;
		for(j=1;j<=i;j++){
			niz[i][j]=pascal(i,j);
			printf("%-4d",niz[i][j]);
		}
		printf("\n");
	}
	return 0;
}
