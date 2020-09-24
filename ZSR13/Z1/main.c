#include <stdio.h>
int a1(int *x, int *y)
{
	*y = *x / *y;
	return *y;
}
int a2(int* p1)
{
	int y;
	printf("\naaa: %d",*p1);
	y=++*p1;
	printf("\naaa: %d",*p1);
	printf("\naaa: %d",*p1);
	printf("\naaa: %d",*p1);
	y+=*p1++;
	y++;
	return y;
}
void a3(char *p)
{
	*(p+3)='-';
	*p++='-';
	p+=3;
	printf("\n%c\n",*p);
	*p='-';
}
int main()
{
	int X[4]= {5,10,15,20};
	int Y[2][2]= {1,2,3,4};
	char z[]="-lo--da";
	int y=1,x=1;
	//printf("%d\n",*(Y[1]+1);
	y=*(Y[1]+1)+*(X+3);
	printf("%d\n",y);
	y=a1(X+1,&x);
	printf("%d\n",y);
	y=a2(Y);
	printf("\ndududu%d\n",y);
	a1(&x,&y);
	printf("%d\n",x);
	a3(z);
	printf("%s\n",z);
	return 0;
}








































/*#include <stdio.h>
//19 40
int b(int *p, int x) {
	int *z = p;
	while(*z++<x);
	return z-p;
}


int main() {
	int y[2][2];
	y[0][0]=5;
	y[0][1]=6;
	y[0][2]=7;
	y[1][0]=8;
	y[1][1]=9;
	y[1][2]=10;
	int a=y[1+1][0]++;
	printf("%d",a);
	printf("\n%d",y[0][0]);

	return 0;
}
*/