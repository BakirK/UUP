#include <stdio.h>


int izbaci_iste_cifre (int a[], int n1, int b[], int n2) {
	int i, j, k, broj1, broj2, cifra1, cifra2, brojac=0, br_istih=0, pomocni;
	int duzina;
	for(i=0;i<n1;i++) {
		for(j=0;j<n2;j++) {
			brojac=0;
			br_istih=0;
			if(a[i]>b[j]) {
				pomocni=a[i];
				while(pomocni>0) {
					brojac++;
					pomocni/=10;
				};
			}
			else if(b[j]>=a[i]) {
				pomocni=b[j];
				while(pomocni>0) {
					brojac++;
					pomocni/=10;
				};
			}
			
			
			broj1=a[i];
			while(broj1>0) {
				cifra1=broj1%10;
				broj1=broj1/10;
				broj2=b[j];
				while(broj2>0) {
					cifra2=broj2%10;
					broj2=broj2/10;
					if(cifra1==cifra2) {
						br_istih++;
					}
				};
			};
			
			if(brojac==br_istih) {
				if(n2-1==j) {
					b[j]=-1;
				}
				else {
					for(k=j;k<n2-1;k++) {
						b[k]=b[k+1];
					}
					b[k]=-1;
				}
			}
			
		}
	}
	duzina=0;
	for(i=0;i<n2;i++) {
		if(b[i]==-1) {
			continue;
		}
		duzina++;
	}
	return duzina;
}


int main() {
	int A[100], B[100], i, n1, n2, a;
	int j;
	printf("Unesite niz A: ");
	i=0;
	while(i<100) {
		scanf("%d", &a);
		if(a==-1) {
			break;
		}
		A[i]=a;
		i++;
	};
	n1=i;
	i=0;
	printf("Unesite niz B: ");
	while(i<100) {
		scanf("%d", &a);
		if(a==-1) {
			break;
		}
		B[i]=a;
		i++;
	};
	n2=i;
	i=0;
	int duzina=izbaci_iste_cifre(A,n1,B,n2);
	
	for(j=0;j<duzina;j++) {
		if(B[j]==-1) {
			continue;
		}
		if(j!=duzina-1) {
			printf("%d,",B[j]);
		} else{
			printf("%d.",B[j]);
		}
	}

}
