#include <stdio.h>

int prva_rijec(char *s) {
	char *p=s;
	int broj=0;
	//brojanje rijeci
	while(*p!='\0') {
		if(p==s){
			if(*p!=' ') {
				broj++;
			}
		}
		else if(*p!=' ' && *(p-1)==' ') {
			broj++;
			
		}
		p++;
	}
	//izbacivanje sve osim 1. rijeci
	p=s+1;
	while(*p!='\0') {
		if(*p==' ' && *(p-1)!=' ') {
			*p='\0';
			break;
		}
		p++;
	}
	
	
	return broj;
}

int main() {
	char recenica[200] = "    I     jogurt.   ujutru     godi.    ";
	printf("Broj rijeci u recenici je: %d\n", prva_rijec(recenica));
	printf("%s", recenica);
	return 0;
}
