//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	    void recursiv(string s,set<string>& ans,int l){
	        if(l>=s.length()){
	            ans.insert(s);
	            return;
	        }
	        else{
	            for(int i=l;i<s.length();i++){
	                 swap(s[l],s[i]);
	                 recursiv(s,ans,l+1);
	                 swap(s[l],s[i]);
	            }
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    set<string>ans;
            recursiv(S,ans,0);
            vector<string>result(ans.begin(),ans.end());
            return result;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends