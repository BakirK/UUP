#include <stdio.h>

int main() {
	double niz[10],temp;
    int i,j,a=9;
    /* unos niza */
    for (i=0; i<10; i++) {
        printf("Unesite %d. realan broj: ", i+1);
        scanf("%lf", &niz[i]);
    }
    
    for (j=0; j<9; j++){
        for (i=0; i<a; i++){
            if(niz[i]<niz[i+1]){
                temp=niz[i];
                niz[i]=niz[i+1];
                niz[i+1]=temp;
            }
        }
        a--;
    }
    
    printf("Sortiran niz:\n");
    for (i=0; i<10; i++)
        printf("%g ", niz[i]);
    printf("\n");
    
	return 0;
}
