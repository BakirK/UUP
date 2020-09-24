#include <stdio.h>

int main() {
	//printf("Zadaća 1, Zadatak 2");
	int iznos,a=0,b=0,c=0,d=0,e=0,f=0;
	printf("Unesite iznos: ");
	scanf("%d",&iznos);
	a=iznos/50; 
	if(a>0) iznos-=a*50; 
	else a=0;
	
	b=iznos/20; 
	if(b>0) iznos-=b*20;
	else b=0;
	
	c=iznos/10;
	if(c>0) iznos-=c*10; 
	else c=0;
	
	d=iznos/5; 
	if(d>0) iznos-=d*5; 
	else d=0;
	
	e=iznos/2;
	if(e>0) iznos-=e*2;
	else e=0;
	
	f=iznos/1;
	if(f>0) iznos-=f*1;
	else f=0;
	
	printf("%d novcanica od 50 KM\n",a);
	printf("%d novcanica od 20 KM\n",b);
	printf("%d novcanica od 10 KM\n",c);
	printf("%d novcanica od 5 KM\n",d);
	printf("%d novcanica od 2 KM\n",e);
	printf("%d novcanica od 1 KM\n",f);
	
	
	
	
	
	
	
	return 0;
}
