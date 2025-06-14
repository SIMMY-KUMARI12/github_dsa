// to find the greatest common divisor of the two numbers using the euclidean algorithm 
// T.C -> log (min(a,b)) base fhi.  
#include <iostream>
using namespace std;
int find_gcd(int a, int b)
{
    while(a>0 && b>0)
    {
        if(a>b)
        {
            a=a%b;
        }
        else
        {
            b=b%a;
        }
    }
    if(a==0)
    return b;
    else 
    return a;
}
int main()
{
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    int gcd= find_gcd(a,b);
    cout<<"gcd of given numbers : "<<gcd;

    return 0;
}