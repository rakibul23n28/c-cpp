//O(n^2)

#include<iostream>

void optimizedbubbleSort(int* arr,int n){
    int temp;
    bool flag;
    for(int i=0;i<n;i++){
        flag=false;
        for (int j = 0; j < n-i-1; j++)
        {
            if(arr[j]>arr[j+1]){
                flag=true;
                 temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        } 
            if(flag==false) break;
    }
    for(int i=0;i<n;i++){
        std::cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    std::cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    optimizedbubbleSort(arr,n);
    return 0;
}