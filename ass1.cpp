//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int countZeroes(vector<int> &arr) {
        // code here 
    
    int n=arr.size();
    
    int low = 0;
    int high = n - 1;

    // Binary search to find the first occurrence of 0
    while (low <= high) {
        int mid = (low + high) / 2;

        // Check if mid is the first occurrence of 0
        if (arr[mid] == 0 && (mid == 0 || arr[mid - 1] == 1)) {
            return n - mid;
        }
        // If the middle element is 1, search in the right half
        else if (arr[mid] == 1) {
            low = mid + 1;
        }
        // If the middle element is 0 but not the first occurrence
        //search in the left half
        else {
            high = mid - 1;
        }
    }
    
    // If there are no 0s in the array
    return 0;


    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.countZeroes(arr) << endl;
    }

    return 0;
}

// } Driver Code Ends