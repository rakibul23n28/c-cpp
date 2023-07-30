#include<stdio.h>
int main(){
    printf("Enter n: ");
    int x,sum=0;
    scanf(" %d",&x);
    int arr1[x][x],arr2[x][x],arr3[x][x];

    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            scanf(" %d",&arr1[i][j]);
        }

    }
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            scanf(" %d",&arr2[i][j]);
        }

    }
    for(int i=0;i<x;i++){
        for(int k=0;k<x;k++){
            for(int j=0;j<x;j++){
                sum=sum+arr1[i][j]*arr2[j][i];
            }
            arr3[i][k]=sum;
            sum=0;
        }
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
        printf("%d ",arr3[i][j]);
        }
        printf("\n");
    }
    return 0;
}