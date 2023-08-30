//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int num) {
	     int start=0;
        int end=n-1;
        int mid;
        while(start<=end){
            mid=start +(end-start)/2;
            if(num==arr[mid]){
                break;
            }
            else if(arr[mid]<num){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
            
        }
        if(start>end) return 0;
        int count=0;
        for(int i=mid;i>=0;i--){
            if(arr[i]==arr[mid]) count++;
            else break;
        }
        for(int i=mid+1;i<n;i++){
            if(arr[i]==arr[mid]) count++;
            else break;
        }
        return count;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends