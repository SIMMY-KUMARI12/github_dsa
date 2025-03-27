#include <iostream>
using namespace std;
int single_ele_position(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }
    if (arr[0] != arr[1])
    {
        return arr[0];
    }
    if (arr[n - 1] != arr[n - 2])
    {
        return arr[n - 1];
    }
    int s = 1, e = n - 2;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
        {
            return mid;
        }

        // need to check if the single value is in the left half or the right half from mid
        // ALL the double values in the right of the single value comes in the (even_index, odd_index) order

        // 1.-->> for checking if single values lies in the right half
        //  ******if the mid is in the odd position then check if the value just before the position is same as the value at the mid  ELSE IF the mid position is even then compare the the value at the position (odd) next to it
        if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) || (mid % 2 == 1 && arr[mid] == arr[mid - 1]))
        {
            // now need to move right as the single element is present in the right side
            s = mid + 1;
        }
        else // 2.--->> else the single value lies in the left part of the array
        {
            e = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1, 1, 2, 2, 5, 5, 7, 9, 9, 12, 12}; // contains only one element which is single and rest are duble
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = single_ele_position(arr, n);
    cout << "The position of the single element is:" << index;
    return 0;
}