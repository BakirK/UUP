#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int jeSlozen(int broj) {
	int i;
	if(broj<=1){
			return 0;
	}
	else{
		for(i=2;i<broj;i++){
			if((broj%i)==0){
				return 0;
			}
		}
	}
	return 1;
}



int proste_sume(int niz1[], int vel1, int niz2[], int vel2) {
	int i, j=0;
	int broj=0, suma=0;
	int temp;
	for(i=0 ; i<vel1 ; i++) {
		if(j>=vel2) {
			return j;
		}
		suma=0;
		broj=abs(niz1[i]);
		temp=niz1[i];
		while(broj>0) {
			suma+=broj%10;
			broj/=10;
		}
		if(jeSlozen(suma)==1) {
			niz2[j]=temp;
			j++;
		}
	}
	return j;
	
}


int main() {
	int niz1[] = {1, 20101, 4, 44, 40};
    int niz2[2];
    int n1 = sizeof niz1 / sizeof *niz1, n2 = sizeof niz2 / sizeof *niz2;
    int vel = proste_sume(niz1, n1, niz2, n2);
    printf ("Vel: %d\n", vel, *niz2);
    /* Sad ipak IMA prostih suma cifri, dvije */
    niz1[0] = 2; niz1[4] = 501010;
    vel = proste_sume(niz1, n1, niz2, n2);
    printf ("Vel: %d, niz2[0] = %d, niz2[1] = %d", vel, niz2[0], niz2[1]);
	return 0;
}
