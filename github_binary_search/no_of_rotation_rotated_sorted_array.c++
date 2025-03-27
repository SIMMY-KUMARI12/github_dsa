#include <iostream>
#include<cmath>
#include<climits>
using namespace std;
int main()
{    int mini=INT_MAX;
    
    int index=-1;
    int arr[] = {15,17,19,21,23,25, 11, 13};
    int ans = INT_MAX;
    int s = 0, e = sizeof(arr) / sizeof(arr[0]) - 1;
    while (s <= e)
    {        
            int mid=s+(e-s)/2;
            if(arr[s]<=arr[e])
            {
                if(arr[s]<ans)
                {
                    index=s;
                    break;
                }
            }
            if(arr[s]<=arr[mid])
            {
                if(arr[s]<ans)
                {
                    ans=arr[s];
                    index=s;
                }
                s=mid+1;
            }
            else
            {
                if(arr[mid]<ans)
                {
                    ans=arr[mid];
                    index=mid;
                }
                e=mid-1;
            }
        
    }
   cout<<"the array is rotated "<<index<<" time";
    return 0;
}