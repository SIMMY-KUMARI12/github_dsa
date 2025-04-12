#include<iostream>
#include<climits>
using namespace std;

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

bool possible(int arr[], int n, int div,int threshold)
{   long long int sum=0; // so that it is not more than the integer maximum value
    for(int i=0;i<n;i++)
    {   if(arr[i]%div==0)
        {
            sum+=(arr[i]/div);
        }
        else
        {
            sum+=((arr[i]/div)+1);
        }
    }
    if(sum<=threshold)
    {
        return true;
    }
    else
    {
        return false;
    }

}


int mini_divisor(int arr[],int n,int threshold)
{
    int s=1; // as the minimum divisor can be 1  
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
{   int n;
    cout<<" enter the number of element in the array:";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
  int threshold=5;
  int mini_div=mini_divisor(arr,n,threshold);
  cout<<"the mini divisor in the array is: "<<mini_div; 
   
    return 0;
}