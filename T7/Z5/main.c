#include <stdio.h>
#include <math.h>

float faktorijel(float n){
	float i,suma=1;
	for(i=1;i<=n;i++){
		suma*=i;
	}
	return suma;
}

float sinus(float x, float n){
	int i;
	float suma=0;
	for(i=1;i<=n;i++){
		suma+=pow(-1,i-1) * (pow(x,(2*i)-1)/(faktorijel((2*i)-1)));
	}
	return suma;
}

int main() {
	float x, n;
	float sinus1, sinus_funkcija,razlika, p;
	printf("Unesite x: \n");
	scanf("%f",&x);
	printf("Unesite n: \n");
	scanf("%f",&n);
	sinus_funkcija=sin(x);
	printf("\nsin(x)=%f\n",sinus_funkcija);
	sinus1=sinus(x,n);
	printf("sinus(x)=%f\n",sinus1);
	razlika=fabs(sinus_funkcija-sinus1);
	//razlika=fabs(razlika);
	//razlika=razlika/sinus_funkcija;
	p=razlika*100;
	printf("Razlika: %.6f (%.2f%).",razlika,p);
	
	
	
	return 0;
}
