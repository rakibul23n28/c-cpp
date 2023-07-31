//O(n^2)

#include<iostream>

void insertionSort(int* arr,int n){
    int key;
    for(int i=1;i<n;i++){
        int j=i-1;
        key=arr[i];
        while(j>=0 && key<arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        
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
    insertionSort(arr,n);
    return 0;
}