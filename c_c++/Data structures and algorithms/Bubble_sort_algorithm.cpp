//O(n^2)

#include<iostream>

void bubbleSort(int* arr,int n){
    int temp;
    for(int i=0;i<n;i++){
        for (int j = 0; j < n-i-1; j++)
        {
            if(arr[j]>arr[j+1]){
                 temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        } 
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
    bubbleSort(arr,n);
    return 0;
}