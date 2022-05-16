#include <stdio.h>
#include <stdlib.h>

struct identitas{
    int kamar, harga;
    char nama[30], jeniskelamin[10], alamat[30];
};

void sorting(struct identitas *ID, int bdata){
    int menu, a, b;
    do{
        system("cls");
        printf("1. Urutkan berdasarkan Nama\n");
        printf("2. Urutkan berdasarkan No Kamar\n");
        printf("3. Urutkan berdasarkan Jenis Kelamin\n");
        printf("4. Urutkan berdasarkan Alamat\n");
        printf("5. Urutkan berdasarkan Harga\n");
        printf("6. Kembali\n");
        scanf("%i", &menu);
        switch(menu){
            case 1:
                printf("");
                struct identitas tempNama;
                for(int i = 0; i < bdata-1; i++){
                    for(int j = 0; j < (bdata-1-i); j++){
                        if (strcmp(ID[j].nama, ID[j+1].nama) > 0){
                            tempNama = ID[j];
                            ID[j] = ID[j+1];
                            ID[j+1] = tempNama;
                        }
                    }
                }
                break;
            case 2:
                printf("");
                struct identitas tempNoKamar;
                for(int i = 0; i < bdata-1; i++){
                    for(int j = 0; j < (bdata-1-i); j++){
                        a = ID[j].kamar;
                        b = ID[j+1].kamar;
                        if (a > b){
                            tempNoKamar = ID[j];
                            ID[j] = ID[j+1];
                            ID[j+1] = tempNoKamar;
                        }
                    }
                }
                break;
            case 3:
                printf("");
                struct identitas tempJK;
                for(int i = 0; i < bdata-1; i++){
                    for(int j = 0; j < (bdata-1-i); j++){
                        if (strcmp(ID[j].jeniskelamin, ID[j+1].jeniskelamin) > 0){
                            tempJK = ID[j];
                            ID[j] = ID[j+1];
                            ID[j+1] = tempJK;
                        }
                    }
                }
                break;
            case 4:
                printf("");
                struct identitas tempAlamat;
                for(int i = 0; i < bdata-1; i++){
                    for(int j = 0; j < (bdata-1-i); j++){
                        if (strcmp(ID[j].alamat, ID[j+1].alamat) > 0){
                            tempAlamat = ID[j];
                            ID[j] = ID[j+1];
                            ID[j+1] = tempAlamat;
                        }
                    }
                }
                break;
            case 5:
                printf("");
                struct identitas tempHarga;
                for(int i = 0; i < bdata-1; i++){
                    for(int j = 0; j < (bdata-1-i); j++){
                        a = ID[j].kamar;
                        b = ID[j+1].kamar;
                        if (a > b){
                            tempHarga = ID[j];
                            ID[j] = ID[j+1];
                            ID[j+1] = tempHarga;
                        }
                    }
                }
                break;
            case 6:
                break;
            default:printf("Inputan Salah\n");break;
        }
        getch();
    }while(menu != 6);
}

void searching(struct identitas *ID, int bdata){
    int menu, ada;
    do{
        system("cls");
        printf("1. Cari berdasarkan Nama\n");
        printf("2. Cari berdasarkan No Kamar\n");
        printf("3. Cari berdasarkan Jenis Kelamin\n");
        printf("4. Cari berdasarkan Alamat\n");
        printf("5. Cari berdasarkan Harga\n");
        printf("6. Kembali\n");
        scanf("%i", &menu);
        switch(menu){
            case 1:
                printf("");
                char nama[30];
                printf("Cari Nama : ");fflush(stdin);gets(nama);
                ada = 0;
                for(int i = 0; i < bdata; i++){
                    if(strcmp(ID[i].nama, nama) == 0){
                        ada = 1;
                        printf("DATA KE - %i\n", i+1);
                        printf("Nama            : %s\n", ID[i].nama);
                        printf("Nomor Kamar     : %i\n", ID[i].kamar);
                        printf("Jenis Kelamin   : %s\n", ID[i].jeniskelamin);
                        printf("Alamat          : %s\n", ID[i].alamat);
                        printf("Harga           : %i\n\n", ID[i].harga);
                    }
                }

                if(ada == 0){
                    printf("Data Tidak Ditemukan\n");
                }
                break;
            case 2:
                printf("");
                int kamar;
                printf("Cari No Kamar : ");scanf("%i", &kamar);
                ada = 0;
                for(int i = 0; i < bdata; i++){
                    if(ID[i].kamar == kamar){
                        ada = 1;
                        printf("DATA KE - %i\n", i+1);
                        printf("Nama            : %s\n", ID[i].nama);
                        printf("Nomor Kamar     : %i\n", ID[i].kamar);
                        printf("Jenis Kelamin   : %s\n", ID[i].jeniskelamin);
                        printf("Alamat          : %s\n", ID[i].alamat);
                        printf("Harga           : %i\n\n", ID[i].harga);
                    }
                }

                if(ada == 0){
                    printf("Data Tidak Ditemukan\n");
                }
                break;
            case 3:
                printf("");
                char jeniskelamin[10];
                printf("Cari Jenis Kelamin : ");fflush(stdin);gets(jeniskelamin);
                ada = 0;
                for(int i = 0; i < bdata; i++){
                    if(strcmp(ID[i].jeniskelamin, jeniskelamin) == 0){
                        ada = 1;
                        printf("DATA KE - %i\n", i+1);
                        printf("Nama            : %s\n", ID[i].nama);
                        printf("Nomor Kamar     : %i\n", ID[i].kamar);
                        printf("Jenis Kelamin   : %s\n", ID[i].jeniskelamin);
                        printf("Alamat          : %s\n", ID[i].alamat);
                        printf("Harga           : %i\n\n", ID[i].harga);
                    }
                }

                if(ada == 0){
                    printf("Data Tidak Ditemukan\n");
                }
                break;
            case 4:
                printf("");
                char alamat[30];
                printf("Cari Nama : ");fflush(stdin);gets(alamat);
                ada = 0;
                for(int i = 0; i < bdata; i++){
                    if(strcmp(ID[i].alamat, alamat) == 0){
                        ada = 1;
                        printf("DATA KE - %i\n", i+1);
                        printf("Nama            : %s\n", ID[i].nama);
                        printf("Nomor Kamar     : %i\n", ID[i].kamar);
                        printf("Jenis Kelamin   : %s\n", ID[i].jeniskelamin);
                        printf("Alamat          : %s\n", ID[i].alamat);
                        printf("Harga           : %i\n\n", ID[i].harga);
                    }
                }

                if(ada == 0){
                    printf("Data Tidak Ditemukan\n");
                }
                break;
            case 5:
                printf("");
                int harga;
                printf("Cari Harga : ");scanf("%i", &harga);
                ada = 0;
                for(int i = 0; i < bdata; i++){
                    if(ID[i].harga == harga){
                        ada = 1;
                        printf("DATA KE - %i\n", i+1);
                        printf("Nama            : %s\n", ID[i].nama);
                        printf("Nomor Kamar     : %i\n", ID[i].kamar);
                        printf("Jenis Kelamin   : %s\n", ID[i].jeniskelamin);
                        printf("Alamat          : %s\n", ID[i].alamat);
                        printf("Harga           : %i\n\n", ID[i].harga);
                    }
                }

                if(ada == 0){
                    printf("Data Tidak Ditemukan\n");
                }
                break;
            case 6:break;
            default:printf("Inputan Salah\n");break;
        }
        getch();
    }while(menu != 6);
}

void main(){
    int menu;
    int jumlah_data, bdata;
    struct identitas *ID = malloc(jumlah_data*sizeof(struct identitas));
    do{
        system("cls");
        printf ("===================================================");
        printf ("\n");
        printf ("MENU");
        printf ("\n");
        printf ("===================================================");
        printf ("\n");
        printf ("1. buat data baru\n");
        printf ("2. lihat data\n");
        printf ("3. hapus data\n");
        printf ("4. edit data\n");
        printf ("5. mencari data pada kolom\n");
        printf ("6. mengurutkan data\n");
        printf ("7. riwayat aktivitas\n");
        printf ("8. exit\n");
        printf ("\n");
        printf ("==================================================");
        printf ("\n");
        printf ("pilih : ");
        scanf ("%d", &menu);
        printf ("==================================================");
        system("cls");

        switch (menu){
        case 1:
            system("cls");
            printf("Mau input berapa data? : ");scanf("%i", &jumlah_data);
            for(int i = 0; i < jumlah_data; i++){
                printf ("Nama : ");
                fflush(stdin);gets(ID[bdata].nama);
                printf ("Nomor kamar : ");
                scanf("%i", &ID[bdata].kamar);
                printf ("Jenis kelamin : ");
                fflush(stdin);gets(ID[bdata].jeniskelamin);
                printf ("alamat : ");
                fflush(stdin);gets(ID[bdata].alamat);
                printf ("harga : ");
                scanf("%i", &ID[bdata].harga);
                bdata++;
                printf("\n");
            }
            printf("%i", bdata);
            break;
        case 2:
            system("cls");
            printf ("==============================================\n");
            printf ("\nDaftar Data\n");
            printf ("=============================================\n");
            if (bdata == 0){
                printf("Belum ada data yang bisa ditampilkan!\n\n\n");
            }
            else{
                for(int i = 0; i < bdata; i++){
                    printf ("Nama          : %s\n",ID[i].nama);
                    printf ("Nomor kamar   : %i\n", ID[i].kamar);
                    printf ("Jenis kelamin : %s\n", ID[i].jeniskelamin);
                    printf ("alamat        : %s\n", ID[i].alamat);
                    printf ("harga         : %i\n\n", ID[i].harga);
                }
            }
            break;
        case 5:
            system("cls");
            searching(ID, bdata);
            break;
        case 6:
            system("cls");
            sorting(ID, bdata);
            break;
        }
        getch();
    }while(menu!=8);
}
