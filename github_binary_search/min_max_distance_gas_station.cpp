#include <iostream>
#include<cmath>
using namespace std;

int countfun(int station[], int n, long double mid)
{   int count=0;
    int difference=0.0;
    for(int i=0;i<n-1;i++)
    { difference=ceil((station[i+1]-station[i]) /mid);
        count+=(difference-1);
    }
    return count;
}

long double find_max_dis(int station[], int n,int k)
{   long double ans=-1;
    long double low = 0;
    long double high =station[n-1];
    while((high-low)>0.000001)
    {long double mid=(low+high)/2.0;
       int  count_inserted_stations=countfun(station,n,mid);
       if(count_inserted_stations>k)
       {
        low=mid;
       }
       else{
        ans=mid;
        high=mid;
       }
    }
  return ans;
}
int main()
{
    int n;
    cout << "enter the size of the station array:";
    cin >> n;
    int station[n];
    cout << "Enter the position of the gas stations in increasing order\n";
    for (int i = 0; i < n; i++)
    {
        cin >> station[i];
    }
    int k;
    cout<<"\nEnter the number of gas stations you want to add: ";
    cin>>k;
    long double maxidis=find_max_dis(station,n,k);
    cout<<"The minimized maximum distance between the two consecutive stations after adding new stations is: "<<maxidis;
    return 0;
}