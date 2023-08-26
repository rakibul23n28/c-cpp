//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int count=0;
        vector<int> r;
        unordered_map<int,int> m;
        int flag=1;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
            if(m[arr[i]]>1&&flag) {
                r.push_back(arr[i]);
                flag=0;
            }
        }
        flag=1;
        for(int i=1;i<n;i++){
            if (!(m.find(i) != m.end())){
                r.push_back(i);
                flag=0;
                break;
            }
        }
        if(flag) r[1]=n;
        return r;
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends