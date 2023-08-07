#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    scanf("%[^\n]", input);
    int count[256]={0};
    int len=strlen(input);
    for (int i=0;i<len;i++) {
        count[input[i]]++;
    }
    char maxChar;
    int maxCount = 0;
    for (int i=0;i<256;i++) {
        if (count[i]>maxCount) {
            maxChar=i;
            maxCount=count[i];
        }
    }

    printf("'%c' \n", maxChar);
    return 0;
}
