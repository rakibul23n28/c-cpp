//O(n^2)

#include<iostream>

void selectionSort(int* arr,int n){
    int temp;
    for(int i=0;i<n-1;i++){
        int min=i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min !=i){
            temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
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
    selectionSort(arr,n);
    return 0;
}