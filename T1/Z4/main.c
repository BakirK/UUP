#include <stdio.h>
#include <math.h>
#define PI 3.14

float square(float a){
	float b=a*a;
	return b;
	
}

int main() {
	float a, b, c, r, H, P_valjka, P_pravougaonika, P_total, V_total, V_valjka, V_pravougaonika;
	printf("unesi stranicu a,b,c pravougaonika: ");
	scanf("%f,%f,%f",&a,&b,&c);
	printf("unesi visinu,poluprecnik valjka: ");
	scanf("%f,%f",&r,&H);
	P_valjka=2*r*PI*(r+H);
	V_valjka=square(r)*PI*H;
	P_pravougaonika=4*a*b+2*c*b;
	V_pravougaonika=a*b*c;
	P_total=P_valjka+P_pravougaonika;
	V_total=V_pravougaonika+V_valjka;
	printf("povrsina tijela: %.2f \n volumen tijela: %.2f",P_total,V_total);
	
	
	/*
	printf("unesi z2: ");
	scanf("%f",&z2);
	t=sqrt( square((x2-x1)) + square((y2-y1)) + square((z2 - z1))  );
	printf("Udaljenost izmedju ive 2 tacke: %.2f",t);
	*/
	return 0;
}


