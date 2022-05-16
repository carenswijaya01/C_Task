#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char file_name[] = "list_data.txt";
char delim[] = ";";
char data_barang[200][3][200];
int jml_data_barang = 0;
int i,k=0;
int namapesan[100];
int jmlpesan[100];

char *substring(char *string, int position, int length) {
   	char *pointer;
   	int c;

   	pointer = malloc(length+1);

   	if (pointer == NULL) {
      	printf("Unable to allocate memory.\n");
		exit(EXIT_FAILURE);
   	}

   	for (c = 0 ; c < length ; c++) {
      	*(pointer+c) = *(string+position-1);
      	string++;
   	}

   	*(pointer+c) = '\0';

   	return pointer;
}

void getData() {
	FILE *fp = fopen(file_name, "r");
    char line[200];

	memset(data_barang,0,sizeof(data_barang));
    jml_data_barang = 0;

	if (fp == NULL) {
		fp=fopen(file_name, "w");
		fclose(fp);
	} else {
		int i = 0;
		while (fgets(line, sizeof(line), fp) != NULL) {
			char *token = strtok(line, delim);

    		int j = 0;
			while (token != NULL) {
				strcpy(data_barang[i][j], token);
				token = strtok(NULL, delim);
				j++;
			}

			i++;
			jml_data_barang++;
		}
	}
	fclose(fp);
}

void viewData() {
    getData();
    system("@cls||clear");
    printf("============================================\n");
   	printf("Menu Lihat Data Barang\n");
   	printf("============================================\n");
    if (jml_data_barang > 0) {
        printf("Nama Barang\tHarga\tStok\n");
   		printf("============================================\n");
        int i;
		for (i = 0; i < jml_data_barang; i++) {
			char nama_brg[100];
			strcpy(nama_brg, data_barang[i][0]);
			if (strlen(nama_brg) > 15) {
		   		strcpy(nama_brg, substring(nama_brg, 1, 15));
			} else if (strlen(nama_brg) < 8) {
		   		snprintf(nama_brg, sizeof nama_brg, "%s%s", data_barang[i][0], "\t");
			}
            int harga_brg = atoi(data_barang[i][1]);
            int stok_brg = atoi(data_barang[i][2]);

            printf("%s\t%d\t%d \n",nama_brg,harga_brg,stok_brg);
        }
    } else {
        printf("Tidak ada data barang!\n");
    }
    printf("============================================\n");
    system("pause");
    menu_utama();
}

bool addToFile(char inputan[]) {
	FILE *fp = fopen(file_name,"a+");
	if (fp == NULL) {
		return false;
	} else {
		fputs(inputan, fp);
	}
	fclose(fp);
	return true;
}

void tambahData() {
	scanf("%c");
	system("@cls||clear");
	printf("============================================\n");
   	printf("Menu Tambah Data Barang\n");
   	printf("============================================\n");

   	char nama[100], harga[50], stok[50], hasil[200];

	printf("Masukkan Nama Barang : ");
   	gets(nama);
   	if (strlen(nama) > 15) {
   		strcpy(nama, substring(nama, 1, 15));
	}

   	printf("Masukkan Harga Barang : ");
   	gets(harga);
   	int hargaa = atoi(harga);
   	if (hargaa < 1000) hargaa = 1000;
   	else if (hargaa > 9999999) hargaa = 9999999;

   	printf("Masukkan Stok Barang : ");
   	gets(stok);
   	int stokk = atoi(stok);
   	if (stokk < 1) stokk = 1;
   	else if (stokk > 10000) stokk = 10000;

   	printf("============================================\n");
	snprintf(hasil, sizeof hasil, "%s;%d;%d;\n", nama, hargaa, stokk);
	if (addToFile(hasil)) {
		printf("Sukses tambah data barang!\n");
	} else {
		printf("Gagal tambah data barang!\n");
	}
	printf("============================================\n");
	system("pause");
    menu_utama();
}

void hapusData() {
	scanf("%c");
	system("@cls||clear");
	printf("============================================\n");
   	printf("Menu Hapus Data Barang\n");
   	printf("============================================\n");
   	char nama[100];
   	printf("Masukkan Nama Barang : ");
   	gets(nama);
	if (jml_data_barang > 0) {
		FILE *fp = fopen(file_name, "r");
	    char line[200];

		if (fp == NULL) {
			printf("Gagal membuka file %s", file_name);
			exit(EXIT_FAILURE);
		} else {
			bool ada = false, ada2 = false;
			int i = 0, j = 0, k = 0;
			char tampung[100][200];
			while (fgets(line, sizeof(line), fp) != NULL) {
				char *token = strtok(line, delim);
	    		j = 0;
				ada = false;
				while (token != NULL) {
					if (j == 0) {
						if (strcmp(data_barang[i][j],nama) == 0) {
							ada = true;
							ada2 = true; //memastikan jika ketemu
						}
					}
					token = strtok(NULL, delim);
					j++;
				}

				if (!ada) {
					//data barang yg bukan dihapus akan ditampung di array tampung
					snprintf(tampung[k], sizeof tampung[k], "%s;%s;%s;\n", data_barang[i][0], data_barang[i][1], data_barang[i][2]);
					k++;
				}

				i++;
			}

			fclose(fp);

			printf("============================================\n");
			if (ada2) {
				fp = fopen(file_name, "w"); //reset file jadi kosong
				fclose(fp);
				if (k > 0) {
					for (i = 0; i < k; i++) {
						addToFile(tampung[i]);
					}
				}
				printf("Sukses hapus (%s) dari data barang!\n",nama);
			} else {
				printf("Nama barang (%s) tidak ditemukan!\n",nama);
			}
		}
   	} else {
   		printf("============================================\n");
   		printf("Tidak ada data barang!\n");
    }

    printf("============================================\n");
    system("pause");
    menu_utama();
}

void menu(int pil) {
	if (pil == 1) viewData();
	else if (pil == 2) tambahData();
	else if (pil == 3) hapusData();
	else if (pil == 4) transaksi();
}

void transaksi(){
	int no,check=0,ytcek;
	int jmlh,total;
	char yt[1];
	getData();
    system("@cls||clear");
    printf("============================================\n");
   	printf("\tMENU RESTORAN BANGCAD\n");
   	printf("============================================\n");
    if (jml_data_barang > 0) {
        printf("No\tNama Barang\tHarga\tStok\n");
   		printf("============================================\n");
		for (i = 0; i < jml_data_barang; i++) {

			char nama_brg[100];
			strcpy(nama_brg, data_barang[i][0]);
			if (strlen(nama_brg) > 15) {
		   		strcpy(nama_brg, substring(nama_brg, 1, 15));
			} else if (strlen(nama_brg) < 8) {
		   		snprintf(nama_brg, sizeof nama_brg, "%s%s", data_barang[i][0], "\t");
			}
            int harga_brg = atoi(data_barang[i][1]);
            int stok_brg = atoi(data_barang[i][2]);

			printf("%i. \t",(i+1));
            printf("%s\t%d\t%d \n",nama_brg,harga_brg,stok_brg);
        }
    } else {
        printf("Tidak ada data barang!\n");
    }
    printf("\n\n99.\tMenu Utama\n");
    printf("============================================\n\n");

    int stok[jml_data_barang];
	for(i=0;i<jml_data_barang;i++){
    	stok[i] = atoi(data_barang[i][2]);
	}

	int harga[jml_data_barang];
	for(i=0;i<jml_data_barang;i++){
    	harga[i] = atoi(data_barang[i][1]);
	}

	do{
    	printf("\nNo. Pesanan    : ");scanf("%i",&no);

    	if(no == 99){
    		system("cls");
    		menu_utama();
		}

    	int temp;
        if(no>0 & no<=jml_data_barang){
            printf("Jumlah Pesanan : ");scanf("%i",&jmlh);
            if(jmlh<=stok[no-1]){
            	stok[no-1]=stok[no-1]-jmlh;
            	temp=jmlh*harga[no-1];
            	total=temp+total;
				namapesan[k]=no-1;
				jmlpesan[k]=jmlh;
			}else{
				k--;
				printf("Stok yang dipesan tidak cukup!\n");
			}

            do{
            	printf("Apakah anda masih ingin memesan? (Y/T)");scanf("%s",&yt);
    			if(strcmp(yt,"Y")==0||strcmp(yt,"y")==0){
    				k++;
    				check = 0;ytcek = 1;
    			}else if(strcmp(yt,"T")==0||strcmp(yt,"t")==0){
    				check = 1;
        			Struk(total);
    			}else{
    				ytcek = 0;
        			printf("Input Salah\n\n");
    			}
			}while(ytcek == 0);

    	}else{
        	printf("No. Pesanan tidak terdaftar!\n");
			check = 0;
    	}
	}while(check==0);
}

void Struk(int total){
	int bali, bayar, check, pilihan;
	system("cls");
	printf("Total Pesanan\n");
    printf("---------------\n");
    for(i=0;i<=k;i++){
    	printf("%i. %s (%i)\n",(i+1),data_barang[namapesan[i]],jmlpesan[i]);
	}
    printf("\nTotal Harga : Rp %i\n",total);
    do{
    	printf("\nBayar       : Rp ");scanf("%i",&bayar);
    	if(bayar>=total){
    		check = 1;
        	bali=bayar-total;
        	printf("Kembalian   : Rp %i\n\n",bali);
        	printf("1. Cetak Struk\n");
        	printf("2. Ke Menu Utama\n");
        	printf("Pilihan: ");scanf("%i",&pilihan);
        	switch(pilihan){
        		case 1:
					CetakStruk(total,bayar,bali);
					printf("\nStruk Anda Telah Dicetak!");
					getch();
					break;
        		case 2:break;
        		default:
        			printf("Input Salah");
        			getch();
        			system("cls");
        			Struk(total);
        			break;
			}
        	system("cls");
        	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
        	printf("\t\t\tTerima kasih, pesanan anda segera di proses.\n");
        	getch();
        	system("cls");

        	for(i=0;i<=k;i++){
        		namapesan[i]=0;
        		jmlpesan[i]=0;
        		k=0;
			}

        	menu_utama();
    	}else{
    		check = 0;
        	printf("Uang Anda Kurang!");
        	getch();
    	}
	}while(check == 0);
}

void CetakStruk(int total,int bayar,int bali){
	FILE *fp;

	fp=fopen("Struk.txt", "w");
	if(fp == NULL)
    	exit(-1);

	fprintf(fp,"Total Pesanan\n");
    fprintf(fp,"---------------\n");
    for(i=0;i<=k;i++){
    	fprintf(fp,"%i. %s uwu (%i)\n",(i+1),data_barang[namapesan[i]][0],jmlpesan[i]);
	}
	fprintf(fp,"\nTotal Harga : Rp. %i\n",total);
	fprintf(fp,  "Bayar       : Rp. %i\n",bayar);
	fprintf(fp,  "Kembalian   : Rp. %i\n\n",bali);
	fprintf(fp,"=====Terima Kasih Telah Berbelanja=====");
	fclose(fp);
}

void menu_utama() {
	int pilihan = 0;
	while (pilihan == 0) {
		system("@cls||clear");
		printf("============================================\n");
		printf("SELAMAT DATANG DI RESTORAN BANGCAD\n");
		printf("============================================\n");
		printf("1. Lihat Data Barang\n");
		printf("2. Tambah Data Barang\n");
		printf("3. Hapus Data Barang\n");
		printf("4. Transaksi\n");
		printf("5. Logout\n");
		printf("6. Exit\n");
		printf("Pilih Menu : ");
		scanf("%d",&pilihan);
		if (pilihan <= 0 || pilihan > 6) {
			pilihan = 0;
			system("@cls||clear");
			printf("Pilihan Menu Salah!");
			system("pause");
		}
	}

	if (pilihan == 5) login();
	else if (pilihan == 6) exit(EXIT_SUCCESS);
	else menu(pilihan);
}

void login() {
	system("@cls||clear");
	char username[20], password[20];
	printf("===LOGIN===\n");
	printf("Username : ");scanf("%s",&username);
	printf("Password : ");scanf("%s",&password);

	if (strcmp(username,"resto") == 0 && strcmp(password,"resto") == 0) {
		printf("Selamat Datang %s!\n",username);
		getch();
		menu_utama();
	} else {
		printf("Username/Password Salah!\n");
		getch();
		login();
	}
}

void main() {
	getData();
	login();
}
