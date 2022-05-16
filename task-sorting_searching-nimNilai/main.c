#include <stdio.h>
#include <stdlib.h>

struct data{
    int nim, nilai;
    char nama[50];
};

void sorting(struct data *sData, int jumlahData){
    int i, j;
    struct data temp;
    for(i = 0; i < jumlahData-1; i++){
        for(j = 0; j < (jumlahData-1-i); j++){
            int a = sData[j].nim;
            int b = sData[j+1].nim;
            if (a > b){
                temp = sData[j];
                sData[j] = sData[j+1];
                sData[j+1] = temp;
            }
        }
    }
}

int searching(struct data *sData, int yangDiCari, int jumlahData){
    int i;
    for(i = 0; i < jumlahData; i++){
        if(sData[i].nim == yangDiCari){
            break;
        }
    }
    return i;
}

int main()
{
    int i, j, jumlahData;
    printf("Masukkan jumlah data : ");scanf("%i", &jumlahData);


    //biar structnya fleksibel kayak list
    struct data *sData = malloc(jumlahData*sizeof(struct data));


    //ngeinput
    for(i = 0; i < jumlahData; i++){
        printf("\nData ke -%i\n", (i+1));
        printf("NIM    = ");scanf("%i", &sData[i].nim);
        printf("Nama   = ");fflush(stdin); gets(sData[i].nama);
        printf("Nilai  = ");scanf("%i", &sData[i].nilai);
        printf("\n");
    }


    //print awalan
    printf("=================================================================================================\n");
    printf("Sebelum di sorting\n");
    printf("\tNo\t|\tNIM\t\t|\tNama\t\t\t|\tNilai\t\t|\n");
    for(i = 0; i < jumlahData; i++){
        printf("\t%i\t|\t%i\t|\t%s\t\t|\t%i\t\t|\n", (i+1), sData[i].nim, sData[i].nama, sData[i].nilai);
    }
    printf("\n");


    //buat sorting
    sorting(sData, jumlahData);
    printf("=================================================================================================\n");
    printf("Sesudah di sorting\n");
    printf("\tNo\t|\tNIM\t\t|\tNama\t\t\t|\tNilai\t\t|\n");
    for(i = 0; i < jumlahData; i++){
        printf("\t%i\t|\t%i\t|\t%s\t\t|\t%i\t\t|\n", (i+1), sData[i].nim, sData[i].nama, sData[i].nilai);
    }
    printf("\n");


    //buat searching
    printf("=================================================================================================\n");
    int inputCari;
    printf("Data yang mau dicari : ");scanf("%i", &inputCari);
    int lokasiCari = searching(sData, inputCari, jumlahData);
    printf("\tNo\t|\tNIM\t\t|\tNama\t\t\t|\tNilai\t\t|\n");
    printf("\t%i\t|\t%i\t|\t%s\t\t|\t%i\t\t|\n", (lokasiCari+1), sData[lokasiCari].nim, sData[lokasiCari].nama, sData[lokasiCari].nilai);


    return 0;
}
