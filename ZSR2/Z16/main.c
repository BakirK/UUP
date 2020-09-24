#include <stdio.h>

int main() {
	printf("ZSR 2, Zadatak 16");
	int i;
	
	for(i=1; i<100; i++) {
		if(((i+1173)%26)==10) {
			printf("\n%d",i);
		}
		
	}/*
	for(i=1; i<9999; i++) {
		if(i%11==10 && i%19==2 && i%20==0) {
			printf("\n%d",i);
			break;
		}
		
	}*/
	return 0;
}
