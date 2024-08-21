/*Implement a problem of move all zeroes to end of 
array.
Statement: Given an array of random numbers, Push all the zero’s 
of a given array to the end of the array. For example, if the given 
arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, it should be changed to {1, 9, 
8, 4, 2, 7, 6, 0, 0, 0, 0}. The order of all other elements should be 
same.
Input : arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
Output : arr[] = {1, 2, 4, 3, 5, 0, 0, 0}; */


#include <iostream>
using namespace std;

void movezerotoend(int arr[],int start,int end)
{
    if(start >=end) return;
    int mid =(start+end)/2;
    movezerotoend(arr,start,mid);
    movezerotoend(arr,mid+1,end);
    int temp[end-start+1];
    int i=start ,j=mid+1,k=0;
    while(i<=mid)
    {
        if(arr[i]!=0)
        {
            temp[k++] =arr[i];
        }
        i++;
    }
    while(j<=end)
    {
        if(arr[j]!=0)
        {
            temp[k++] =arr[j];
        }
        j++;
    }

    while(k <(end-start+1))
    {
        temp[k++] =0;
    }
    for(i=start;i<=end;i++)
    {
        arr[i] =temp[i-start];
    }

}
int main()
{
    int n;
    cout<<"Enter the number of elements :";
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }
    movezerotoend(arr,0,n-1);

    cout<<"Resultant array!";
    for(int i =0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}