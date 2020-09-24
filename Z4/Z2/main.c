#include <stdio.h>

int razmak(char p) {
	if(p!=' ' && p!='.' && p!=',' && p!=';' && p!='?' && p!='!') {
		return 1;
	}
	else {
		return 0;
	}
	return 0;
}

char *zamijeni_min_max(char *s) {
	char *p=s;
	char *p1;
	char *pp[99999];
	int n;
	int brojac[99999]={0};
	int i=0;
	int br_rijeci;
	int min=0, max=0;
	char *min_index=p;
	char *max_index=p;
	int rijec=0;
	char temp[99999];
	int provjera=0;
	
	
	//provjera da li string ima rijeci
	while(*p!='\0') {
		if(razmak(*p)==1) {
			provjera=1;
			break;
		}
		p++;
	}
	if(provjera==0) {
		return s;
	}
	
	
	
	p=s;
	//brojanje slova u svakoj rijeci
	// i pamcenje pokazivaca na pocetak svake rijeci
	while(*p!='\0') {
		if(razmak(*p) && rijec==0) {
			rijec=1;
			//pp je niz pokazivaca na svaku rijec
			pp[i]=p;
			p1=p;
			//brojac[i]=0;
			while(razmak(*p1) && *p1!='\0') {
				brojac[i]++;
				p1++;
			}
			i++;
		}
		if(razmak(*p)==0 && rijec==1 ){
			rijec=0;
		}
		
		p++;
	}
	
	br_rijeci=i;
	min=brojac[0];
	max=brojac[0];
	max_index=pp[0];
	min_index=pp[0];
	//trazenje rijeci sa min i max brojem slova
	for(i=0;i<br_rijeci;i++) {
		if(brojac[i]>max) {
			max=brojac[i];
			max_index=pp[i];
		}
		if(brojac[i]<min) {
			min=brojac[i];
			min_index=pp[i];
		}
	}
	//ako je ista rijec, ne radi nista tj zavrsi funkciju
	if(min_index==max_index) {
		return s;
	}
	p=s;
	i=0;
	//kopira string u temp niz uz promjenu redoslijeda slovima
	// koje treba zamijeniti
	while(*p!='\0') {
		if(p==min_index) {
				p1=max_index;
				while(*p1!='\0' && razmak(*p1)) {
					temp[i]=*p1;
					p1++;
					i++;
				}
				while(*p!='\0' && razmak(*p)) {
					p++;
				}
		}
		else if(p==max_index) {
				p1=min_index;
				while (*p1!='\0' && razmak(*p1)) {
					temp[i]=*p1;
					p1++;
					i++;
				}
				while(*p!='\0' && razmak(*p)==1) {
					p++;
				}
		}
		else {
			temp[i]=*p;
			i++;
			p++;
		}
	}
	temp[i]='\0';
	n=i;
	p=s;
	//sada niz temp premjesta u string
	for(i=0;i<=n;i++) {
		*p=temp[i];
		p++;
	}
	return s;
	
}


int main() {
	char recenica[] = ".";
	printf ("'%s'\n", zamijeni_min_max(recenica));
	return 0;
}



