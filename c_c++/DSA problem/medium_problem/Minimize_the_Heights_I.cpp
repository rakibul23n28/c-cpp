//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution{   
public:
    void merge(int* arr,int start,int mid,int end){
        int l=mid-start+1;
        int r=end-mid;
        int l_arr[l],r_arr[r];
        for(int i=0;i<l;i++) l_arr[i]=arr[start+i];
        for(int i=0;i<r;i++) r_arr[i]=arr[mid+i+1];
        
        int i=0,j=0,k=start;
        while(i<l&&j<r){
            if(l_arr[i]<r_arr[j]) arr[k++]=l_arr[i++];
            else arr[k++]=r_arr[j++];
        }
        while(i<l) arr[k++]=l_arr[i++];
        while(j<r) arr[k++]=r_arr[j++];
    }
    
    void mergeSort(int* arr,int start,int end){
        if(start<end){
            int mid=(end+start)/2;
            mergeSort(arr,start,mid);
            mergeSort(arr,mid+1,end);
            merge(arr,start,mid,end);
        }
    }

    int getMinDiff(int arr[], int n, int k) {
        mergeSort(arr,0,n-1);
        int mindif=arr[n-1]-k-arr[0]+k;
        for(int i=1;i<n;i++){
            int mini=min(arr[0]+k,arr[i]-k);
            int maxi=max(arr[n-1]-k,arr[i-1]+k);
            mindif=min(mindif,maxi-mini);
        }
        return mindif;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends