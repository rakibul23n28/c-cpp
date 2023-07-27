#include<stdio.h>
int main(){
    int n,j;
    scanf(" %d",&n);
    int nc=n;
    j=1;
    for(int i=1;i<=n;i++){
        while(nc-n<n) {
            if(j%2==0){
                printf("0",j);
            }
            else printf("1",j);
            nc++;
            j++;
        }
        printf("\n");
        nc=n;
    }
    return 0;
}
