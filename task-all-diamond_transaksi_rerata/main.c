#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//variabel buat transaksi
int jmlh,th[],total;
total=0;
int h[]={0,20500,3500,15800,9000,12500};
//gotoxy
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//kotak lognn
void kotak(int x1,int x2,int y1,int y2)
{
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

//login form
void Login()
{
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
            Menu();
        }
        else
        {
            gotoxy(50,19);printf("Password Salah");
            getch();
            system("cls");
            Login();
        }
    }
    else
    {
        gotoxy(50,18);printf("Username salah");
        getch();
        system("cls");
        Login();
    }
}
//menu
void Menu()
{
    system("COLOR E");
    int menu;
    printf("1. Bintang Diamond\n");
    printf("2. Transaksi\n");
    printf("3. Rata-rata nilai\n");
    printf("4. Author Information\n");
    printf("5. Exit\n");
    printf("Masukkan pilihan: ");scanf("%i",&menu);
    switch(menu)
    {
        case 1:Diamond();break;
        case 2:Tabel();break;
        case 3:Rata();break;
        case 4:Author();break;
        case 5:system("taskkill/IM cb_console_runner.exe");
        default:
            system("cls");
            Menu();
    }
}
//diamond
void Diamond()
{
    system("COLOR E");
    system("cls");
    int i,j,k;
    printf("Masukkan angka: ");scanf("%i",&k);
    printf("\n\n");
    for(i=1;i<=k;i++)
    {
        for(j=i;j<=k;j++)
        {
            printf("*");
        }
        for(j=2;j<=2*i-1;j++)
        {
            printf(" ");
        }
        for(j=i;j<=k;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("*");
        }
        for(j=2*k-2*i;j>=1;j--)
        {
            printf(" ");
        }
        for(j=1;j<=i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    getch();
    system("cls");
    Menu();
}
//transaksi1-tabel
void Tabel()
{
    system("COLOR E");
    system("cls");
    printf("+------------------------------------------+\n");
    printf("|                PASCAL MART               |\n");
    printf("+------------------------------------------+\n");
    printf("| No. |     Nama Barang     | Harga Satuan |\n");
    printf("|------------------------------------------|\n");
    printf("|1.   |Shampo Clear (btl)   |Rp 20.500,-   |\n");
    printf("|2.   |Sabun Lifebuoy (bh)  |Rp  3.500,-   |\n");
    printf("|3.   |Pepsodent 75ml (bh)  |Rp 15.800,-   |\n");
    printf("|4.   |Tissue basah (bh)    |Rp  9.000,-   |\n");
    printf("|5.   |Rexona 50ml (bh)     |Rp 12.500,-   |\n");
    printf("|     |                     |              |\n");
    printf("|     |                     |              |\n");
    printf("+------------------------------------------+\n\n");
    printf("Belanjaan\n");
    printf("---------\n");
    Belanja();
}
//transaksi2-input belanja
void Belanja()
{
    system("COLOR E");
    int no,i;
    printf("\nNo. Barang: ");scanf("%i",&no);
    if(no>0 & no<=5)
    {
        for(i=no;i>0;i++)
        {
            printf("Jumlah Barang: ");scanf("%i",&jmlh);
            th[i]=jmlh*h[i];
            total=th[i]+total;
            Konfirmasi();
        }
    }
    else
    {
        printf("Maaf!! No. Barang yang anda masukan tidak terdaftar\n");
        Konfirmasi();
    }

}
//transaksi3-output belanja
void Struk()
{
    system("COLOR E");
    int bayar,bali;
    printf("\n\nBayar: ");scanf("%i",&bayar);
    if(bayar>=total)
    {
        bali=bayar-total;
        printf("Kembalian: %i",bali);
        getch();
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("                   Terima Kasih Telah Berbelanja di Toko Kami.\n");
        getch();
        system("cls");
        Menu();
    }
    else
    {
        printf("Uang Anda Kurang!");
        getch();
        Struk();
    }
}
//transaksi4-yes/no
void Konfirmasi()
{
    system("COLOR E");
    char yt[0];
    printf("Apakah anda masih ingin berbelanja? (Y/T)");scanf("%s",&yt);
    if(strcmp(yt,"Y")==0||strcmp(yt,"y")==0)
    {
        Belanja();
    }
    else if(strcmp(yt,"T")==0||strcmp(yt,"t")==0)
    {
        system("cls");
        printf("Total belanjaan\n");
        printf("---------------\n");
        printf("Rp %i",total);
        Struk();
    }
    else
    {
        printf("Input Salah");
        getch();
        system("cls");
        Tabel();
    }
}
//nilai rata-rata
void Rata()
{
    system("COLOR E");
    system("cls");
    int i,mapel,nilai,jumlah;
    jumlah=0;
    float rata;
    printf("Masukkan jumlah mapel: ");scanf("%i", &mapel);
    if(mapel>=1)
    {
        printf("Masukkan Nilai:\n\n");
        for(i=1;i<=mapel;i++)
        {
        printf("Nilai %i: ",i);scanf("%i", &nilai);
        jumlah+=nilai;
        }
        rata=(float)jumlah/mapel;

        if(rata>100)
        {
            printf("Input Nilai Anda Salah");
            getch();
            system("cls");
            Menu();
        }
        else
        {
            printf("Rata rata : %.2f\n",rata);
            if(rata>=90 & rata<=100)
            {
                printf("Indeks nilai anda A");
                printf("\n");
                printf("Anda LULUS");
            }
            else if(rata>=80 & rata<90)
            {
                printf("Indeks nilai anda B");
                printf("\n");
                printf("Anda LULUS");
            }
            else if(rata>=70 & rata<80)
            {
                printf("Indeks nilai anda C");
                printf("\n");
                printf("Anda LULUS, Lebih ditingkatkan lagi!");
            }
            else if(rata>=60 & rata<70)
            {
                printf("Indeks nilai anda D");
                printf("\n");
                printf("Anda TIDAK LULUS, Silahkan Mengulang Tahun Depan");
            }
            else
            {
                printf("Indeks nilai anda E");
                printf("\n");
                printf("Anda TIDAK LULUS, Silahkan Mengulang Tahun Depan");
            }
        }
    }
    else
    {
        printf("Input Jumlah Mapel Anda Salah");
        getch();
        system("cls");
        Menu();
    }
    getch();
    system("cls");
    Menu();
}
//author
void Author()
{
    system("COLOR E");
    system("cls");
    printf("Windy Kusumawati Suhet/672019068\n");
    printf("Carens Kurniawan Wijaya/672019084\n");
    getch();
    system("cls");
    Menu();
}
//main
void main()
{
    Login();
}
