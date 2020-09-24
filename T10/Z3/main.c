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

char* izbaci_rijec(char *s, int n) {
	if(n<1) {
		return s;
	}
	int razmak=1;
	char *p1;
	char *p2;
	char *p=s;
	int broj=0;
	while(*p!='\0') {
		if(jeSlovo(p)==0){
			razmak=1;
		}
		else if(razmak==1){
			razmak=0;
			broj++;
		}
		if(broj==n) {
			p1=p;
			while(jeSlovo(p1)==1) {
				p1++;	
			}
			p2=p1;
			p1=p;
			while(*p2!='\0') {
				*p1=*p2;
				p1++;
				p2++;
			}
			*p1='\0';
			return s;
		}
		p++;
	}
	
	
	return s;
}

int main() {
	char testni_string[] = "lmn!   opQ!";
	printf("%s", izbaci_rijec(testni_string,1));
	return 0;
}