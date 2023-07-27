#include<stdio.h>
int main(){
    printf("Enter M X N: ");
    int x,y,temp;
    scanf(" %d %d",&x,&y);
    int arr[x][y];
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            scanf(" %d",&arr[i][j]);
        }

    }
    for(int i=0;i<x;i++){
         for (int j = 0; j < y / 2; j++) {
            temp = arr[i][j];
            arr[i][j] = arr[i][y-j-1];
            arr[i][y - j - 1] = temp;
        }
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");

    }

    return 0;
}