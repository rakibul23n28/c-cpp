#include<stdio.h>
int main(){
    printf("Enter n: ");
    int x,sum=0,sum2=0;
    scanf(" %d",&x);
    int arr[x][x];
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
                scanf(" %d",&arr[i][j]);
        }

    }
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            if(i==0||i==(x-1) || j==0 || j==(x-1)) sum=sum+arr[i][j];
            else sum2=sum2+arr[i][j];
        }
    }
    printf("border sum: %d\n",sum);
    printf("innerbox sum: %d\n",sum2);

    return 0;
}