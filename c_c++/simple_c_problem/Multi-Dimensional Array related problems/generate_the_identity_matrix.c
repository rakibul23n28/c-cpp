#include<stdio.h>
int main(){
    printf("Enter n: ");
    int x;
    scanf(" %d",&x);
    int arr[x][x];
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
                if(i==j) arr[i][j]=1;
                else arr[i][j]=0;
        }

    }
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
        printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}