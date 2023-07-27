#include<stdio.h>
int main(){
    int x,sum=0;
    scanf(" %d", &x);
    int arr[x];
    for(int i=0;i<x;i++) {
            scanf(" %d",&arr[i]);
            if(arr[i]%2==0)
                sum=sum+arr[i];
    }
    printf("%d ",sum);
    return 0;
}

