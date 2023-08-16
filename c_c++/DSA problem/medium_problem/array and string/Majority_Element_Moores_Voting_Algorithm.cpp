//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    //Moore's Voting Algorithm
    int majorityElement(int a[], int n)
    {
        int majority_index=0;
        int count=1;//for first majority_candided
        for(int i=1;i<n;i++){
            if(a[majority_index]==a[i]) count++;
            else count--;
            if(count==0){
                majority_index=i;
                count=1;
            }
        }
        count=0;
        for(int i=0;i<n;i++){
            if(a[majority_index]==a[i]){
                count++;
            }
        }
        return n/2<count ? a[majority_index] :  -1;
        
        
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends