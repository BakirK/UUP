#include <stdio.h>
#include <math.h>
/* Definicija tacke i kruznice */
struct Tacka {
    double x,y;
};

struct Pravougaonik {
	struct Tacka dole_lijevo;
	struct Tacka gore_desno;
};

float obim_pravougaonika(struct Pravougaonik p) {
	float obim=(fabs(p.gore_desno.x-p.dole_lijevo.x)*2)+2*fabs(p.gore_desno.y-p.dole_lijevo.y);
	return obim;
}

float povrsina_pravougaonika(struct Pravougaonik p) {
	float povrsina=fabs(p.gore_desno.x-p.dole_lijevo.x)*fabs(p.gore_desno.y-p.dole_lijevo.y);
	return povrsina;
	
}

int tacka_u_pravougaoniku(struct Tacka t,struct Pravougaonik p) {
	if((t.x>=p.dole_lijevo.x && t.x<=p.gore_desno.x) && (t.y>=p.dole_lijevo.y && t.y<=p.gore_desno.y)){
		return 1;
	}
	else {
		return 0;
	}
}

struct Kruznica {
    struct Tacka centar;
    double poluprecnik;
};

/* Funkcije za unos */
struct Tacka unos_tacke() {
    struct Tacka t;
    printf ("Unesite koordinate tacke (x, y): \n");
    scanf ("%lf,%lf", &t.x, &t.y);
    return t;
}

struct Kruznica unos_kruznice() {
    struct Kruznica k;
    printf ("Unesite centar kruznice:\n");
    k.centar = unos_tacke();
    printf ("Unesite poluprecnik kruznice: \n");
    scanf("%lf", &k.poluprecnik);
    return k;
}

/* Funkcija za udaljenost izmedju dvije tacke */
float udaljenost(struct Tacka t1, struct Tacka t2) {
    return sqrt( (t1.x-t2.x)*(t1.x-t2.x) + (t1.y-t2.y)*(t1.y-t2.y) );
}

float obim_kruznice(struct Kruznica k) {
	float obim=4.0 * atan (1.0)*k.poluprecnik*2;
	return obim;
}

float povrsina_kruznice (struct Kruznica k) {
	float povrsina=k.poluprecnik*k.poluprecnik*4.0 * atan (1.0);
	return povrsina;
}






/* Glavni program: Da li je tacka unutar kruznice */
int main() {
    struct Kruznica k;
    struct Tacka t;
    double d;
    printf ("Unesite kruznicu:\n");
    k = unos_kruznice();
    printf ("Unesite neku tacku:\n");
    t = unos_tacke();

    /* Tacka se nalazi unutar kruznice ako je udaljenost tacke od centra
    kruznice manja od poluprecnika kruznice */
    d = udaljenost(t, k.centar);
    if (d<k.poluprecnik)
        printf("Tacka je unutar kruznice.\n");
    else if (d==k.poluprecnik)
        printf("Tacka je na kruznici.\n");
    else
        printf("Tacka je izvan kruznice.\n");
        
        printf("Obim kruznice: %.3f\n",obim_kruznice(k));
        printf("Povrsina kruznice: %.3f",povrsina_kruznice(k));
        
    return 0;
}
