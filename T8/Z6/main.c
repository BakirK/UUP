/*
#include <stdio.h>

void sortiraj(double* niz,int vel){
	double* ptr=niz;
	int i,j;
	double temp;
	for(i=0;i<vel;i++){
		for(j=i+1;j<vel;j++){
			if(*(ptr+i)>*(ptr+j)){
			temp=*(ptr+i);
			*(ptr+i)=*(ptr+j);
			*(ptr+j)=temp;
			}
		}
	}
}

double main() {
	return 0;
}
*/

#include <stdio.h>

void sortiraj(double* niz, int vel){
    double temp;
    double* p=niz;
    int i,j;
	for (j=0; j<vel; j++){
        for (i=0; i<vel-1; i++){
            if(*p>*(p+1)){
                temp=*p;
                *p=*(p+1);
                *(p+1)=temp;
            }
            p++;
        }
        p=niz;
    }
    
}


int main() {
	//printf("Tutorijal 8, Zadatak 6");
	return 0;
}
