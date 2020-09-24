#include <stdio.h>
#include <stdlib.h>

int main() {
	double i,r;
	for (i=0;i<=20;i++){
	r=rand()%(2);
	printf("\n%f",r);
	}
	return 0;
}
