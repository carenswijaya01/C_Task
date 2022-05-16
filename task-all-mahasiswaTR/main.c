#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //ngide buat boolean
#include <string.h> //buat fungsi2 string kayak strcat, snprintf, dll
#include <windows.h> //buat koordinat
#include <time.h> //buat delay

//TEMA - MAHASISWA
//CARENS KURNIAWAN WIJAYA
//672019084

char file_name[] = "list_data.txt";
char delim[] = ";";
int urutanDB = 1;

//struct khusus untuk mahasiswa
struct mahasiswa{
    char nama[30],
    alamat[30],
    fakultas[30],
    progdi[30],
    nim[10];

    int tglLahir, bulanLahir, tahunLahir;

    struct mahasiswa *next;
}*curr, *head, *tail;

//struct khusus untuk log
struct logAdmin{
    char log [200];

    struct logAdmin *next;
}*currLog, *headLog, *tailLog;

//buat ngosongin notepad
void kosongNP(){
    FILE *fp = fopen(file_name, "w");
    fclose(fp);
}

//buat nambah ke notepad
void tambahNP(char dataDB[]) {
	FILE *fp = fopen(file_name,"a+");
    fputs(dataDB, fp);
	fclose(fp);
}

//buat baca notepad
void loadData() {
	FILE *fp = fopen(file_name, "r");
    char line[200];

    //kalo filenya belum ada diwrite dulu
	if (fp == NULL) {
		fp=fopen(file_name, "w");
		fclose(fp);
	} else {
	    int i = 1;
	    //baca per baris, trus dipecah per token, trus per token masukin ke struct
		while (fgets(line, sizeof(line), fp) != NULL) {
            curr = (struct mahasiswa*)malloc(sizeof(struct mahasiswa));
			char *token = {strtok(line, delim)};

    		int j = 0;
			while (token != NULL) {
                if(j == 0){
                    strcpy(curr->nama, token);
                }else if(j == 1){
                    strcpy(curr->nim, token);
                }
                else if(j == 2){
                    strcpy(curr->fakultas, token);
                }
                else if(j == 3){
                    strcpy(curr->progdi, token);
                }
                else if(j == 4){
                    strcpy(curr->alamat, token);
                }
                else if(j == 5){
                    sscanf(token, "%d", &curr->tglLahir);
                }
                else if(j == 6){
                    sscanf(token, "%d", &curr->bulanLahir);
                }
                else if(j == 7){
                    sscanf(token, "%d", &curr->tahunLahir);
                }
				token = strtok(NULL, delim);
				j++;

			}
            if(head == NULL){
                head = tail = curr;
            }
            else{
                tail->next = curr;
                tail = curr;
            }
            tail->next = NULL;
            i++;
        }
        //nyari urutanDB
        urutanDB = i;
	}
	fclose(fp);
}

//buat hapus data di notepad
void hapusNP(char *nim){
    //ngosongin notepad dulu
    kosongNP();

    //nampung data yang bukan mau dihapus
    int i = 0;
    char hasil[urutanDB-1][400];
    struct mahasiswa *temp = head;
    while(temp != NULL){
        if(strcmp(temp->nim, nim) != 0){
            snprintf(hasil[i], sizeof hasil[i], "%s;%s;%s;%s;%s;%d;%d;%d;\n", temp->nama, temp->nim, temp->fakultas, temp->progdi, temp->alamat, temp->tglLahir, temp->bulanLahir, temp->tahunLahir);
            i++;
        }
        temp = temp->next;
    }

    //masukin data yang ditampung ke file lagi
    for(i = 0; i < urutanDB-2; i++){
        tambahNP(hasil[i]);
    }
}

//buat edit data di notepad
void editNP(int menuUbah, char data[], int nilai, int index){
    //nampung data
    int i = 0;
    char hasil[urutanDB-1][400];
    struct mahasiswa *temp = head;
    while(temp != NULL){
        if(i != index){
            snprintf(hasil[i], sizeof hasil[i], "%s;%s;%s;%s;%s;%d;%d;%d;\n", temp->nama, temp->nim, temp->fakultas, temp->progdi, temp->alamat, temp->tglLahir, temp->bulanLahir, temp->tahunLahir);
        }else{
            //ngubah format di index yg mo diganti
            if(menuUbah == 1){
                sprintf(hasil[index], "%s;%s;%s;%s;%s;%d;%d;%d;\n", temp->nama, data, temp->fakultas, temp->progdi, temp->alamat, temp->tglLahir, temp->bulanLahir, temp->tahunLahir);
            }
            else if (menuUbah == 2){
                sprintf(hasil[index], "%s;%s;%s;%s;%s;%d;%d;%d;\n", data, temp->nim, temp->fakultas, temp->progdi, temp->alamat, temp->tglLahir, temp->bulanLahir, temp->tahunLahir);
            }else if (menuUbah == 3){
                sprintf(hasil[index], "%s;%s;%s;%s;%s;%d;%d;%d;\n", temp->nama, temp->nim, data, temp->progdi, temp->alamat, temp->tglLahir, temp->bulanLahir, temp->tahunLahir);
            }else if (menuUbah == 4){
                sprintf(hasil[index], "%s;%s;%s;%s;%s;%d;%d;%d;\n", temp->nama, temp->nim, temp->fakultas, data, temp->alamat, temp->tglLahir, temp->bulanLahir, temp->tahunLahir);
            }else if (menuUbah == 5){
                sprintf(hasil[index], "%s;%s;%s;%s;%s;%d;%d;%d;\n", temp->nama, temp->nim, temp->fakultas, temp->progdi, data, temp->tglLahir, temp->bulanLahir, temp->tahunLahir);
            }else if (menuUbah == 6){
                sprintf(hasil[index], "%s;%s;%s;%s;%s;%d;%d;%d;\n", temp->nama, temp->nim, temp->fakultas, temp->progdi, temp->alamat, nilai, temp->bulanLahir, temp->tahunLahir);
            }else if (menuUbah == 7){
                sprintf(hasil[index], "%s;%s;%s;%s;%s;%d;%d;%d;\n", temp->nama, temp->nim, temp->fakultas, temp->progdi, temp->alamat, temp->tglLahir, nilai, temp->tahunLahir);
            }else if (menuUbah == 8){
                sprintf(hasil[index], "%s;%s;%s;%s;%s;%d;%d;%d;\n", temp->nama, temp->nim, temp->fakultas, temp->progdi, temp->alamat, temp->tglLahir, temp->bulanLahir, nilai);
            }
        }
        temp = temp->next;
        i++;
    }

    //ngosongin array
    kosongNP();

    //masukin data tampungan ke file
    for(i = 0; i < urutanDB-1; i++){
        tambahNP(hasil[i]);
    }
}

//gotoxy
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//menuUtama
void menuUtama(){
    char pilihan;
    do{
        kosongLL();
        loadData();
        system("cls");
        gotoxy(2,0);printf("====================================================================================================================\n");
        gotoxy(2,1);printf("||                                                                                                                ||\n");
        gotoxy(2,2);printf("||  *       *        *        *       *        *        *********  *  *********  *  *               *    *        ||\n");
        gotoxy(2,3);printf("||  **     **       * *       *       *       * *       *          *  *          *  *               *   * *       ||\n");
        gotoxy(2,4);printf("||  * *   * *      *   *      *       *      *   *      *          *  *          *   *             *   *   *      ||\n");
        gotoxy(2,5);printf("||  *  * *  *     *     *     *********     *     *     *********  *  *********  *    *           *   *     *     ||\n");
        gotoxy(2,6);printf("||  *   *   *    *********    *       *    *********            *  *          *  *     *    *    *   *********    ||\n");
        gotoxy(2,7);printf("||  *       *   *         *   *       *   *         *           *  *          *  *      *  * *  *   *         *   ||\n");
        gotoxy(2,8);printf("||  *       *  *           *  *       *  *           *  *********  *  *********  *        *   *    *           *  ||\n");
        gotoxy(2,9);printf("||                                                                                                                ||\n");
        gotoxy(2,10);printf("====================================================================================================================\n\n");
        gotoxy(21,12);printf("=====================       =====================       =====================\n");
        gotoxy(21,13);printf("|  1. BUAT DATA     |       |  4. HAPUS DATA    |       |  7. LOG ADMIN     |\n");
        gotoxy(21,14);printf("=====================       =====================       =====================\n\n");
        gotoxy(21,15);printf("=====================       =====================       =====================\n");
        gotoxy(21,16);printf("|  2. LIHAT DATA    |       |  5. EDIT DATA     |       |  8. URUTKAN DATA  |\n");
        gotoxy(21,17);printf("=====================       =====================       =====================\n\n");
        gotoxy(21,18);printf("=====================       =====================       =====================\n");
        gotoxy(21,19);printf("|  3. TAMBAH DATA   |       |  6. CARI DATA     |       |  9. KELUAR        |\n");
        gotoxy(21,20);printf("=====================       =====================       =====================\n\n");
        gotoxy(2,22);printf("====================================================================================================================\n\n");
        gotoxy(53,24);printf("Pilihan : "); scanf(" %c", &pilihan);
        switch(pilihan){
        case '1' :
            system("cls");
            buatDB();
            break;
        case '2' :
            system("cls");
            LihatDB();
            break;
        case '3' :
            system("cls");
            tambahDB();
            break;
        case '4' :
            system("cls");
            hapusDB();
            break;
        case '5' :
            system("cls");
            editDB();
            break;
        case '6' :
            system("cls");
            cariDB();
            break;
        case '7' :
            system("cls");
            lihatLogAdmin();
            break;
        case '8' :
            system("cls");
            urutDB();
            break;
        case '9' :
            system("cls");
            kotak(35,80,8,21);
            gotoxy(51,11);printf("G O O D   B Y E");
            gotoxy(54,13);printf("Author By");
            gotoxy(46,15);printf("CARENS KURNIAWAN WIJAYA");
            gotoxy(54,16);printf("672019084");
            gotoxy(52,18);printf("FTI UKSW 2021");
            gotoxy(0,25);getch();exit(0);
            break;
        default :
            gotoxy(49,26);printf("Inputan Menu Salah!\n");
            break;
        }
        getch();
    }while(pilihan != '9');
}

//buat ngosongin LL
void kosongLL(){
    curr = head;
    while(curr != NULL ){
        head = head->next;
        free(curr);
        curr = head;
    }
}

//ngebuat DB baru
void buatDB(){
    int i, banyakData;

    kosongLL();
    kosongNP();
    urutanDB = 1;

    gotoxy(2,0);printf("====================================================================================================================\n");
    gotoxy(2,1);printf("|| << 0. Kembali                                      BUAT DATA                                                   ||\n");
    gotoxy(2,2);printf("====================================================================================================================\n");

    gotoxy(47,4);printf("Mau input berapa data? : ");scanf("%i", &banyakData);
    gotoxy(25,6);printf("==================================================================\n");

    if(banyakData == 0){
        menuUtama();
    }

    char nama[30],
    alamat[30],
    fakultas[30],
    progdi[30],
    nim[10],
    hasil[banyakData][200];

    int tglLahir, bulanLahir, tahunLahir;

    int xy = 8;

    for(i = 0; i < banyakData; i++){
        curr = (struct mahasiswa*)malloc(sizeof(struct mahasiswa));

        gotoxy(50,xy);printf("DATA MAHASISWA KE-%i\n", urutanDB);xy++;
        gotoxy(47,xy);printf("NIM                  : ");scanf("%s", &nim);xy++;
        gotoxy(47,xy);printf("Nama                 : ");fflush(stdin);gets(nama);xy++;
        gotoxy(47,xy);printf("Fakultas             : ");fflush(stdin);gets(fakultas);xy++;
        gotoxy(47,xy);printf("Program Studi        : ");fflush(stdin);gets(progdi);xy++;
        gotoxy(47,xy);printf("Alamat               : ");fflush(stdin);gets(alamat);xy++;
        do{
            gotoxy(47,xy);printf("Tanggal Lahir (1-31) : ");scanf("%i", &tglLahir);
            if(tglLahir < 1 || tglLahir > 31){
                xy++;
                gotoxy(47,xy);printf("Masukkan tanggal lahir dengan rentang 1 - 31\n\n");
                xy+=2;
            }
        }while(tglLahir < 1 || tglLahir > 31);
        xy++;
        do {
            gotoxy(47,xy);printf("Bulan Lahir (1-12)   : ");scanf("%i", &bulanLahir);
            if(bulanLahir < 1 || bulanLahir > 12){
                xy++;
                gotoxy(47,xy);printf("Masukkan bulan lahir dengan rentang 1 - 12\n\n");
                xy+=2;
            }
        }while (bulanLahir < 1 || bulanLahir > 12);
        xy++;
        gotoxy(47,xy);printf("Tahun Lahir          : ");scanf("%i", &tahunLahir);xy+=2;

        strcpy(curr->nama, nama);
        strcpy(curr->nim, nim);
        strcpy(curr->fakultas, fakultas);
        strcpy(curr->progdi, progdi);
        strcpy(curr->alamat, alamat);

        curr->tglLahir = tglLahir;
        curr->bulanLahir = bulanLahir;
        curr->tahunLahir = tahunLahir;

        if(head == NULL){
            head = tail = curr;
        }
        else{
            tail->next = curr;
            tail = curr;
        }
        tail->next = NULL;

        urutanDB++;

        snprintf(hasil, sizeof hasil, "%s;%s;%s;%s;%s;%d;%d;%d;\n", curr->nama, curr->nim, curr->fakultas, curr->progdi, curr->alamat, curr->tglLahir, curr->bulanLahir, curr->tahunLahir);
        tambahNP(hasil);
    }
    gotoxy(48,xy);printf("DATA BERHASIL DIINPUT!\n");

    char log[20];
    sprintf(log, "Admin membuat %i data", banyakData);

    tambahLogAdmin(log);
}

//menu 1, menu 3
void tambahDB(){
    int i, banyakData;

    gotoxy(2,0);printf("====================================================================================================================\n");
    gotoxy(2,1);printf("|| << 0. Kembali                                     TAMBAH  DATA                                                  ||\n");
    gotoxy(2,2);printf("====================================================================================================================\n");
    if(head==NULL){
        gotoxy(42,8);printf("Belum ada Data, silahkan input dulu!\n");
    }else{
        gotoxy(47,4);printf("Mau input berapa data? : ");scanf("%i", &banyakData);
        gotoxy(25,6);printf("==================================================================\n");
        if(banyakData == 0){
            menuUtama();
        }

        char nama[30],
        alamat[30],
        fakultas[30],
        progdi[30],
        nim[10],
        hasil[banyakData][200];

        int tglLahir, bulanLahir, tahunLahir;

        int xy = 8;

        for(i = 0; i < banyakData; i++){
            curr = (struct mahasiswa*)malloc(sizeof(struct mahasiswa));

            gotoxy(50,xy);printf("DATA MAHASISWA KE-%i\n", urutanDB);xy++;
            gotoxy(47,xy);printf("NIM                  : ");scanf("%s", &nim);xy++;
            gotoxy(47,xy);printf("Nama                 : ");fflush(stdin);gets(nama);xy++;
            gotoxy(47,xy);printf("Fakultas             : ");fflush(stdin);gets(fakultas);xy++;
            gotoxy(47,xy);printf("Program Studi        : ");fflush(stdin);gets(progdi);xy++;
            gotoxy(47,xy);printf("Alamat               : ");fflush(stdin);gets(alamat);xy++;
            do{
                gotoxy(47,xy);printf("Tanggal Lahir (1-31) : ");scanf("%i", &tglLahir);
                if(tglLahir < 1 || tglLahir > 31){
                    xy++;
                    gotoxy(47,xy);printf("Masukkan tanggal lahir dengan rentang 1 - 31\n\n");
                    xy+=2;
                }
            }while(tglLahir < 1 || tglLahir > 31);
            xy++;
            do {
                gotoxy(47,xy);printf("Bulan Lahir (1-12)   : ");scanf("%i", &bulanLahir);
                if(bulanLahir < 1 || bulanLahir > 12){
                    xy++;
                    gotoxy(47,xy);printf("Masukkan bulan lahir dengan rentang 1 - 12\n\n");
                    xy+=2;
                }
            }while (bulanLahir < 1 || bulanLahir > 12);
            xy++;
            gotoxy(47,xy);printf("Tahun Lahir          : ");scanf("%i", &tahunLahir);xy+=2;

            strcpy(curr->nama, nama);
            strcpy(curr->nim, nim);
            strcpy(curr->fakultas, fakultas);
            strcpy(curr->progdi, progdi);
            strcpy(curr->alamat, alamat);

            curr->tglLahir = tglLahir;
            curr->bulanLahir = bulanLahir;
            curr->tahunLahir = tahunLahir;

            if(head == NULL){
                head = tail = curr;
            }
            else{
                tail->next = curr;
                tail = curr;
            }
            tail->next = NULL;

            urutanDB++;

            snprintf(hasil, sizeof hasil, "%s;%s;%s;%s;%s;%d;%d;%d;\n", curr->nama, curr->nim, curr->fakultas, curr->progdi, curr->alamat, curr->tglLahir, curr->bulanLahir, curr->tahunLahir);
            tambahNP(hasil);
        }
        gotoxy(48,xy);printf("DATA BERHASIL DIINPUT!\n");

        char log[20];
        sprintf(log, "Admin menambah %i data", banyakData);

        tambahLogAdmin(log);
    }
}

//menu 2
void LihatDB(){
    loading(0.25);
    int y = 7;
    gotoxy(2,0);printf("====================================================================================================================\n");
    gotoxy(2,1);printf("||                                                   LIHAT DATA                                                   ||\n");
    gotoxy(2,2);printf("====================================================================================================================\n");
    gotoxy(2,4);printf("====================================================================================================================\n");
    gotoxy(4,5);printf("NIM");
    gotoxy(15,5);printf("NAMA");
    gotoxy(40,5);printf("FAKULTAS");
    gotoxy(55,5);printf("PPROGRAM STUDI");
    gotoxy(75,5);printf("ALAMAT");
    gotoxy(103,5);printf("TANGGAL LAHIR");
    gotoxy(2,6);printf("====================================================================================================================\n");
    if(head == NULL){
        gotoxy(42,8);printf("Belum ada Data, silahkan input dulu!\n");
    }else{
        curr = head;
        while(curr != NULL){
            gotoxy(4,y);printf("%s\n", curr->nim);
            gotoxy(15,y);printf("%s\n", curr->nama);
            gotoxy(40,y);printf("%s\n", curr->fakultas);
            gotoxy(55,y);printf("%s\n", curr->progdi);
            gotoxy(75,y);printf("%s\n", curr->alamat);
            gotoxy(103,y);printf("%i - %i - %i\n", curr->tglLahir, curr->bulanLahir, curr->tahunLahir);
            curr = curr->next;
            y++;
        }
    }
    printf("\n");

    tambahLogAdmin("Admin melihat data");
}

//cek y/n untuk hapus data
bool cekHapus(int x, int y){
    char cek;
    gotoxy(x,y);printf("Anda Yakin Mau Menghapus Data Ini? (y/n) : ");
    scanf(" %c", &cek);
    if(cek == 'y' || cek == 'Y'){
        return true;
    }else{
        return false;
    }
}

//menu 4
void hapusDB(){
    int y=7;
    char nim [10];
    char log[50];

    gotoxy(2,0);printf("====================================================================================================================\n");
    gotoxy(2,1);printf("|| << 0. Kembali                                     HAPUS DATA                                                   ||\n");
    gotoxy(2,2);printf("====================================================================================================================\n");
    gotoxy(2,4);printf("====================================================================================================================\n");
    gotoxy(4,5);printf("NIM");
    gotoxy(15,5);printf("NAMA");
    gotoxy(40,5);printf("FAKULTAS");
    gotoxy(55,5);printf("PPROGRAM STUDI");
    gotoxy(75,5);printf("ALAMAT");
    gotoxy(103,5);printf("TANGGAL LAHIR");
    gotoxy(2,6);printf("====================================================================================================================\n");

    if (head == NULL){
        gotoxy(42,8);printf("Belum ada Data, silahkan input dulu!\n");
    }else{
        struct mahasiswa *temp = head;
        curr = head;

        while(curr != NULL){
            gotoxy(4,y);printf("%s\n", curr->nim);
            gotoxy(15,y);printf("%s\n", curr->nama);
            gotoxy(40,y);printf("%s\n", curr->fakultas);
            gotoxy(55,y);printf("%s\n", curr->progdi);
            gotoxy(75,y);printf("%s\n", curr->alamat);
            gotoxy(103,y);printf("%i - %i - %i\n", curr->tglLahir, curr->bulanLahir, curr->tahunLahir);
            curr = curr->next;
            y++;
        }

        curr = head;

        gotoxy(42,y+2);printf("Cari NIM yang mau dihapus : ");scanf("%s", &nim);y+=2;

        if(strcmp(nim, "0") == 0){
            menuUtama();
        }

        int index = 0;
        while (curr != NULL) {
            if (strcmp(curr->nim, nim)==0){
                break;
            }
            index++;
            curr = curr->next;
        }

        if (index == 0){
            if(cekHapus(37,y+2)){
                y+=2;
                hapusNP(nim);

                head = temp->next;
                free(temp);

                gotoxy(42,y+2);printf("DATA BERHASIL DI HAPUS\n");
                urutanDB--;
                sprintf(log, "Admin menghapus data untuk NIM : %s", nim);
                tambahLogAdmin(log);
            }else{
                menuUtama();
            }
        }else{
            int i;
            for (i=0; temp!=NULL && i<index-1; i++){
                temp = temp->next;
            }
            if (temp == NULL || temp->next == NULL){
                gotoxy(42,y+2);printf("Data tidak ada\n");
            }else{
                if(cekHapus(37, y+2)){
                    y+=2;
                    hapusNP(nim);
                    struct mahasiswa *next = temp->next->next;
                    free(temp->next);
                    temp->next = next;
                    gotoxy(42,y+2);printf("DATA BERHASIL DI HAPUS\n");
                    urutanDB--;
                    sprintf(log, "Admin menghapus data untuk NIM : %s", nim);
                    tambahLogAdmin(log);
                }else{
                    menuUtama();
                }
            }
        }
    }
}

//menu 5
void editDB(){

    gotoxy(2,0);printf("====================================================================================================================\n");
    gotoxy(2,1);printf("|| << 0. Kembali                                     EDIT  DATA                                                   ||\n");
    gotoxy(2,2);printf("====================================================================================================================\n");
    char log[200];
    if(head==NULL){
        gotoxy(42,4);printf("Belum ada Data, silahkan input dulu!\n");
    }else{
        int index = 0;

        curr = head;

        char nim [10];
        gotoxy(47,4);printf("Cari NIM yang mau diedit : ");scanf("%s", &nim);

        if(strcmp(nim, "0") == 0){
            menuUtama();
        }

        while (curr != NULL) {
            if (strcmp(curr->nim, nim)==0){
                char pilihan;
                do{
                    system("cls");

                    gotoxy(2,0);printf("====================================================================================================================\n");
                    gotoxy(2,1);printf("||                                                   EDIT  DATA                                                   ||\n");
                    gotoxy(2,2);printf("====================================================================================================================\n");

                    gotoxy(47,4);printf("Cari NIM yang mau diedit : %s",nim);

                    gotoxy(2,6);printf("====================================================================================================================\n");
                    gotoxy(4,7);printf("NIM");
                    gotoxy(15,7);printf("NAMA");
                    gotoxy(40,7);printf("FAKULTAS");
                    gotoxy(55,7);printf("PPROGRAM STUDI");
                    gotoxy(75,7);printf("ALAMAT");
                    gotoxy(103,7);printf("TANGGAL LAHIR");
                    gotoxy(2,8);printf("====================================================================================================================\n");

                    gotoxy(4,9);printf("%s\n", curr->nim);
                    gotoxy(15,9);printf("%s\n", curr->nama);
                    gotoxy(40,9);printf("%s\n", curr->fakultas);
                    gotoxy(55,9);printf("%s\n", curr->progdi);
                    gotoxy(75,9);printf("%s\n", curr->alamat);
                    gotoxy(103,9);printf("%i - %i - %i\n", curr->tglLahir, curr->bulanLahir, curr->tahunLahir);

                    gotoxy(2,10);printf("====================================================================================================================\n");

                    gotoxy(21,12);printf("=====================       ======================       ========================\n");
                    gotoxy(21,13);printf("|  1. EDIT NIM      |       |  4. EDIT PROGDI    |       |  7. EDIT BULAN LAHIR |\n");
                    gotoxy(21,14);printf("=====================       ======================       ========================\n\n");
                    gotoxy(21,15);printf("=====================       ======================       ========================\n");
                    gotoxy(21,16);printf("|  2. EDIT NAMA     |       |  5. EDIT ALAMAT    |       |  8. EDIT TAHUN LAHIR |\n");
                    gotoxy(21,17);printf("=====================       ======================       ========================\n\n");
                    gotoxy(21,18);printf("=====================       ======================       ========================\n");
                    gotoxy(21,19);printf("|  3. EDIT FAKULTAS |       |  6. EDIT TGL LAHIR |       |  9. KELUAR           |\n");
                    gotoxy(21,20);printf("=====================       ======================       ========================\n\n");
                    gotoxy(53,22);printf("Pilihan : "); scanf(" %c", &pilihan);
                    switch(pilihan){
                        case '1' :
                            printf("");
                            char editNIM[10];
                            gotoxy(49,24);printf("NIM : ");fflush(stdin);gets(editNIM);

                            sprintf(log, "Admin mengubah NIM : %s menjadi ", curr->nim);

                            strcpy(curr->nim, editNIM);

                            strcat(log, curr->nim);

                            editNP(1, curr->nim, 0, index);

                            tambahLogAdmin(log);

                            gotoxy(49,26);printf("Data berhasil diedit\n");

                            break;
                        case '2' :
                            printf("");
                            char editNama[30];
                            gotoxy(49,24);printf("Nama : ");fflush(stdin);gets(editNama);

                            strcpy(curr->nama, editNama);

                            editNP(2, curr->nama, 0, index);

                            sprintf(log, "Admin mengubah Nama pada NIM : %s menjadi %s", curr->nim , curr->nama);

                            tambahLogAdmin(log);

                            gotoxy(49,26);printf("Data berhasil diedit\n");
                            break;
                        case '3' :
                            printf("");
                            char editFakultas[30];
                            gotoxy(49,24);printf("Fakultas : ");fflush(stdin);gets(editFakultas);

                            strcpy(curr->fakultas, editFakultas);

                            editNP(3, curr->fakultas, 0, index);

                            sprintf(log, "Admin mengubah Fakultas pada NIM : %s menjadi %s", curr->nim , curr->fakultas);

                            tambahLogAdmin(log);

                            gotoxy(49,26);printf("Data berhasil diedit\n");
                            break;
                        case '4' :
                            printf("");
                            char editProgdi[30];
                            gotoxy(49,24);printf("Program Studi : ");fflush(stdin);gets(editProgdi);

                            strcpy(curr->progdi, editProgdi);

                            editNP(4, curr->progdi, 0, index);

                            sprintf(log, "Admin mengubah Program Studi pada NIM : %s menjadi %s", curr->nim , curr->progdi);

                            tambahLogAdmin(log);

                            gotoxy(49,26);printf("Data berhasil diedit\n");
                            break;
                        case '5' :
                            printf("");
                            char editAlamat[30];
                            gotoxy(49,24);printf("Alamat : ");fflush(stdin);gets(editAlamat);

                            strcpy(curr->alamat, editAlamat);

                            editNP(5, curr->alamat, 0, index);

                            sprintf(log, "Admin mengubah Alamat pada NIM : %s menjadi %s", curr->nim , curr->alamat);

                            tambahLogAdmin(log);

                            gotoxy(49,26);printf("Data berhasil diedit\n");
                            break;
                        case '6' :
                            printf("");
                            int tglLahir;
                            do{
                                gotoxy(49,24);printf("Tanggal Lahir (1-31) : ");scanf("%i", &tglLahir);
                                if(tglLahir < 1 || tglLahir > 31){
                                    gotoxy(49,26);printf("Masukkan tanggal lahir dengan rentang 1 - 31\n\n");
                                    getch();
                                    gotoxy(49,26);printf("                                                ");
                                }
                            }while(tglLahir < 1 || tglLahir > 31);

                            curr->tglLahir = tglLahir;

                            editNP(6, NULL, curr->tglLahir, index);

                            sprintf(log, "Admin mengubah Tanggal Lahir pada NIM : %s menjadi %i", curr->nim, curr->tglLahir);

                            tambahLogAdmin(log);

                            gotoxy(49,26);printf("Data berhasil diedit\n");
                            break;
                        case '7' :
                            printf("");
                            int bulanLahir;
                            do{
                                gotoxy(49,24);printf("Bulan Lahir (1-12) : ");scanf("%i", &bulanLahir);
                                if(bulanLahir < 1 || bulanLahir > 12){
                                    gotoxy(49,26);printf("Masukkan bulan lahir dengan rentang 1 - 12\n\n");
                                    getch();
                                    gotoxy(49,26);printf("                                                ");
                                }
                            }while(bulanLahir < 1 || bulanLahir > 12);

                            curr->bulanLahir = bulanLahir;

                            editNP(7, NULL, curr->bulanLahir, index);

                            sprintf(log, "Admin mengubah Bulan Lahir pada NIM : %s menjadi %i", curr->nim, curr->bulanLahir);

                            tambahLogAdmin(log);

                            gotoxy(49,26);printf("Data berhasil diedit\n");
                            break;
                        case '8' :
                            printf("");
                            int tahunLahir;
                            gotoxy(49,24);printf("Tahun Lahir : ");scanf("%i", &tahunLahir);
                            curr->tahunLahir = tahunLahir;

                            editNP(8, NULL, curr->tahunLahir, index);

                            sprintf(log, "Admin mengubah Tahun Lahir pada NIM : %s menjadi %i", curr->nim, curr->tahunLahir);

                            tambahLogAdmin(log);

                            gotoxy(49,26);printf("Data berhasil diedit\n");
                            break;
                        case '9' :
                            system("cls");
                            menuUtama();
                            break;
                        default :
                            gotoxy(49,24);printf("Inputan Menu Salah\n");
                            break;
                    }
                    getch();
                }while(pilihan != '9');
                break;
            }else if(curr == NULL || curr->next==NULL){
                gotoxy(53,6);printf("Data tidak ada");
            }
            curr = curr->next;
            index++;
        }
    }
}

//menu 6
void cariDB(){
    char pilihan, log[200];
    int y = 21;
    gotoxy(2,0);printf("====================================================================================================================\n");
    gotoxy(2,1);printf("||                                                   CARI  DATA                                                   ||\n");
    gotoxy(2,2);printf("====================================================================================================================\n");

    if(head==NULL){
        gotoxy(42,4);printf("Belum ada Data, silahkan input dulu!\n");
    }else{
        do{
            system("cls");
            gotoxy(2,0);printf("====================================================================================================================\n");
            gotoxy(2,1);printf("||                                                   CARI  DATA                                                   ||\n");
            gotoxy(2,2);printf("====================================================================================================================\n");
            gotoxy(21,4);printf("=====================       ======================       ========================\n");
            gotoxy(21,5);printf("|  1. CARI NIM      |       |  4. CARI PROGDI    |       |  7. CARI BULAN LAHIR |\n");
            gotoxy(21,6);printf("=====================       ======================       ========================\n\n");
            gotoxy(21,7);printf("=====================       ======================       ========================\n");
            gotoxy(21,8);printf("|  2. CARI NAMA     |       |  5. CARI ALAMAT    |       |  8. CARI TAHUN LAHIR |\n");
            gotoxy(21,9);printf("=====================       ======================       ========================\n\n");
            gotoxy(21,10);printf("=====================       ======================       ========================\n");
            gotoxy(21,11);printf("|  3. CARI FAKULTAS |       |  6. CARI TGL LAHIR |       |  9. KELUAR           |\n");
            gotoxy(21,12);printf("=====================       ======================       ========================\n\n");
            gotoxy(53,14);printf("Pilihan : "); scanf(" %c", &pilihan);
            switch(pilihan){
                case '1':
                    printf("");
                    char nim [10];
                    gotoxy(21,16);printf("Cari berdasarkan NIM : ");fflush(stdin);gets(nim);

                    gotoxy(2,18);printf("====================================================================================================================\n");
                    gotoxy(4,19);printf("NIM");
                    gotoxy(15,19);printf("NAMA");
                    gotoxy(40,19);printf("FAKULTAS");
                    gotoxy(55,19);printf("PPROGRAM STUDI");
                    gotoxy(75,19);printf("ALAMAT");
                    gotoxy(103,19);printf("TANGGAL LAHIR");
                    gotoxy(2,20);printf("====================================================================================================================\n");

                    curr = head;
                    while(curr != NULL){
                        if(strcmp(curr->nim, nim) == 0){
                            gotoxy(4,y);printf("%s\n", curr->nim);
                            gotoxy(15,y);printf("%s\n", curr->nama);
                            gotoxy(40,y);printf("%s\n", curr->fakultas);
                            gotoxy(55,y);printf("%s\n", curr->progdi);
                            gotoxy(75,y);printf("%s\n", curr->alamat);
                            gotoxy(103,y);printf("%i - %i - %i\n", curr->tglLahir, curr->bulanLahir, curr->tahunLahir);
                            y++;
                        }
                        curr = curr->next;
                    }

                    sprintf(log,"Admin mencari NIM : %s", nim);

                    tambahLogAdmin(log);
                    y=21;
                    break;
                case '2':
                    printf("");
                    char nama [30];
                    gotoxy(21,16);printf("Cari berdasarkan Nama : ");fflush(stdin);gets(nama);

                    gotoxy(2,18);printf("====================================================================================================================\n");
                    gotoxy(4,19);printf("NIM");
                    gotoxy(15,19);printf("NAMA");
                    gotoxy(40,19);printf("FAKULTAS");
                    gotoxy(55,19);printf("PPROGRAM STUDI");
                    gotoxy(75,19);printf("ALAMAT");
                    gotoxy(103,19);printf("TANGGAL LAHIR");
                    gotoxy(2,20);printf("====================================================================================================================\n");

                    curr = head;
                    while(curr != NULL){
                        if(strcmp(curr->nama, nama) == 0){
                            gotoxy(4,y);printf("%s\n", curr->nim);
                            gotoxy(15,y);printf("%s\n", curr->nama);
                            gotoxy(40,y);printf("%s\n", curr->fakultas);
                            gotoxy(55,y);printf("%s\n", curr->progdi);
                            gotoxy(75,y);printf("%s\n", curr->alamat);
                            gotoxy(103,y);printf("%i - %i - %i\n", curr->tglLahir, curr->bulanLahir, curr->tahunLahir);
                            y++;
                        }
                        curr = curr->next;
                    }

                    sprintf(log,"Admin mencari Nama : %s", nama);

                    tambahLogAdmin(log);
                    y=21;
                    break;
                case '3':
                    printf("");
                    char fakultas [30];
                    gotoxy(21,16);printf("Cari berdasarkan Fakultas : ");fflush(stdin);gets(fakultas);

                    gotoxy(2,18);printf("====================================================================================================================\n");
                    gotoxy(4,19);printf("NIM");
                    gotoxy(15,19);printf("NAMA");
                    gotoxy(40,19);printf("FAKULTAS");
                    gotoxy(55,19);printf("PPROGRAM STUDI");
                    gotoxy(75,19);printf("ALAMAT");
                    gotoxy(103,19);printf("TANGGAL LAHIR");
                    gotoxy(2,20);printf("====================================================================================================================\n");

                    curr = head;
                    while(curr != NULL){
                        if(strcmp(curr->fakultas, fakultas) == 0){
                            gotoxy(4,y);printf("%s\n", curr->nim);
                            gotoxy(15,y);printf("%s\n", curr->nama);
                            gotoxy(40,y);printf("%s\n", curr->fakultas);
                            gotoxy(55,y);printf("%s\n", curr->progdi);
                            gotoxy(75,y);printf("%s\n", curr->alamat);
                            gotoxy(103,y);printf("%i - %i - %i\n", curr->tglLahir, curr->bulanLahir, curr->tahunLahir);
                            y++;
                        }
                        curr = curr->next;
                    }

                    sprintf(log,"Admin mencari Fakultas : %s", fakultas);

                    tambahLogAdmin(log);
                    y=21;
                    break;
                case '4':
                    printf("");
                    char progdi [30];
                    gotoxy(21,16);printf("Cari berdasarkan Progdi : ");fflush(stdin);gets(progdi);

                    gotoxy(2,18);printf("====================================================================================================================\n");
                    gotoxy(4,19);printf("NIM");
                    gotoxy(15,19);printf("NAMA");
                    gotoxy(40,19);printf("FAKULTAS");
                    gotoxy(55,19);printf("PPROGRAM STUDI");
                    gotoxy(75,19);printf("ALAMAT");
                    gotoxy(103,19);printf("TANGGAL LAHIR");
                    gotoxy(2,20);printf("====================================================================================================================\n");

                    curr = head;
                    while(curr != NULL){
                        if(strcmp(curr->progdi, progdi) == 0){
                            gotoxy(4,y);printf("%s\n", curr->nim);
                            gotoxy(15,y);printf("%s\n", curr->nama);
                            gotoxy(40,y);printf("%s\n", curr->fakultas);
                            gotoxy(55,y);printf("%s\n", curr->progdi);
                            gotoxy(75,y);printf("%s\n", curr->alamat);
                            gotoxy(103,y);printf("%i - %i - %i\n", curr->tglLahir, curr->bulanLahir, curr->tahunLahir);
                            y++;
                        }
                        curr = curr->next;
                    }

                    sprintf(log,"Admin mencari Progdi : %s", progdi);

                    tambahLogAdmin(log);
                    y=21;
                    break;
                case '5':
                    printf("");
                    char alamat [30];
                    gotoxy(21,16);printf("Cari berdasarkan Alamat : ");fflush(stdin);gets(alamat);

                    gotoxy(2,18);printf("====================================================================================================================\n");
                    gotoxy(4,19);printf("NIM");
                    gotoxy(15,19);printf("NAMA");
                    gotoxy(40,19);printf("FAKULTAS");
                    gotoxy(55,19);printf("PPROGRAM STUDI");
                    gotoxy(75,19);printf("ALAMAT");
                    gotoxy(103,19);printf("TANGGAL LAHIR");
                    gotoxy(2,20);printf("====================================================================================================================\n");

                    curr = head;
                    while(curr != NULL){
                        if(strcmp(curr->alamat, alamat) == 0){
                            gotoxy(4,y);printf("%s\n", curr->nim);
                            gotoxy(15,y);printf("%s\n", curr->nama);
                            gotoxy(40,y);printf("%s\n", curr->fakultas);
                            gotoxy(55,y);printf("%s\n", curr->progdi);
                            gotoxy(75,y);printf("%s\n", curr->alamat);
                            gotoxy(103,y);printf("%i - %i - %i\n", curr->tglLahir, curr->bulanLahir, curr->tahunLahir);
                            y++;
                        }
                        curr = curr->next;
                    }

                    sprintf(log,"Admin mencari Alamat : %s", alamat);

                    tambahLogAdmin(log);
                    y=21;
                    break;
                case '6':
                    printf("");
                    int tglLahir;
                    gotoxy(21,16);printf("Cari berdasarkan Tanggal Lahir : ");scanf("%i", &tglLahir);

                    gotoxy(2,18);printf("====================================================================================================================\n");
                    gotoxy(4,19);printf("NIM");
                    gotoxy(15,19);printf("NAMA");
                    gotoxy(40,19);printf("FAKULTAS");
                    gotoxy(55,19);printf("PPROGRAM STUDI");
                    gotoxy(75,19);printf("ALAMAT");
                    gotoxy(103,19);printf("TANGGAL LAHIR");
                    gotoxy(2,20);printf("====================================================================================================================\n");

                    curr = head;
                    while(curr != NULL){
                        if(curr->tglLahir == tglLahir){
                            gotoxy(4,y);printf("%s\n", curr->nim);
                            gotoxy(15,y);printf("%s\n", curr->nama);
                            gotoxy(40,y);printf("%s\n", curr->fakultas);
                            gotoxy(55,y);printf("%s\n", curr->progdi);
                            gotoxy(75,y);printf("%s\n", curr->alamat);
                            gotoxy(103,y);printf("%i - %i - %i\n", curr->tglLahir, curr->bulanLahir, curr->tahunLahir);
                            y++;
                        }
                        curr = curr->next;
                    }

                    sprintf(log,"Admin mencari Tanggal Lahir : %i", tglLahir);

                    tambahLogAdmin(log);
                    y=21;
                    break;
                case '7':
                    printf("");
                    int bulanLahir;
                    gotoxy(21,16);printf("Cari berdasarkan Bulan Lahir : ");scanf("%i", &bulanLahir);

                    gotoxy(2,18);printf("====================================================================================================================\n");
                    gotoxy(4,19);printf("NIM");
                    gotoxy(15,19);printf("NAMA");
                    gotoxy(40,19);printf("FAKULTAS");
                    gotoxy(55,19);printf("PPROGRAM STUDI");
                    gotoxy(75,19);printf("ALAMAT");
                    gotoxy(103,19);printf("TANGGAL LAHIR");
                    gotoxy(2,20);printf("====================================================================================================================\n");

                    curr = head;
                    while(curr != NULL){
                        if(curr->bulanLahir == bulanLahir){
                            gotoxy(4,y);printf("%s\n", curr->nim);
                            gotoxy(15,y);printf("%s\n", curr->nama);
                            gotoxy(40,y);printf("%s\n", curr->fakultas);
                            gotoxy(55,y);printf("%s\n", curr->progdi);
                            gotoxy(75,y);printf("%s\n", curr->alamat);
                            gotoxy(103,y);printf("%i - %i - %i\n", curr->tglLahir, curr->bulanLahir, curr->tahunLahir);
                            y++;
                        }
                        curr = curr->next;
                    }

                    sprintf(log,"Admin mencari Tanggal Lahir : %i", bulanLahir);

                    tambahLogAdmin(log);
                    y=21;
                    break;
                case '8':
                    printf("");
                    int tahunLahir;
                    gotoxy(21,16);printf("Cari berdasarkan Tahun Lahir : ");scanf("%i", &tahunLahir);

                    gotoxy(2,18);printf("====================================================================================================================\n");
                    gotoxy(4,19);printf("NIM");
                    gotoxy(15,19);printf("NAMA");
                    gotoxy(40,19);printf("FAKULTAS");
                    gotoxy(55,19);printf("PPROGRAM STUDI");
                    gotoxy(75,19);printf("ALAMAT");
                    gotoxy(103,19);printf("TANGGAL LAHIR");
                    gotoxy(2,20);printf("====================================================================================================================\n");

                    curr = head;
                    while(curr != NULL){
                        if(curr->tahunLahir == tahunLahir){
                            gotoxy(4,y);printf("%s\n", curr->nim);
                            gotoxy(15,y);printf("%s\n", curr->nama);
                            gotoxy(40,y);printf("%s\n", curr->fakultas);
                            gotoxy(55,y);printf("%s\n", curr->progdi);
                            gotoxy(75,y);printf("%s\n", curr->alamat);
                            gotoxy(103,y);printf("%i - %i - %i\n", curr->tglLahir, curr->bulanLahir, curr->tahunLahir);
                            y++;
                        }
                        curr = curr->next;
                    }

                    sprintf(log,"Admin mencari Tahun Lahir : %i", tahunLahir);

                    tambahLogAdmin(log);
                    y=21;
                    break;
                case '9' :
                    system("cls");
                    menuUtama();
                    break;
                default :
                    gotoxy(49,16);printf("Inputan Menu Salah!\n");
                    break;
            }
            getch();system("cls");
        }while(pilihan != '9');
    }

}

//submenu 7
void tambahLogAdmin(char log[]){
    currLog = (struct logAdmin*)malloc(sizeof(struct logAdmin));

    strcpy(currLog->log, log);

    if(headLog == NULL){
        headLog = tailLog = currLog;
    }
    else{
        tailLog->next = currLog;
        tailLog = currLog;
    }

    tailLog->next = NULL;
}

//menu 7
void lihatLogAdmin(){
    gotoxy(2,0);printf("====================================================================================================================\n");
    gotoxy(2,1);printf("||                                                   LOG  ADMIN                                                   ||\n");
    gotoxy(2,2);printf("====================================================================================================================\n");
    if(headLog == NULL){
        gotoxy(52,4);printf("LOG ADMIN KOSONG\n");
    }else{
        currLog = headLog;
        int i = 1, y = 4;
        while(currLog != NULL){
            gotoxy(2,y);printf(">>> [ %i ] : %s\n", i, currLog->log);
            currLog = currLog->next;
            i++;y++;
        }
        i = 1;
    }
    printf("\n");
}

//menu 8
void urutDB(){
    char pilihan;
    int y = 21;

    gotoxy(2,0);printf("====================================================================================================================\n");
    gotoxy(2,1);printf("||                                                  URUTKAN DATA                                                  ||\n");
    gotoxy(2,2);printf("====================================================================================================================\n");

    if(head==NULL){
        gotoxy(42,4);printf("Belum ada Data, silahkan input dulu!\n");
    }else{
        do{
            char tempNama[30],
            tempAlamat[30],
            tempFakultas[30],
            tempProgdi[30],
            tempNIM[10];

            int tglLahir, bulanLahir, tahunLahir;

            struct mahasiswa *temp;

            system("cls");
            gotoxy(2,0);printf("====================================================================================================================\n");
            gotoxy(2,1);printf("||                                                  URUTKAN DATA                                                  ||\n");
            gotoxy(2,2);printf("====================================================================================================================\n");
            gotoxy(21,4);printf("=====================       ======================       ========================\n");
            gotoxy(21,5);printf("|  1. URUT NIM      |       |  4. URUT PROGDI    |       |  7. URUT BULAN LAHIR |\n");
            gotoxy(21,6);printf("=====================       ======================       ========================\n\n");
            gotoxy(21,7);printf("=====================       ======================       ========================\n");
            gotoxy(21,8);printf("|  2. URUT NAMA     |       |  5. URUT ALAMAT    |       |  8. URUT TAHUN LAHIR |\n");
            gotoxy(21,9);printf("=====================       ======================       ========================\n\n");
            gotoxy(21,10);printf("=====================       ======================       ========================\n");
            gotoxy(21,11);printf("|  3. URUT FAKULTAS |       |  6. URUT TGL LAHIR |       |  9. KELUAR           |\n");
            gotoxy(21,12);printf("=====================       ======================       ========================\n\n");
            gotoxy(53,14);printf("Pilihan : "); scanf(" %c", &pilihan);

            switch(pilihan){
                case '1':
                    printf("");

                    for(curr = head; curr!=NULL; curr = curr->next){
                        for(temp = curr->next; temp!=NULL; temp=temp->next){
                            if(strcmp(curr->nim, temp->nim) > 0) {
                                strcpy(tempNIM,curr->nim);
                                strcpy(curr->nim,temp->nim);
                                strcpy(temp->nim,tempNIM);

                                strcpy(tempNama,curr->nama);
                                strcpy(curr->nama,temp->nama);
                                strcpy(temp->nama,tempNama);

                                strcpy(tempFakultas,curr->fakultas);
                                strcpy(curr->fakultas,temp->fakultas);
                                strcpy(temp->fakultas,tempFakultas);

                                strcpy(tempProgdi,curr->progdi);
                                strcpy(curr->progdi,temp->progdi);
                                strcpy(temp->progdi,tempProgdi);

                                strcpy(tempAlamat,curr->alamat);
                                strcpy(curr->alamat,temp->alamat);
                                strcpy(temp->alamat,tempAlamat);

                                tglLahir = curr->tglLahir;
                                curr->tglLahir = temp->tglLahir;
                                temp->tglLahir = tglLahir;

                                bulanLahir = curr->bulanLahir;
                                curr->bulanLahir = temp->bulanLahir;
                                temp->bulanLahir = bulanLahir;

                                tahunLahir = curr->tahunLahir;
                                curr->tahunLahir = temp->tahunLahir;
                                temp->tahunLahir = tahunLahir;
                            }
                        }
                    }

                    gotoxy(2,17);printf("TABEL YANG DIURUTKAN : ");
                    gotoxy(2,18);printf("====================================================================================================================\n");
                    gotoxy(4,19);printf("NIM");
                    gotoxy(15,19);printf("NAMA");
                    gotoxy(40,19);printf("FAKULTAS");
                    gotoxy(55,19);printf("PPROGRAM STUDI");
                    gotoxy(75,19);printf("ALAMAT");
                    gotoxy(103,19);printf("TANGGAL LAHIR");
                    gotoxy(2,20);printf("====================================================================================================================\n");

                    temp = head;
                    while(temp != NULL){
                        gotoxy(4,y);printf("%s\n", temp->nim);
                        gotoxy(15,y);printf("%s\n", temp->nama);
                        gotoxy(40,y);printf("%s\n", temp->fakultas);
                        gotoxy(55,y);printf("%s\n", temp->progdi);
                        gotoxy(75,y);printf("%s\n", temp->alamat);
                        gotoxy(103,y);printf("%i - %i - %i\n", temp->tglLahir, temp->bulanLahir,temp->tahunLahir);
                        y++;
                        temp = temp->next;
                    }

                    y = 21;

                    tambahLogAdmin("Admin Mengurutkan Data Berdasarkan NIM");

                    break;
                case '2':
                    printf("");

                    for(curr = head; curr!=NULL; curr = curr->next){
                        for(temp = curr->next; temp!=NULL; temp=temp->next){
                            if(strcmp(curr->nama, temp->nama) > 0) {
                                strcpy(tempNIM,curr->nim);
                                strcpy(curr->nim,temp->nim);
                                strcpy(temp->nim,tempNIM);

                                strcpy(tempNama,curr->nama);
                                strcpy(curr->nama,temp->nama);
                                strcpy(temp->nama,tempNama);

                                strcpy(tempFakultas,curr->fakultas);
                                strcpy(curr->fakultas,temp->fakultas);
                                strcpy(temp->fakultas,tempFakultas);

                                strcpy(tempProgdi,curr->progdi);
                                strcpy(curr->progdi,temp->progdi);
                                strcpy(temp->progdi,tempProgdi);

                                strcpy(tempAlamat,curr->alamat);
                                strcpy(curr->alamat,temp->alamat);
                                strcpy(temp->alamat,tempAlamat);

                                tglLahir = curr->tglLahir;
                                curr->tglLahir = temp->tglLahir;
                                temp->tglLahir = tglLahir;

                                bulanLahir = curr->bulanLahir;
                                curr->bulanLahir = temp->bulanLahir;
                                temp->bulanLahir = bulanLahir;

                                tahunLahir = curr->tahunLahir;
                                curr->tahunLahir = temp->tahunLahir;
                                temp->tahunLahir = tahunLahir;
                            }
                        }
                    }

                    gotoxy(2,17);printf("TABEL YANG DIURUTKAN : ");
                    gotoxy(2,18);printf("====================================================================================================================\n");
                    gotoxy(4,19);printf("NIM");
                    gotoxy(15,19);printf("NAMA");
                    gotoxy(40,19);printf("FAKULTAS");
                    gotoxy(55,19);printf("PPROGRAM STUDI");
                    gotoxy(75,19);printf("ALAMAT");
                    gotoxy(103,19);printf("TANGGAL LAHIR");
                    gotoxy(2,20);printf("====================================================================================================================\n");

                    temp = head;
                    while(temp != NULL){
                        gotoxy(4,y);printf("%s\n", temp->nim);
                        gotoxy(15,y);printf("%s\n", temp->nama);
                        gotoxy(40,y);printf("%s\n", temp->fakultas);
                        gotoxy(55,y);printf("%s\n", temp->progdi);
                        gotoxy(75,y);printf("%s\n", temp->alamat);
                        gotoxy(103,y);printf("%i - %i - %i\n", temp->tglLahir, temp->bulanLahir,temp->tahunLahir);
                        y++;
                        temp = temp->next;
                    }

                    y = 21;

                    tambahLogAdmin("Admin Mengurutkan Data Berdasarkan Nama");

                    break;
                case '3':
                    printf("");

                    for(curr = head; curr!=NULL; curr = curr->next){
                        for(temp = curr->next; temp!=NULL; temp=temp->next){
                            if(strcmp(curr->fakultas, temp->fakultas) > 0) {
                                strcpy(tempNIM,curr->nim);
                                strcpy(curr->nim,temp->nim);
                                strcpy(temp->nim,tempNIM);

                                strcpy(tempNama,curr->nama);
                                strcpy(curr->nama,temp->nama);
                                strcpy(temp->nama,tempNama);

                                strcpy(tempFakultas,curr->fakultas);
                                strcpy(curr->fakultas,temp->fakultas);
                                strcpy(temp->fakultas,tempFakultas);

                                strcpy(tempProgdi,curr->progdi);
                                strcpy(curr->progdi,temp->progdi);
                                strcpy(temp->progdi,tempProgdi);

                                strcpy(tempAlamat,curr->alamat);
                                strcpy(curr->alamat,temp->alamat);
                                strcpy(temp->alamat,tempAlamat);

                                tglLahir = curr->tglLahir;
                                curr->tglLahir = temp->tglLahir;
                                temp->tglLahir = tglLahir;

                                bulanLahir = curr->bulanLahir;
                                curr->bulanLahir = temp->bulanLahir;
                                temp->bulanLahir = bulanLahir;

                                tahunLahir = curr->tahunLahir;
                                curr->tahunLahir = temp->tahunLahir;
                                temp->tahunLahir = tahunLahir;
                            }
                        }
                    }

                    temp=head;

                    gotoxy(2,17);printf("TABEL YANG DIURUTKAN : ");
                    gotoxy(2,18);printf("====================================================================================================================\n");
                    gotoxy(4,19);printf("NIM");
                    gotoxy(15,19);printf("NAMA");
                    gotoxy(40,19);printf("FAKULTAS");
                    gotoxy(55,19);printf("PPROGRAM STUDI");
                    gotoxy(75,19);printf("ALAMAT");
                    gotoxy(103,19);printf("TANGGAL LAHIR");
                    gotoxy(2,20);printf("====================================================================================================================\n");

                    temp = head;
                    while(temp != NULL){
                        gotoxy(4,y);printf("%s\n", temp->nim);
                        gotoxy(15,y);printf("%s\n", temp->nama);
                        gotoxy(40,y);printf("%s\n", temp->fakultas);
                        gotoxy(55,y);printf("%s\n", temp->progdi);
                        gotoxy(75,y);printf("%s\n", temp->alamat);
                        gotoxy(103,y);printf("%i - %i - %i\n", temp->tglLahir, temp->bulanLahir,temp->tahunLahir);
                        y++;
                        temp = temp->next;
                    }

                    y = 21;

                    tambahLogAdmin("Admin Mengurutkan Data Berdasarkan Fakultas");

                    break;
                case '4':
                    printf("");

                    for(curr = head; curr!=NULL; curr = curr->next){
                        for(temp = curr->next; temp!=NULL; temp=temp->next){
                            if(strcmp(curr->progdi, temp->progdi) > 0) {
                                strcpy(tempNIM,curr->nim);
                                strcpy(curr->nim,temp->nim);
                                strcpy(temp->nim,tempNIM);

                                strcpy(tempNama,curr->nama);
                                strcpy(curr->nama,temp->nama);
                                strcpy(temp->nama,tempNama);

                                strcpy(tempFakultas,curr->fakultas);
                                strcpy(curr->fakultas,temp->fakultas);
                                strcpy(temp->fakultas,tempFakultas);

                                strcpy(tempProgdi,curr->progdi);
                                strcpy(curr->progdi,temp->progdi);
                                strcpy(temp->progdi,tempProgdi);

                                strcpy(tempAlamat,curr->alamat);
                                strcpy(curr->alamat,temp->alamat);
                                strcpy(temp->alamat,tempAlamat);

                                tglLahir = curr->tglLahir;
                                curr->tglLahir = temp->tglLahir;
                                temp->tglLahir = tglLahir;

                                bulanLahir = curr->bulanLahir;
                                curr->bulanLahir = temp->bulanLahir;
                                temp->bulanLahir = bulanLahir;

                                tahunLahir = curr->tahunLahir;
                                curr->tahunLahir = temp->tahunLahir;
                                temp->tahunLahir = tahunLahir;
                            }
                        }
                    }

                    gotoxy(2,17);printf("TABEL YANG DIURUTKAN : ");
                    gotoxy(2,18);printf("====================================================================================================================\n");
                    gotoxy(4,19);printf("NIM");
                    gotoxy(15,19);printf("NAMA");
                    gotoxy(40,19);printf("FAKULTAS");
                    gotoxy(55,19);printf("PPROGRAM STUDI");
                    gotoxy(75,19);printf("ALAMAT");
                    gotoxy(103,19);printf("TANGGAL LAHIR");
                    gotoxy(2,20);printf("====================================================================================================================\n");

                    temp = head;
                    while(temp != NULL){
                        gotoxy(4,y);printf("%s\n", temp->nim);
                        gotoxy(15,y);printf("%s\n", temp->nama);
                        gotoxy(40,y);printf("%s\n", temp->fakultas);
                        gotoxy(55,y);printf("%s\n", temp->progdi);
                        gotoxy(75,y);printf("%s\n", temp->alamat);
                        gotoxy(103,y);printf("%i - %i - %i\n", temp->tglLahir, temp->bulanLahir,temp->tahunLahir);
                        y++;
                        temp = temp->next;
                    }

                    y = 21;

                    tambahLogAdmin("Admin Mengurutkan Data Berdasarkan Program Studi");

                    break;
                case '5':
                    printf("");

                    for(curr = head; curr!=NULL; curr = curr->next){
                        for(temp = curr->next; temp!=NULL; temp=temp->next){
                            if(strcmp(curr->alamat, temp->alamat) > 0) {
                                strcpy(tempNIM,curr->nim);
                                strcpy(curr->nim,temp->nim);
                                strcpy(temp->nim,tempNIM);

                                strcpy(tempNama,curr->nama);
                                strcpy(curr->nama,temp->nama);
                                strcpy(temp->nama,tempNama);

                                strcpy(tempFakultas,curr->fakultas);
                                strcpy(curr->fakultas,temp->fakultas);
                                strcpy(temp->fakultas,tempFakultas);

                                strcpy(tempProgdi,curr->progdi);
                                strcpy(curr->progdi,temp->progdi);
                                strcpy(temp->progdi,tempProgdi);

                                strcpy(tempAlamat,curr->alamat);
                                strcpy(curr->alamat,temp->alamat);
                                strcpy(temp->alamat,tempAlamat);

                                tglLahir = curr->tglLahir;
                                curr->tglLahir = temp->tglLahir;
                                temp->tglLahir = tglLahir;

                                bulanLahir = curr->bulanLahir;
                                curr->bulanLahir = temp->bulanLahir;
                                temp->bulanLahir = bulanLahir;

                                tahunLahir = curr->tahunLahir;
                                curr->tahunLahir = temp->tahunLahir;
                                temp->tahunLahir = tahunLahir;
                            }
                        }
                    }

                    gotoxy(2,17);printf("TABEL YANG DIURUTKAN : ");
                    gotoxy(2,18);printf("====================================================================================================================\n");
                    gotoxy(4,19);printf("NIM");
                    gotoxy(15,19);printf("NAMA");
                    gotoxy(40,19);printf("FAKULTAS");
                    gotoxy(55,19);printf("PPROGRAM STUDI");
                    gotoxy(75,19);printf("ALAMAT");
                    gotoxy(103,19);printf("TANGGAL LAHIR");
                    gotoxy(2,20);printf("====================================================================================================================\n");

                    temp = head;
                    while(temp != NULL){
                        gotoxy(4,y);printf("%s\n", temp->nim);
                        gotoxy(15,y);printf("%s\n", temp->nama);
                        gotoxy(40,y);printf("%s\n", temp->fakultas);
                        gotoxy(55,y);printf("%s\n", temp->progdi);
                        gotoxy(75,y);printf("%s\n", temp->alamat);
                        gotoxy(103,y);printf("%i - %i - %i\n", temp->tglLahir, temp->bulanLahir,temp->tahunLahir);
                        y++;
                        temp = temp->next;
                    }

                    y = 21;

                    tambahLogAdmin("Admin Mengurutkan Data Berdasarkan Alamat");

                    break;
                case '6':
                    printf("");

                    for(curr = head; curr!=NULL; curr = curr->next){
                        for(temp = curr->next; temp!=NULL; temp=temp->next){
                            if(curr->tglLahir > temp->tglLahir) {
                                strcpy(tempNIM,curr->nim);
                                strcpy(curr->nim,temp->nim);
                                strcpy(temp->nim,tempNIM);

                                strcpy(tempNama,curr->nama);
                                strcpy(curr->nama,temp->nama);
                                strcpy(temp->nama,tempNama);

                                strcpy(tempFakultas,curr->fakultas);
                                strcpy(curr->fakultas,temp->fakultas);
                                strcpy(temp->fakultas,tempFakultas);

                                strcpy(tempProgdi,curr->progdi);
                                strcpy(curr->progdi,temp->progdi);
                                strcpy(temp->progdi,tempProgdi);

                                strcpy(tempAlamat,curr->alamat);
                                strcpy(curr->alamat,temp->alamat);
                                strcpy(temp->alamat,tempAlamat);

                                tglLahir = curr->tglLahir;
                                curr->tglLahir = temp->tglLahir;
                                temp->tglLahir = tglLahir;

                                bulanLahir = curr->bulanLahir;
                                curr->bulanLahir = temp->bulanLahir;
                                temp->bulanLahir = bulanLahir;

                                tahunLahir = curr->tahunLahir;
                                curr->tahunLahir = temp->tahunLahir;
                                temp->tahunLahir = tahunLahir;
                            }
                        }
                    }

                    gotoxy(2,17);printf("TABEL YANG DIURUTKAN : ");
                    gotoxy(2,18);printf("====================================================================================================================\n");
                    gotoxy(4,19);printf("NIM");
                    gotoxy(15,19);printf("NAMA");
                    gotoxy(40,19);printf("FAKULTAS");
                    gotoxy(55,19);printf("PPROGRAM STUDI");
                    gotoxy(75,19);printf("ALAMAT");
                    gotoxy(103,19);printf("TANGGAL LAHIR");
                    gotoxy(2,20);printf("====================================================================================================================\n");

                    temp = head;
                    while(temp != NULL){
                        gotoxy(4,y);printf("%s\n", temp->nim);
                        gotoxy(15,y);printf("%s\n", temp->nama);
                        gotoxy(40,y);printf("%s\n", temp->fakultas);
                        gotoxy(55,y);printf("%s\n", temp->progdi);
                        gotoxy(75,y);printf("%s\n", temp->alamat);
                        gotoxy(103,y);printf("%i - %i - %i\n", temp->tglLahir, temp->bulanLahir,temp->tahunLahir);
                        y++;
                        temp = temp->next;
                    }

                    y = 21;

                    tambahLogAdmin("Admin Mengurutkan Data Berdasarkan Tanggal Lahir");

                    break;
                case '7':
                    printf("");

                    for(curr = head; curr!=NULL; curr = curr->next){
                        for(temp = curr->next; temp!=NULL; temp=temp->next){
                            if(curr->bulanLahir > temp->bulanLahir) {
                                strcpy(tempNIM,curr->nim);
                                strcpy(curr->nim,temp->nim);
                                strcpy(temp->nim,tempNIM);

                                strcpy(tempNama,curr->nama);
                                strcpy(curr->nama,temp->nama);
                                strcpy(temp->nama,tempNama);

                                strcpy(tempFakultas,curr->fakultas);
                                strcpy(curr->fakultas,temp->fakultas);
                                strcpy(temp->fakultas,tempFakultas);

                                strcpy(tempProgdi,curr->progdi);
                                strcpy(curr->progdi,temp->progdi);
                                strcpy(temp->progdi,tempProgdi);

                                strcpy(tempAlamat,curr->alamat);
                                strcpy(curr->alamat,temp->alamat);
                                strcpy(temp->alamat,tempAlamat);

                                tglLahir = curr->tglLahir;
                                curr->tglLahir = temp->tglLahir;
                                temp->tglLahir = tglLahir;

                                bulanLahir = curr->bulanLahir;
                                curr->bulanLahir = temp->bulanLahir;
                                temp->bulanLahir = bulanLahir;

                                tahunLahir = curr->tahunLahir;
                                curr->tahunLahir = temp->tahunLahir;
                                temp->tahunLahir = tahunLahir;
                            }
                        }
                    }

                    gotoxy(2,17);printf("TABEL YANG DIURUTKAN : ");
                    gotoxy(2,18);printf("====================================================================================================================\n");
                    gotoxy(4,19);printf("NIM");
                    gotoxy(15,19);printf("NAMA");
                    gotoxy(40,19);printf("FAKULTAS");
                    gotoxy(55,19);printf("PPROGRAM STUDI");
                    gotoxy(75,19);printf("ALAMAT");
                    gotoxy(103,19);printf("TANGGAL LAHIR");
                    gotoxy(2,20);printf("====================================================================================================================\n");

                    temp = head;
                    while(temp != NULL){
                        gotoxy(4,y);printf("%s\n", temp->nim);
                        gotoxy(15,y);printf("%s\n", temp->nama);
                        gotoxy(40,y);printf("%s\n", temp->fakultas);
                        gotoxy(55,y);printf("%s\n", temp->progdi);
                        gotoxy(75,y);printf("%s\n", temp->alamat);
                        gotoxy(103,y);printf("%i - %i - %i\n", temp->tglLahir, temp->bulanLahir,temp->tahunLahir);
                        y++;
                        temp = temp->next;
                    }

                    y = 21;

                    tambahLogAdmin("Admin Mengurutkan Data Berdasarkan Bulan Lahir");

                    break;
                case '8':
                    printf("");

                    for(curr = head; curr!=NULL; curr = curr->next){
                        for(temp = curr->next; temp!=NULL; temp=temp->next){
                            if(curr->tahunLahir > temp->tahunLahir) {
                                strcpy(tempNIM,curr->nim);
                                strcpy(curr->nim,temp->nim);
                                strcpy(temp->nim,tempNIM);

                                strcpy(tempNama,curr->nama);
                                strcpy(curr->nama,temp->nama);
                                strcpy(temp->nama,tempNama);

                                strcpy(tempFakultas,curr->fakultas);
                                strcpy(curr->fakultas,temp->fakultas);
                                strcpy(temp->fakultas,tempFakultas);

                                strcpy(tempProgdi,curr->progdi);
                                strcpy(curr->progdi,temp->progdi);
                                strcpy(temp->progdi,tempProgdi);

                                strcpy(tempAlamat,curr->alamat);
                                strcpy(curr->alamat,temp->alamat);
                                strcpy(temp->alamat,tempAlamat);

                                tglLahir = curr->tglLahir;
                                curr->tglLahir = temp->tglLahir;
                                temp->tglLahir = tglLahir;

                                bulanLahir = curr->bulanLahir;
                                curr->bulanLahir = temp->bulanLahir;
                                temp->bulanLahir = bulanLahir;

                                tahunLahir = curr->tahunLahir;
                                curr->tahunLahir = temp->tahunLahir;
                                temp->tahunLahir = tahunLahir;
                            }
                        }
                    }

                    gotoxy(2,17);printf("TABEL YANG DIURUTKAN : ");
                    gotoxy(2,18);printf("====================================================================================================================\n");
                    gotoxy(4,19);printf("NIM");
                    gotoxy(15,19);printf("NAMA");
                    gotoxy(40,19);printf("FAKULTAS");
                    gotoxy(55,19);printf("PPROGRAM STUDI");
                    gotoxy(75,19);printf("ALAMAT");
                    gotoxy(103,19);printf("TANGGAL LAHIR");
                    gotoxy(2,20);printf("====================================================================================================================\n");

                    temp = head;
                    while(temp != NULL){
                        gotoxy(4,y);printf("%s\n", temp->nim);
                        gotoxy(15,y);printf("%s\n", temp->nama);
                        gotoxy(40,y);printf("%s\n", temp->fakultas);
                        gotoxy(55,y);printf("%s\n", temp->progdi);
                        gotoxy(75,y);printf("%s\n", temp->alamat);
                        gotoxy(103,y);printf("%i - %i - %i\n", temp->tglLahir, temp->bulanLahir,temp->tahunLahir);
                        y++;
                        temp = temp->next;
                    }

                    y = 21;

                    tambahLogAdmin("Admin Mengurutkan Data Berdasarkan Tahun Lahir");

                    break;
                case '9' :
                    system("cls");
                    menuUtama();
                    break;
                default :
                    gotoxy(49,16);printf("Inputan Menu Salah\n");
                    break;
            }
            getch();system("cls");
        }while(pilihan != '9');
    }
}

//kotak login
void kotak(int x1,int x2,int y1,int y2){
    int i;
    for(i=x1;i<=x2;i++)
    {
        gotoxy(i,y1);printf("%c",205);
        gotoxy(i,y2);printf("%c",205);
    }
    for(i=y1;i<=y2;i++)
    {
        gotoxy(x1,i);printf("%c",186);
        gotoxy(x2,i);printf("%c",186);
    }
    gotoxy(x1,y1);printf("%c",201);
    gotoxy(x1,y2);printf("%c",200);
    gotoxy(x2,y1);printf("%c",187);
    gotoxy(x2,y2);printf("%c",188);
}

//delay
void delay(float sec){
    float milli_seconds = 75 * sec;

    clock_t start_time = clock();

    while (clock() < start_time + milli_seconds)
        ;
}

//loading
void loading(float dl){
    int q;
    gotoxy(20,16); for(q=1;q<=80;q++) printf("*");
    gotoxy(20,18); for(q=1;q<=80;q++) printf("*");

    int i,k;
    for(i=1;i<=99;i++){
        gotoxy(46,12);
        printf("Menyiapkan Sistem ...   %i%\n\n\n\n\n",1+i,178);
        gotoxy(20,17);
        if(i==3)
            printf("%c",178);
        else if(i==10)
            printf("%c%c",178,178);
        else if(i==15)
            printf("%c%c%c",178,178,178);
        else { }

        gotoxy(20,17);
        for(k=20;k<=i;k++){

            printf("%c",178);
        }
        delay(dl);
    }
    system("cls");
}

//login_code
bool login(){
    char user[6], pass[6];
    kotak(35,80,8,22);
    gotoxy(48,12);printf("SELAMAT DATANG ADMIN\n");
    gotoxy(50,14);printf("Username : ");scanf("%s", &user);
    gotoxy(50,16);printf("Password : ");//scanf("%s", &pass);
    int p = 0;
    do{
        pass[p]=getch();
        if(pass[p] == '\b'){
            if(p == 0){
                printf("");
            }else{
                printf("\b \b");
                p--;
            }
            continue;
        }
        if(pass[p]!='\r'){
            printf("*");
        }
        p++;
    }while(pass[p-1]!='\r');
    pass[p-1]='\0';
    if(strcmp(user, "admin") == 0){
        if(strcmp(pass, "admin") == 0){
            gotoxy(53,18);printf("HALO ADMIN\n");
            getch();
            return true;
        }else{
            gotoxy(48,18);printf("Password Salah\n");
            getch();
            return false;
        }

    }else{
        gotoxy(48,18);printf("Username Salah\n");
        getch();
        return false;
    }
}

//main
void main(){

    system("color 1F");

    //loading
    loading(1);

    //cek login
    bool cek = false;
    do{
        if(login()){
            cek = true;
        }
        system("cls");
    }while(cek != true);

    //masuk menu utama
    menuUtama();
}
