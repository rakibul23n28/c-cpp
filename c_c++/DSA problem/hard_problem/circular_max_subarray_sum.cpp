//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
long long kadane(int arr[], int n) {
    long long currsum = 0;
    long long maxs = INT_MIN;
    for (int i = 0; i < n; i++) {
        currsum += arr[i];
        maxs = max(maxs, currsum);

        if (currsum < 0)
            currsum = 0;
    }
    return maxs;
}

long long circularSubarraySum(int arr[], int n) {
    long long nonWrapSum = kadane(arr, n);
    long long totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
        arr[i] = -arr[i];
    }
    long long wrapSum = totalSum + kadane(arr, n);
    if(wrapSum==0)return nonWrapSum;
    return max(wrapSum, nonWrapSum);
}
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends