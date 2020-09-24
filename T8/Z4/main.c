#include <stdio.h>

int drugi(int niz[], int n) {
	int prvi,i,index_p,index_d=-1,drugi;
	prvi=niz[0];
	drugi=-1;
	index_p=0;
	//index_d=0;
	for (i=0;i<n;i++){
		if(niz[i]>prvi){
			index_d=index_p;
			drugi=prvi;
			prvi=niz[i];
			index_p=i;
		}
		else if(niz[i]>drugi && niz[i]!=prvi){
			drugi=niz[i];
			index_d=i;
		}
	}
	return index_d;
}

int main() {
	int a,n=0,niz[100];
	printf("Unesite niz brojeva: ");
	do{
		scanf("%d",&a);
		if(a!=-1){
			niz[n]=a;
			n++;
		}
		else break;
	}
	while(a!=-1);
	a=drugi(&niz[0],n);
	printf("Indeks drugog po velicini je: %d",a);
	
	
	return 0;
}
