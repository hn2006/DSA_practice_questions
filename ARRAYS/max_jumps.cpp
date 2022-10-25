// we have to traverse in this array once as order of time complexity is O(n) and hence find the maximum elemnent in the next array element
// in this way when we complete our journey we will return the count
#include <bits/stdc++.h>
using namespace std;
int max_jump(int a[], int n);
int find_max(int start, int end, int a[]);
int main()
{

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    printf("%d", max_jump(arr, n));
    return 0;
}
int max_jump(int a[], int n)
{
    int count = 0, i = 0;
    while (i < n)
    {
        int temp = find_max(i + 1, i + a[i], a);
        if ((i + a[i]) >= (n - 1))
        {
            count++;
            break;
        }
        else
        {
            i = temp;
            count++;
        }
    }
    return count;
}
int find_max(int start, int end, int a[])
{
    int max = 0, i = start;
    while (i <= end)
    {
        if (a[i] > max)
        {
            max=i;
        }
        i++;
    }
    return max;
}