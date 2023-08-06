#include<stdio.h>
int main(){
    char words[100];
    scanf(" %[^\n]",words);
    int count=0;
    for(int i=0;words[i]!='\0';i++){
        count++;
    }
    printf("%d",count);
    return 0;
}