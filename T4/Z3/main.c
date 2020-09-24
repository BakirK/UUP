#include <stdio.h>

int main() {
	//printf("Tutorijal 4, Zadatak 3");
	int i,j=1,x=1,a=1,broj=1,y=1,brojac=1;
	char x1='X',ap='|';
	for (i = 0; i <= 12; i++) {
		if(i==1){
			while(x<=10){
					if(j==3){
						printf("%3c",x1);
					}
					else if(j==5){
						printf("%2c",ap);
						
					}
					/*
					else if(x==10){
						x++;
						printf("%d",x);
					}*/
					else if(j%4==1 && j>5){
						printf("%4d",x);
						x++;
					}
					/*
					else {
						printf(" ");
					}*/
					j++;
			}
			   
		}
			printf("\n");
			
			if(i==2){
				do{
					if(a==5)
					printf("+");
				else printf("-");
				a++;
				}
				while(a<j);
			}
			
			if(i>2){
				x=1;
				brojac=1;
				y=i-2;
				broj=1;
				while(broj<=10){
					if(brojac==3){
						printf("%3d",y);
					}
					else if(brojac==5){
						printf("%2c",ap);
						
					}

					else if(brojac%4==1 && brojac>5){
						printf("%4d",x*y);
						x++;
						broj++;
					}
					/*
					else {
						printf(" ");
					}*/
					brojac++;
			}
			}
		}
		
	
	return 0;
}
