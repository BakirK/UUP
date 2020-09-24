#include <stdio.h>

int provjeri_zagrade(char *s) {
	char *p=s;
	int velika=0, srednja=0, mala=0;
	//char rijec[9999];
	while(*p!='\0') {
		if(*p=='(' || *p==')' || *p=='[' || *p==']' || *p=='{' || *p=='}') {
			if(*p=='(' && mala==0) {
				mala=1;
			}
			else if(*p=='[' && srednja==0) {
				srednja=1;
				//ako je srednja otvorena u malim sto nije dozvoljeno
				if(mala==1) {
					return 0;
				}
			}
			else if(*p=='{' && velika==0) {
				velika=1;
				//ako je velika otvorena u srednjim ili malim
				if(mala==1 || srednja==1) {
					return 0;
				}
			}
			else if(*p==')' && mala==1) {
				mala=0;
			}
			else if(*p==']' && srednja==1) {
				srednja=0;
				//uslov za ukrstanje [(])
				if(mala==1) {
					return 0;
				}
			}
			else if(*p=='}' && velika==1) {
				velika=0;
				//uslov za ukrstanje {(}) {[}]
				if(mala==1 || srednja==1) {
					return 0;
				}
			}
			else {
				return 0;
			}
		}
		p++;
	}
	if(mala==0 && srednja==0 && velika==0) {
		return 1;
	}
	else {
		return 0;
	}
}


int main() {
	printf("%d ", provjeri_zagrade("[[]]"));
	return 0;
}
