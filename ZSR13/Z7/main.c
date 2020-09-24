#include <stdio.h>

int main() {
	char imeprezime[40];
	char *p1=imeprezime;
	char ime_temp[20];
	char prezime_temp[20];
	char *p2=ime_temp;
	while(*p1!=' ') {
		*p2=*p1;
		p1++;
		p2++;
	}
	p1++;
	p2=prezime_temp;
	while(*p1!='\0') {
		*p2=*p1;
		p1++;
		p2++;	
	}
	*p2='\0';
	return 0;
}
