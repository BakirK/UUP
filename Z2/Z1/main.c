#include <stdio.h>
#include <math.h>

#define BLANK  " "
#define FILLED "*"

void spirala(int size){
    int i, j;
    int half=(size/2) + 1;

    //gornja polovina
    //i & 1 je isto sto i i%2==1 
    for (i=0;i<half;i++){
        if (!(i & 1)){
            for (j=0;j<size;j++){
                if ((j & 1) && (j < i - 1 || j >= size - i)){
                    printf(BLANK);
                }
                else{
                    printf(FILLED);
                }
            }
        }
        else{
            for (j=0;j<size;j++){
                if ((j<i-1 || j>=size-i) && j%2==0){
                    printf(FILLED);
                }
                else{
                    printf(BLANK);
                }
            }
        }
        puts("");
         //isto sto i printf("\n");
    }
    //donja polovina 
    //j & 1 je isto sto i i%2==1 
    for (; i<size; i++){
        if (!(i&1)){
            for (j=0;j<size;j++){
                if ((j%2==1) && (j<size-i || j>i)){
                    printf(BLANK);
                }
                else{
                    printf(FILLED);
                }
            }
        }
        
        else{
            for (j = 0;j<size;j++){
                if (!(j & 1) && (j<size-i || j>i)){
                    printf(FILLED);
                }
                else{
                    printf(BLANK);
                }
            }
        }
        puts("");
        //isto sto i printf("\n");
    }
}

int main() {
    int n;
	do{
		printf("Unesite broj N: ");
		scanf("%d",&n);
		if(n%4!=1){
			printf("N nije ispravno!\n");
		}
	}
	while(n%4!=1);
	printf("\n");
    spirala(n);
    return 0;
}