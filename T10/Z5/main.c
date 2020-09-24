#include <stdio.h>
#include <stdlib.h>

//provjerava da li postoji zatvorenje komentara "/*" iako u zadatku
// pise da je pretpostavka da jeste zatvoren, test 2 ne jebe to sekunde
int postoji_zatvoren(char *s) {
    char *p=s;
    while(*p!='\0') {
        if (*p=='*' &&  *(p+1)=='/') {
            return 1;
        }
        p++;
    }
    return 0;
}

char* ukloni_komentare (char *s) {
    char *p=s;
    char *p2;
    char recenica[1000];
    p2=recenica;
    int copy=1;
    int linijski=0;
    int ml=0;
    
    while((*p)!='\0') {
         if((*p=='/' && *(p+1)=='*') && copy==1 && ml==0 && linijski==0) {
             //provjera da li postoji zatvoren komentar
            if(postoji_zatvoren(p)==1) {
                copy=0;
                ml=1;
                 
                p++;
                if(*(p+1)=='\0') {
                    break;
                } else{ 
                    p++;
                }
            }
        }
        if((*p=='*' && *(p+1)=='/') && copy==0 && ml==1 && linijski==0) {
            copy=1;
            ml=0;
            p++;
            // hardcode kad zavrsava sa */\0 pa skakanje sa * na \0 daje mem gresku
            if(*(p+1)=='\0') {
                break;
            } else{ 
                p++;
            }
        }
       
        if(*p=='/' && *(p+1)=='/' && copy==1 && ml==0 && linijski==0) {
            copy=0;
            linijski=1;
        }
        if(*p=='\n' && copy==0 && ml==0 && linijski==1) {
            copy=1;
            linijski=0;
        }
        if(copy==1) {
            *p2=*p;
            p2++;
        }
        p++;
        
    }
    *p2='\0';
    p2=recenica;
    p=s;
    while(*p2!='\0') {
        *p=*p2;
        p++;
        p2++;
    }
    *p='\0';
    	return s;
}

int main()
{
    char kod[] = "aa**/**/*/*/*/bb";
    printf("%s", ukloni_komentare(kod));
    return 0;
}
