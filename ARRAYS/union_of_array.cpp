// this is the method we use linear search and time complexity is O(n) and space complexity is O(1)
#include <bits/stdc++.h>
using namespace std;
void union_array(int a[], int b[], int n1, int n2);
int main()
{

    int arr[] = {1, 2, 3, 4};
    int arr2[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(int);
    int n2 = sizeof(arr2) / sizeof(int);
    union_array(arr, arr2, n, n2);
    return 0;
}
void union_array(int a[], int b[], int n1, int n2)
{
    int max = 0, count = 0;
    for (int i = 0; i < n1; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    for (int i = 0; i < n2; i++)
    {
        if (b[i] > max)
        {
            max = b[i];
        }
    }
    int temp[max + 1] = {0};
    for (int i = 0; i < n1; i++)
    {
        temp[a[i]]++;
    }
    for (int i = 0; i < n2; i++)
    {
        if (temp[b[i]] > 0)
        {
            count++;
            temp[b[i]] = 0;
        }
    }
    cout<<count<<" "<<endl;
}