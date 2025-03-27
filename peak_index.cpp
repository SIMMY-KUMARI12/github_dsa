// find the peak element of the array,  there might be two or more peak index element
#include <iostream>
using namespace std;
int find_peak(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }
    if (arr[0] > arr[1])
    {
        return arr[0];
    }
    if (arr[n - 1] > arr[n - 2])
    {
        return arr[n - 1];
    }
    int s = 1, e = n - 2; // not pointing to the first and the last element of the array as they are the end points and we have already given the condition for it
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            return arr[mid];
        }
        if (arr[mid] < arr[mid + 1]) // means we are in the peak value is in the right half
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return -1;
}

/* NOTE------>>>> 
     EVEN IF WE HAVE MULTIPLE PEAKS THEN IT WILL GIVE US THE PEAK ELEMENT ---->>> AS THE MID VALUE WILL ALWAYS FALL INTO THE INC OR DEC SLOPS OR AT THE PEAK VALUE 
     ---->> HERE ANY OF THE PEAK VALUE WILL BE RETURNED
*/
int main()
{
    int arr[] = {1, 4, 6, 7, 9, 6, 4, 2,7,8,10,13,25,16,15,12,9,5,3};  //  MULTIPLE PEAK VALUES ARE - 9 & 25 
    int n = sizeof(arr) / sizeof(arr[0]);
    int peak_ele=find_peak(arr,n);
    cout<<"The peak element in the array is:"<<peak_ele;
    return 0;
}