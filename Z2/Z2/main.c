#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int all_the_same(int x){
	int digit;
	x=abs(x);
    digit = x%10;
    while(!(x<=0))
    {
        if(x%10 != digit) return 0;
        x = x/10;
    }
    return 1;
}

int main() {
	int i=0, broj_clanova, niz[100], a, privremena, j, m, n, brojac=0, brojac2=0; 
	printf("Unesite brojeve:");
	do{
		scanf("%d",&a);
		brojac++;
		if(a!=-1){
			niz[i]=a;
			i++;
		}
		if(brojac==100){
			break;
		}
	}
	while(a!=-1);
	broj_clanova=i-1;
	m=i-1;
	n=m;
	
	for(i=0;i<=broj_clanova;i++){
		if(all_the_same(niz[i])==1){
			brojac2++;
		}
	}
	for(j=1;j<=brojac2;j++){
		for(i=n;i>0;i--){
				if(all_the_same(niz[i])==1){
					privremena=niz[i];
					niz[i]=niz[i-1];
					niz[i-1]=privremena;
				}
		}
	}
	printf("\nNakon preslaganja niz glasi:\n");
	for(i=0;i<=broj_clanova;i++){
		if(i==broj_clanova){
			printf("%d.",niz[i]);
		}
		else{
			printf("%d,",niz[i]);
		}
	}

	
	
	
	
	return 0;
}
