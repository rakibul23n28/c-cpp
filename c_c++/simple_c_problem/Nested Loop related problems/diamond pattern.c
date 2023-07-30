// 1           1
// 12         21
// 123       321
// 1234     4321
// 12345   54321
// 123456 654321
// 1234567654321



#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
                printf("%d",j);

        }
        for(int j=(i*2-1);j<=(n*2-3);j++){
            printf(" ");
        }
        for(int j=i;j>=1;j--){
            if(j==7) printf("");
            else printf("%d",j);

        }
        printf("\n");
    }
    return 0;
}
