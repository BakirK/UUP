#include <stdio.h>
#include <stdlib.h> /* Zbog funkcije exit() */
#include <string.h>

void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

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
    FILE *ulaz;
    char  ime[20]="ispiti.txt";
    char naziv[20]="predmeti.txt";
    int prolaz=0, ukupno=0, suma_ocjena=0;
    int index,  ocjena;
    char trazeni_predmet[900];
    int predmet;
    char pct='%';
    float prosjek, prolaznost;
    char ime_predmeta[900];
    int broj_predmet;
    int flag=0;
    while(1) {
        ulaz=fopen(naziv, "r");
        if(ulaz == NULL) {
            printf("Pogreska kod otvaranja datoteke %s!!\n\n",naziv);
            return 0;
        }
        flag=0;
        printf("Unesite predmet: ");
        unesi(trazeni_predmet, 900);
        while(fscanf(ulaz,"%d %[^\n]s", &broj_predmet, ime_predmeta)==2) {
            if(strcmp(ime_predmeta, trazeni_predmet)==0) {
                flag=1;
                break;
            }
        }
        if (flag==0) {
            printf("Nepostojeci predmet!\n");
        }
        else if(flag==1) {
            break;
        }
        fclose(ulaz);
    }
    
    izlaz = fopen(ime, "rw");
    if (izlaz == NULL) {
        printf ("Pogreska kod otvaranja datoteke %s!\n\n", ime);
        return 0;
    }
    while((fscanf(izlaz,"%d%d%d",&index, &predmet, &ocjena))==3) {
        if(predmet!=broj_predmet) {
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
        printf("Prosjecna ocjena: %.2f", prosjek);
        prolaznost=(float)((float)prolaz/ukupno)*100;
        printf("\nProlaznost: %.0f%c", prolaznost,pct);
    }
    else printf("Zalimo, ali ne postoje podaci o predmetu %s!", trazeni_predmet);
    fclose (izlaz);
    return 0;
}
