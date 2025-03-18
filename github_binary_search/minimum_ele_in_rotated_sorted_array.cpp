#include<iostream>
#include<cmath>
#include<climits>
using namespace std;
int main()
{ int arr[10]={5,7,9,11,-2,-1,0,1,2,4};
  int s=0,e=9,mini=INT_MAX;
  while(s<=e)
  {long long mid=s+(e-s)/10;
    if(arr[s]<=arr[mid])
    {  
      mini=min(mini,arr[s]);  
      s=mid+1; // moving to the non sorted part of the array as the values to the right of index s and till mid may be bigger then the value in mini variable
    }
    else
    {   mini=min(mini,arr[mid]);  // may be the minimum value stored at the mid may be lost
        e=mid-1; // moving to the right as all valule to the right of mid are bigger then it and we may get mini value in the unsorted part of the array
    }
  }

  cout<<"The minimum value in the array is: "<<mini;
    return 0;
}