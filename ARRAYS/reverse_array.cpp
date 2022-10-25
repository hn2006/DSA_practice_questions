#include <bits/stdc++.h>
using namespace std;
void reverse_array(int a[], int n);
int main()
{

    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(int);
    reverse_array(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
void reverse_array(int a[], int n)
{

    int i = 0, j = n - 1;
    while (i < j)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
}