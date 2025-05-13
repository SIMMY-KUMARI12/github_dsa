#include<iostream>
#include<cmath>
using namespace std;
int fun_int_root(int num, int n)
{ int s=1, e=(num/n);
    // without using the temp variable
  while(s<=e)
  {
    int mid=s+(e-s)/2;
    if(pow(mid,n)>num)
    {
        e=mid-1;
    }
    else{
        s=mid+1;  
  // if we do use a variable then var=mid  then condition is -----> s<e
    }
  }
  return e;
}
double fun_deci_root(int ans, int num,int n)
{  double x=1.0;
    double d_ans= (double)ans;
    for(int i=1;i<=n;i++)
    {
        x=x/10;
        for(int j=1;i<=10;j++)
        {
            if(pow(d_ans+x,n)>num)
            {
                break;
            }
            else{
                d_ans+=x;
            }
        }
    }
    return d_ans;
}

int main()
{ int num;
    int n;
    cout<<"Entert the number you want to find the nth root of: ";
    cin>>num;
    cout<<"Enter which root you want to find: ";
    cin>>n;
    int int_root= fun_int_root(num,n);
    double d_root= fun_deci_root(int_root,num,n);
    cout<<"The "<<n<<"th root of the number "<<num<<" is: "<<d_root;
    return 0;
}
