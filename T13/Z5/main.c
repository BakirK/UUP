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
	struct Student studenti[300], tmp;
    int j, vel, max;
	struct Student osoba;
	FILE *ulaz, *izlaz;;
	char naziv[]="ispit.dat";
	do{
		printf("Unesite 1 za unos, 2 za ispis, 3 za usmeni, 0 za izlaz: ");
		scanf("%d", &izbor);
		if(izbor==0) {
			return 0;
		}
		else if(izbor!=1 && izbor!=2 && izbor!=3) {
			continue;
		}
		if(izbor == 1) {
			ulaz=fopen(naziv, "ab");
			if(ulaz==NULL) {
				printf("Greska pri otvaranju datoteke ispit.dat");
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
			fwrite(&osoba, sizeof(struct Student), 1, ulaz);
			fclose(ulaz);
		}
		
		else if(izbor == 2) {
			i=1;
			ulaz=fopen(naziv, "rb");
			if(ulaz==NULL) {
				printf("Greska pri otvaranju datoteke ispit.dat");
				return 0;
			}
			while(fread(&osoba, sizeof(struct Student), 1, ulaz) == 1) {
				printf("%d. %s %s - %d, %d\n", i, osoba.ime, osoba.prezime, osoba.broj_bodova1, osoba.broj_bodova2);
				i++;
			}
			fclose(ulaz);
		}
		
		else if(izbor == 3) {
			if ((ulaz = fopen("ispit.dat","r")) == NULL) {
		        printf("Greska pri otvaranju datoteke ispit.dat");
		        return 0;
		    }
		    if ((izlaz = fopen("usmeni.dat","w")) == NULL) {
		        fclose(ulaz);
		        printf("Greska pri otvaranju datoteke ispit_sortiran.dat");
		        return 0;
		    }
		
		    /* Ucitavanje datoteke u niz studenti */
		    i=0;
		     while (fread(&studenti, sizeof(struct Student), 1, ulaz) == 1 && i<300){
		     	i++;
		     }
		    vel = i;
		
		    /* Sortiranje niza po broju bodova */
		    for (i=0; i<vel; i++) {
		        max = i;
		        for (j=i+1; j<vel; j++)
		            if (studenti[j].broj_bodova1+studenti[j].broj_bodova2 > studenti[max].broj_bodova1 + studenti[max].broj_bodova2) 
		                max = j;
		        tmp = studenti[i];
		        studenti[i] = studenti[max];
		        studenti[max] = tmp;
		    }
		   
		    // Upis niza u datoteku
		    for (i=0; i<vel; i++) {
		        if(studenti[i].broj_bodova1>=10 && studenti[i].broj_bodova2>=10) {
		        	fwrite(studenti, sizeof(struct Student), vel, izlaz);
		        }
			}
		    printf ("Izlazna datoteka usmeni.txt je kreirana\n");
		    fclose(ulaz);
		    fclose(izlaz);
		}
	}
	while(izbor!=0);
	return 0;
}