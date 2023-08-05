#include<iostream>

void shellSort(int* arr,int arr_size){
    for(int gap=arr_size/2;gap>0;gap/=2){
        for(int j=gap;j<arr_size;j++){
            int temp=arr[j];
            int i;
            for(i=j;i>=gap && arr[i-gap]>temp;i-=gap){
                arr[i]=arr[i-gap];
            }
            arr[i]=temp;
        }
    }
}


int main(){
    int arr_size;
    std::cin>>arr_size;
    int arr[arr_size];
    for(int i=0;i<arr_size;i++){
        std::cin>>arr[i];
    }
    shellSort(arr,arr_size);
    for(int i=0;i<arr_size;i++) std::cout<<arr[i] <<" ";
    return 0;
}