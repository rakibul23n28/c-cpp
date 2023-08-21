//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int arr[], int l, int h, int key){
    int start=l,end=h;
    while(end>=start){
        int mid=(end+start)/2;
        if(key==arr[mid]) return mid;
        else if(arr[start]<=arr[mid]){
            if(key<arr[mid] && key>=arr[start]) end=mid-1;
            else start=mid+1;
        }
        else{
            if(key>arr[mid] && key<=arr[end]) start=mid+1;
            else end=mid-1;
        }
        
    }
    return -1;
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends