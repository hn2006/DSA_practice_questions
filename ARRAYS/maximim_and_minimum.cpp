// this is the method we use linear search and time complexity is O(n) and space complexity is O(1)
#include <bits/stdc++.h>
using namespace std;
void max_and_min_element(int a[], int *max, int *min, int n);
int main()
{

    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(int), max = arr[0], min = arr[0];
    max_and_min_element(arr, &max, &min, n);
    cout << "maximum element is: " << max << endl;
    cout << "minimum element is: " << min << endl;
    return 0;
}
void max_and_min_element(int a[], int *max, int *min, int n)
{

    for (int i = 0; i < n; i++)
    {
        if (a[i] > (*max))
        {
            (*max) = a[i];
        }
        if (a[i] < (*min))
        {
            (*min) = a[i];
        }
    }
}