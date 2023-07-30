
#include<stdio.h>
int main(){
    int x,i,t=1;
    scanf(" %d", &x);
    int arr[x];
    for(int i=0;i<x;i++) {
            scanf(" %d",&arr[i]);
    }
    int y;
    scanf(" %d", &y);
    for (i = 0; i < x ; i++) {
        if(arr[i]==y) {
                printf("%d ",i);
                t=0;

        }
    }
    if(t) printf("NOT FOUND");
    return 0;
}



