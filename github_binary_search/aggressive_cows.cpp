#include<iostream>
using namespace std;

int main()
{ int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int stalls[n];
    cout<<"Enter all the stall number available for the cows:";
    for(int i=0;i<n;i++)
    {
        cin>>stalls[i];
    }

    return 0;
}