#include <stdio.h>

int main() {
    char input[100];
    scanf("%[^\n]", input);
    int length = strlen(input);
    int i, j;

    for (i = 0;input[i]!='\0'; i++) {
        if(input[i]>='a'&&input[i]<='z') input[i]=input[i]-32;
    }

    printf("%s\n", input);

    return 0;
}
