#include<stdio.h>
int x(char *a, char *b)
{
	*b=*a/ *b;
	return *b;
}//10 29
int y(int *p,int a)
{
	int* c;
	c=p;
	printf("*c%d\n",*c);
	printf("*p%d\n",*p);
	printf("p%d\n",p);
	printf("c%d\n",c);
	c++;
	printf("c++%d\n",c);
	printf("p++%d\n",p);
	while(*c++<a){
	};
	return c-p;
}
void z(char *p)
{
	*(p+1)='-';
	*p++='-';
	p+=1;
	*p--='-';
}
int main()
{
	int B[3][3]= {1,2,3,4};
	char c[9]="Trebinje";
	char A[4]= {10,19,28,37};
	int b=1,a=1;
	b=B[0][3]+*(A+3);
	//printf("%d\n",b);
	b=y(A,29);
	printf("%d\n",b);
	y(B,5);
	printf("%d\n",b);
	x(&a,&b);
	printf("%d\n",a);
	z(c);
	printf("%s\n",c);
	return 0;
}