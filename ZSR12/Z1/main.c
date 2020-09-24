#include <stdio.h>

int main() {
	char x,y;
	FILE *ulaz;
	FILE *izlaz;
	
	printf("Unesite znakove x i y: ");
	
	scanf("%c %c",&x,&y);
	
	if(y < x){
		printf("Pogresan unos");
		return 0;
	}
	
	ulaz = fopen("input.txt","r");
	
	if(ulaz == NULL){
		printf("Greska pri otvaranju datoteke input.txt");
		return 0;
	}
	
	izlaz = fopen("output.txt","w");
	
	if(izlaz == NULL){
		printf("Greska pri otvaranju datoteke output.txt");
		return 0;

	}
	
	char c;
	int brojac = 0;
	
	do {
		c = getc(ulaz);
		if(c >= x && c <= y){
			fputc(c,izlaz);
		}
		
	}
	while(c != EOF);

	
	return 0;
}