#include <stdio.h>

int main() {
	float A,B,C,D,MIN,MAX;
    printf("Unesite brojeve a,b,c,d: ");
    scanf("%f %f %f %f", &A,&B,&C,&D);
    if (A>C) MAX=A; else MAX=C;
    if (B<D) MIN=B; else MIN=D;
    if ((B<C)||(A>D)) printf("Skupovi se ne sijeku."); 
    else {
    printf ("Rezultantni interval je [%g,%g].", MAX, MIN); }
	return 0;
}
