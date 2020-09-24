#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	srand(0);
	//printf("Zadaća 1, Zadatak 3");
	double cash=100000,cash_pocetno=100000;
	int input,i,j,p,k=1,input_buy;
	double cijena_nafta=70, cijena_zlato=1200, cijena_srebro=15,kupljeno_zlato=0, kupljeno_srebro=0, kupljeno_nafta=0;
	double pn=0,pz=0,ps=0;
	double amount_buy,total;
	do{
		for(i=1;i<=5;i++){
			for(j=1;j<=3;j++){
				switch(j){
					case 3:
						p=rand()%(2);
						if(p==1){
							pn+=0.1;
							}
						else if(p==0){
							pn+=-0.1;
							}
						cijena_nafta=cijena_nafta+(pn*cijena_nafta/100);
						break;
					case 2:
					p=rand()%(2);
						if(p==1){
							ps+=0.1;
							}
						else if(p==0){
							ps+=-0.1;
							}
						cijena_srebro=cijena_srebro+(ps*cijena_srebro/100);
						break;
					case 1:
					p=rand()%(2);
						if(p==1){
							pz+=0.1;
							}
						else if(p==0){
							pz+=-0.1;
							}
						cijena_zlato=cijena_zlato+(pz*cijena_zlato/100);
						break;
				}
			}
			
			switch(i){
			case 1:
			printf("\nPON: Zlato $%.2lf (%+.1lf) Srebro $%.2lf (%+.1lf) Nafta $%.2lf (%+.1lf)", cijena_zlato, pz, cijena_srebro, ps, cijena_nafta, pn);
			break;
			case 2:
			printf("\nUTO: Zlato $%.2lf (%+.1lf) Srebro $%.2lf (%+.1lf) Nafta $%.2lf (%+.1lf)", cijena_zlato, pz, cijena_srebro, ps, cijena_nafta, pn);
			break;
			case 3:
			printf("\nSRI: Zlato $%.2lf (%+.1lf) Srebro $%.2lf (%+.1lf) Nafta $%.2lf (%+.1lf)", cijena_zlato, pz, cijena_srebro, ps, cijena_nafta, pn);
			break;
			case 4:
			printf("\nCET: Zlato $%.2lf (%+.1lf) Srebro $%.2lf (%+.1lf) Nafta $%.2lf (%+.1lf)", cijena_zlato, pz, cijena_srebro, ps, cijena_nafta, pn);
			break;
			case 5:
			printf("\nPET: Zlato $%.2lf (%+.1lf) Srebro $%.2lf (%+.1lf) Nafta $%.2lf (%+.1lf)", cijena_zlato, pz, cijena_srebro, ps, cijena_nafta, pn);
			break;
			}
		}
			printf("\n");
			do{
				k=1;
				do{
				printf("\n\nImate:");
				total=kupljeno_zlato*cijena_zlato + kupljeno_srebro*cijena_srebro + kupljeno_nafta*cijena_nafta + cash;
				printf("\nZlata: %g ($%.2lf) Srebra: %g ($%.2lf) Nafte: %g ($%.2lf) Novca: $%.2lf",
				kupljeno_zlato, kupljeno_zlato*cijena_zlato, kupljeno_srebro, kupljeno_srebro*cijena_srebro, kupljeno_nafta, kupljeno_nafta*cijena_nafta, cash);
				printf("\nUKUPNO: $%.2lf ($%+.2lf)",total,total-cash_pocetno);
					
						printf("\n");
					printf("\nUnesite izbor (1 - Kupi, 2 - Prodaj, 3 - Sljedeca sedmica, 0 - Kraj igre): ");
					scanf("%d",&input);
					if(input!=0 && input!=1 && input!=2 && input!=3){
						printf("Pogresan izbor!");
					}
				}
				while(input!=0 && input!=1 && input!=2 && input!=3);
				
				switch(input){
					//kupi
						case 1:
						{
							printf("Sta kupujete (1 - Zlato, 2 - Srebro, 3 - Naftu): ");
							scanf("%d",&input_buy);
							printf("Koliko? ");
							scanf("%lf",&amount_buy);
							//kupovina
							switch(input_buy){
								case 1: 
								{
									if(amount_buy*cijena_zlato<=cash){
										kupljeno_zlato+=amount_buy;
										cash=cash-(amount_buy*cijena_zlato);
									}
									else{
										printf("Nemate toliko novca!\n");
									}
									break;
								}
									case 2:
									{
										if(amount_buy*cijena_srebro<=cash){
											kupljeno_srebro+=amount_buy;
											cash=cash-(amount_buy*cijena_srebro);
										}
										else{
											printf("Nemate toliko novca!\n");
										}
										break;
									}
									case 3:
									{
										if(amount_buy*cijena_nafta<=cash){
											kupljeno_nafta+=amount_buy;
											cash=cash-(amount_buy*cijena_nafta);
										}
										else{
											printf("Nemate toliko novca!\n");
										}
										break;
									}
									break;
								}
						break;	
						}
					
					//prodaj
					case 2:
				{
						printf("Sta prodajete (1 - Zlato, 2 - Srebro, 3 - Naftu): ");
						scanf("%d",&input_buy);
						printf("Koliko? ");
						scanf("%lf",&amount_buy);
						switch(input_buy){
							case 1: 
							{
								if(amount_buy<=kupljeno_zlato){
									kupljeno_zlato-=amount_buy;
									cash+=amount_buy*cijena_zlato;
								}
								else{
									printf("Nemate toliko zlata!\n");
								}
								break;
						}
							case 2:
							{
								if(amount_buy<=kupljeno_srebro){
									kupljeno_srebro-=amount_buy;
									cash+=amount_buy*cijena_srebro;
								}
								else{
									printf("Nemate toliko srebra!\n");
								}
								break;
							}
							case 3:
							{
								if(amount_buy<=kupljeno_nafta){
									kupljeno_nafta-=amount_buy;
									cash+=amount_buy*cijena_nafta;
								}
								else{
									printf("Nemate toliko nafte!\n");
								}
								break;
							}
					}
					break;
				}
						case 3:
						{
							input=0;
							k=0;
							break;
						}
						case 0:	
						{
							return 0;
							input=0;
							k=0;
							break;
						}
				}
						
				
			}
			while(k==1);
	}
	
		while(input<=0);
	return 0;
}
