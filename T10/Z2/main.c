#include <stdio.h>

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

char* rot13(char *s) {
    char *p=s;
    
    int i;
    while(*p!='\0') {
        if(*p>='A' && *p<='Z') {
            for(i=0;i<13;i++) {
                (*p)+=1;
                if(*p=='[') {
                    *p='A';
                }
            }
        }
        else if (*p>='a' && *p<='z') {
            for(i=0;i<13;i++) {
                (*p)+=1;
                if(*p=='{') {
                    *p='a';
                }
            }
        }
        p++;
        
    }
    
    
    return s;
	
}


int main() {
	char testni_string[] = "Moje ime je medvjedic Lino";
    printf("%s", rot13(testni_string));
	return 0;
}
