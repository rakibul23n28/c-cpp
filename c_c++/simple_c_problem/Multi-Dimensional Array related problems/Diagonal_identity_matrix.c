#include <stdio.h>
int main() {
    int x,y;
    scanf(" %d %d", &x,&y);

    int matrix[x][y];
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    int is_Diagonal=1;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(i!=j && matrix[i][j]!=0) is_Diagonal=0;
        }
    }
    int is_Identity=1;
    for(int i=0;i<x;i++){
        if(matrix[i][i]!=1) is_Identity=0;
    }
    if(is_Diagonal){
        printf("Diagonal Matrix\n");
        if(is_Identity) printf("Identity Matrix\n");
        else printf("Not an Identity Matrix\n");
    }
    else  printf("Not a Diagonal Matrix\n");
    return 0;
}
