#include <bits/stdc++.h>
using namespace std;
bool search_row(vector<int> v, int target);
bool searchMatrix(vector<vector<int>> &matrix, int target);
int main()
{

    vector<vector<int>> mat{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    cout<<searchMatrix(mat, 100);
}
bool searchMatrix(vector<vector<int>> &matrix, int target)
{

    int size = matrix.size();
    int column_size = matrix[0].size();
    for (int i = 0; i < size; i++)
    {
        if ((target >= matrix[i][0]))
        {
            if ((target <= matrix[i][column_size - 1]))
            {
                if (search_row(matrix[i], target))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return false;
}
bool search_row(vector<int> v, int target)
{
    int low = 0;
    int high = v.size() - 1, mid=0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (v[mid] > target)
        {
            high = mid - 1;
        }
        else if (v[mid] < target)
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