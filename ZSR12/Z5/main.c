#include <stdio.h>
#include <stdlib.h>

int analiza() {
	FILE* ulaz;
	int i;
	unsigned short int brojaci[65536]={0};
	ulaz=fopen("brojevi.dat", "rb");
	if(ulaz==NULL) {
		printf("Greska");
		return 0;
	}
	unsigned short int temp;
	//nuliranje cijelog niza jer nije automatski nuliran?
	for(i=0;i<65536;i++) {
		brojaci[i]=0;
	}
	while(fread(&temp,2,1,ulaz)==1) {
			brojaci[temp]++;
	}
	int max=brojaci[0];
	int max_broj=0;
	for(i=0; i<65536; i++) {
		if(brojaci[i]>max) {
			max=brojaci[i];
			max_broj=i;
		}
	}
	int ukupno=0;
	for(i=max_broj+1; i<65536; i++) {
		ukupno+=brojaci[i];
	}
	fclose(ulaz);
	
	return ukupno;
}

int main() {
FILE* izlaz = fopen("brojevi.dat", "wb");

/* Broj 32768 je veci od 32767 */
fputc(255, izlaz);
fputc(127, izlaz);
fputc(0, izlaz);
fputc(128, izlaz);
fputc(255, izlaz);
fputc(127, izlaz);

fclose(izlaz);
printf("%d", analiza());
}