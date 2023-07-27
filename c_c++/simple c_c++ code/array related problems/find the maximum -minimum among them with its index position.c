
#include<stdio.h>
int main(){
    int x;
    scanf(" %d", &x);
    int arr[x];
    int max,maxindex=0,min,minindex=0;
    for(int i=0;i<x;i++) {
            scanf(" %d",&arr[i]);
    }
    max=arr[0];
    min=arr[0];
    for (int i = 0; i < x ; i++) {
        if(max<arr[i]){
            max=arr[i];
            maxindex=i;
        }
        if(min>arr[i]){
            min=arr[i];
            minindex=i;
        }
    }
    printf("max:%d,index: %d\n",max,maxindex);
    printf("min:%d,index: %d",min,minindex);
    return 0;
}

