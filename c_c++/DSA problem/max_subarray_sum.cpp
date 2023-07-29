#include<iostream>
#include<climits>
using namespace std;

long long maxSubarraySum(int arr[], int n){
        
       long long currsum = 0;
        long long maxs = arr[0];
        for(int i=0; i<n; i++)
        {           
            currsum+=arr[i];
            maxs=max(maxs,currsum);
        
           if(currsum<0)
           currsum=0;
       }
       return maxs;
        
    }
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    long long maxSum=maxSubarraySum(arr,n);
    cout<<maxSum;
    return 0;
}