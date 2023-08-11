#include<stdio.h>
int is_valid(int base){
    return (base<=16&&base>=2)?1:0;
}
int Get_Number_And_Base(int number,int base){
    int c_number=number;
    int res=0;
    int a=1;
    while (c_number>0)
    {
        int rem=c_number%base;
        res=res+rem*a;
        c_number/=base;
        a*=10;
    }
    return res; 
}


int main(){
    int number,base;
    scanf(" %d %d", &number, &base);
    if(!is_valid(base)){
        printf("Base not within proper range!\n");
    }
    else printf("%d",Get_Number_And_Base(number,base));
    return 0;
}