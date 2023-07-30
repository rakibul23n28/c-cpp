
#include<stdio.h>
int main(){
    int x,temp;
    scanf(" %d", &x);
    int arr1[x];
    for(int i=0;i<x;i++) {
            scanf(" %d",&arr1[i]);
    }
    int y;
    scanf(" %d", &y);
    int arr2[y];
    for(int i=0;i<y;i++) {
            scanf(" %d",&arr2[i]);
    }
    arr1[y];
    arr2[x];
    for (int i = 0; i < x ; i++) {
            temp=arr1[i];
        arr1[i]=arr2[i];
        arr2[i]=temp;
    }
    printf("arr1: ");
    for(int i=0;i<y;i++) {
            printf("%d ",arr1[i]);
    }
    printf("\narr2: ");
    for(int i=0;i<x;i++) {
            printf("%d ",arr2[i]);
    }
    return 0;
}

