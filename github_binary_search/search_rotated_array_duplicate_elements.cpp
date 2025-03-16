#include<iostream>
using namespace std;
bool rotate_array_duplicate(int arr[],int n,int target)
{   int s=0,e=n-1;
    while(s<=e)
    { 
        long long mid=s+(e-s)/2;
        if(arr[mid]==target)
        {
            return true;
        }
        if(arr[s]== arr[mid] && arr[mid]==arr[e])   // when duplicate elements present and restricts determining the sorted and non sorted part 
        { s++;
          e--;
          continue;

        }
        if(arr[s]<arr[mid])  //means the left part from the mid is the sortedpart of the array 
        { if(arr[s]<=target && target<=arr[mid])  // searching in the sorted art of the array
            {
                e=mid-1; // if target in then making it the search space
            }
            else
            {
                s=mid+1; // if not then making the non sorted array as the search space
            }
        }
        else  //means the right part from the mid is the sortedpart of the array 
        {
            if(target>=arr[mid+1] && target<=arr[e])  // searching in the sorted art of the array
            {
                s=mid+1;  // if target in then making it the search space
            }
            else
            {
                e=mid-1;  // if not then making the non sorted array as the search space
            }
        }
    }
    return false;
}
int main()
{ int arr[]={4,5,6,6,7,0,1,2,4,4};
int n=sizeof(arr)/sizeof(arr[0]);
int target;
cout<<"Enter the number you want to search for:";
cin>>target;
bool result=rotate_array_duplicate(arr,n,target);
if(result)
{
    cout<<target<<" is present in the array";
}
else{
    cout<<target<<" is not present in the array";

}
    return 0;
}