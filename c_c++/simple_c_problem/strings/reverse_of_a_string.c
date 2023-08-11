#include <stdio.h>
#include<string.h>
int main() {
    char input[100];
    scanf("%[^\n]", input);
    int length=strlen(input);
    int i,j;
    for (i=0,j=length-1;i<j;i++,j--) {
        char temp=input[i];
        input[i]=input[j];
        input[j]=temp;
    }
    printf("%s\n",input);
    return 0;
}
