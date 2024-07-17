#include<iostream>
#include<algorithm>


int returnMidvalueoutof3value(int* arr){
    std::sort(arr,arr+3);
    return arr[1];
}

int main(){

    int t;
    std::cin>> t;
    while(t--){
        int n;
        std::cin>>n;
        int arr[n][3];
        for(int i=0;i<n;i++){
            std::cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
        }

        for(int i=0;i<n;i++){
            int value = returnMidvalueoutof3value(arr[i]);
            std::cout<<abs(arr[i][0] - value) + abs(arr[i][1] - value) + abs(arr[i][2] - value)<<std::endl;
        }
    }
    return 0;
}