//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        int j=0;
        string temp="";
        string ans="";
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='.'){
                reverse(temp.begin(),temp.end());
                temp+=s[i];
                ans = ans + temp;
                temp="";
                j=0;
                
            }
            else if(i==0){
                temp+=s[i];
                reverse(temp.begin(),temp.end());
                ans = ans + temp;
                temp="";
                j=0;
            }
            else{
                temp+=s[i];
                j++;
            }
        }
        return ans;
        
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends