// in this algorithm we use two variables max sum and another sum which can change after every condtion and not fixed
// the concept we use here is if we found sum to be negative then we will make sum as 0 and check after every condition that sum>max sum then
// update the max sum and hence after that we will get the max sum
#include <bits/stdc++.h>
using namespace std;
int max_sum(int a[], int n);
int main()
{

    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(int);
    printf("%d", max_sum(arr, n));
    return 0;
}
int max_sum(int a[], int n)
{
    int sum = 0, max_sum_var = a[0], i = 0;
    while (i < n)
    {
        sum = sum + a[i];
        if (sum > max_sum_var)
        {
            max_sum_var = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
        i++;
    }
    return max_sum_var;
}