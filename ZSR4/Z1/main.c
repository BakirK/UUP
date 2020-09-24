#include <stdio.h>

int main() {
	char a[]="NRKDLUHRKTYLXYYTULXUHAJDUTUFUIURKHURLYZRAPWFDUOUNZUTUNUHRKTAOIXKFHKQUFKQUFAIK";
	int i;
	for(i=0;i<77;i++) {
		a[i] =((23*a[i])+21) % 26 + 65;
	}
	printf("%s",a);
	
	/*
	char a[]="OECGJMZMXGHERZEXUOVZEHERVSDYEOEHNEXEHERJSXUOYZMDRMCEDMCEDUYM";
	int i;
	for(i=0;i<60;i++) {
		a[i] =(((7*a[i]+11) % 26) + 65);
	}
	printf("%s",a);
*/
	return 0;
}
