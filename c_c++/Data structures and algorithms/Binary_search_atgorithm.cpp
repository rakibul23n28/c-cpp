#include<iostream>

void binarySearch(int* arr,int n,int num){
    int start=0;
    int end=n-1;
    int mid;
    while(start<=end){
        mid=start +(end-start)/2;
        if(num==arr[mid]){
            std::cout<<"found on index: "<<mid<<std::endl;
            return;
        }
        else if(arr[mid]<num){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        
    }
    std::cout<<"Not found"<<std::endl;
}

int main(){
    int n;
    std::cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    int search_element;
    std::cin>>search_element;
    binarySearch(arr,n,search_element);

    return 0;
}