#include<iostream>

void merge(int* arr,int left,int mid,int right){
    int left_arr_size=mid-left+1;
    int right_arr_size=right-mid;
    int left_arr[left_arr_size],right_arr[right_arr_size];

    for(int i=0;i<left_arr_size;i++) left_arr[i]=arr[left+i];
    for(int i=0;i<right_arr_size;i++) right_arr[i]=arr[mid+i+1];

    int i=0,j=0,k=left;
    while (i<left_arr_size && j<right_arr_size)
    {
        if(left_arr[i]<=right_arr[j]) arr[k++]=left_arr[i++];
        else arr[k++]=right_arr[j++];
    }
     while (i<left_arr_size) arr[k++]=left_arr[i++];

     while (j<right_arr_size) arr[k++]=right_arr[j++];

}

void mergeSortAlgorithm(int* arr,int left,int right){
    if(left<right){
        int mid=(right+left)/2;
        mergeSortAlgorithm(arr,left,mid);
        mergeSortAlgorithm(arr,mid+1,right);
        merge(arr,left,mid,right);
    }else return;
}


int main() {
    int size;
    std::cin>>size;
    int arr[size];
    for (int i = 0; i < size; i++) {
        std::cin>>arr[i];
    }
    mergeSortAlgorithm(arr,0,size-1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
