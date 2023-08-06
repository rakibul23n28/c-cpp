#include <stdio.h>
#include<string.h>

int main() {
    char input[100];
    scanf("%[^\n]", input);
    int lenght=strlen(input);
    int i, j;
    int is_palindrome=1;
    for (i = 0,j=lenght-1;i<j; i++,j--) {
        if(input[i]!=input[j]) is_palindrome=0;
    }

    if(is_palindrome) printf("Yes");
    else  printf("No");

    return 0;
}