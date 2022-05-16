#include <stdio.h>
#include <stdlib.h>

//Carens Kurniawan Wijaya - 672019084

int dat = 0;
int urut = 0;

struct data{
    char nama[30], nomorind[10], posisi[30], kota[30], alamat[75];
    int nomor, tgl, bulan, tahunlahir, tahunlulus;
    float gaji;
}dt[50];

int bykdata(int a){
    dat = dat + a;
    return dat;
}

void isiData(){
    int i,tc,cek;
    printf("INPUTAN DATA PEGAWAI FAKULTAS TEKNOLOGI INFORMASI\n");
    printf("Mau berapa data? [0-50]: ");scanf("%i", &tc);
    if(tc < 0 || tc > 50){
        printf("Maaf, hanya bisa input 50 data.");
    }else{
        bykdata(tc);
        for(i = 0; i< tc; i++){
            printf("\nData ke-%i\n", i+1);
            printf("Nama Pegawai              : ");fflush(stdin);gets(dt[urut].nama);
            printf("Nomor Induk Pegawai       : ");fflush(stdin);gets(dt[urut].nomorind);
            printf("Posisi Pegawai            : ");fflush(stdin);gets(dt[urut].posisi);
            printf("Kota/Kabupaten Pegawai    : ");fflush(stdin);gets(dt[urut].kota);
            printf("Alamat Pegawai            : ");fflush(stdin);gets(dt[urut].alamat);
            printf("Nomor Rumah Pegawai       : ");scanf("%i", &dt[urut].nomor);
            printf("Tanggal Lahir Pegawai     : ");scanf("%i", &dt[urut].tgl);
            do{
                printf("Bulan Lahir Pegawai [1-12]: ");scanf("%i", &dt[urut].bulan);
                if(dt[urut].bulan < 1 || dt[urut].bulan > 12){
                    printf("Bulan harus antara 1-12.\n\n");
                    cek = 1;
                }else{
                    cek = 0;
                }
            }while(cek != 0);
            printf("Tahun Lahir Pegawai       : ");scanf("%i", &dt[urut].tahunlahir);
            printf("Gaji Bulanan              : ");scanf("%f", &dt[urut].gaji);
            printf("Lulusan Tahun             : ");scanf("%i", &dt[urut].tahunlulus);
            urut++;
        }

        printf("\nData yang Anda input telah tersimpan.\n");
    }
}

void lihatData(){
    int i;
    printf("DATA PEGAWAI FAKULTAS TEKNOLOGI INFORMASI\n");
    for(i = 0; i < dat; i++){
        printf("\nData ke-%i\n", i+1);
        printf("Nama Pegawai              : %s\n", dt[i].nama);
        printf("Nomor Induk Pegawai       : %s\n", dt[i].nomorind);
        printf("Posisi Pegawai            : %s\n", dt[i].posisi);
        printf("Kota/Kabupaten Pegawai    : %s\n", dt[i].kota);
        printf("Alamat Pegawai            : %s\n", dt[i].alamat);
        printf("Nomor Rumah Pegawai       : %i\n", dt[i].nomor);
        printf("Tanggal Lahir Pegawai     : %i\n", dt[i].tgl);
        printf("Bulan Lahir Pegawai       : %i\n", dt[i].bulan);
        printf("Tahun Lahir Pegawai       : %i\n", dt[i].tahunlahir);
        printf("Gaji Bulanan              : Rp %.2f\n", dt[i].gaji);
        printf("Lulusan Tahun             : %i\n", dt[i].tahunlulus);
    }
}

void main()
{
    int menu;
    do{
        printf("MENU\n-----------------\n");
        printf("1. Isi Data\n");
        printf("2. Lihat Data\n");
        printf("3. Keluar\n");
        printf("Pilihan: ");scanf("%i", &menu);
        switch(menu){
            case 1: system("cls");isiData();getch();system("cls");break;
            case 2: system("cls");lihatData();getch();system("cls");break;
            case 3: exit(0);break;
            default:
                printf("Maaf, pilihan Anda tidak ada\n");getch();system("cls");break;
        }

    }while(menu != 3);
}
