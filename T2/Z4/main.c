#include <stdio.h>

//Niste rekli da ne smijemo koristiti pokazivace i funkcije 😎
void swap(int* a, int* b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

int main() {
	int a,b,c,i=3;
	printf("Unesite tri broja: ");
	scanf("%d %d %d",&a,&b,&c);
	if( c>200 || c<50 || b>200 || b<50 || a>200 || a<50  ){
		printf("Svi brojevi nisu iz intervala 50 do 200");
	}
	else{
		if(a>=c){
			swap(&a,&c);
		}
		if(a>=b){
			swap(&a,&b);
		}
		if(b>=c){
			swap(&b,&c);
		}
		printf("Brojevi poredani po velicini glase: %d,%d,%d",a,b,c);
		if(a==b){
			i--;
		}
		if(b==c){
			i--;
		}
		if(a==c){
			i--;
		}
		if(i<1)i=1;
		if(i>1){
			printf("\nUnesena su %d razlicita broja",i);
		}
		else printf("\nUnesen je %d razlicit broj",i);
	}
	return 0;
}


