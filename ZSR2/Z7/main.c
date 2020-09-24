#include <stdio.h>
#include <math.h>

int main() {
	int i, suma1 = 0, suma2 = 0;
    int niz1[5] = {-1}, niz2[5] = {-1};
    for(i = 0; i < 5; i++) 
    {
        suma1+=++niz1[i];
        suma2+=niz2[i]++;
    }
        
    printf("%d %d", suma1, suma2);









		return 0;
}