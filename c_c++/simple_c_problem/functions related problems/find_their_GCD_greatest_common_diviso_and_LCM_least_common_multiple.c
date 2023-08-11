#include<stdio.h>
int LCM(int num1,int num2){
    int result=1;
    for(int i=1;i<num1&&i<num2;i++){
        if(num1%i==0&&num2%i==0) result=i;
    }
    return result;
}
int GCD(int num1,int num2){
    int result=1;
    int i=1;
    while(1){
        if(i%num1==0&&i%num2==0){
            return i;
        }
        i++;
    }
}

int main(){
    int num1,num2;
    scanf(" %d %d", &num1, &num2);
    printf("%d\n",LCM(num1,num2));
    printf("%d\n",GCD(num1,num2));
}