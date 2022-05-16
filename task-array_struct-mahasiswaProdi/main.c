#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pilihan;
int cek = 0, cek2 = 0, datmhs = 10, datpro = 4, urut1, urut2, cek3[4];
struct mahasiswa{
    char nama[30], nim[10], progdi[20];
}mhs[12];

struct progdix{
    char idprog[3], namprog[20];
}pro[4];

void pilih1() {

	if(cek == 0)
    {
		printf ("\n	Yok, input dulu");
	}
	else {
        int i;
        for(i = 0; i < urut1; i++){
            printf("\n	Nama Mahasiswa = %s \n", mhs[i].nama);
            printf("	NIM Mahasiswa = %s \n", mhs[i].nim);
            printf("	Progdi Mahasiswa = %s \n", mhs[i].progdi);
        }
	}
	getch();
	system("cls");
}

void pilih2() {
    int inp,pil=0,cek4;
	if (cek2 == 0)
    {
		printf("\n	prodi belum ada, buat dulu yok");
	}else{
        if(datmhs == 0){
            printf("	Data yang diinput sudah mencapai batas maksimal.");
        }else{
            printf("	Mau input berapa data? (1-%i) : ", datmhs);scanf("%i", &inp); //ngeinput
            if(inp == 0){
                printf("	Data harus lebih dari 0");
            }else if(inp > datmhs){
                printf("	Data yang diinput tidak lebih dari %i", datmhs);
            }else{
                datmhs -= inp; //pengurangan maksimal
                int i;
                for(i = 0; i < inp; i++){
                    char *temp[20];
                    printf("	Data ke %i\n", i+1); //estetik
                    printf("	Masukkan Nama = ");fflush(stdin);gets(mhs[urut1].nama);
                    printf("	Masukkan NIM = ");fflush(stdin);gets(mhs[urut1].nim);
                    //printf("	Masukkan Progdi = ");fflush(stdin);gets(mhs[urut1].progdi);
                    do{
                       printf("	Pilihan Program Studi = \n");
                       int i;
                        for(i = 0; i < urut2; i++){
                            printf("		%i. %s (%s) \n", i+1, pro[i].namprog, pro[i].idprog);
                        }
                        printf("	Pilihan Anda : ");scanf("%i", &pil);
                        cek4 = 0;
                        for(i = 0; i < urut2; i++){
                            if(pil == cek3[i]){
                                cek4 = 1;
                                break;
                            }
                        }
                        if(cek4 !=1){
                            printf("	Pilihan Anda Tidak Terdaftar\n\n");
                        }else{
                            *temp = pro[pil-1].namprog;
                            memcpy(mhs[urut1].progdi, *temp, sizeof pro);
                            break;
                        }
                    }while(cek4!=1);
                    urut1++;
                    int i;
                    for(i = 0; i<sizeof(*temp); i++){
                        temp[i]= '\0';
                    }
                }
                printf("	Data Anda telah tersimpan.");
                cek = 1;
            }
        }
	}
    getch();
    system("cls");
}

void pilih3() {
    int i;
	if (cek2 == 0)
    {
		printf("\n	prodi belum ada, buat dulu yok");
	}
	else {
        int i;
        for(i = 0; i < urut2; i++){
            printf("\n	Id Progdi = %s \n",pro[i].idprog);
            printf("	Nama Progdi = %s \n", pro[i].namprog);
        }
	}
	getch();
	system("cls");
}

void pilih4() {
    int inp,i;
    if(datpro == 0){
        printf("	Data yang diinput sudah mencapai batas maksimal.");
    }else{
        printf("	Mau input berapa data? (1-%i) : ", datpro);scanf("%i", &inp);
        if(inp == 0){
            printf("	Data harus lebih dari 0");
        }else if(inp > datpro){
            printf("	Data yang diinput tidak lebih dari %i", datpro);
        }else{
            datpro -= inp;
            int i;
            for(int i = 0; i < inp; i++){
                printf( "\n	Masukkan ID Progdi = "); fflush(stdin);gets(pro[urut2].idprog);
                printf( "	Masukkan Nama Progdi = "); fflush(stdin);gets(pro[urut2].namprog);
                urut2++;
                cek3[urut2-1] = urut2;
            }
            printf("	Data Anda telah tersimpan.");
            cek2 = 1;
        }
    }
    getch();
    system("cls");
}



void mhsw(){
	do{system("cls");
        printf("============================================================\n");
        printf("		Data Mahasiswa\n");
        printf("============================================================\n");
        printf("\n	Menu :\n\n");
        printf("	1. Lihat Data Mahasiswa\n");
        printf("	2. Input Data Mahasiswa\n");
        printf("	3. Back\n");
        printf("\n	Pilihan : ");scanf("%i",&pilihan);
        switch(pilihan)
        {
            case 1:pilih1();break;
            case 2:pilih2();break;
            case 3:main();break;
            default :
                printf("	Pilihan Tidak Ada!\n");
                getch();
                system("cls");
        }
	}while(pilihan!=3);
}

void prdg(){
	do{system("cls");
        printf("============================================================\n");
        printf("		Data Progdi\n");
        printf("============================================================\n");
        printf("\n	Menu :\n\n");
        printf("	1. Lihat Data Progdi\n");
        printf("	2. Input Data Progdi\n");
        printf("	3. Back\n");
        printf("\n	Pilihan : ");scanf("%i",&pilihan);
        switch(pilihan)
        {
            case 1:pilih3();break;
            case 2:pilih4();break;
            case 3:main();break;
            default :
                printf("	Pilihan Tidak Ada!\n");
                getch();
                system("cls");
        }
	}while(pilihan!=3);
}

void main(){
	do{ system("cls");
		printf("============================================================\n");
	    printf("	Selamat datang di Pemrograman Data Mahasiswa\n");
	    printf("============================================================\n");
	    printf("\n	Menu :\n\n");
	    printf("	1. Mahasiswa\n");
	    printf("	2. Progdi\n");
	    printf("	3. Exit\n");
	    printf("\n	Pilihan : ");scanf("%i",&pilihan);
	    switch(pilihan)
	    {
	        case 1:mhsw();break;
	        case 2:prdg();break;
	        case 3 : break;
	        default :
                printf("	Pilihan Tidak Ada!\n");
                getch();
                system("cls");
                main();
	    }
    }while(pilihan!=3);
}
