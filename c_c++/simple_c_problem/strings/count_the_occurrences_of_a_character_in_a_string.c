#include <stdio.h>

int main() {
    char input[100];
    char ch;
    scanf("%[^\n]", input);
    scanf(" %c", &ch);
    int count=0;

    for (int i = 0;input[i]!='\0'; i++) {
        if(ch==input[i]) count++;
    }

    printf("%d\n", count);

    return 0;
}