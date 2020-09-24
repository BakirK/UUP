#include <stdio.h>
#include <stdlib.h> /* Zbog funkcije exit() */
#include <string.h>

void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

int jeBroj(char s) {
	char p=s;
	if(p>=48 && p<=57) {
		return 1;
	}
	else return 0;
}

int samoglasnik(char p) {
    if (p=='A' || p=='a' ||p=='E' ||p=='e' ||p=='I' ||p=='i' || p=='O' ||p=='o' ||p=='U' ||p=='u'){
			return 1;
		}
		return 0;
}

int jeVelikoSlovo(char s) {
    if(s>=65 && s<=90) {
        return 1;
    }
    return 0;
}

int main() {
	//
	//UPOZORENJE: SPANSKI JEZIK AHEAD - DANGER
	//
    FILE *izlaz; //var tipa file
    FILE *ulaz;
    char  ime[20]="ispiti.txt";
    char naziv[20]="predmeti.txt";
    int prolaz=0, ukupno=0, suma_ocjena=0;
    int index,  ocjena;
    char trazeni_predmet[900];
    int predmet;
    char pct='%';
    float prosjek, prolaznost;
    float pct_predmeta;
    char ime_predmeta[900];
    int broj_predmet;
    int flag=0;
    int choice;
    int broj_indexa, slusao=0, polozenih=0, total=0;
    do {
    	printf("Unesite 1 za statistiku studenta, 2 za statistiku predmeta, 0 za izlaz: ");
    	scanf("%d", &choice);
    	if(choice==0) {
    		return 0;
    	}
    	if(choice==1) {
    		slusao=0; polozenih=0; total=0;
    		printf("\nUnesite broj indexa: ");
    		scanf("%d", &broj_indexa);
    		ulaz=fopen(ime, "r");
    		if(ulaz==NULL) {
    			printf("Pogreska kod otvaranja datoteke %s!!\n\n",ime);
    		}
    		while(fscanf(ulaz, "%d%d%d", &index, &predmet, &ocjena)==3) {
    			if(index!=broj_indexa) {
    				continue;
    			}
    			slusao++;
    			if (ocjena>=6) {
    				polozenih++;
    				total+=ocjena;
    			}
    		}
    		if(slusao!=0) {
    			prosjek=(float)total/polozenih;
    			pct_predmeta=(float)slusao/polozenih*100;
    			printf("Student je slusao %d predmeta, a polozio %d (%.0f%c).\n", slusao, polozenih, pct_predmeta, pct);
    			printf("Prosjecna ocjena polozenih predmeta je %.1f\n", prosjek);
    		}
    		else printf("Zalimo, ali ne postoje podaci o studentu sa brojem indexa %d!\n", broj_indexa);
		    fclose (ulaz);
    	}
    	if(choice==2) {
		    while(1) {
		    ulaz=fopen(naziv, "r");
		    if(ulaz == NULL) {
		        printf("Pogreska kod otvaranja datoteke %s!!\n\n",naziv);
		    	return 0;
		    }
		        flag=0;
		        printf("Unesite predmet: ");
		        unesi(trazeni_predmet, 900);
		        while(fscanf(ulaz,"%d %[^\n]s", &broj_predmet, ime_predmeta)==2) {
		            if(strcmp(ime_predmeta, trazeni_predmet)==0) {
		                flag=1;
		                break;
		            }
		        }
		        if (flag==0) {
		            printf("Nepostojeci predmet!\n");
		        }
		        else if(flag==1) {
		            break;
		        }
		        fclose(ulaz);
		    }
		    
		    izlaz = fopen(ime, "rw");
		    if (izlaz == NULL) {
		        printf ("Pogreska kod otvaranja datoteke %s!\n\n", ime);
		        return 0;
		    }
		    while((fscanf(izlaz,"%d%d%d",&index, &predmet, &ocjena))==3) {
		        if(predmet!=broj_predmet) {
		            continue;
		        }
		        ukupno++;
		        if(ocjena>=6) {
		            prolaz++;
		        }
		        suma_ocjena+=ocjena;
		    }
		    if(ukupno!=0){
		        prosjek=(float)suma_ocjena/ukupno;
		        printf("Prosjecna ocjena: %.2f\n", prosjek);
		        prolaznost=(float)((float)prolaz/ukupno)*100;
		        printf("Prolaznost: %.0f%c\n", prolaznost,pct);
		    }
		    else printf("Zalimo, ali ne postoje podaci o predmetu %s!\n", trazeni_predmet);
		    fclose (izlaz);
    	}
    }
    while(choice!=0);
    
    
    
    
    return 0;
}
