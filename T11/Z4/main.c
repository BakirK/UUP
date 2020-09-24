#include <stdio.h>
#include <stdlib.h>

struct Vrijeme {
        int sati;
        int minute;
        int sekunde;
    };
struct Vrijeme unos_vremema() {
        struct Vrijeme v;
        scanf("%d%d%d",&v.sati,&v.minute,&v.sekunde);
        return v;
}

int proteklo(struct Vrijeme v1, struct Vrijeme v2) {
        int sekunde1=v1.sati*3600+v1.minute*60+v1.sekunde;
        int sekunde2=v2.sati*3600+v2.minute*60+v2.sekunde;
        int proteklo=sekunde2-sekunde1;
        return abs(proteklo);
}


int main() {
        struct Vrijeme v1;
        struct Vrijeme v2;
	printf("Unesite prvo vrijeme (h m s): \n");
	v1=unos_vremema();
	printf("Unesite drugo vrijeme (h m s): ");
	v2=unos_vremema();
	int sekunde=proteklo(v1,v2);
	printf("\nIzmedju dva vremena je proteklo %d sekundi.",sekunde);
	
	return 0;
}