#include<iostream>
using namespace std;
int pivote(int arr[],int n)
{ 
  int s=0, e=n-1;
  long long mid=s+(e-s)/2;
  while(s<e)
  {
    if(arr[mid]>arr[e])
    {
        s=mid+1;
    }
    else
    {
        e=mid;
    }
    mid=s+(e-s)/2;
  }
  return mid;

}

int binary_search(int arr[],int s, int e, int target)
{
    long long mid=s+(e-s)/2;
    while(s<=e)
    {if(target== arr[mid])
    {
        return mid;
    }
    else if(target>arr[mid])
    {
       s=mid+1; 
    }
    else
    e=mid-1;

    mid=s+(e-s)/2;
 } 
 return -1;
}


int search(int arr[], int n, int target)
{ int s=0, e=n;
  long long mid=s+(e-s)/2;
  int pivot_index=pivote(arr,n);
  if(target==arr[0])
  {
    return 0;
  }
  else if(target==arr[n-1])
  {
    return n-1;
  }
  else if(arr[pivot_index]<target && target>=arr[0])
  {
    return binary_search(arr,s,(pivot_index-1),target);
  }
  else if(arr[pivot_index]>=target && target<arr[0])
  {
    return binary_search(arr,pivot_index,e,target);
  }
  return -1;
}


int main()
{  int arr[]={12,14,16,17,18,20,2,4,6,7,8,9,11}; 
   int target;   
   cout<<"enter the number you want to search for:";
   cin>>target;
   int n=sizeof(arr)/sizeof(arr[0]);
   int result=search(arr,n,target);
   cout<<"The target element is present at index:"<<result;


    return 0;
}



// // method-2 for binary search in rotated sorted array
// int binary_search(int arr[],int s, int e, int target)
// {
//     long long mid=s+(e-s)/2;
//     while(s<=e)
//     {if(target== arr[mid])
//     {
//         return mid;
//     }
//     else if(target>arr[mid])
//     {
//        s=mid+1; 
//     }
//     else
//     e=mid-1;

//     mid=s+(e-s)/2;
//  } 
//  return -1;
// }
// int search(int arr[],int s,int e, int target)
// { int mid=s+(e-s)/2;
//   if(arr[s]<=arr[mid])   // means it is the sorted left part
//    {
//     if(arr[s]<=target && target<=arr[mid])
//     {
//       e=mid;
//     }
//     else{
//       s=mid+1;
//     }
//    }
//    else   // means right part is sorted
//    {
//     if(arr[mid+1]<=target && arr[e]>=target)
//     {
//       s=mid+1;
//     }
//     else
//     {
//       e=mid;
//     }
//    }
//   return  binary_search(arr,s,e,target);
// }
// #include<iostream>
// using namespace std;
// int main()
// { int arr[]={12,14,16,18,22,1,3,5,7,9,11};
//   int n=sizeof(arr)/sizeof(arr[0]);
//   int index=search(arr,0,n-1,22);
//   cout<<"THE INDEX AT WHICH THE TARGET VALUE IS PRESENT IS:"<<index;
//   return 0;
// }