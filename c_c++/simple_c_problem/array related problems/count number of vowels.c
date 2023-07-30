
#include<stdio.h>
int main(){
    int x,count=0;
    scanf(" %d", &x);
    char arr[x];
    for(int i=0;i<x;i++) {
            scanf(" %c",&arr[i]);
    }
    for(int i=0;i<x;i++) {
            if(arr[i]=='a' || arr[i]=='A' || arr[i]=='e' || arr[i]=='E' || arr[i]=='i' || arr[i]=='I' || arr[i]=='o' || arr[i]=='O' || arr[i]=='u' || arr[i]=='U'){
                count++;
            }
    }
    printf("Count :%d",count);

    return 0;
}


