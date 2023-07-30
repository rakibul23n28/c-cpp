#include<stdio.h>
int main(){
    printf("Enter n: ");
    int x,sum=0;
    scanf(" %d",&x);
    int arr[x][x];
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            scanf(" %d",&arr[i][j]);
        }

    }
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            if(i==0 || i==(x-1) || i==j|| (x-i-1)==j) sum=sum+arr[i][j];
        }
    }
    printf("sum of the integers at first row, last row and two diagonals without overlap: %d ",sum);
    return 0;
}