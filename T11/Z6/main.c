#include <stdio.h>
int i=0;
struct Osoba {
        char ime[15];
        char prezime[20];
        int telefon;
    };

void unesi(char niz[], int velicina){
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n' && znak!=' ') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

struct Osoba unos_osobe() {
    struct Osoba novi;
    printf("Unesite ime: ");
    unesi(novi.ime,15);
    printf("Unesite prezime: ");
    unesi(novi.prezime,20);
    printf("Unesite broj telefona: ");
    scanf("%d",&novi.telefon);
    return novi;
}

void ispis_osobe(struct Osoba o) {
	printf("%s %s, Tel: %d\n",o.ime,o.prezime,o.telefon);
}




int main() {
	struct Osoba imenik[100];
	int a;
	int j;
	do{
		printf("Pritisnite 1 za unos, 2 za ispis, 0 za izlaz: ");
		scanf("%d",&a);

		switch (a) {
			case 0: {
				break;
			}
			case 1: {
				imenik[i]=unos_osobe();
				i++;
				break;
			}
			case 2: {
				for(j=0;j<i;j++) {
					printf("\n%d. ",j+1);
					ispis_osobe(imenik[j]);
				}
				break;
			}
			default:{
				break;
			}
		}
		
	} while(a!=0);
	//printf("Tutorijal 11, Zadatak 6");
	return 0;
}














