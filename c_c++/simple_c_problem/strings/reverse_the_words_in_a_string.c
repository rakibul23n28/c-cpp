#include <stdio.h>
#include <string.h>

void reverseWord(char word[]) {
    int start = 0;
    int end = strlen(word) - 1;
    char temp;
    while (start < end) {
        temp = word[start];
        word[start] = word[end];
        word[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char input[1000];
    printf("Enter a string: ");
    scanf("%[^\n]", input);
    char temp[1000];
    int i, j = 0,k=0;
    for(int i=0;i<=strlen(input);i++){
        if(input[i]==' '||input[i]=='\0'){
            temp[j]='\0';
            reverseWord(temp);
            for (int l = 0; temp[l] != '\0'; l++) input[k++]=temp[l];
            if (input[i] == ' ') {
                input[k++] = ' ';
            }
            j=0;
        }
        else{
            temp[j]=input[i];
            j++;
        }
    }
                printf("%s ", input);
    printf("\n");
    return 0;
}
