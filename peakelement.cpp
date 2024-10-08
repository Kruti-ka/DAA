/*Given an 0-indexed array of integers arr[] of size n, find its peak element and return it's index.
 An element is considered to be peak if it's value is greater than or equal to the values of its adjacent 
 elements (if they exist).
Note: The output will be 1 if the index returned by your function is correct; otherwise, it will be 0.

Examples :

Input: n = 3, arr[] = {1, 2, 3} 
Output: 1
Explanation: If the index returned is 2, then the output printed will be 1. Since arr[2] = 3 is greater
 than its adjacent elements, and there is no element after it, we can consider it as a peak element. 
 No other index satisfies the same property, so answer will be printed as 0.*/


 //{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       // Your code her
       // Handle edge cases
        if (n == 1) return 0; // Only one element
        if (arr[0] >= arr[1]) return 0; // Peak at the start
        if (arr[n-1] >= arr[n-2]) return n-1; // Peak at the end
        
        // Check for peaks in the middle of the array
        for (int i = 1; i < n - 1; i++)
        {
            if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
            {
                return i; // Peak found
            }
        }
        
        return -1;

    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n], tmp[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			tmp[i] = a[i];
		}
		bool f=0;
		Solution ob;
		
		int A = ob. peakElement(tmp,n);
		
		if(A<0 and A>=n)
		    cout<<0<<endl;
		else
		{
    		if(n==1 and A==0)
    		    f=1;
    		else if(A==0 and a[0]>=a[1])
    		    f=1;
    		else if(A==n-1 and a[n-1]>=a[n-2])
    		    f=1;
    		else if(a[A]>=a[A+1] and a[A]>= a[A-1])
    		    f=1;
    		else
    		    f=0;
    		cout<<f<<endl;
		}
		
	}

	return 0;
}
// } Driver Code Ends