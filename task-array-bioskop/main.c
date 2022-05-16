#include <stdio.h>
#include <stdlib.h>

int x,kursi;
int k[25]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};

void Kursi()
{
    int i,j;
    for(i=1;i<=5;i++)//baris
    {
        for(j=1;j<=5;j++)//kolom
        {
            if(k[x]<10){//1-9
                printf("   %i  ",k[x]);
                x++;
            }
            else{//10 lebih
                printf("  %i  ",k[x]);
                x++;
            }
        }
        printf("\n");
        printf("\n");
    }
}
void main()
{
    int menu;
    do{
        printf("=====================================\n");
        printf("Selamat datang di Bioskop Pemrograman\n");
        printf("=====================================\n");
        printf("Menu :\n");
        printf("=====================================\n");
        printf("1. Lihat Kursi\n");
        printf("2. Pesan Kursi\n");
        printf("3. Hapus Kursi\n");
        printf("4. Exit\n");
        printf("Pilihan : ");scanf("%i",&menu);
        switch(menu)
        {
            case 1:
                x=0;
                printf("=====================================\n");
                printf("=============Lihat Kursi=============\n");
                printf("=====================================\n");
                Kursi();
                printf("Kursi yang ditandai '0' sudah dipesan\n");
                printf("=====================================\n");
                system("pause");
                system("cls");break;
            case 2:
                x=0;
                printf("=====================================\n");
                printf("=============Pesan Kursi=============\n");
                printf("=====================================\n");
                Kursi();
                printf("Mau pesan kursi nomer berapa? ");scanf("%i",&kursi);
                system("cls");
                if(k[kursi-1]==kursi)
                {
                    x=0;
                    k[kursi-1]=0;//index ke sekian diganti kursi
                    printf("=====================================\n");
                    Kursi();
                    printf("Kursi berhasil dipesan!\n");
                }
                else
                {
                    x=0;
                    printf("=====================================\n");
                    Kursi();
                    printf("Kursi sudah dipesan!\n");
                }
                printf("=====================================\n");
                system("pause");
                system("cls");break;
            case 3:
                x=0;
                printf("=====================================\n");
                printf("=============Hapus Kursi=============\n");
                printf("=====================================\n");
                Kursi();
                printf("Kursi yang ditandai '0' sudah dipesan\n");
                printf("Mau hapus kursi nomer berapa? ");scanf("%i",&kursi);
                system("cls");
                if(k[kursi-1]==0)
                {
                    x=0;
                    k[kursi-1]=kursi;//index ke sekian diganti kursi
                    printf("=====================================\n");
                    Kursi();
                    printf("Kursi berhasil dihapus!\n");
                }
                else
                {
                    x=0;
                    printf("=====================================\n");
                    Kursi();
                    printf("Kursi belum dipesan!\n");
                }
                printf("=====================================\n");
                system("pause");
                system("cls");break;
            case 4:break;
            default:
                printf("Pilihan Tidak Ada!");
                getch();
                system("cls");
                continue;
        }
    }while(menu!=4);
}
