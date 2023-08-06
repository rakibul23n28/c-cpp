#include<stdio.h>
int main(){
    char str1[100];
    char str2[100];
    char res[200];
    scanf(" %[^\n]", str1);
    scanf(" %[^\n]", str2);
    int i=0,j=0;
    while(str1[i]!='\0'){
        res[j]=str1[i];
        j++;
        i++;
    }
    i=0;
     while(str2[i]!='\0'){
        res[j]=str2[i];
        j++;
        i++;
    }
    res[j]='\0';
    printf("%s",res);
    return 0;
}