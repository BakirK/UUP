#include <stdio.h>

char* kapitaliziraj(char *s)
{
	char *p=s;
	int rijec=1;
	while(*p!='\0' && *p!='\n') {
		if(rijec==1) {
			if(p==s) {
				if(*p>='a' && *p<='z') {
					*p-=32;
					rijec=0;
				}
			} else if(*(p-1)==' ' && *p!=' ') {
				if(*p>='a' && *p<='z') {
					*p-=32;
					rijec=0;
				}
			}
		}
		if(*p==' ' && *(p+1)!=' ' && rijec==0) {
			rijec=1;
		}
		p++;
	}
	return s;

}

void unesi(char niz[], int velicina)
{
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}


int main()
{
	char a[80];
	char* p=a;
	printf("Unesite neki tekst: ");
	unesi(a,80);
	kapitaliziraj(a);
	while(*p!='\0' && *p!='\n') {
		printf("%c",*p);
		p++;
	}
	return 0;
}
