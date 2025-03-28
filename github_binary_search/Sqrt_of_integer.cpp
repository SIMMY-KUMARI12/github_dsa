#include<iostream>
using namespace std;
float find_sqrt(int n,int deci)
{ int ans=1;
    int s=1,e=n;
    while(s<=e)
    { int mid=s+(e-s)/2;
      if(mid*mid<=n)
      {
        ans=mid;
        s=mid+1;
      }
      else{
        e=mid-1;
      }
    }
  
  float l=1,sqrt=ans;// here high point to the integer sqrt of the given number
for(int i=1;i<=deci;i++)
{  l=l/10;
  for(float j=sqrt;j*j<n;j=j+l)
  {
    sqrt=j;
  }
}
return sqrt;
}

int main()
{  int n=0;
    cout<<"Enter the number whose square root you want to find: ";
    cin>>n;
    int deci=0;
    cout<<"Enter the deciaml point till which you want to have sqrt: ";
    cin>>deci;
    float sqrt=find_sqrt(n,deci);
    cout<<"The sqrt of: "<<n<<" is "<<sqrt;
    return 0;
}