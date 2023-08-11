#include<stdio.h>
void ShowMatrix(int x,int y,int (*matrix)[y]){
    printf("Original:\n");
     for (int  i=0;i<x;i++)
    {
        for(int j=0;j<y;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}
void ScalarMultiply(int x,int y,int (*matrix)[y],int value){
     for (int  i=0;i<x;i++)
    {
        for(int j=0;j<y;j++){
            matrix[i][j]=matrix[i][j]*value;
        }
    }
    printf("Multiplied by %d:\n",value);
    for (int  i=0;i<x;i++)
    {
        for(int j=0;j<y;j++){
            printf("%-3d ",matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int x,y;
    scanf("%d %d", &x, &y);
    int matrix[x][y];
    for (int  i=0;i<x;i++)
    {
        for(int j=0;j<y;j++){
            scanf(" %d", &matrix[i][j]);
        }
    }
    int value;
    scanf(" %d", &value);
    ShowMatrix(x,y,matrix);
    ScalarMultiply(x,y,matrix,value);

    
    return 0;
}