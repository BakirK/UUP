#include <stdio.h>

int samoglasnici(char *s) {
	int brojac=0;
	char* p=s;
	while(*p!='\n' && *p!='\0'){
		if (*p=='A' || *p=='a' ||*p=='E' ||*p=='e' ||*p=='I' ||*p=='i' || *p=='O' ||*p=='o' ||*p=='U' ||*p=='u'){
			brojac++;
		}
		p++;
	}
	return brojac;
	
}


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

int prebroji(char* s, char znak) {
    int broj = 0;
    while (*s != '\0') {
        if (*s == znak)
            broj++;
        s++;
    }
    return broj;
}

int main() {
    char a[80],c;
    printf ("\nUnesite jednu rijec do 80 znakova (ENTER za kraj): ");
    unesi(a, 80);
    printf ("\nKoji znak treba prebrojati: ");
    scanf ("%c", &c);
    printf ("\nBroj znakova %c je: %d\n",c,prebroji(a,c));
    printf ("\nBroj samoglasnika je: %d\n",samoglasnici(a));
    return 0;
}
