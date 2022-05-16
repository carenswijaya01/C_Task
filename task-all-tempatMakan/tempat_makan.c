#include <stdio.h>
#include <stdlib.h>

int h[]={0,12000,10000,10000,15000,10000,10500,15000,10000,5000,3000};
int stok[] = {0,9,9,9,9,9,9,9,9,9,9};
int i,k=0;
char lis[11][20]={"","Nasi Goreng","Nasi Kuning","Nasi Campur","Bakso","Binte","Tinutuan","Gado-gado","Mie Ayam Cakalang","Tinorangsa","RW Ayam"};
int namapesan[100];
int jmlpesan[100];

void login() {
	system("COLOR 17");
	system("@cls||clear");
	char username[20], password[20];
	printf("===LOGIN===\n");
	printf("Username : ");
	gets(username);
	printf("Password : ");
	gets(password);
	
	if (strcmp(username,"resto") == 0 && strcmp(password,"resto") == 0) {
		printf("Selamat Datang %s!\n",username);
		scanf("%c");
		menu_utama();
	} else {
		printf("Username/Password Salah!\n");
		scanf("%c");
		login();
	}
}

void menu_utama() {
	system("COLOR F9");
	int pilihan = 0;
	while (pilihan == 0) {
		system("@cls||clear");
		printf("===MENU===\n");
		printf("1. List Menu\n");
		printf("2. Pesan\n");
		printf("3. Logout\n");
		printf("4. Exit\n");
		printf("Pilih Menu : ");
		scanf("%d",&pilihan);
		scanf("%c");
		if (pilihan <= 0 || pilihan > 4) {
			pilihan = 0;
			system("@cls||clear");
			printf("Pilihan Menu Salah!");
			scanf("%c");
		}
	}
	
	if (pilihan == 3) login();
	else if (pilihan == 4) exit(EXIT_SUCCESS);
	else menu(pilihan);
}

void menu(int a) {
	system("@cls||clear");
	if (a == 1) {
		List();
	} else if (a == 2) {
		Pesan();
	} else if (a == 3) {
		printf("INI MENU 3\n");
	}
	
	scanf("%c");
	menu_utama();
}

void List(){
	system("COLOR DF");
	printf("O---------------------------------------------------O\n");
    printf("|                   RESTORAN BANGCAD                |\n");
    printf("|---------------------------------------------------|\n");
    printf("| No. | Menu Makanan        | Harga          | Stok |\n");
    printf("|-----|---------------------|----------------|------|\n");    
    printf("| 1.  | Nasi Goreng         | Rp 12.000,-    | %i    |\n",stok[1]);
    printf("| 2.  | Nasi Kuning         | Rp 10.000,-    | %i    |\n",stok[2]);
    printf("| 3.  | Nasi Campur         | Rp 10.000,-    | %i    |\n",stok[3]);
    printf("| 4.  | Bakso               | Rp 15.000,-    | %i    |\n",stok[4]);
    printf("| 5.  | Binte               | Rp 10.000,-    | %i    |\n",stok[5]);
    printf("| 6.  | Tinutuan            | Rp 10.500,-    | %i    |\n",stok[6]);
    printf("| 7.  | Gado-gado           | Rp 15.000,-    | %i    |\n",stok[7]);
    printf("| 8.  | Mie Ayam Cakalang   | Rp 10.000,-    | %i    |\n",stok[8]);
    printf("| 9.  | Tinorangsa          | Rp  5.000,-    | %i    |\n",stok[9]);
    printf("| 10. | RW Ayam             | Rp  3.000,-    | %i    |\n",stok[10]);
    printf("|     |                     |                |      |\n");
    printf("| 99. | Menu Utama          |                |      |\n");
	printf("O---------------------------------------------------O\n\n");
}

void Pesan(){
	int no,check=0,ytcek;
	int jmlh,total;
	char yt[1];
	List();
    printf("Silahkan Masukkan Pesanan Anda!\n");
    printf("-------------------------------\n");
    
    do{
    	printf("\nNo. Pesanan: ");scanf("%i",&no);
    	
    	if(no == 99){
    		system("cls");
    		menu_utama();
		}
    	
    	int temp;
        if(no>0 & no<=10){
            printf("Jumlah Pesanan: ");scanf("%i",&jmlh);
            if(jmlh<=stok[no]){
            	stok[no]=stok[no]-jmlh;//ngubah stok
            	temp=jmlh*h[no];
            	total=temp+total;
				namapesan[k]=no;
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
        	printf("No. Pesanan tidak terdaftar\n");
			check = 0;
			getch();
    	}	
	}while(check==0);
}

void Struk(int total){
	int bali, bayar, check, pilihan;
	system("cls");
	printf("Total Pesanan\n");
    printf("---------------\n");
    for(i=0;i<=k;i++){
    	printf("%i. %s (%i)\n",(i+1),lis[namapesan[i]],jmlpesan[i]);
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
        	system("COLOR F0");
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
    	fprintf(fp,"%i. %s (%i)\n",(i+1),lis[namapesan[i]],jmlpesan[i]);
	}
	fprintf(fp,"\nTotal Harga : Rp. %i\n",total);
	fprintf(fp,  "Bayar       : Rp. %i\n",bayar);
	fprintf(fp,  "Kembalian   : Rp. %i\n\n",bali);
	fprintf(fp,"=====Terima Kasih Telah Berbelanja=====");
	fclose(fp);
}

void main(){
	login();
}
