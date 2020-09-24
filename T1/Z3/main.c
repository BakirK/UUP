#include <stdio.h>
#include <math.h>

float square(float a){
	float b=a*a;
	return b;
	
}

int main() {
	float x1,x2,y1,y2,z1,z2,t;
	printf("unesi x1: ");
	scanf("%f",&x1);
	printf("unesi y1: ");
	scanf("%f",&y1);
	printf("unesi z1: ");
	scanf("%f",&z1);
	printf("unesi x2: ");
	scanf("%f",&x2);
	printf("unesi y2: ");
	scanf("%f",&y2);
	printf("unesi z2: ");
	scanf("%f",&z2);
	t=sqrt( square((x2-x1)) + square((y2-y1)) + square((z2 - z1))  );
	printf("Udaljenost izmedju ive 2 tacke: %.2f",t);
	return 0;
}


