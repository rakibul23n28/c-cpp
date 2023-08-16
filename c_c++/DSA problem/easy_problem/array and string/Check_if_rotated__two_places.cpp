//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
   bool isRotated(string str1, string str2)
    {
        if(str1==str2) return true;
        if(str1.size()>=2&&str2.size()>=2){
           string b1=str2.substr(str1.size()-2);
        string b2=str2.substr(0,str1.size()-2);
        string b3=b1+b2;
        if(str1==b3) return true;
         b1=str2.substr(2,str1.size());
        b2=str2.substr(0,2);
         b3=b1+b2;
        if(str1==b3) return true; 
        }
        
        
        return false;
    }


};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends