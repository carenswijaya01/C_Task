#include <stdio.h>
#include <stdlib.h>

int main() {
	int p,a;
	int x,y,z,q,w,e;

	do {
    	printf("Masukkan Tinggi Segitiga (Max 5) : ");
    	scanf("%d", &a);
    	printf("Pilih Varian Segitiga Mu !!!\n");
    	printf("1.Biasa\n");
    	printf("2.Istimewa\n");
    	printf("Masukan Pilihan Menu : ");
		scanf("%d", &p);

    	switch (p) {

			case 1:

        	if(a) {
    			for (x = 1; x <= a; x++)	{
    				for (y = x; y <= a-1; y++) {
    					for (z = 1; z <= a+1; z++) {
    						printf(" ");
						}
					}
    				for (q = 1; q <= x; q++) {
    					for(w = x; w <= a; w++) {
    						printf(" ");
						}
    					for (e = 1; e <= x; e++) {
    						printf("*");
						}
					} printf("\n");
				}
			} else printf("Maksimal 5!\n");
    			break;

    		case 2 :

    		if(a)
    			for (x = 1;x <= a; x++) {
    				for (y = x; y <= a-1; y++)	{
    					for (z = 1; z <= a+1; z++) {
    						printf(" ");
						}
					}
    				for (q = 1; q <= x; q++) {
    					for(w = x; w <= a; w++) {
    						printf(" ");
						}
    					for (e = 1; e <= x; e++) {
    						printf("%d",x);
						}
					} printf(" ");

    				for (y = x; y >= x-1; y--) {
    					for (z = 1; z >= x+1; z--) {
							printf("*");
						}
					}
    				for (q = 1; q <= x; q++) {
    					for(w = 1; w <= x; w++) {
    						printf("%d",x);
						}
    					for (e = x; e <= a; e++) {
    						printf(" ");
						}
					} printf("\n");
			} else printf("Maksimal 5!\n");
    			break;

    		case 3 :

    		printf("Program Selesai!\n");
			break;
    		default : printf("Yang Anda Input Salah\n");
		} break;
	} while(p!=3);
}
