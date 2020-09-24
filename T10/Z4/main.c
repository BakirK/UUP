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

char* whitespace(char* s) {
	char *p=s;
	char s2[500];
	char *p2=s2;
	int a=1;
	while(*p!='\0') {
		if(a==1) {
			if((*p==' ' || *p=='\n' || *p=='\t') && (jeSlovo(p-1)==1 || *(p)=='.')) {
				*p2=*p;
				p2++;
			}
			else if(*p!=' ' && *p!='\n' && *p!='\t') {
				*p2=*p;
				p2++;
			}
		}
		else {
			if(*p==' ' && (jeSlovo(p-1)==1 || *(p-1)=='.')) {
				*p2=*p;
				p2++;
			}
			else if((*p=='\n' || *p=='\t') && jeSlovo(p-1)==1) {
				*p2=' ';
				p2++;
			}
			else if(*p!=' ' && *p!='\n' && *p!='\t') {
				*p2=*p;
				p2++;
			}
		}
		a=0;
		p++;
	}
	*p2='\0';
	if(*(p2-1)==' ') {
		*(p2-1)='\0';
	}
	p=s;
	p2=s2;
	while(*p2!='\0') {
		*p=*p2;
		p++;
		p2++;
	}

	*p='\0';
	return s;
}


int main() {
	char tekst[] = "  \t  Prva   recenica.  \n \t   Druga\nrecenica\t\n\t";
	printf("'%s'", whitespace(tekst));
	
	return 0;
}
