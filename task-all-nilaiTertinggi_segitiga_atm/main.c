#include <stdio.h>
#include <stdlib.h>

int saldo=0;
void Menu()
{
    int menu;
    system("cls");
    printf("1. Angka Terbesar\n");
    printf("2. Segitiga\n");
    printf("3. ATM\n");
    printf("4. Author\n");
    printf("5. Exit\n\n");
    printf("Pilihan: ");scanf("%i",&menu);
    switch(menu)
    {
        case 1: Angka();break;
        case 2: Segitiga();break;
        case 3: ATM();break;
        case 4: Author();break;
        case 5: system("taskkill/IM cb_console_runner.exe");break;
        default:
            printf("Input Salah");
            getch();
            system("cls");
            Menu();
            break;
    }
}

void Angka()
{
    int a,b,c;
    system("cls");
    printf("=======  Menu 1: Angka Terbesar  =======\n\n");
    printf("Masukkan Angka 1: ");scanf("%i",&a);
    printf("Masukkan Angka 2: ");scanf("%i",&b);
    printf("Masukkan Angka 3: ");scanf("%i",&c);
    printf("\n");
    if(a>b & a>c)
    {
        printf("Angka terbesar adalah %i",a);
    }
    else if(b>a & b>c)
    {
        printf("Angka terbesar adalah %i",b);
    }
    else if(c>a & c>b)
    {
        printf("Angka terbesar adalah %i",c);
    }
    else
    {
        printf("Input Salah");
        getch();
        system("cls");
        Angka();
    }
    getch();
    system("cls");
    Menu();
}

void Segitiga()
{
    int i,j,ang;
    system("cls");
    printf("=======  Menu 2: Segitiga  =======\n\n");
    printf("Masukkan angka: ");scanf("%i",&ang);
    printf("\n");
    for(i=1;i<=ang;i++)
    {
        for(j=i;j<=ang;j++)
        {
            printf(" ");
        }
        for(j=1;j<=2*i-1;j++)
        {
            if(j%2==1)
            {
                printf("*");
            }
            else
            {
                printf("_");
            }
        }
        printf("\n");
    }
    getch();
    system("cls");
    Menu();
}

void ATM()
{
    system("cls");
    printf("=======  Menu 3: ATM  =======\n\n");
    printf("Masukkan jumlah saldo: ");scanf("%i",&saldo);
    system("cls");
    ATMenu();
}

void ATMenu()
{
    int menu;
    printf("=======  Menu 3: ATM  =======\n\n");
    printf("Jumlah Saldo: %i\n\n",saldo);
    printf("1. Tarik\n");
    printf("2. Setor\n");
    printf("3. Exit\n");
    printf("Pilihan: ");scanf("%i",&menu);
    switch(menu)
    {
        case 1: Tarik();break;
        case 2: Setor();break;
        case 3: Menu();break;
        default:
            printf("Input Salah");
            getch();
            system("cls");
            ATMenu();
    }
}

void Tarik()
{
    int tarik;
    system("cls");
    printf("Masukkan jumlah tarikan: ");scanf("%i",&tarik);
    if(saldo>=tarik)
    {
        saldo-=tarik;
        printf("Sisa Saldo Anda %i",saldo);
        getch();
        system("cls");
        ATMenu();
    }
    else
    {
        printf("Saldo Anda Kurang");
        getch();
        system("cls");
        ATMenu();
    }
}

void Setor()
{
    int setor;
    system("cls");
    printf("Masukkan jumlah setoran: ");scanf("%i",&setor);
    saldo+=setor;
    printf("Sisa Saldo Anda %i",saldo);
    getch();
    system("cls");
    ATMenu();
}

void Author()
{
    system("cls");
    printf("Carens Kurniawan Wijaya/672019084");
    getch();
    system("cls");
    Menu();
}

void main()
{
    Menu();
}
