#include <stdio.h>
int main() {
    char input[1000];
    char word[100];
    scanf(" %[^\n]", input);
    scanf(" %[^\n]", word);

    int i,j;
    int count=0;
    for (i = 0;input[i]!='\0'; i++) {
        int found = 1;
        for (j = 0;word[j]!='\0'; j++) {
            if (input[i + j] != word[j]) {
                found = 0;
                break;
            }
        }
        if(found) count++;
    }
    printf("%d",count);
    return 0;
}