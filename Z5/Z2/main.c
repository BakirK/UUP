#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Tacka {
   double x,y;
};

struct Kruznica {
   struct Tacka centar;
   double poluprecnik;
};


struct Kvadrat {
   struct Tacka dl;
   double stranica;
};


int obuhvacen (struct Kruznica kr, struct Kvadrat kv) {
	if (kr.centar.x+kr.poluprecnik < kv.dl.x+kv.stranica) {
		return 0;
	}
	else if (kr.centar.x-kr.poluprecnik > kv.dl.x) {
		return 0;
	}
	if (kr.centar.y+kr.poluprecnik < kv.dl.y ) {
		return 0;
	}
	else if (kr.centar.y-kr.poluprecnik > kv.dl.y+kv.stranica) {
		return 0;
	}
	struct Tacka pomocna=kv.dl;
	double duzina=sqrtf(fabs(powf(kr.centar.x-pomocna.x,2)+powf(kr.centar.y-pomocna.y,2)));
	if (duzina>kr.poluprecnik) {
		return 0;
	}
	pomocna.x+=kv.stranica;
	duzina=sqrtf(fabs(powf(kr.centar.x-pomocna.x,2)+powf(kr.centar.y-pomocna.y,2)));
	if (duzina>kr.poluprecnik) {
		return 0;
	}
	pomocna.y+=kv.stranica;
	duzina=sqrtf(fabs(powf(kr.centar.x-pomocna.x,2)+powf(kr.centar.y-pomocna.y,2)));
	if (duzina>kr.poluprecnik) {
		return 0;
	}
	pomocna.x-=kv.stranica;
	duzina=sqrtf(fabs(powf(kr.centar.x-pomocna.x,2)+powf(kr.centar.y-pomocna.y,2)));
	if (duzina>kr.poluprecnik) {
		return 0;
	}
	return 1;
}


int izbaci_visak(struct Kruznica* kr, int velkr, struct Kvadrat* kv, int velkv) {
	int i=0, j=0, flag=1, n;
	struct Kruznica *kruzic=kr;
	struct Kvadrat *kvadratic=kv;
	struct Kvadrat *pomocni;
	while (i<velkv) {
		j=0;
		kruzic=kr;
		flag=0;
		while (j<velkr) {
			if(obuhvacen(*kruzic, *kvadratic)==1) {
				flag=1;
			}
			kruzic++;
			j++;
		}
		
		if(flag==0) {
			n=i;
			pomocni=kvadratic;
			if(n<velkv-1) {
				while(n<velkv-1) {
					*pomocni=*(pomocni+1);
					n++;
					pomocni++;
				}
				velkv--;
				kvadratic--;
				i--;
			} 
			else if(n==velkv-1) {
				velkv--;
			}
		}
		kvadratic++;
		i++;
	}
	return velkv;
}


int main() {
struct Kruznica kr[] = {
    {{-10,-10}, 1}
};
struct Kvadrat kv[] = {
   {{-10,-11},0}
};
kv[1].stranica = sin(M_PI/4) - 0.001;
int vel = izbaci_visak(kr, 1, kv, 1);
int i;
for (i=0; i<vel; i++) {
    printf ("(%g,%g) %g\n", kv[i].dl.x, kv[i].dl.y, kv[i].stranica);
}

	return 0;
}
