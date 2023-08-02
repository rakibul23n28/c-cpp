// Online C++ compiler to run C++ program online
#include <iostream>

int main() {
    int n;
    std::cin>>n;
    int temp=1;
    int col_leng=n/2+1;
    
    int flag=1;
    for(int i=1;i<=col_leng;i++){
        for( int j=1;j<=i;j++){
            if(flag){
                std::cout<<temp;
                temp++;
                if(temp==n) {
                    flag=0;
                }
            }
            else{
                 std::cout<<temp;
                temp--;
                if(temp==1) {
                    flag=1;
                }
            }
        }
        for(int j=i;j<n/2+1;j++) std::cout<<"$";
        std::cout<<std::endl;
    }
        for(int i=col_leng+1;i<=n;i++){
        for( int j=i;j<=n;j++){
            if(flag){
                std::cout<<temp;
                temp++;
                if(temp==n) {
                    flag=0;
                }
            }
            else{
                 std::cout<<temp;
                temp--;
                if(temp==1) {
                    flag=1;
                }
            }
        }
        std::cout<<std::endl;
    }

    return 0;
}
