#include <stdio.h>

int main() {
    char input[100];
    scanf("%[^\n]", input);
    int i, j;

    for (i = 0;input[i]!='\0'; i++) {
        if(input[i]>='a'&&input[i]<='z') input[i]=input[i]-32;
        else if(input[i]>='A'&&input[i]<='Z') input[i]=input[i]+32;
    }

    printf("%s\n", input);

    return 0;
}
