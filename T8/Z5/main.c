#include <stdio.h>
#include <math.h>

void zaokruzi(double* niz, int vel){
	double* p=niz;
	while(p<niz+vel){
		*p=round((*p)*10)/10;
		p++;
	}
}

int main() {
	printf("Tutorijal 8, Zadatak 5");
	return 0;
}
