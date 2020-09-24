#include <stdio.h>
#include <math.h>

int main() {
	long long int a=23, i,b;
	for(i=1;i<512;i=i*2) {
		b=pow(a,i);
		printf("\ni:%lld b:%lld",i,b%679);
	}
	
	return 0;
}
