// in this we will take three pointers variables that will as high ,low and middle
// steps will be we will have to continue mid till (mid<=high)holds then follow the steps given:-
// 1. if array[mid]=0 then swap array[low] with mid and update mid as mid++ and low as low++
// 2. if array[mid]=1 then simply simply increment the value of mid
// 3. if array[mid]=2 then swap arr[high] with mid and update high as high-- without changing mid

#include <bits/stdc++.h>
using namespace std;
void sort_array(int a[], int n);
void swap(int *a, int *b);
int main()
{

    int arr[] = {1, 2, 0, 1, 2, 1, 0, 2, 1};
    int n = sizeof(arr) / sizeof(int);

    sort_array(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
void sort_array(int a[], int n)
{

    int high = n - 1, low = 0, mid = 0;
    while (mid <= high)
    {
        if (a[mid] == 0)
        {
            swap(&a[low], &a[mid]);
            low++;
            mid++;
        }
        else if (a[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(&a[high], &a[mid]);
            high--;
        }
    }
}
void swap(int *a, int *b)
{

    int temp = (*a);
    *a = *b;
    *b = temp;
}