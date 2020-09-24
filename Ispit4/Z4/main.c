#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Mjerenje {
   int sati;
    int minute;
    int sekunde;
    float mjerenje;
};


int main() {
    float mjerenja[10000];
    float odstupanje;
    int i=0;
    int j=0;
    int n1, n2;
   struct Mjerenje zadana[10000];
	FILE *ulaz1, *ulaz2, *ulaz3;
	if ((ulaz1 = fopen("mjerenja.txt","r")) == NULL) {
        printf("Nije uspjelo otvaranje datoteke mjerenja.txt");
        return 0;
    }
    if ((ulaz2 = fopen("zadane.dat","rb")) == NULL) {
        printf("Nije uspjelo otvaranje datoteke zadane.dat");
        return 0;
    }
     if ((ulaz3 = fopen("provjera.txt","w")) == NULL) {
        printf("Nije uspjelo otvaranje datoteke provjera.txt");
        return 0;
    }
    
    while(fscanf(ulaz1,"%f,",&mjerenja[i])==1 && i<10000) {
        i++;
    }
    n1=i;
    i=0;
    while(fread(&zadana, sizeof(struct Mjerenje), 1, ulaz2)==1){
        i++;
    };
    n2=i;
    for(i=0 ; i<n1; i++) {
        for(j=0;j<n2;j++) {
            odstupanje=(mjerenja[i]/zadana[j].mjerenje)*100;
            odstupanje=fabs(100-odstupanje);
            if (odstupanje<=5) {
            fprintf(ulaz3,"%d:%d:%d %.2f\n", zadana[j].sati, zadana[j].minute, zadana[j].sekunde, mjerenja[i]);
            }
        }
    }
    fclose(ulaz1);
    fclose(ulaz2);
    fclose(ulaz3);
    
	return 0;
}
//fread(&zadana_mjerenja, sizeof(struct Mjerenje), 1, ulaz) == 1) 