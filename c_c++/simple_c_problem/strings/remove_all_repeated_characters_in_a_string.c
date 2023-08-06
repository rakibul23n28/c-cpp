#include <stdio.h>
int main() {
    char input[1000];
    scanf(" %[^\n]", input);

    int i,j,k;
    int count=0;
    for (i = 0;input[i]!='\0'; i++) {
        for (j = i+1;input[j]!='\0'; j++) {
            if(input[i]==input[j]){
                for( k=j;input[k]!='\0';k++){
                    input[k]=input[k+1];
                }
                j--;
            }
        }
    }
    printf("%s",input);
    return 0;
}