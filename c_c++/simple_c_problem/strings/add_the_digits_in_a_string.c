#include <stdio.h>

int main() {
    char input[100];
    scanf("%[^\n]", input);
    int i;
    int num;
    int sum=0;
    for (i = 0;input[i]!='\0'; i++) {
        if(input[i]>='0'&&input[i]<='9') {
            num=input[i]-'0';
            sum+=num;
        }
    }
    printf("%d",sum);
    return 0;
}