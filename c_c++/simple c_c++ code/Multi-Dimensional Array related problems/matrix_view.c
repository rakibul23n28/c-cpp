#include<stdio.h>
int main(){
    printf("Enter rows and coluom: ");
    int x,y;
    scanf(" %d %d",&x,&y);
    int arr[x][y];
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
                scanf(" %d",&arr[i][j]);
        }

    }
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
        printf(" %d ",arr[i][j]);
        }
        printf("\n"); 

    }
    return 0;
}