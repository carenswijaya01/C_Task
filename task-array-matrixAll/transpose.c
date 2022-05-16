#include <stdio.h>
#include <Stdlib.h>

void main() {
  	int baris, kolom, i, j, matriksA[10][10], matriksB[10][10], kali[10][10];
  	
  	printf("Masukkan Jumlah Baris Matriks : ");
  	scanf("%d", &baris);
  	
	printf("Masukkan Jumlah Kolom Matriks : ");
  	scanf("%d", &kolom);
  
  	printf("\nMasukkan Data Matriks A : \n");
  	for (i = 0; i < baris; i++) {
    	for (j = 0; j < kolom; j++) {
      		scanf("%d", &matriksA[i][j]);
    	}
  	}
  		
  	printf("\nMasukkan Data Matriks B : \n");
  	for (i = 0; i < baris; i++) {
    	for (j = 0; j < kolom; j++) {
      		scanf("%d", &matriksB[i][j]);
    	}
	}
  	
  	printf("\nHasil Penjumlahan Matriks : \n");
  	for (i = 0; i < baris; i++) {
	    for (j = 0; j < kolom; j++) {
	      	printf("%d \t", matriksA[i][j] + matriksB[i][j]);
	    }
    	printf("\n");
  	}
  	
  	printf("\nHasil Pengurangan Matriks : \n");
  	for (i = 0; i < baris; i++) {
	    for (j = 0; j < kolom; j++) {
	      	printf("%d \t", matriksA[i][j] - matriksB[i][j]);
	    }
    	printf("\n");
  	}
  	
  	printf("\nHasil Perkalian Matriks : \n");
  	if(baris==kolom){
  		for (i = 0; i < baris; i++) {
			for (j = 0; j < kolom; j++){
				kali[i][j]=(matriksA[i][0]*matriksB[0][j])+(matriksA[i][1]*matriksB[1][j]);
				printf("%d \t", kali[i][j]);	
			}
			printf("\n");
    	}
 	}
  	else{
  		printf("tidak bisa dikali\n");
  	}
    
    printf("\n Transpose A : \n");
    for(i = 0; i < kolom; i++) {
        for(j = 0; j < baris; j++) {
      printf("%d \t ", matriksA[j][i]);
    }
    printf("\n");
    }
    
    printf("\n Transpose B : \n");
    for(i = 0; i < kolom; i++) {
        for(j = 0; j < baris; j++) {
      printf("%d \t ", matriksB[j][i]);
    }
    printf("\n");
    }
}
