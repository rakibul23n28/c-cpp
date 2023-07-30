//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        sort(arr, arr + n);
        vector<int> a(100000, 0);
        vector<int> b;
        
        int index;
        for(int i=0;i<n;i++){
            index=arr[i];
            a[index]++;
            if(a[index]>1 and arr[i]!=arr[i+1] ){
                
             b.push_back(arr[i]);
            }
        }
       return b.empty() ? vector<int>{-1} : b;
       
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends