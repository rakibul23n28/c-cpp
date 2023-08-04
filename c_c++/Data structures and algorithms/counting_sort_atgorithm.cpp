//O(n+k)
#include<iostream>
// #include <cstring>
#include <algorithm>
void countingSort(int* arr, int arr_size) {
    int maxi=arr[0];
    int mini=arr[0];
    for(int i=1;i<arr_size;i++){
        maxi=std::max(maxi,arr[i]);
        mini=std::min(mini,arr[i]);
    }
    int range = maxi-mini+1;
    int* out_arr=new int[arr_size];
    int* count=new int[range]{0};
    for(int i=0;i<arr_size;i++){
        count[arr[i]-mini]++;
    }
    for(int i=1;i<range;i++){
        count[i]+=count[i-1];
    }
    for (int i = arr_size - 1; i >= 0; i--) {
        out_arr[--count[arr[i] - mini]] = arr[i];
    }
    for(int i=0;i<arr_size;i++){
        arr[i]=out_arr[i];
    }

    delete[] count;
    delete[] out_arr;
}

int main(){
    int n;
    std::cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    countingSort(arr,n);
    for(int i=0;i<n;i++) std::cout<<arr[i] <<" ";
    return 0;
}