#include<stdio.h>
int length(char* word){
    int count=0;
    for(int i=0;word[i]!='\0';i++){
        count++;
    }
    return count;
}
int find_substr(char* input,char* sub_string){
    int len_input=length(input);
    int len_sub=length(sub_string);
    for(int i=0;i<=(len_input-len_sub);i++){
        int flag=1;
        for(int j=0;j<len_sub;j++){
            if(sub_string[j]!=input[i+j]) flag=0;
        }
        if(flag) return 1;
    }
    return 0;
}
int main(){
    char input[100];
    char sub_string[100];
    scanf(" %[^\n]", input);
    scanf(" %[^\n]", sub_string);
    printf("%d",find_substr(input,sub_string));
}