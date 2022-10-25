// in this question i will make use of two pointing variables one will be my current and other is low
//  current variable will be incremented until reaches the end and now check the below given condition:
//  if array[current]<0 then swap array[current] with array[low] and update low as low++ and mid as mid++
//  else update simply mid as mid++

#include <bits/stdc++.h>
using namespace std;
void negative_pos_array(int a[], int n);
void swap(int *a, int *b);
int main()
{

    int arr[] = {1, -2, 3, -4, -1};
    int n = sizeof(arr) / sizeof(int);
    negative_pos_array(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
void negative_pos_array(int a[], int n)
{

    int low = 0, current = low + 1;
    while (current < n && low < n)
    {
        if (a[low] < 0)
        {
            low++;
        }
        else if (a[current] > 0)
        {
            current++;
        }
        else
        {
            swap(&a[current], &a[low]);
            current++;
            low++;
        }
    }
}
void swap(int *a, int *b)
{

    int temp = (*a);
    *a = *b;
    *b = temp;
}