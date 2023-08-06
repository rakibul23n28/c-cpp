//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    
    int countFunction(int n){
        int count=0;
        while(n>0){
            count++;
            n/=10;
        }
        return count;
    }


    vector<int> cyclicPermutations(int N)
    {
        vector<int> arr;
        int num=N;
        int count=countFunction(N);
        while(1){
            arr.push_back(num);
            int rem=num%10;
            int div=num/10;
            num=pow(10,count-1)*rem+div;
            if(num==N) break;
        }
        return arr;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
      
        Solution ob;
        vector<int> ans  = ob.cyclicPermutations(N);
        for(int permutation : ans){
            cout<<permutation<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends