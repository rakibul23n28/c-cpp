// 7
//    $   
//   $$$  
//  $ $ $ 
// $$$$$$$
//  $ $ $ 
//   $$$  
   $
#include<stdio.h>
int main(){
    int n;
    scanf(" %d", &n);
    for(int i=1;i<=n/2+1;i++){
         for(int j=1;j<=n;j++){
             if(j==n/2+1 || i==n/2+1|| j==n/2+2-i ||j==n/2+i ) printf("$");
           else printf(" ");
        }
        printf("\n");
    }
    for(int i=n/2;i>=1;i--){
         for(int j=1;j<n;j++){
             if(j==n/2+1 || i==n/2+1|| j==n/2+2-i ||j==n/2+i ) printf("$");
           else printf(" ");
        }
        printf("\n");
    }
    return 0;
}