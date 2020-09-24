#include <stdio.h>
#include <stdlib.h> /* Zbog funkcije exit() */

int jeBroj(char s) {
	char p=s;
	if(p>=48 && p<=57) {
		return 1;
	}
	else return 0;
}

int samoglasnik(char p) {
    if (p=='A' || p=='a' ||p=='E' ||p=='e' ||p=='I' ||p=='i' || p=='O' ||p=='o' ||p=='U' ||p=='u'){
			return 1;
		}
		return 0;
}

int jeVelikoSlovo(char s) {
    if(s>=65 && s<=90) {
        return 1;
    }
    return 0;
}

int main() {
    FILE *izlaz; //var tipa file
    char  ime[20]="ispiti.txt";
    int prolaz=0, ukupno=0, suma_ocjena=0;
    int index, trazeni_predmet, ocjena;
    int predmet;
    char pct='%';
    float prosjek, prolaznost;
    printf("Unesite predmet: ");
    scanf("%d",&trazeni_predmet);
    izlaz = fopen(ime, "rw");
    if (izlaz == NULL) {
        printf ("Pogreska kod otvaranja datoteke %s!\n\n", ime);
        exit (1);
    }
    while((fscanf(izlaz,"%d%d%d",&index, &predmet, &ocjena))==3) {
        if(predmet!=trazeni_predmet) {
            continue;
        }
        ukupno++;
        if(ocjena>=6) {
            prolaz++;
        }
        suma_ocjena+=ocjena;
    }
    if(ukupno!=0){
        prosjek=(float)suma_ocjena/ukupno;
        printf("Prosjecna ocjena: %.2f",prosjek);
        prolaznost=(float)((float)prolaz/ukupno)*100;
        printf("\nProlaznost: %.0f%c",prolaznost,pct);
    }
    else printf("Zalimo, ali ne postoje podaci o predmetu sa brojem %d!",trazeni_predmet);
    fclose (izlaz);
    return 0;
}
