#include <stdio.h>
#define PI 3.14

int main() {
     float R, P, V, plopte;

    /* Unos poluprecnika sa tastature i izracunavanje */

    printf ("n Unesite poluprecnik:");
    scanf ("%f", &R);
    P=(R*R)*PI;
    V=(4/3)*R*R*R*PI;
    plopte=4*R*R*PI;

    /* Ispis na monitoru*/
    printf("\n Povrsina kruga sa poluprecnikom %  2f je %.2f", R,P);
    printf("\n Zapremina kugle sa poluprecnikom %2f je %.2f", R,V);
    printf("\n Povrsina lopte sa poluprecnikom %2f je %.2f", R, plopte);
    return 0;

}
