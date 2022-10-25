#include <bits/stdc++.h>
using namespace std;
int max_jump(int arr[], int n);
int find_max(int start, int end, int a[]);
int main()
{

    int arr[] = {0, 1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    printf("%d", max_jump(arr, n));
    return 0;
}
int max_jump(int arr[], int n)
{
    int max_pos = arr[0];
    int steps = arr[0];
    int jump = 1;
    if (n == 1)
    {
        jump = 1;
    }
    else if (arr[0] == 0)
    {
        jump = -1;
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
            {
                break;
            }
            else
            {
                max_pos = max(max_pos, i + arr[i]);
                steps--;
                if (steps == 0)
                {
                    jump++;
                    if (max_pos < i)
                    {
                        jump = -1;
                    }
                    i = max_pos - i;
                }
            }
        }
    }
    return jump;
}