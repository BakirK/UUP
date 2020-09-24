#include <stdio.h>

int jeSlovo(char *s) {
	if(*s>='A' && *s<='Z') {
		return 1;
	}
	else if (*s>='a' && *s<='z') {
		return 1;
	}
	return 0;
}


char* tritacke(char *s) {
	char *p=s;
	char *pocetak;
	int brojac=0;
	int razmak=1;
	while(*p!='\0') {
		if(jeSlovo(p)==0) {
			razmak=1;
		}
		if(jeSlovo(p)==1) {
			brojac++;
			razmak=0;
		}
		else brojac=0;
		p++;
	}
	return s;
}

int main() {
	printf("Tutorijal 10, Zadatak 6");
	return 0;
}
