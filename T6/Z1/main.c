/*
#include <stdio.h>
#define DUZINA 10
int main() {
    double niz[DUZINA],temp;
    int i,j,min;
     //unos niza 
    for (i=0; i<DUZINA; i++) {
        printf("Unesite %d. realan broj: ", i+1);
        scanf("%lf", &niz[i]);
    }

    for (i=0; i<DUZINA; i++) {
        min=i;
        for (j=i+1; j<DUZINA; j++) {
            if (niz[j] < niz[i])
                min = j;
        temp = niz[i];
        niz[i] = niz[min];
        niz[min] = temp;
    }
    }

     //ispis niza 
    printf("Sortiran niz:\n");
    for (i=0; i<DUZINA; i++)
        printf("%g ", niz[i]);
    printf("\n");
    return 0;
}
*/



#include <stdio.h>

int main() {
	double niz[10],temp;
    int i,j,a=9;
    /* unos niza */
    for (i=0; i<10; i++) {
        printf("Unesite %d. realan broj: ", i+1);
        scanf("%lf", &niz[i]);
    }
    
    for (j=0; j<10; j++){
        for (i=0; i<a; i++){
            if(niz[i]>niz[i+1]){
                temp=niz[i];
                niz[i]=niz[i+1];
                niz[i+1]=temp;
            }
        }
        //a--;
    }
    
    printf("Sortiran niz:\n");
    for (i=0; i<10; i++)
        printf("%g ", niz[i]);
    printf("\n");
    
	return 0;
}

