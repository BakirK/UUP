#include <stdio.h>

int daj_sljedeci_broj(int n)
{
	static int pogadjanje=50;
	static	int najvise=100;
	static	int najnize=0;
	char c;
	printf("Da li je taj broj %d?",pogadjanje);
	if(n==-1) {
		najvise=pogadjanje;
		if(najvise-najnize==1) {
			pogadjanje=najnize;
		} else {
			pogadjanje=(najvise+najnize)/2;
		}
	} else if(n==1) {
		najnize=pogadjanje;
		pogadjanje=(najvise+najnize)/2;
	} else if(n==0) {
		printf("Pogodili ste");
	}
}
int main()
{
	char c;
	int n=1;
	printf("Zamislite neki broj...\n");
	while(1) {
		do {
			scanf(" %c",&c);
			if(c!='M' && c!='V' && c!='J') {
				printf("Pogresan unos, probajte ponovo.");
			} else {
				break;
			}
		} while(c!='M' && c!='V' && c!='J');
		if(c=='M') {
			n=-1;
			daj_sljedeci_broj(n);
		} else if(c=='V') {
			n=1;
			daj_sljedeci_broj(n);
		} else if(c=='J') {
			n=0;
			daj_sljedeci_broj(n);
			return 0;
		}
	}
	return 0;
}
