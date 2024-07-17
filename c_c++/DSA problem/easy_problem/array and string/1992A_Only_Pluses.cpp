#include<bits/stdc++.h>

int main(){
    int n;
    std::cin>>n;
    
    int arr[n][3];
    for(int i=0;i<n;i++){
        std::cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    int value;

    for(int i=0;i<n;i++){
        std::sort(arr[i],arr[i]+3);
        if(arr[i][0] == arr[i][1]){
            if (arr[i][2] - arr[i][1] == 1 || arr[i][1] == arr[i][2])
            {
                arr[i][0]+=2;
                arr[i][1]+=2;
                arr[i][2]+=1;
            }else{
                arr[i][0]+=3;
                arr[i][1]+=2;
            }
            
            
        }else if(arr[i][1] - arr[i][0] <= 3 ){
            if (arr[i][1] == arr[i][2])
            {
                arr[i][0]+=3;
                arr[i][1]+=1;
                arr[i][2]+=1;
            }else if (arr[i][1] != arr[i][2] && arr[i][1] - arr[i][0] <= 2 )
            {
                arr[i][0]+=3;
                arr[i][1]+=2;

            }else{
                arr[i][0]+=4;
                arr[i][1]+=1;;
            }  
        }
        else {
            arr[i][0]+=5;
        }
        
    }
    for(int i=0;i<n;i++){
        std::cout<<arr[i][0]*arr[i][1]*arr[i][2]<<std::endl;
    }

    return 0;
}