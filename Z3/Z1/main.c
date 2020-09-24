#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void oduzmi_cifre(int niz[], int n){
	int cifre[100],i,broj,j=0,nc,k=0;
	for (i=0;i<n;i++) {
		if (niz[i]<0) {
			niz[i]=abs(niz[i]);
		}
	}
    for (i=0;i<n;i++) {
    	broj=niz[i];
    	k=0;
    	//k predstavlja broj cifri koje izracunam dole
    	if (broj<10 && broj>=0) {
    		niz[i]=0;
    	}
    	else{
    		j=0;
	    	while(broj>0) {
	    		cifre[j]=broj%10;
	    		broj/=10;
	    		j++;
	    	}
	    	nc=j;
	    	for (j=0;j<nc-1;j++) {
	    		cifre[j]=cifre[j]-cifre[j+1];
	    		if(cifre[j]<0){
	    			cifre[j]=abs(cifre[j]);
	    		}
	    	}
	    	nc--;
	    	k=nc-1;
	    	niz[i]=0;
		    for (j=(nc-1);j>=0;j--) {
	    		niz[i]+=(cifre[j])*pow(10,k);
	    		k--;
	    	}
    	}
    }
}

int main() {
	int i,niz[100];
	printf("Unesite broj: ");
	for(i=0;i<1;i++) {
		scanf("%d",&niz[i]);
	}
	oduzmi_cifre(&niz[0], i);
	for(i=0;i<1;i++) {
		printf("%d",niz[i]);
	}
	return 0;
}
