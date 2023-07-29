//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int l_r=0;
            int r_l=n-1;
            int temp;
            while(l_r<m&&r_l>=0){
                if(arr1[r_l]<=arr2[l_r]) break;
                else {
                    // temp=arr2[l_r];
                    // arr2[l_r]=arr1[r_l];
                    // arr1[r_l]=temp;
                    swap(arr1[r_l], arr2[l_r]);
                }
                    l_r++;
                    r_l--;
            }
        sort(arr1,arr1+n);
        sort(arr2,arr2+m);
        }
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends