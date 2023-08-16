//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	

    
    void merge(vector<pair<int, int>>& arr, int left, int mid, int right, vector<int>& count) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        vector<pair<int, int>> L(n1);
        vector<pair<int, int>> R(n2);
        
        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];
        
        int i = 0, j = 0, k = left;
        
        while (i < n1 && j < n2) {
            if (L[i].first <= R[j].first) {
                arr[k] = L[i];
                count[L[i].second] += j;
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        
        while (i < n1) {
            arr[k] = L[i];
            count[L[i].second] += j;
            i++;
            k++;
        }
        
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    
    void mergeSort(vector<pair<int, int>>& arr, int left, int right, vector<int>& count) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid, count);
            mergeSort(arr, mid + 1, right, count);
            merge(arr, left, mid, right, count);
        }
    }
	vector<int> constructLowerArray(int *nums, int n) {
        vector<pair<int, int>> arr;
        
        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});
        
        vector<int> count(n, 0);
        
        mergeSort(arr, 0, n - 1, count);
        
        return count;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.constructLowerArray(arr, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends