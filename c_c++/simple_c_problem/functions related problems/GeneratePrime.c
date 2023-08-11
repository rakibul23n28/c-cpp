
#include <stdio.h>

void generatePrime(int n){
    printf("Prime less then %d:",n);
    for(int i=2;i<n;i++){
        int flag=1;
        for(int j=2;j<i;j++){
            if(i%j==0) flag=0;
        }
        if(flag) printf("%d ",i);
    }
}

int main()
{
    int n;
    scanf(" %d",&n);
    generatePrime(n);

    return 0;
}