#include<stdio.h>
int main(){
    int n;
    scanf(" %d", &n);

    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }
    int queen;
    scanf(" %d", &queen);
    int x,y;
    while (queen--)
    {
        scanf(" %d %d", &x, &y);
        arr[x][y]=1;
    }
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==1){
                int count=0;
                for(int k=j-1;k>=0;k--){
                    if(arr[i][k]==1){
                        count++;
                        break;
                    }
                }
                 for(int k=j+1;k<n;k++){
                    if(arr[i][k]==1){
                        count++;
                        break;
                    }
                }
                 for(int k=i-1;k>=0;k--){
                    if(arr[k][j]==1){
                        count++;
                        break;
                    }
                }
                for(int k=i+1;k<n;k++){
                    if(arr[k][j]==1){
                        count++;
                        break;
                    }
                }
                int a=i-1;
               for(int k=j-1;k>=0;k--){
                    if(arr[a][k]==1){
                        count++;
                        break;
                    }
                    a--;
                }
                a=i+1;
                  for(int k=j+1;k<n;k++){
                    if(arr[a][k]==1){
                        count++;
                        break;
                    }
                    a++;
                }
                  a=i-1;
               for(int k=j+1;k>=0;k--){
                    if(arr[a][k]==1){
                        count++;
                        break;
                    }
                    a--;
                }
                a=i+1;
                  for(int k=j-1;k<n;k++){
                    if(arr[a][k]==1){
                        count++;
                        break;
                    }
                    a++;
                }
                printf("%d\n",count);
            }
        }
    }
    
    return 0;    
}