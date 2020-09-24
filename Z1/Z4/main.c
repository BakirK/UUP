/*
4. Svako kome je poznata igra bilijar zna da se kugla kreće po stolu i odbija od rubove stola slijedeći jednostavno pravilo: ugao pod kojim će se kugla odbiti od rub jednak je uglu pod kojim je kugla prilazila rubu.

U našem zadatku zamislićemo da je dat neki bilijarski sto dimenzija  (n je širina, a m dužina stola). Neka su na stolu iscrtane linije tako da on izgleda kao koordinatni sistem. Na početku igrač postavlja kuglu na mjesto tako što izbroji x1 linija po širini i y1 linija po dužini. Zatim cilja bilijarskim štapom tako da pogodi ivicu stola na mjestu xP i yP. 

Pretpostavimo da će se kugla kretati beskonačno dugo i odbijati od rubove po pravilu koje smo spomenuli. Koliko puta će se kugla odbiti od ivice stola prije nego što se po prvi put vrati u početnu poziciju?

Ukoliko kugla pogodi ćošak stola, tada problem nema rješenja i program treba ispisati -1 M gdje je M broj odbijanja od ivice prije pogađanja ćoška, u suprotnom program treba ispisati 0 M gdje je M broj odbijanja prije povratka u početnu poziciju.

U prvom redu ulaza se nalaze četiri cijela broja: x1 y1 xP i yP koji predstavljaju redom koordinate početne pozicije kugle i koordinate tačke ivice stola koju igrač cilja da pogodi. U sljedećem redu se nalaze dva cijela broja n i m razdvojena razmakom, koji predstavljaju širinu i dužinu stola.

Primjer ulaza i izlaza:
Unesite brojeve x1 y1 xp i yp: 2 2 4 6
Unesite n i m: 6 6
0 6

U ovom primjeru kugla se nalazi na početnoj poziciji 2,2 (obojena narandžasta tačka na slici). Igrač cilja tačku na rubu stola 4,6 (narandžasta kružnica na slici). Ukupne dimenzije stola su 6x6.



Na izlazu trebamo dobiti 0 6. Broj 0 označava da postoji rješenje, a broj 6 da se kugla 6 puta odbila od rubove stola. Kugla se odbija od rubove redom u tačkama: (4,6), (6,2), (5,0), (2,6), (0,2), (1,0). Iako se kugla uvijek na početku nalazi na cjelobrojnim koordinatama i cilja se prema tački koja je također na cjelobrojnim koordinatama, to ne znači da će se sve buduće tačke odbijanja nalaziti na cjelobrojnim koordinatama.

Primjer 2:
Unesite brojeve x1 y1 xp i yp: 1 1 7 5
Unesite n i m: 7 7
0 10


*/


	#include <stdio.h>
	#include <math.h>

	int main() {
		//printf("Zadaća 1, Zadatak 4");
		int sirina,duzina; //sirina-n --> y=n, duzina-m --> x=m
		double x1, y1, x2, y2, k1, k_pocetno, n1, n_pocetno, x, y;
		int uslov,rez=1,brojac=0;
		printf("Unesite brojeve x1 y1 xp i yp: ");
		scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
		printf("Unesite n i m: ");
		scanf("%d %d",&sirina,&duzina);
		if(x1==x2 ^ y1==y2){
                //ako su x1 i x2 ili y1 i y2 jednaki
                //onda je k=infinity tj desit ce se beskonacna reflekcija
                //znaci da ce se lopta jednom odbiti i to ce biti rjesenje jer
                //svako iduce odbijanje je isto kao prethodno;
                //printf("XOR\n");
                brojac++;
                rez=0;
            	printf("%d %d",rez,brojac);
            	return 0;
		}

		k1=(y2-y1)/(x2-x1);
		if(k1==0){
			rez=-1;
			printf("%d %d",rez,brojac);
			return 0;
		}
		k_pocetno=k1;
		n1=y1-(k1*x1);
		n_pocetno=n1;
		//printf("k:%lf n:%lf",k1,n1);

		//uslovi
		//x2 i y2 su tacke ciljanja
		//x1 i y1 su pocetne tacke kogle
		//x i y su prave koje odredjuju granice stola
		if(x2>=x1 && y2>=y1){
			uslov=1;
			//prava sijece gore i desno y=sirina, x=duzina
		}
		else if(x2>=x1 && y2<=y1){
			uslov=2;
			//prava sijece dole i desno y=0, x=duzina
		}
		else if(x2<=x1 && y2>=y1){
			uslov=3;
			//prava sijece gore i lijevo y=sirina, x=0
		}
		else if(x2<=x1 && y2<=y1){
			uslov=4;
			//prava sijece dole i lijevo y=0, x=0
		}

		switch(uslov){
			case 1:{
				//printf("\ncase 1");
				x=duzina;
				y=k1*x+n1;
				//printf("\ny:%lf x:%lf",y,x);
				if(y>sirina || y<0){
					y=sirina;
					x=(y-n1)/k1;
				}
				k1=k1*(-1);
				y1=y;
				x1=x;
				//printf("\ny1:%lf x1:%lf\n",y1,x1);
				brojac++;
				break;
			}

			case 2:{
				//printf("\ncase 2");
				y=0;
				x=(y-n1)/k1;
			//	printf("\ny:%lf x:%lf",y,x);
				if(x<0 || x>duzina){
					x=duzina;
					y=k1*duzina+n1;
					//printf("\ny:%lf x:%lf",y,x);
				}

				k1=k1*(-1);
				y1=y;
				x1=x;
				brojac++;
				//printf("brojac case 2:%d\n",brojac);
				break;
			}

			case 3:{
				//printf("\ncase 3");
					y=n1;
					x=0;
				//printf("\ny:%lf x:%lf",y,x);
				if(y<0 || y>sirina){
					y=sirina;
					x=(y-n1)/k1;
					//printf("\ny:%lf x:%lf",y,x);
				}
				k1=k1*(-1);
				y1=y;
				x1=x;
				brojac++;
				//printf("brojac case 3:%d\n",brojac);
				break;
			}
			case 4:{
				//printf("\ncase 4");
				y=0;
				x=(y-n1)/k1;
				//printf("\ny:%lf x:%lf",y,x);
				if(x<0 || x>duzina){
					x=0;
					y=k1*duzina+n1;
					//printf("\ny:%lf x:%lf",y,x);
				}
				k1=k1*(-1);
				y1=y;
				x1=x;
				brojac++;
                //printf("brojac case 4:%d\n",brojac);
				break;
			}
		}
		do{
			//printf("\nx:%lf y:%lf k:%lf n:%lf\n brojac:%lf",x1,y1,k1,n1,brojac);
			if(((float)x1==0 || x1==duzina) && (y1==0 || (y1==sirina))){
				rez=-1;
				//printf("\nx:%lf y:%lf k:%lf n:%lf\n",x1,y1,k1,n1);
				//printf("\nema rjesenja");
				brojac-=1;
				printf("%d %d",rez,brojac);
				break;
				return 0;
			}
		n1=y1-(k1*x1);
			if(k1==k_pocetno && (float)n1==n_pocetno){
				//printf("\naso rez");
				rez=0;
				printf("%d %d",rez,brojac);
				return 0;
			}
				x=0;
				y=n1;
				if(y<0 || y>sirina || (y==y1 && x==x1)){
					x=duzina;
					y=k1*x+n1;
					if(y<0 || y>sirina || (y==y1 && x==x1)){
						y=0;
						x=(y-n1)/k1;
						if(x<0 || x> duzina || (y==y1 && x==x1)){
							y=sirina;
							x=(y-n1)/k1;
							if(x>=0 && x<= duzina && (y!=y1 && x!=x1)){
								x1=x;
								y1=y;
								k1=k1*(-1);
								brojac++;
							}
							else{
								printf("\nlet me get uhhh");
							}
						}
						else{
						x1=x;
						y1=y;
						k1=k1*(-1);
						brojac++;
						}
					}
					else{
					x1=x;
					y1=y;
					k1=k1*(-1);
					brojac++;
					}
				}
				else{
					x1=x;
					y1=y;
					k1=k1*(-1);
					brojac++;
				}
		}
		while(rez>0);
		return 0;
	}
