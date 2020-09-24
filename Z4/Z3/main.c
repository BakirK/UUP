#include <stdio.h>
#include <math.h>

//funkcija provjerava da li je karakter broj ili ne
int jeBroj(char *s) {
	char *p=s;
	if(*p>=48 && *p<=57) {
		return 1;
	}
	else return 0;
}


char *dvostruko(char *s) {
	char *p=s;
	char *p1;
	char *p2;
	int broj_stari;
	int broj_temp;
	int br_cifara;
	int br_cifara_stari;
	int i=0, stepen=0, duzina=0;
	int broj=0;
	int cifra=0;
	while(*p!='\0') {
		if(jeBroj(p)==1 && cifra==0) {
			stepen=0;
			cifra=1;
			p1=p;
			broj=0;
			duzina=0;
			br_cifara=0;
			br_cifara_stari=0;
			//pomjera pokazivac na kraj trenutnog broja
			//te broji duzinu broja
			while(jeBroj(p1)) {
				duzina++;
				p1++;
			}
			p2=p1;
			p2--;
			//u varijablu "broj" smijestam cifre odozada tj
			//pocevsi od cifra jedinica sto odredjuje var stepen
			for(i=0;i<duzina;i++) {
				broj+=((*p2)-'0')*pow(10,stepen);
				stepen++;
				p2--;
			}
			broj_stari=broj;
			broj=broj*2;
			broj_temp=broj;
			//prebrojavanje cifri novog i starog broja
			//da se ustanovi da li ce doci do overflow-a
			while(broj_stari!=0) {
				br_cifara_stari++;
				broj_stari/=10;
			}
			while(broj_temp!=0) {
				br_cifara++;
				broj_temp/=10;
			}
			//ako nije doslo do overflow-a
			if(br_cifara==br_cifara_stari) {
				//pokaivac p pokazuje na prvu cifru broja
				p2=p;
				stepen--;
				for(i=0;i<duzina;i++) {
					*p2=(broj/pow(10,stepen))+'0';
					broj-=(*p2-'0')*pow(10,stepen);
					stepen--;
					p2++;
				}
			}
			//ako jesto doslo do overflow-a, moram sve shiftat za jedno mjesto
			//jer svaki broj pomnozen sa 2 ne moze imati vise od 1 cifru overflow-a
			else {
				p2=p;
				//pomjeram p2 na kraj stringa da mogu sve shiftat za 1 da moze primit overflow
				while(*p2!='\0') {
					p2++;
				}
				//pokazivac sada pokazuje na '\0'
				//pomjeram pokazivac out of bounds sa pretpostavkom da string ima dovoljno mjesta
				p2++;
				*p2='\0';
				
				p2--;
				//shifting
				while(p2!=p) {
					*p2=*(p2-1);
					p2--;
					
				}
				//pokaivac p pokazuje na prvu cifru broja
				p2=p;
				//duzina se povecala jer imamo jednu novu cifru tj. carry out
				duzina++;
				for(i=0;i<duzina;i++) {
					*p2=(broj/pow(10,stepen))+'0';
					broj-=(*p2-'0')*pow(10,stepen);
					stepen--;
					p2++;
				}
			}
		}
		//provjera da li je trenutna rijec cifra
		//svaki put kad dodje do praznog mjesta, 
		//varijabla cifra se resetuje na 0 
		if(jeBroj(p)==0) {
			cifra=0;
		}
		p++;
	}
	
	return s;
}

int main() {
	char tekst[100] = "5";
	printf("'%s'", dvostruko(tekst));
	return 0;
}