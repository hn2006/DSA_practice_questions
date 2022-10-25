#include <bits/stdc++.h>
using namespace std;
bool binary_search_array(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1, mid=0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    cout<<binary_search_array(arr,n,10)<<endl;

}