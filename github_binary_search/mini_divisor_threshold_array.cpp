#include<iostream>
#include<climits>
using namespace std;
int minimum(int arr[],int n)
{  int  min= INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    return min;
}

int maximum(int arr[],int n)
{  int  max= INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    return max;
}


bool possible(int arr[],int n,int div,int threshold)
{    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]%div==0)
        {
            sum+=(arr[i]/div);
        }
        else
        {
            sum+=(arr[i]/div)+1;
        }
    }
    if(sum<=threshold)
    {
        return true;
    }
    else 
    return false;
}

int mini_divisor(int arr[],int n,int threshold)
{
    int s= minimum(arr,n);
    int e=maximum(arr,n);
    while(s<=e){
        int mid=s+(e-s)/2;
        if(possible(arr,n,mid,threshold))
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    return s;
}
int main()
{   int n=5;
    int arr[]={44,22,33,11,1};
  int threshold=5;
  int mini_div=mini_divisor(arr,n,threshold);
  cout<<"the mini dovisor in the array is: "<<mini_div; 
   
    return 0;
}