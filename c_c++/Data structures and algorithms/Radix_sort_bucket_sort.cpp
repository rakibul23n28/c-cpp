#include<iostream>

void countingSort(int * arr,int arr_size,int div,int mini){
    int range=10;
    int* count=new int[range]{0};
    int* out_arr=new int[arr_size];
    for(int i=0 ; i<arr_size;i++){
        count[((arr[i]-mini)/div)%10]++;
    }
    for(int i=1;i<range;i++){
        count[i]+=count[i-1];
    }
    for(int i=arr_size-1;i>=0;i--){
        out_arr[count[((arr[i]-mini)/div)%10]-1]=arr[i];
        count[((arr[i]-mini)/div)%10]--;
    }
    for(int i=0;i<arr_size;i++){
        arr[i]=out_arr[i];
    }
    delete[] count;
    delete[] out_arr;
}

int maxDigit(int* arr,int arr_size){
    int maxi=arr[0];
    for(int i=1;i<arr_size;i++){
        maxi=std::max(maxi,arr[i]);
    }
    return maxi;
}
int minDigit(int* arr,int arr_size){
    int mini=arr[0];
    for(int i=1;i<arr_size;i++){
        mini=std::min(mini,arr[i]);
    }
    return mini;
}

int radixSort(int* arr,int arr_size){
    int m=maxDigit(arr,arr_size);
    int mini=minDigit(arr,arr_size);
    for(int div=1; (m/div) > 0 ; div*=10){
        countingSort(arr,arr_size,div,mini);
    }
}




int main(){
    int arr_size;
    std::cin>>arr_size;
    int arr[arr_size];
    for(int i=0;i<arr_size;i++){
        std::cin>>arr[i];
    }
    radixSort(arr,arr_size);
    for(int i=0;i<arr_size;i++) std::cout<<arr[i] <<" ";
    return 0;
}