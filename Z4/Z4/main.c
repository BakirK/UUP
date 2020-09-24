#include <stdio.h>
#define A 65
#define Z 90

void unesi(char niz[], int velicina) {
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

char *kapitaliziraj(char *s)
{
	char *p=s;
	while(*p!='\0') {
				if(*p>='a' && *p<='z') {
					*p-=32;
				}
		p++;
	}
	return s;
}


void substring(char *p, int index, int  duzina, char* temp) {
	int i=0;
	while(i!=duzina) {
		*temp=*(p+index);
		temp++;
		p++;
		i++;
	}
	*temp='\0';
	
}


char *dodaj(char *s, char *p) {
	while(*p!='\0') {
		*s=*p;
		s++;
		p++;
	}
	return s;
}


int main() {
	int duzina, visina;
	char T[99999];
	char temp[99999];
	char *temp_p=temp;
	scanf("%d%d",&duzina, &visina);
	unesi(T, 99999);
	kapitaliziraj(T);
	char *p2=T;
	char *p;
	int i;
	int s;
	char noviString[99999];
	char *p1=noviString;
	for(i=0; i<visina; i++) {
	    char red[99999];
	    unesi(red, 99999);
	    p=red;
	    p2=T;
	    while(*p2!='\0') {
	        s=(int) *p2;
	        if(s < A || s > Z) {
	            substring(p, duzina * (Z - A + 1), duzina, temp_p);
	            p1=dodaj(p1,temp_p);
	        }
	        else {
	            substring(p, duzina * (s - A), duzina, temp_p);
	            p1=dodaj(p1,temp_p);
	        }
	        p2++;
	    }
	    *p1='\n';
	    p1++;
	}
	*p1='\0';
	p1=noviString;
	while(*p1!='\0') {
		printf("%c",*p1);
		p1++;
	}
	
	
	
	return 0;
}
