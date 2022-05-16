#include <stdio.h>
#include <stdlib.h>

void main()
{
    int i,j,A[3][4],B[4][5],C[3][3];

    printf("ARRAY A (3X4) : \n");
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            scanf("%d",&A[i][j]);
        }
    }

    printf("\nARRAY B (4X5) : \n");
    for(i=0;i<4;i++){
        for(j=0;j<5;j++){
            scanf("%d",&B[i][j]);
        }
    }

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(A[i][j]%2==0){
				if(j==0){
					if(A[i][1]%2==0){
						C[i][0]=(A[i][0]*B[i][0]+A[i][0]*B[i][2]+A[i][0]*B[i][4]) + (A[i][1]*B[i][0]+A[i][1]*B[i][2]+A[i][1]*B[i][4]);
					}else{
						C[i][0]=(A[i][0]*B[i][0]+A[i][0]*B[i][2]+A[i][0]*B[i][4]) + (A[i][1]*B[i][1]+A[i][1]*B[i][3]);
					}
				}else{
					if(A[i][j+1]%2==0){
						C[i][j]=(A[i][j+1]*B[i][0]+A[i][j+1]*B[i][2]+A[i][j+1]*B[i][4]);
					}else{
						C[i][j]=(A[i][j+1]*B[i][1]+A[i][j+1]*B[i][3]);
					}
				}
			}else{
				if(j==0){
					if(A[i][1]%2==0){
						C[i][0]=(A[i][0]*B[i][1]+A[i][0]*B[i][3]) + (A[i][1]*B[i][0]+A[i][1]*B[i][2]+A[i][1]*B[i][4]);
					}else{
						C[i][0]=(A[i][0]*B[i][1]+A[i][0]*B[i][3]) + (A[i][1]*B[i][1]+A[i][1]*B[i][3]);
					}
				}
				else{
					if(A[i][j+1]%2==0){
						C[i][j]=(A[i][j+1]*B[i][0]+A[i][j+1]*B[i][2]+A[i][j+1]*B[i][4]);
					}else{
						C[i][j]=(A[i][j+1]*B[i][1]+A[i][j+1]*B[i][3]);
					}
				}
			}
		}
	}

    printf("\nOUPUT (3X3) : \n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }

}
