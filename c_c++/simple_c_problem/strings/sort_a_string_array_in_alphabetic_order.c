#include <stdio.h>
//insertion sort
int main() {
    char input[100];
    scanf("%[^\n]", input);
    int length = strlen(input);
    int i, j;

    for (i = 1;input[i]!='\0'; i++) {
        char key=input[i];
        j=i-1;
        while (j>=0&&input[j]>key)
        {
            input[j+1]=input[j];
            j--;
        }
        input[j+1]=key;
        
    }
    printf("%s\n", input);

    return 0;
}
