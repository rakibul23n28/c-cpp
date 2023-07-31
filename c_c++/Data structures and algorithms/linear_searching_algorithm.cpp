#include<iostream>

void linearSearch(int* arr,int n,int search_element ){
    for(int i=0;i<n;i++){
        if(arr[i]==search_element) {
            std::cout<<"found in index of : "<<i<<std::endl;
            return;
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
    linearSearch(arr,n,search_element);
    
    return 0;
}