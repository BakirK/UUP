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

struct Vrijeme proteklo(struct Vrijeme v1, struct Vrijeme v2) {
		struct Vrijeme v;
        int sekunde1=v1.sati*3600+v1.minute*60+v1.sekunde;
        int sekunde2=v2.sati*3600+v2.minute*60+v2.sekunde;
        
        int proteklo=abs(sekunde2-sekunde1);
        v.sati=proteklo/3600;
        proteklo=proteklo-v.sati*3600;
        v.minute=proteklo/60;
        proteklo=proteklo-v.minute*60;
        v.sekunde=proteklo;
        return v;
}


int main() {
        struct Vrijeme v1;
        struct Vrijeme v2;
        struct Vrijeme v;
	printf("Unesite prvo vrijeme (h m s): \n");
	v1=unos_vremema();
	printf("Unesite drugo vrijeme (h m s): ");
	v2=unos_vremema();
	v=proteklo(v1,v2);
	printf("\nIzmedju dva vremena je proteklo %d sati, %d minuta i %d sekundi.",v.sati, v.minute, v.sekunde);
	
	return 0;
}