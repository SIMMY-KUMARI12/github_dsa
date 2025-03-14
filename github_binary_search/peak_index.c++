




#include<iostream>
#include<algorithm>
using namespace std;

int peak_element_in_mountain_array(int arr[],int n)
{  
     int s=0,e=n-1;
     int mid=s+(e-s)/2;
     while(s<e)
     {
        if(arr[mid]<arr[mid+1])
        {
            s=mid+1;
        }
        else if(arr[mid]>arr[mid+1])
        {
            e=mid;
        }
        mid=s+(e-s)/2;
     }
     return s;
}

int main()
{   int n;
    int arr[n];
    cout<<"Enter the size of the array(should be greater then 3):";
    cin>>n;
    cout<<"Enter the elements of the array first in increasing then in decreasing order:\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=peak_element_in_mountain_array(arr,n);
    cout<<"The index of the peak element of the array is: "<<ans<<" and the value is: "<<arr[ans];
    return 0;
}
