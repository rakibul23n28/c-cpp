
#include<stdio.h>
int main(){
    int x,sum=0;
    scanf(" %d", &x);
    int arr1[x],arr2[x],sumarr[x];
    for(int i=0;i<x;i++) {
            scanf(" %d",&arr1[i]);
    }
    for(int i=0;i<x;i++) {
            scanf(" %d",&arr2[i]);
    }
    for(int i=0;i<x;i++) {
            sumarr[i]=arr1[i]+arr2[i];
    }
    for(int i=0;i<x;i++) {
            printf("%d ",sumarr[i]);
    }
    return 0;
}


