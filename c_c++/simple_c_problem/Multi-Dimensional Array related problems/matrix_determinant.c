#include<stdio.h>
int main(){
    int x=3,y=3;
    // scanf(" %d %d",&x,&y);
    int arr[x][y];
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            scanf(" %d",&arr[i][j]);
        }

    }
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
        printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    int a,b,c;
    a=arr[1][1]*arr[2][2]-arr[1][2]*arr[2][1];
    b=arr[1][0]*arr[2][2]-arr[1][2]*arr[2][0];
    c=arr[1][0]*arr[2][1]-arr[1][1]*arr[2][0];
    int result=arr[0][0]*a-arr[0][1]*b+arr[0][2]*c;
    printf("determinant: %d",result);
    return 0;
}