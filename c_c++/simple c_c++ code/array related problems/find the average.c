
#include<stdio.h>
int main(){
    int x,sum=0;
    scanf(" %d", &x);
    int arr[x];
    for(int i=0;i<x;i++) {
            scanf(" %d",&arr[i]);
            sum=sum+arr[i];
    }
    printf("%.2f ",1.0*sum/x);
    return 0;
}

