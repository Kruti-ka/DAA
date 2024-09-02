/*Given an array arr of size n−1 that contains distinct integers in the range of 1 to n (inclusive),
 find the missing element. The array is a permutation of size n with one element missing. 
 Return the missing element.
Examples:

Input: n = 5, arr[] = [1,2,3,5]
Output: 4
Explanation : All the numbers from 1 to 5 are present except 4.*/

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int>& arr) {

        // Your code goes h
         unordered_set<int> numbers;
        
        // Add all numbers in the array to the set
        for (int num : arr) {
            numbers.insert(num);
        }
        
        // Find the missing number
        for (int i = 1; i <= n; i++) {
            if (numbers.find(i) == numbers.end()) {
                return i;
            }
        }
        
        // If no number is missing, return -1 (this line should never be reached in a valid input)
        return -1;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n - 1);
        for (int i = 0; i < n - 1; ++i)
            cin >> arr[i];
        Solution obj;
        cout << obj.missingNumber(n, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends