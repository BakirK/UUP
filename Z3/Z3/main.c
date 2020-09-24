#include <stdio.h>

int daj_sljedeci_broj(int vrijednost){
	static int min=0,max=100;
	static int broj;
	switch(vrijednost){
			case -1:{ 
				max=(min+max)/2;
				broj=(min+max)/2;
				break;
			}
			case 1:{
				min=(min+max)/2;
				broj=(min+max)/2;
				break;
			}
			case 0:{
				broj=(min+max)/2;
				break;
			}
			default:{
				break;
			}
	}
	if (broj == 0) {
		broj = 1;//ne ukljucuje se nula
	}
	return broj;
}

int main() {
	char a;
	printf("Zamislite neki broj...\n");
	do{
		printf("Da li je taj broj %d? ",daj_sljedeci_broj(0));
		scanf(" %c",&a);
		switch(a){
			case 'M':{ 
				daj_sljedeci_broj(-1);
				break;
			}
			case 'V':{
				daj_sljedeci_broj(1);
				break;
			}
			case 'J':{
				printf("Pogodio sam!");
				break;
			}
			default:{
				printf("Pogresan unos, probajte ponovo.\n");
				break;
			}
		}
	}
	while(a!='J');
	return 0;
}
