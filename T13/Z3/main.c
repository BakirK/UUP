#include <stdio.h>

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

struct Student {
    char prezime[20];
    char ime[15];
    int  broj_bodova1;
    int  broj_bodova2;
};

int main() {
	int izbor;
	int i=1;
	struct Student osoba;
	FILE *ulaz;
	char naziv[]="ispit.txt";
	do{
		printf("Unesite 1 za unos, 2 za ispis, 0 za izlaz: ");
		scanf("%d", &izbor);
		if(izbor==0) {
			return 0;
		}
		else if(izbor!=1 && izbor!=2) {
			continue;
		}
		if(izbor==1) {
			ulaz=fopen(naziv, "a");
			if(ulaz==NULL) {
				printf("Greska pri otvaranju datoteke ispit.txt");
				return 0;
			}
			printf("Unesite ime: ");
			unesi(osoba.ime, 15);
			printf("Unesite prezime: ");
			unesi(osoba.prezime, 20);
			printf("Unesite broj bodova na I parcijalnom: ");
			scanf("%d", &osoba.broj_bodova1);
			printf("Unesite broj bodova na II parcijalnom: ");
			scanf("%d", &osoba.broj_bodova2);
			fprintf(ulaz, "%-19s %-14s %2d %2d\n", osoba.prezime, osoba.ime, osoba.broj_bodova1, osoba.broj_bodova2);
			fclose(ulaz);
		}
		else if(izbor==2) {
			ulaz=fopen(naziv, "r");
			if(ulaz==NULL) {
				printf("Greska pri otvaranju datoteke ispit.txt");
				return 0;
			}
			while(fscanf(ulaz,"%s %s %d %d", osoba.prezime, osoba.ime, &osoba.broj_bodova1, &osoba.broj_bodova2)==4) {
				printf("\n%d. %s %s - %d, %d\n", i, osoba.ime, osoba.prezime, osoba.broj_bodova1, osoba.broj_bodova2);
				i++;
			}
			fclose(ulaz);
		}
	}
	while(izbor!=0);
	return 0;
}