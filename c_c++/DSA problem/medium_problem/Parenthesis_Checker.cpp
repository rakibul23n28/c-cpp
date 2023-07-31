//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        vector<char> store;
         store.push_back(x[0]);
        int i=1;
        int de=0;
        do{
            if(x[i]-1==store[de] || x[i]-2==store[de] ){
                store.pop_back();
                de-=1;
                if(de<0 && i!=x.size()-1){
                   de=0; 
                   store.push_back(x[i+1]);
                   i++;
                } 

            }
            else 
            {
                store.push_back(x[i]);
                de++;
            }
            i++;
        }while(i<x.size());
        return store.empty()? true : false;
        
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends