#include <stdio.h>


int prost(int broj){
	int i,a=0;
	if(broj<=0){
		return 0;
		}
	else{
		if(broj==1){
			return 0;
		}
		else{
			for(i=2;i<broj;i++){
				if((broj%i)==0){
					return 0;
				}
			}
			if(a==0){
				return 1;
			}
		}
		return 0;
	}
}




int main() {
	int i,a;
	for(i=0;i<=100;i++){
		a=prost(i);
		if(a==0){
			continue;
		}
		else{
			printf("%d\n",i);
		}
	}
	return 0;
}
