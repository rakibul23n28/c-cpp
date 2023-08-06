#include<stdio.h>
int main(){
    char str1[100];
    scanf(" %[^\n]", str1);
    int count=0,space=0;
    for(int i=0;str1[i]!='\0';i++){
        count++;
        if(str1[i]==' '&&str1[i+1]!=' '&&str1[i+1]!='\0') space++;
    }
    printf("%d",space+1);
    return 0;
}