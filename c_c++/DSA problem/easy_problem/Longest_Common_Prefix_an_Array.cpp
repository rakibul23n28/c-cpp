//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string compare(string ans,string arr){
        string result="";
        for(int i=0;(ans[i]!='\0'&&arr[i]!='\0');i++){
            if(ans[i]==arr[i]) result=result+ans[i];
            else return result;
        }
        return result;
    }
    
    string longestCommonPrefix (string arr[], int N)
    {
        string ans=arr[0];
        for(int i=0;i<N-1;i++){
            string x=compare(ans,arr[i+1]);
            if(x=="") return "-1";
            ans=x;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends