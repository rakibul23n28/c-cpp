
#include<stdio.h>
int main(){
    int x,i,t=1;
    scanf(" %d", &x);
    int arr[x],arr2[x];
    for(int i=0;i<x;i++) {
            scanf(" %d",&arr[i]);
    }
    for (i = 0; i < x ; i++) {
        arr2[i]=arr[x-1-i];
    }
    for (i = 0; i < x ; i++) {
        printf("%d ",arr2[i]);
    }
    return 0;
}


