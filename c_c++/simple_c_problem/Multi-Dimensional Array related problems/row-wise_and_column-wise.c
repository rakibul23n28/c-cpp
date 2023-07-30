#include<stdio.h>
int main(){
    int x,y;
    scanf(" %d %d",&x,&y);
    int arr[x][y];
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            scanf(" %d",&arr[i][j]);
        }

    }
    printf("row_wise : ");
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
        printf("%d ",arr[i][j]);
        }
    }
    printf("\n"); 
    printf("column_wise : ");
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
        printf("%d ",arr[j][i]);
        }

    }
    return 0;
}