#include <stdio.h>

void GenNthPrime(int n){
    printf("%dth Prime::",n);
    int count=0;
    int i=2;
    while(i){
        int flag=1;
        for(int j=2;j<i;j++){
            if(i%j==0) flag=0;
        }
        if(flag) count++;
        if(count==n) {
            printf("%d",i);
            return;
        }
        i++;
    }
}

int main()
{
    int n;
    scanf(" %d",&n);
    GenNthPrime(n);

    return 0;
}