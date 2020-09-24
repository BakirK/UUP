#include <stdio.h>
#include <math.h>

int obrnut(int x){
	int suma=0,broj=x;
	int digit,brojac=0,i;
	//x=abs(x);
    digit = x%10;
    //suma=digit;
    while(!(x<=0))
    {
    	brojac++;
        x = x/10;
    }
    for(i=brojac;i>0;i--){
    	suma+=(broj%10)*pow(10,i-1);
    	broj=broj/10;
    }
    return suma;
}


int main() {
	int broj,a;
	//printf("Tutorijal 7, Zadatak 4");
	scanf("%d",&broj);
	a=obrnut(broj);
	printf("Broj je: %d!!",obrnut(broj));
	
	
	return 0;
}
