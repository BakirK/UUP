#include <stdio.h>

int main() {
	float VT, MT, cijena_VT, cijena_MT, tarifa_total, iznos_racuna, udio_MT, udio_VT;
	printf("unesi veliku tarifu ");
	scanf("%f",&VT);
	printf("unesi malu tarifu ");
	scanf("%f",&MT);
	printf("unesi cijenu velike tarife ");
	scanf("%f",&cijena_VT);
	printf("unesi cijenu male tarife ");
	scanf("%f",&cijena_MT);
	tarifa_total=VT+MT;
	iznos_racuna=VT*cijena_VT + MT * cijena_MT;
	udio_MT= MT/tarifa_total*100;
	udio_VT = VT/tarifa_total*100;
	printf("Ukupna potrosnja je: %.2f \n",tarifa_total);
	printf("Udio velike tarife u ukupnoj potrosnji je: %3.1f % \n",udio_VT);
	printf("Udio male tarife u ukupnoj potrosnji je: %3.1f % \n",udio_MT);
	printf("Iznos racuna: %.2f ",iznos_racuna);

	
	
	return 0;
}
