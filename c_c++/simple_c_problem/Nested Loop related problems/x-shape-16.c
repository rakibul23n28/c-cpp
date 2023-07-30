#include<stdio.h>
int main(){
    int n;
    scanf(" %d",&n);
    for(int i=1,ic=n;i<=n,ic>=1;i++,ic--){
        for(int j=n,jc=1;j>=1,jc<=n;j--,jc++){
            if(j==ic ||ic==jc ){
                printf("*");
            }
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}

