#include <stdio.h>
#include <string.h>

struct Osoba {
	char ime[20];
	char prezime[20];
};

struct Grad {
	char naziv[50];
	int br_stanovnika;
	struct Osoba gradonacelnik;
};


struct Drzava {
	char naziv[100];
	char glavni_grad[50];
	int br_stanovnika;
};


int samo_glavni(struct Osoba osobe[], int vel_osobe, struct Grad gradovi[], int vel_gradovi, struct Drzava drzave[], int vel_drzave) {
	int i, j;
	int found=0;
	for(i=0;i<vel_gradovi;i++) {
		found=0;
		for(j=0 ; j<vel_drzave ; j++) {
			if(strcmp(gradovi[i].naziv, drzave[j].glavni_grad)==0) {
				found=1;
			}
		}
			if(found==0) {
				for(j=i; j<vel_gradovi-1; j++) {
					gradovi[j]=gradovi[j+1];
				}
				vel_gradovi--;
				i--;
			}
		
	}
	
	for(i=0;i<vel_gradovi;i++) {
		found=0;
		for(j=0 ; j<vel_osobe ; j++) {
			if(strcmp(gradovi[i].gradonacelnik.ime, osobe[j].ime)==0 && strcmp(gradovi[i].gradonacelnik.prezime, osobe[j].prezime)==0) {
				found=1;
			}
		}
			if(found==0) {
				for(j=i; j<vel_gradovi-1; j++) {
					gradovi[j]=gradovi[j+1];
				}
				vel_gradovi--;
			}
		
	}
	
	return vel_gradovi;
	
	
	
	
}




int main() {
	struct Osoba niz1[5] = {{"Meho", "Mehic"}, {"Pero", "Peric"}, {"Mujo", "Mujic"}, {"Sara", "Sarac"}, {"Jozo", "Jozic"}};
	struct Drzava niz3[7] = {{"BiH", "Sarajevo", 111}, {"Srbija", "Beograd", 222}, {"Hrvatska", "Zagreb", 333}, 
		{"SAD", "Washington", 444}, {"Velika Britanija", "London", 555}, {"Francuska", "Pariz", 666},
		{"Rusija", "Moskva", 777}};
	struct Grad niz2[8] = {
		{"Sarajevo", 111, {"Fata", "Fatic"}},  /* Izbacujemo - ne postoji Fata Fatic */
		{"Tuzla", 222, {"Meho", "Mehic"}}, /* Izbacujemo - nije glavni grad */
		{"Zagreb", 333, {"Jozo", "Jozic"}}, /* NE izbacujemo */
		{"Beogradd", 444, {"Pero", "Peric"}}, /* Izbacujemo - tipfeler - viska d */
		{"Washihinton", 777, {"Mujo", "Mujic"}} /* Izbacujemo - vise tipfelera */
		 /* NE izbacujemo */
	};		
	int vel = samo_glavni(niz1, 5, niz2, 8, niz3, 7);
	int i;
	printf("Vel: %d\n", vel);
	for (i=0; i<vel; i++) {
		printf("%s\n", niz2[i].naziv);
	}
}
/*
struct Osoba niz1[5] = {{"Mujo", "Mujic"}};
	struct Drzava niz3[7] = { {"SAD", "Washington", 444}};
	struct Grad niz2[8] = {
		{"Washihinton", 777, {"Mujo", "Mujic"}}, 
	};		
	int vel = samo_glavni(niz1, 5, niz2, 8, niz3, 7);
	int i;
	printf("Vel: %d\n", vel);
	for (i=0; i<vel; i++) {
		printf("%s\n", niz2[i].naziv);
	}
	return 0;
	*/