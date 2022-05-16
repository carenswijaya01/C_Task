#include <stdio.h>
#include <stdlib.h>

void menu1(){
    int F, B, hasil=0;
    scanf("%d", &F);//10
    scanf("%d", &B);
    for(int i=F; i <= B; i++){
        if(i%10 == 3 || i%10==4){
            hasil++;
        }
    }
    printf("%d", hasil);
}

void menu2(){
    int T, N;
    scanf("%i", &T);
    for(int i = 0; i < T; i++){
        //minta inputan N
        scanf("%i", &N);

        //cetak 3 angka ganjil
        for(int j = 0; j < 3; j++){
            if(N%2==0){
                //genap
                N++;
            }else{
                //ganjil
                N+=2;
            }
            printf("%i ", N);
        }
        printf("\n");
    }
}

void menu3(){
    int M, N, E, hasil = 0;
    scanf("%i", &M);//pembagi
    scanf("%i", &N);//jumlah tc
    for(int i = 0; i < N; i++){
        scanf("%i", &E);
        hasil = hasil + (E%M);
    }
    printf("%i", hasil);
}

void menu4(){
    int X, Y, K;
    scanf("%i", &X);
    scanf("%i", &Y);
    scanf("%i", &K);
    for(int i = 1; i <= K; i++){
        if(i%X==0 && i%Y==0){
            printf("BOMDUARR");
        }else if(i%X==0){
            printf("BOM");
        }else if(i%Y==0){
            printf("DUAR");
        }else{
            printf("%i", i);
        }
        printf("\n");
    }
}

void menu5(){
    int N;
    scanf("%i", &N);
    if(N < 1 || N > 6){
        printf("Ga Sesuai Batasan\n");
    }else{
        for(int i=0; i < N; i++){
            for(int j = 0; j < N+3; j++){
                printf("%i", j+1);
                if(i==j){
                    printf("**");
                    j+=2;
                }
            }
            printf("\n");
        }
    }
}

int main()
{
    //menu1();
    //menu2();
    //menu3();
    //menu4();
    menu5();
    return 0;
}
