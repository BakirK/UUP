#include <stdio.h>

struct Datum {
	int dan, mjesec, godina;
};

struct Student {
	char ime[20], prezime[20];
	struct Datum datum_rodjenja;
};


void zapisi(struct Student studenti[], int broj) {
	FILE *ulaz;
	ulaz=fopen("studenti.dat", "wb");
	if(ulaz==NULL) {
		printf("Greska pri otvaranju datoteke student.dat");
	}
	int i=0;
	while((fwrite(&studenti, sizeof(struct Student), 1, ulaz)==1) && i<broj) {
		i++;
	};
	fclose(ulaz);
}

void promijeni(struct Student osoba, int n) {
	FILE *ulaz;
	struct Student studenti[3000];
	ulaz=fopen("studenti.dat", "rb+");
	if(ulaz==NULL) {
		printf("Greska pri otvaranju datoteke student.dat");
	}
	int i=0;
	while((fread(&studenti, sizeof(struct Student), 1, ulaz)==1) && i<3000) {
		i++;
	};
	fclose(ulaz);
	studenti[n+1]=osoba;
	
	
	//ponovni zapis
	ulaz=fopen("studenti.dat", "wb");
	if(ulaz==NULL) {
		printf("Greska pri otvaranju datoteke student.dat");
	}
	i=0;
	while((fwrite(&studenti, sizeof(struct Student), 1, ulaz)==1) && i<3000) {
		i++;
	};
	fclose(ulaz);
	
	
	
}
	


int main() {
	//struct Student studenti[100];
	return 0;
}
