#include <stdio.h>

int jeBroj(char broj) {
	if(broj>=48 && broj <=57) {
		return 1;
	}
	return 0;
}

int jeRazmak(char c) {
	if(c=='.' || c==',' || c==' ' || c=='\t' || c=='\n' || jeBroj(c)==1) {
		return 1;
	}
	return 0;
}

char *udvostruci_rijec(char *s) {
	char *p=s;
	char *p1, *p2, *p3;
	int brojac=0;
	while(*p!='\0') {
		brojac=0;
		while(jeRazmak(*p)==1 && *p!='\0') {
			p++;
		}
		if(jeRazmak(*p)==0) {
			p1=p;
			p2=p;
		}
		
		//p2 pomaknem na kraj rijeci
		while(jeRazmak(*p2)==0 && *p2!='\0') {
			p2++;
			brojac++;
		}
		
		//p1 na kraj niza
		while(*p1!='\0') {
			p1++;
		}
		//p3 pokazuje na \0
		p3=p1;
		//povecavam za 1 mjesto zbog razmaka izmedju doadanih rijeci
		p1++;
		// zbog extra rijeci
		p1+=brojac;
		
		while(p1>=p2 && p3>=s) {
			*p1=*p3;
			p3--;
			p1--;
		}
		*p2=' ';
		p=p2+brojac+1;
		p++;
	}
	
	return s;
	
}


int main() {
	char s[100] = "075\n\t5";
	printf("%s",udvostruci_rijec(s));
	return 0;
}