//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long* arr,long long start,long long mid,long long end ){
        long long left_arr_size=mid-start+1;
        long long  right_arr_size=end-mid;
        long long left_arr[left_arr_size],right_arr[right_arr_size];
        for(long long i=0;i<left_arr_size;i++) left_arr[i]=arr[start+i];
        for(long long i=0;i<right_arr_size;i++) right_arr[i]=arr[mid+i+1];
        
        long long i=0,j=0,k=start;
        long long int count=0;
        while(i<left_arr_size && j<right_arr_size){
            if(left_arr[i]>right_arr[j]) {
                arr[k++]=right_arr[j++];
                count+=(left_arr_size-i);
            }
            else arr[k++]=left_arr[i++];
        }
        while(i<left_arr_size) arr[k++]=left_arr[i++];
        while(j<right_arr_size) arr[k++]=right_arr[j++];
        for(long long i=0;i<5;i++){
            std::cout<<arr[i]<<" k "<<count;
        }
            std::cout<<std::endl;

        return count;
    }
    
    
    
    long long int mergeSort(long long* arr,long long start,long long end){
        long long int count = 0; // Move count declaration outside the recursive calls
        if(end>start){
            long long mid=(end+start)/2;
            count+=mergeSort(arr,mid+1,end);
            count+=mergeSort(arr,start,mid);
            count+=merge(arr,start,mid,end);
        }
        return count;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long int count=mergeSort(arr,0,N-1);
        return count; // Add return statement for the inversion count
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends