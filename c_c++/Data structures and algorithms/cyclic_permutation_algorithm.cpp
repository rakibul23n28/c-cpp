//sorting for unique  values,for continuous index liike, 0,1,2,3,4,5,6,7 or 4,5,6,7,8,9,10

#include<iostream>
void permutationSort(int* arr,int arr_size){
    int mini=arr[0];
    for(int i=0;i<arr_size;i++){
        mini=std::min(mini,arr[i]);
    }
    for(int i=0;i<arr_size;i++){
        arr[i]=arr[i]-mini;
    }
    int index=0;
    while (index < arr_size)
    {
        if(index != arr[index]){
            int temp = arr[arr[index]];
            arr[arr[index]] = arr[index];
            arr[index] = temp;
        }
        else{
            index++;
        }
    }
    for(int i=0;i<arr_size;i++){
        arr[i]=arr[i]+mini;
    }
    
}

int main(){
    int arr_size;
    std::cin>>arr_size;
    int arr[arr_size];
    for(int i=0;i<arr_size;i++){
        std::cin>>arr[i];
    }
    permutationSort(arr,arr_size);
    for(int i=0;i<arr_size;i++) std::cout<<arr[i] <<" ";
    return 0;
}