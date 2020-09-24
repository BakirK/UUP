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
    FILE *ulaz; //var tipa file
    char znak, ime[20];
    int broj_redova=0, broj_rijeci=0, broj_znakova=0, razmak=1;
    int broj_samoglasnika=0, broj_velikih=0, broj_cifara=0;

    //printf ("Unesite ime datoteke: ");
    scanf ("%s", ime);
    ulaz = fopen(ime, "r");
    if (ulaz == NULL) {
        printf ("Pogreska kod otvaranja datoteke %s!\n\n", ime);
        exit (1);
    }
    while ((znak=fgetc(ulaz)) != EOF) {
        /* Ako je znak novi red, povecaj broj linija za jedan */
        if (znak=='\n')
            ++broj_redova;

        /* Da li je znak razmak? */
        if (znak==' ' || znak=='\n' || znak=='\t')
            razmak=1;

        else {
            ++broj_znakova;
            /* Ako je prethodni znak bio razmak a ovaj nije,
               povecavamo broj rijeci za 1 */
            if (razmak==1) ++broj_rijeci;
            razmak=0;
        }
        
        if(jeBroj(znak)==1) {
            broj_cifara++;
        }
        if(jeVelikoSlovo(znak)==1) {
            broj_velikih++;
        }
        if(samoglasnik(znak)==1) {
            broj_samoglasnika++;
        }
        
    }
    if (broj_znakova != 0) broj_redova++;
    printf ("Broj redova: %d\nBroj rijeci: %d\nBroj znakova: %d\n", 
    broj_redova, broj_rijeci, broj_znakova);
    printf("Broj samoglasnika: %d\nBroj velikih slova: %d\nBroj cifara: %d",broj_samoglasnika, broj_velikih, broj_cifara);
    fclose (ulaz);
    return 0;
}
