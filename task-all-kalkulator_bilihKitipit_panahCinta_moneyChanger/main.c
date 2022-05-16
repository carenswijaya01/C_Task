#include <stdio.h>
#include <stdlib.h>

void Panah()
{
    int i,j,k;
    printf("Masukkan tinggi panah: ");scanf("%i",&k);
    printf("\n\n");
    for(i=1;i<=k;i++)
    {
        for(j=i;j<=k;j++)
        {
            printf(" * ");
        }
        for(j=2;j<=2*i-1;j++)
        {
            printf(" ");
        }
        for(j=i;j<=k;j++)
        {
            printf(" * ");
        }
        printf("\n");
    }
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf(" * ");
        }
        for(j=2*k-2*i;j>=1;j--)
        {
            printf(" ");
        }
        for(j=1;j<=i;j++)
        {
            printf(" * ");
        }
        printf("\n");
    }
}

void MoneyChanger()
{
    int inp, cek;
    char yn;
    float nom;
    do
    {
        printf("============================================\n");
        printf("=!=!=!=!=!=!=EXCHANGE IKUZOOOOO=!=!=!=!=!=!=\n");
        printf("============================================\n");
        printf("Konversi IDR ke:\n");
        printf("1. IDR ke AUD\n");
        printf("2. IDR ke USD\n");
        printf("3. IDR ke JPY\n");
        printf("4. IDR ke RUB\n");
        printf("5. Kembali\n");
        printf("Pilihan: ");scanf("%i", &inp);
        if(inp == 1){
            printf("Nominal IDR ");scanf("%f", &nom);
            nom *= 0.000092;
            printf("Nominal AUD %.6f\n", nom);
        }else if(inp == 2){
            printf("Nominal IDR ");scanf("%f", &nom);
            nom *= 0.000071;
            printf("Nominal USD %.6f\n", nom);
        }else if(inp == 3){
            printf("Nominal IDR ");scanf("%f", &nom);
            nom *= 0.0074;
            printf("Nominal JPY %.6f\n", nom);
        }else if(inp == 4){
            printf("Nominal IDR ");scanf("%f", &nom);
            nom *= 0.0054;
            printf("Nominal RUB %.6f\n", nom);
        }else if(inp == 5){
            system("cls");
            Menu();
        }else{
            printf("Input salah bang\n");
            getch();
            system("cls");
            MoneyChanger();
        }
        do{
            printf("Mau ulang lagi? (y/n) ");scanf(" %c", &yn);
            if(yn == 'y' || yn == 'Y'){
                cek = 1;
                inp = 0;
                system("cls");
            }else if(yn == 'n' || yn == 'N'){
                cek = 1;
                system ("cls");
                Menu();
            }else{
                printf("Input salah bang\n");
                getch();
                cek = 0;
            }
        }while(cek != 1);
    } while (inp != 5);
}

void LayangLayang()
{
    int angka,i,j;
    printf("Panjang 1/2 diagonal: ");scanf("%i",&angka);
    printf("\n\n");
    for(i=1;i<=angka;i++)
    {
        for(j=angka;j>=i;j--)
        {
            printf("*");
        }
        for(j=1;j<=2*i-1;j++)
        {
            if(j==i){
                printf("*");
            }else{
            printf(" ");
            }
        }
        for(j=i;j<=angka;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(i=0;i<=angka;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("*");
        }
        for(j=i;j<=angka*2-i;j++)
        {
            if(i==0){
                printf("*");
            }else if(j==angka){
                printf("*");
            } else{
                printf(" ");
            }
        }
        for(j=1;j<=i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void ProsesKalkulator(float angka1, float angka2)
{
    float hasilTambah,hasilKurang,hasilKali,hasilBagi;

    hasilTambah = angka1 + angka2;
    hasilKurang = angka1 - angka2;
    hasilKali = angka1*angka2;
    hasilBagi = angka1/angka2;

    printf("Hasil Tambah dari %.2f dan %.2f = %.2f",angka1,angka2,hasilTambah);
    printf("\nHasil Kurang dari %.2f dan %.2f = %.2f",angka1,angka2,hasilKurang);
    printf("\nHasil Kali dari %.2f dan %.2f = %.2f",angka1,angka2,hasilKali);
    printf("\nHasil Bagi dari %.2f dan %.2f = %.2f",angka1,angka2,hasilBagi);

}

void InputKalkulator()
{
    float angka1,angka2;

    printf("Masukkan Angka 1 : ");
    scanf("%f",&angka1);
    printf("Masukkan Angka 2 : ");
    scanf("%f",&angka2);

    ProsesKalkulator(angka1,angka2);
}

void Menu()
{
    int pilihan;

    do{
        printf("\n\n========== MENU ==========\n1. Kalkulator Sederhana. \n2. Layang Layang. \n3. Panah Cinta. \n4. Tukar Uang. \n5. Exit. \nPilihan : ");
        scanf("%d",&pilihan);

        if(pilihan == 1)
        {
            system("cls");
            InputKalkulator();
            getch();
            system("cls");
        }
        else if(pilihan == 2)
        {
            system("cls");
            LayangLayang();
            getch();
            system("cls");
        }
        else if(pilihan == 3)
        {
            system("cls");
            Panah();
            getch();
            system("cls");
        }
        else if(pilihan == 4)
        {
            system("cls");
            MoneyChanger();
            system("cls");
        }
        else if(pilihan == 5)
        {
            exit(0);
        }
        else
        {
            printf("Menu Tidak Tersedia !!");
            getch();
            system("cls");
        }

    }while(pilihan != 5);
}

void main()
{
    Menu();
}
