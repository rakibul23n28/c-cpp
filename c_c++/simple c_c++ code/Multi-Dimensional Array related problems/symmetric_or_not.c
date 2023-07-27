#include<stdio.h>
int main(){
    printf("Enter N: ");
    int x,t=1;
    scanf(" %d",&x);
    int arr[x][x];
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            scanf(" %d",&arr[i][j]);
        }

    }
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            if(arr[i][j]!=arr[j][i]) t=0;
        }

    }
    if(t) printf("YES\n");
    else printf("NO");

    return 0;
}