#include<iostream>
#include<algorithm>
using namespace std;
bool min_distance_ispossible(int arr[], int n, int min_dist,int cow_num)
{ int count=1,initial_slot=arr[0];
   for(int i=1;i<n;i++)
   {
    if(arr[i]-initial_slot>=min_dist)
    {
        count++;
        initial_slot=arr[i];
    }
   }
   if(count==cow_num)
   {
    return true;
   }
   else
   return false;
}

int finding_largest_min_distance(int arr[],int n, int cow_num)
{
    int s=*min_element(arr,arr+n);
    int e= *max_element(arr, arr+n);
    while(s<=e)
    {
        int mid= s+(e-s)/2;
        if(min_distance_ispossible(arr,n,mid,cow_num))
        {
            // move to the right 
            s=mid+1;
        }
        else
        {
            // move to left
            e=mid-1;
        }
    }
    return e; // ase will point towrds which is smaller number but among them it will point to the max of the smaller and s vise sera
}
int main()
{ int n,cow_num=0, largest_mini_dist=-1;
    cout<<"Enter the size of the array:";
    cin>>n;
    int stalls[n];
    cout<<"Enter all the stall number available for the cows:";
    for(int i=0;i<n;i++)
    {
        cin>>stalls[i];
    }
    cout<<"Enter the number of cows ypou want to have in the stalls:";
    cin>>cow_num;
    sort(stalls,stalls+n);
   largest_mini_dist=finding_largest_min_distance(stalls,n,cow_num);
   cout<<"The maximum distance between the two cows should be:"<<largest_mini_dist;
    return 0;
}