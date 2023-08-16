//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends


class Solution{
    public:
        //Function to merge the arrays.
        //Function to merge the arrays.
        
        void mergee(long long* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays to store the left and right subarrays
    long long leftArray[n1], rightArray[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of leftArray[], if any
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    // Copy the remaining elements of rightArray[], if any
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSortAlgorithm(long long* arr,int left,int right){
    if(left<right){
        int mid=(right+left)/2;
        mergeSortAlgorithm(arr,left,mid);
        mergeSortAlgorithm(arr,mid+1,right);
        mergee(arr,left,mid,right);
    }else return;
}
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int l_r=0;
            int r_l=n-1;
            int temp;
            while(l_r<m&&r_l>=0){
                if(arr1[r_l]<=arr2[l_r]) break;
                else {
                    temp=arr2[l_r];
                    arr2[l_r]=arr1[r_l];
                    arr1[r_l]=temp;
                }
                    l_r++;
                    r_l--;
            }
            mergeSortAlgorithm(arr1,0,n-1);
            mergeSortAlgorithm(arr2,0,m-1);
        }
};



//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends