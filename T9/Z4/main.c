#include <stdio.h>

char max_slovo(char *s) {
	char *p=s;
	int niz[26], vrijednost;
	int i, max=0;
	int index;
	for(i=0;i<26;i++){
		niz[i]=0;
	}
	while(*p!='\0' && *p!='\n') {
		if(*p>='A' && *p <='Z'){
			vrijednost=*p;
			niz[vrijednost-65]++;
		}
		p++;
	}
	p=s;
	while(*p!='\0' && *p!='\n') {
		if(*p>='a' && *p <='z'){
			vrijednost=*p;
			niz[vrijednost-97]++;
		}
		p++;
	}
	
	
	for(i=0;i<25;i++){
		if(niz[i]>=max){
			max=niz[i];
		}
	}
	for(i=0;i<25;i++){
		if(niz[i]==max){
			index=i;
			return index+65;
			break;
		}
	}
	return index+65;
}

int main() {
	printf("%c\n", max_slovo("Ovo je probni primjer."));
	return 0;
}
