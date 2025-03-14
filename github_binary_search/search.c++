// write a program to do the binary search in the array of size n      
// applicable only on the monotonic function ie. assending order or descending order
// TC ------>>>> O(log n)          SC--------->>>> O(n)+O(1)


#include<iostream>
#include<algorithm>
using namespace std;
int binary_search(int arr[],int n,int target)
{  sort(arr,arr+n);  // for sorting the array first
  int start=0, end=n-1;
  int mid;
  mid=start+(end-start)/2;       // in the case when s & e both are the max value of int the there sum will cross the limit of int causing problem ----->>>> mid formula is "  mid=start+(end-start)/2;  "
  while(start<=end)
  {
    if(arr[mid]==target)
    return mid;
    else if(arr[mid]<target)
    { start=mid+1;
    }
    else if(arr[mid]>target)
    {
     end=mid-1;
    }
    mid=start+(end-start)/2;
  }
  return -1;
}

int main()
{   int n,target,index;
cout<<"Enter the size of the array:";
cin>>n;
cout<<"Enter the elements of the array:";
int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

    }
cout<<"Enter the no you want to search in the array: ";
cin>>target;
index=binary_search(arr,n,target);
cout<<"So "<<target<<" is present at the index "<<index;

    return 0;
}





