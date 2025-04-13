#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int maxi_element(int weights[],int n)
{    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
       if(weights[i]>max)
       {
        max= weights[i];
       }
    }
    return max;
}
int sum_element(int weights[], int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=weights[i];
    }
    return sum;
}
bool possible_to_ship(int weights[], int n, int max_capacity, int days)
{
   int day=1, load=0;
   for(int i=0;i<n;i++)
   {
    if(load+weights[i]>max_capacity)
    {
        day++;
        load=weights[i];
    }
    else{
        load+=weights[i];
    }
   }

   if(day<=days)
   {
    return true;
   }
   else
   return false;
}


int find_min_capacity(int weights[],int n, int days)
{   int s=maxi_element(weights,n);
    int e=sum_element(weights,n);
    while(s<=e)
    {   int mid=s+(e-s)/2;

        if(possible_to_ship(weights,n,mid,days))
        {
            e=mid-1; // moving to th eleft to find the minimum value of the capacity with which we can ship the items withing the given days
        }
        else 
        {
            s=mid+1; // moving to the right
        }
    }
    return s;
}


int main()
{  int n,days;
    cout<<"Enter the number of packages present in the conveyor belt:";
    cin>>n;

    int weights[n];
    cout<<"Enter the weight of each item present in the conveyor belt:";
    for(int i=0;i<n;i++)
    {
    cin>>weights[i];
    }
    cout<<"Enter the number of days in which you want to ship the items:";
    cin>>days;
    int min_cap_of_ship=find_min_capacity(weights,n,days);
    cout<<"The least weight that is need to hip the items is:"<<min_cap_of_ship;

    return 0;
}