#include <iostream>
#include<cmath>
#include<climits>
using namespace std;
int main()
{    int mini=INT_MAX;
    int index=-1;
    int arr[] = {15,17,19,21,23,25, 11, 13};
    int ans = 0;
    int s = 0, e = sizeof(arr) / sizeof(arr[0]) - 1;
    while (s <= e)
    {
        long long mid = s + (e-s) / 2;
        if(arr[s]<=arr[mid])
        {
            mini=min(mini,arr[s]);
            s=mid+1;
        }
        else
        {
            mini=min(mini,arr[mid]);
            if(mini==arr[mid])
            {
                index=mid;
            }
            e=mid-1;
        }
    }
   cout<<"the array is rotated "<<index<<" time";
    return 0;
}