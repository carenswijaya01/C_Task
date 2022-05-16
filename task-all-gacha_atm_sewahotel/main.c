#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

char nama[20], user[20], pass[20], repass[20];
int saldo=0, poin=0;

int discount(char method, int sum);
int roomPrice(char roomcode, int classc, int duration);

void enkripsi(){
    system("cls");
    char message[100], ch;
    int i, key;
    printf("Kalimat yang ingin di enkripsi: ");
    fflush(stdin);gets(message);
    printf("Kunci: ");
    scanf("%d", &key);
    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
    }
    printf("Kalimat Setelah Enkripsi: %s", message);
    getch();
    system("cls");
    menu();
}

void dekripsi(){
    system("cls");
    char message[100], ch;
    int i, key;
    printf("Kalimat yang ingin di dekripsi: ");
    fflush(stdin);gets(message);
    printf("Kunci: ");
    scanf("%d", &key);
    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch - key;
            if(ch < 'a'){
                ch = ch + 'z' - 'a' - 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key;
            if(ch < 'A'){
                ch = ch + 'Z' - 'A' - 1;
            }
            message[i] = ch;
        }
    }
    printf("Kalimat Setelah Dekripsi: %s", message);
    getch();
    system("cls");
    menu();
}

void reg(){ //finzz
    int cek = 0;
    printf("*****************************************\n");
    printf("***          Registrasi Akun          ***\n");
    printf("*****************************************\n");
    printf(" Nama           : ");scanf("%s", &nama);
    printf(" Username       : ");scanf("%s", &user);
    do{
        printf(" Password       : ");scanf("%s", &pass);
        printf(" Ulang Password : ");scanf("%s", &repass);
        if(strcmp(pass, repass) == 0){
            printf("\n====== TERIMAKASIH SUDAH MENDAFTAR ======\n");
            getch();
            system("cls");
            awal();
        }else{
            printf(" Maaf, password yang anda masukkan salah");
            getch();
            printf("\n\n");
            cek = 1;
        }
    }while(cek != 0);
}

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

void login(){ //finzz
    /*char user1[20], pass1[20];
    printf("*****************************************\n");
    printf("***            Login  Akun            ***\n");
    printf("*****************************************\n\n");
    printf(" Username : ");scanf("%s", &user1);
    printf(" Password : ");scanf("%s", &pass1);

    if(strcmp(user1, user) == 0){
        if(strcmp(pass1, pass)==0){
            printf("\n SELAMAT DATANG %s\n", nama);
            getch();
            system("cls");
            menu();
        }else{
            printf(" Password Anda Salah");
            getch();
            system("cls");
            awal();
        }
    }else{
        printf(" Maaf, username Anda belum terdaftar");
        getch();
        system("cls");
        awal();
    }*/
    char us[0];
    char pw[0];
    kotak(35,80,12,20);
    gotoxy(40,14);printf("Masukkan username dan password anda\n");
    gotoxy(50,16);printf("Username: ");scanf("%s",&us);
    if(strcmp(us,"fti")==0)
    {
        gotoxy(50,17);printf("Password: ");scanf("%s",&pw);
        if(strcmp(pw,"fti")==0)
        {
            system("cls");
            menu();
        }
        else
        {
            gotoxy(50,19);printf("Password Salah");
            getch();
            system("cls");
            login();
        }
    }
    else
    {
        gotoxy(50,18);printf("Username salah");
        getch();
        system("cls");
        login();
    }
}

void menu(){//finzzz
    int pil;
    do{
        printf("*********************************\n");
        //printf("***   GA-Ngotak Application   ***\n");
        printf("***          TR  DDP          ***\n");
        printf("*********************************\n");
        printf("| Menu:                         |\n");
        printf("---------------------------------\n");
        printf("| 1. Enkripsi Kalimat           |\n");
        printf("| 2. Dekripsi Kalimat           |\n");
        printf("| 3. ATM Biasa                  |\n");
        printf("| 4. Sewa Hotel Halal           |\n");
        printf("| 5. Author Information         |\n");
        printf("| 6. Logout                     |\n");
        printf("| 7. Exit                       |\n");
        printf("---------------------------------\n");
        printf("Pilihanmu: ");scanf("%i", &pil);
        switch(pil){
            case 1: system("cls");enkripsi(); break;
            case 2: system("cls");dekripsi(); break;
            case 3: system("cls");atm(); break;
            case 4: system("cls");hotel(); break;
            case 5: system("cls");printf("Carens Kurniawan Wijaya");getch();system("cls");break;
            case 6: system("cls");login();break;
            case 7: system("cls");printf("Kesan Pesan untuk Asdos\n");getch();exit(0);break;
            default:
                printf("\nGa ada pilhannya\n");
                getch();
                system("cls");
                break;
        }
    }while(pil != 6);
}

void gacha(){ //finzzz
    int cek=0,cekk=0;
    char yn, hero[16][20] = {"Xinyan", "Beidou", "Rust", "Barbara", "Xiao", "Zhongli", "Skyward", "Widsith", "Fischl", "Bennet", "Noelle", "Rancour", "Bell", "Paimon", "Qiqi", "Klee"};
    do{
        int i,j,k=0,l=0;
        printf("******************************************************\n");
        printf("!!!!                                              !!!!\n");
        printf("!!!!                  GACHA TIME                  !!!!\n");
        printf("!!!!                                              !!!!\n");
        printf("******************************************************\n\n");
        printf("Karakter yang akan di Gacha: \n");
        printf("______________________________________________________\n\n\n");
        for(i = 0; i < 4; i++){
            for(j = k; j < l + 4; j++){
                printf("%s\t\t", hero[j]);
                k++;
            }
            l = k;
            printf("\n\n");
        }
        printf("______________________________________________________\n\n");
        printf("Poin yang Anda miliki saat ini : %d poin \n\n", poin);
        printf("Catatan : Untuk menambah poin, bisa dilakukan dengan\ntransfer ke nomor rekening '0[NIM ANDA]'\n1 poin seharga 10 IDR\n");
        printf("\n****************************************************\n");
        int inp;
        printf("\nMau berapa kali gacha?: ");scanf("%d", &inp);
        //getch();
        int randy[inp];
        if(poin >= inp){
            cek = 0;
            for(i=0;i<inp;i++){
                randy[i]=rand()%16;
            }
            for(i=0;i<inp;i++){
                if(randy[i] == 4 || randy[i] == 5 || randy[i] == 6 || randy[i] == 13 || randy[i] == 14 || randy[i] == 15){
                    printf("\nGacha ke-%d = %s (*5) SELAMAT",i+1,hero[randy[i]]);
                }else{
                    printf("\nGacha ke-%d = %s",i+1,hero[randy[i]]);
                }
                delay(10);
            }
            poin -= inp;
            printf("\n\nPoin yang digunakan       : %d poin\n", inp);
            printf("Sisa poin Anda saat ini   : %d poin\n", poin);
        }else{
            printf("Maaf, poin Anda tidak mencukupi\n\n");
            getch();
        }
        do{
            printf("\nMau ulang? (y/n):  ");scanf(" %c", &yn);
            if(yn == 'y' || yn == 'Y'){
                system("cls");
                cekk = 0;
                cek = 1;
            }else if(yn == 'n' || yn == 'N'){
                cekk = 0;
                cek = 0;
                system("cls");
            }else{
                printf("Input salah\n");
                getch();
                cekk = 1;
            }
        }while (cekk != 0);
    }while(cek != 0);
}

void atm(){ //finzz
    int pil;

    if(strlen(nama) == 0){
        printf("Masukkan Nama: ");scanf("%s", &nama);
        printf("Masukkan saldo: ");scanf("%d", &saldo);
        system("cls");
    }
    do{
        printf("=========================\n");
        printf("|          ATM          |\n");
        printf("=========================\n");
        printf(" Pemilik    : %s\n", nama);
        printf(" Saldo Anda : IDR %d\n", saldo);
        printf("=========================\n");
        printf("| Menu:                 |\n");
        printf("| 1. Transfer Dana      |\n");
        printf("| 2. Tambah Saldo       |\n");
        printf("| 3. Tarik Tunai        |\n");
        printf("| 4. Keluar             |\n");
        printf("=========================\n");
        printf("Pilihan: ");scanf("%i", &pil);
        switch(pil){
            case 1: printf("");
                int i;
                char rek[10];
                printf("\nNo. Rekening Tujuan (10 digit): ");scanf("%s", &rek);
                if (strlen(rek) < 10 || strlen(rek)>10){
                    printf("Maaf, rekening tujuan salah\n\n");
                    getch();
                    system("cls");
                }else{
                    int dana;
                    printf("Masukkan dana yang ingin ditransfer: ");scanf("%d", &dana);
                    if(saldo>=dana){
                        if(strcmp(rek, "0672019084")==0){
                            poin += (dana/10);
                        }
                        saldo-=dana;
                        printf("\n!!!! Transfer Berhasil !!!!\n\n");
                        printf("Sisa Saldo Anda IDR %i",saldo);
                        getch();
                        system("cls");
                    }else{
                        printf("Saldo Anda Kurang");
                        getch();
                        system("cls");
                    }
                }
                break;
            case 2: printf("");
                int setor;
                printf("\nMasukkan jumlah setoran: ");scanf("%d",&setor);
                saldo+=setor;
                printf("\n!!!! Tambah Saldo Berhasil !!!!\n\n");
                printf("Sisa Saldo Anda %d",saldo);
                getch();
                system("cls");
                break;
            case 3: printf("");
                int tarik;
                printf("\nMasukkan jumlah tarikan: ");scanf("%d",&tarik);
                if(saldo>=tarik){
                    saldo-=tarik;
                    printf("\n!!!! Tarik Tunai Berhasil !!!!\n\n");
                    printf("Sisa Saldo Anda %d",saldo);
                    getch();
                    system("cls");
                }
                else
                {
                    printf("Saldo Anda Kurang");
                    getch();
                    system("cls");
                }
                break;
            case 4: system("cls");menu();break;
            default:
                printf("\nGa ada pilhannya\n");
                getch();
                system("cls");
                break;
        }
    }while(pil != 4);
}

void hotel(){ //finzz
    if(strlen(nama) == 0){
        printf("BUAT ATM DULU YA\n");
        getch();
        system("cls");
        menu();
    }else{
        char roomcode, method;
        int cek, classcode, extra, duration;
        printf("*****************************************\n");
        printf("****           HOTEL HALAL           ****\n");
        printf("*****************************************\n");
        printf(" Nama Penyewa            : %s\n", nama);
        do{
            printf(" Kode Kamar [A/B/C]      : ");scanf(" %c", &roomcode);
            if(roomcode == 'A' || roomcode  == 'a' || roomcode  == 'B' || roomcode  == 'b' || roomcode  == 'C' || roomcode  == 'c'){
                cek = 0;
            }else{
                printf(" Inputan Anda Salah\n\n");
                getch();
                cek = 1;
            }
        }while (cek != 0);
        do{
            printf(" Kode Kelas [1/2]        : ");scanf("%i", &classcode);
            if(classcode == 1 || classcode == 2){
                cek = 0;
            }else{
                printf(" Inputan Anda Salah\n\n");
                getch();
                cek = 1;
            }
        }while (cek != 0);
        printf(" Extra Bed               : ");scanf("%i", &extra);
        printf(" Lama Menginap (hari)    : ");scanf("%i", &duration);
        do{
            printf(" Metode pembayaran [K/T] : ");scanf(" %c", &method);
            if(method == 'K' || method == 'k' || method == 'T' || method == 't'){
                cek = 0;
            }else{
                printf(" Inputan Anda Salah\n\n");
                getch();
                cek = 1;
            }
        }while (cek != 0);
        printf("\n! - ! - ! - ! - ! - ! - ! - ! - ! - ! - !\n");
        printf("\n*****************************************\n");

        proses1(roomcode, classcode, extra, duration, method);
    }
}

void proses1(char roomcode, int classcode, int extra, int duration, char method){ //finzzz
    int inp, pin, duit, cek = 0;
    char r[20];
    strcpy(r,room(roomcode));

    char c[20];
    strcpy(c,classname(classcode));

    int rp = roomPrice(roomcode, classcode, duration);
    extra = extra * duration * 100000;
    int sum = rp + extra;
    int disc = discount(method, sum);
    int newsum = sum - disc;

    printf("****         DETAIL  PESANAN         ****\n");
    printf("*****************************************\n");
    printf(" Nama penyewa         = %s\n", nama);
    printf(" Nama kamar           = %s\n", r);
    printf(" Kategori             = %s\n", c);
    printf(" Lama menginap        = %i hari\n", duration);
    printf(" Biaya sewa           = %i\n", rp);
    printf(" Biaya extra bed      = %i\n", extra);
    printf(" Diskon               = %i\n", disc);
    printf(" Total biaya sewa     = %i\n", newsum);
    printf("*****************************************\n");
    do{
        printf("\nMenu: \n");
        printf("-----------------------------------------\n");
        printf(" 1. Lanjutkan Pembayaran\n");
        printf(" 2. Keluar\n");
        printf("-----------------------------------------\n");
        printf("Pilihan: ");scanf("%i", &inp);
        switch(inp){
            case 1:
                if(method == 'K' || method == 'k'){
                    do{
                        printf("\nMasukkan PIN Rekening Anda: ");scanf("%i", &pin);
                        if(pin == 1010){
                            cek = 0;
                            if(saldo >= newsum){
                                saldo -= newsum;
                                printf("Pembayaran Anda Berhasil\n");
                                getch();
                                system("cls");
                                menu();
                            }else{
                                printf("Saldo Anda Kurang\n\n");
                                getch();
                            }
                        }else{
                            printf("PIN Anda salah\n");
                            getch();
                            cek = 1;
                        }
                    }while(cek != 0);
                }else if(method == 'T' || method == 't'){
                    do{
                        printf("\nUang Anda: ");scanf("%i", &duit);
                        if(duit >= newsum){
                            cek = 0;
                            int kembali = duit - newsum;
                            printf("Kembali : %i\n\n", kembali);
                            printf("Terima Kasih sudah memesan\n");
                            getch();
                            system("cls");
                            menu();
                        }else{
                            cek = 1;
                            printf("Uang Anda Kurang\n\n");
                            getch();
                        }
                    }while(cek !=0);

                }
                break;
            case 2:system("cls");break;
            default:break;
        }
    }while(inp != 2);
}

void room(char roomcode){ //finzz
    if (roomcode == 'A' || roomcode == 'a') {
        roomcode = "Standard Room";
    } else if (roomcode == 'B' || roomcode == 'b') {
        roomcode = "Deluxe room";
    } else {
        roomcode = "Suit room";
    }
}

void classname(int classcode){ //finzzz
    char cname[20];
    if (classcode == 1) {
        strcpy(cname, "Single bed");
    } else {
        strcpy(cname, "Twin bed");
    }
    return cname;
}

int roomPrice(char roomcode, int classc, int duration) { //finzzz
    int roomPrice = 0;
    if (roomcode=='A' || roomcode == 'a') {
        if (classc == 1) {
            roomPrice = duration * 250000;
        } else {
            roomPrice = duration * 300000;
        }
    } else if (roomcode=='B' || roomcode == 'b') {
        if (classc == 1) {
            roomPrice = duration * 400000;
        } else {
            roomPrice = duration * 500000;
        }
    } else if (roomcode=='C' || roomcode == 'b') {
        if (classc == 1) {
            roomPrice = duration * 700000;
        } else {
            roomPrice = duration * 850000;
        }
    }
    return roomPrice;
}

int discount(char method, int sum){ //finzzz
    int disc = 0;
    if (method == 'K' || method == 'k') {
        disc = (sum * 5) / 100;
    } else if(method == 'T' || method == 't'){
        disc = 0;
    }
    return disc;
}

void awal(){ //finzzz
    int pil;
    do{
        printf("=========================\n");
        printf("======   WELCOME   ======\n");
        printf("=========================\n");
        printf("1. Registrasi Akun\n");
        printf("2. Login Akun\n");
        printf("Pilihan: ");scanf("%i", &pil);
        switch(pil){
            case 1: system("cls");reg();break;
            case 2: system("cls");login();break;
            default:
                printf("\nGa ada pilhannya\n");
                getch();
                system("cls");
                break;
        }
    }while(pil != 1 && pil != 2);

}

void gotoxy(int x, int y){ //fin
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void delay(int sec){//fin
    int milli_seconds = 75 * sec;

    clock_t start_time = clock();

    while (clock() < start_time + milli_seconds)
        ;
}

void main(){
    system("color 70");
    int q;
    gotoxy(20,16); for(q=1;q<=80;q++) printf("*");
    gotoxy(20,18); for(q=1;q<=80;q++) printf("*");

    int i,k;
    for(i=1;i<=99;i++){
        gotoxy(50,12);
        printf("Sabar Ngab........   %i%\n\n\n\n\n",1+i,178);
        gotoxy(20,17);
        if(i==3)
            printf("%c",178);
        else if(i==10)
            printf("%c%c",178,178);
        else if(i==15)
            printf("%c%c%c",178,178,178);
        else { }

        for(k=20;k<=i;k++){
            printf("%c",178);
        }
      delay(1);
    }
    system("cls");
    login();
}
