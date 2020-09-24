#include <stdio.h>
#include <stdlib.h>

int matrica_sadrzana(int a[][100], int va, int sa, int b[][100], int vb, int sb) {
	int i, j, k, l, sadrzana;
     for (i = 0; i < va - vb + 1; i++) {
         for (j = 0; j < sa - sb + 1; j++) {
              sadrzana = 1; //pretpostvka da matrica jeste sadrzana
              for (k = 0; k < vb; k++) {
                  for (l = 0; l < sb; l++) {
                      if (a[i + k][j + l] != b[k][l]){
                          sadrzana = 0;
                          break;
                      }
                  }
                  if (sadrzana==0) { 
                      break;
                  }
              }
              if (sadrzana==1) { 
                  return 1;
                  
              }
          }
      }          
      return 0;
}

int main() {
    //int A[100][100] = {{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}};
    //int B[100][100] = {{2,3}, {7,8}, {12,13}};
	//printf("%d",matrica_sadrzana(&A[0][0],4,5,&B[0][0],3,2));
	return 0;
}
