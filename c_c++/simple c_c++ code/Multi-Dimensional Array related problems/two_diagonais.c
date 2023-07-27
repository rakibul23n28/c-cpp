#include<stdio.h>
int main(){
    printf("Enter n: ");
    int x;
    scanf(" %d",&x);
    int arr[x][x];
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
                scanf(" %d",&arr[i][j]);
        }

    }
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
        printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\nMajor diagonal : ");
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            if(i==j) printf(" %d ",arr[i][j]);
        }
    }
    printf("\nMinor diagonal : ");
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            if(x-i-1==j) printf(" %d ",arr[i][j]);
        }

    }
    return 0;
}