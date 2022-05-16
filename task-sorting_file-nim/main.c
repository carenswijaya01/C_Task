#include <stdio.h>
#include <stdlib.h>

FILE *fp;
char ch;

struct mahasiswa{
    int nim;
}mhs[20];

//bubble sort
void bubbleSort(){
    int i, j;
    struct mahasiswa temp;
    for(i = 0; i < 20-1; i++){
        for(j = 0; j < (20-1-i); j++){
            int a = mhs[j].nim;
            int b = mhs[j+1].nim;
            if (a > b){
                temp = mhs[j];
                mhs[j] = mhs[j+1];
                mhs[j+1] = temp;
            }
        }
    }
}

//selection sort
void selectionSort(){
  int i, j, posisi, swap;
  for(i = 0; i < (20-1); i++){
    posisi = i;
    for (j = i + 1; j < 20; j++){
      if(mhs[posisi].nim > mhs[j].nim){
        posisi = j;
      }
    }
    if(posisi != i){
      swap = mhs[i].nim;
      mhs[i].nim = mhs[posisi].nim;
      mhs[posisi].nim = swap;
    }
  }
}

//insertion sort
void insertionSort(){
	int i, j,temp;
	for (i = 1; i < 20; i++){
        //temp = mhs[i].nim;
    	j = i;
    	while(j > 0 && mhs[j-1].nim > mhs[j].nim){
    	  temp = mhs[j].nim;
    	  mhs[j].nim = mhs[j-1].nim;
    	  mhs[j-1].nim = temp;
    	  j--;
    	}
  	}
}

//insertion sort
/*void insertionSort()
{
    int i, element, j;
    for (i = 1; i < 20; i++) {
        element = mhs[i].nim;
        j = i - 1;
        while (j >= 0 && mhs[j].nim > element) {
            mhs[j + 1].nim = mhs[j].nim;
            j = j - 1;
        }
        mhs[j + 1].nim = element;
    }
}*/

void cetak_data(){
	fp=fopen("data.txt", "w+");
   	for(int i = 0; i < 20; i++){
       fprintf(fp, "%d\n", mhs[i].nim);
    }
    fclose(fp);
}

int main()
{
    //buka file
    fp = fopen("data.txt", "r");

    //baca isi file
    for(int i = 0; i < 20; i++){
        fscanf(fp, "%d", &mhs[i].nim);
    }

    //cek print sebelum
    printf("SEBELUM DI SORTING\n");
    for(int i = 0; i < 20; i++){
        printf("%d\n", mhs[i].nim);
    }

    //sorting
    //bubbleSort();
    //selectionSort();
    insertionSort();

    //cek print sesudah
    printf("SESUDAH DI SORTING\n");
    for(int i = 0; i < 20; i++){
        printf("%d\n", mhs[i].nim);
    }

    cetak_data();

    fclose(fp);

    return 0;
}
