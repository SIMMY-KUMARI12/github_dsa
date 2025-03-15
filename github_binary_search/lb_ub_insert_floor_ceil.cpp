// function for the lower bound, upper bound, floor, ceil and the insertion position
#include<iostream>
#include<algorithm>

// lower bound---> index of the smallest element >= target
int lower_bound(int arr[], int n, int target)
{  int s=0, e=n-1;
    int ans=n; // hypothetical index
   long long mid=s+(e-s)/2;
    while(s<=e)
    {  if(arr[mid]>=target)
        {
          ans=mid;
          // need to move left as we need to find the smallest element >= target
          e=mid-1;
        }
        else 
        {
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}


// upper bound---> index of the smallest element > target
int upper_bound(int arr[], int n, int target)
{  int s=0, e=n-1;
    int ans=n; // hypothetical index
   long long mid=s+(e-s)/2;
    while(s<=e)
    {  if(arr[mid]>target)
        {
          ans=mid;
          // need to move left as we need to find the smallest element > target
          e=mid-1;
        }
        else 
        {
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}


// finding the position where to insert the key value
int insert_position(int arr[], int n,int key)
{  
   return lower_bound(arr,n,key); 
   // will find the position of the first occurence of the number or the index of the number just greater than it 
   //and will insert the key value there
}


//  FLOOR-----> it is the largest element of the array <= target
int floor(int arr[], int n, int target)
{  int s=0, e=n-1,ans=-1;
    long long mid=s+(e-s)/2;
     while(s<=e)
     {  if(arr[mid]<=target)
         {
           ans=arr[mid];
           // need to move right as we need to find the larget element <= target
           s=mid+1;
         }
         else 
         {
             e=mid-1;
         }
         mid=s+(e-s)/2;
     }
     return ans;

}


// ceil is the element which is the smallest element of the array>= target
int ceil(int arr[], int n, int target)
{ int ans=lower_bound(arr,n,target);
  if(ans==n)
  {
    return -1;
  }
  else
  return arr[ans];
}

using namespace std;
int main()
{ int n,target;
    cout<<"Enter the size of the array";
    cin>>n;
    int arr[n];
    cout<<"Enter all the elements of the array:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
   cout<<"Enter the element whose lb, ub, floor , ceil and position to insert you want find:";
   cin>>target;
   cout<<"lb: "<<lower_bound(arr,n,target)<<endl;
   cout<<"ub: "<<upper_bound(arr,n,target)<<endl;
   cout<<"floor: "<<floor(arr,n,target)<<endl;
   cout<<"ceil: "<<ceil(arr,n,target)<<endl;
   cout<<"index to insert at: "<<insert_position(arr,n,target)<<endl;
    return 0;
}