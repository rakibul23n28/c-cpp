#include<iostream>

int partition(int* arr,int start_index,int end_index){
    int pivot=arr[end_index];
    int pindex=start_index;
    int temp;
    for(int i=start_index;i<end_index;i++){
        if(arr[i]<=pivot){
            temp=arr[pindex];
            arr[pindex]=arr[i];
            arr[i]=temp;
            pindex++;
        }
    }
    temp=arr[pindex];
    arr[pindex]=arr[end_index];
    arr[end_index]=temp;
    return pindex;
}

void quickSort(int* arr,int start_index,int end_index){
    if(start_index<end_index){
        int pivot_point=partition(arr,start_index,end_index);
        quickSort(arr,start_index,pivot_point-1);//first  partition
        quickSort(arr,pivot_point+1,end_index);//second partition
    }

}

int main(){
    int size;
    std::cin>>size;
    int arr[size];
    for (int i = 0; i < size; i++) {
        std::cin>>arr[i];
    }
    quickSort(arr,0,size-1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}