#include <stdio.h>

int strcmpi(const char *s1, const char *s2,  int velikamala) {
	char *p1, *p2;
	char a,b;
	if(velikamala==1) {
		while (*s1 != '\0' && *s2 != '\0') {
			if (*s1 < *s2) return -1;
			if (*s1 > *s2) return 1;
			s1++;
			s2++;
		}
		if (*s1 != '\0') return 1;
		if (*s2 != '\0') return -1;
		return 0;
	}

	else {
		while (*s1 != '\0' && *s2 != '\0') {
			a=*s1;
			b=*s2;
			p1=&a;
			p2=&b;
			if(*p1>='a' && *p1<='z') {
				*p1-=32;
			}
			if(*p2>='a' && *p2<='z') {
				*p2-=32;
			}
			if (*p1 < *p2) return -1;
			if (*p1 > *p2) return 1;
			s1++;
			s2++;
		}
		if (*s1 != '\0') return 1;
		if (*s2 != '\0') return -1;
		return 0;
	}
}


int main() {
	printf("%d ", strcmpi("Sarajevo", "sarajevo", 0));
	printf("%d", strcmpi("Sarajevo", "sarajevo", 1));
	return 0;
}
