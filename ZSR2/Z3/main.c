#include <stdio.h>

int main() {
int niz[6] = {-4,9,-6,-10,-8,0};
int i;
for (i=1; i<6; i++)
	niz[i] += niz[i-1];
	for (i=0; i<6; i++)
printf("%d ", niz[i]);

	return 0;
}
