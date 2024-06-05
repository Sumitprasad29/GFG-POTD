// Given two arrays of integers a[] and b[] of size n and m, the task is to check if a pair of values (one value from each array) exists such that swapping the elements of the pair will make the sum of two arrays equal.

// Note: Return 1 if there exists any such pair otherwise return -1.

// Example 1:

// Input: n = 6, m = 4, a[] = {4, 1, 2, 1, 1, 2}, b[] = (3, 6, 3, 3)
// Output: 1
// Explanation: Sum of elements in a[] = 11, Sum of elements in b[] = 15, To get same sum from both arrays, we can swap following values: 1 from a[] and 3 from b[]
// Example 2:

// Input: n = 4, m = 4, a[] = {5, 7, 4, 6}, b[] = {1, 2, 3, 8}
// Output: 1
// /Explanation: We can swap 6 from array a[] and 2 from array b[]

// Solution ----------->>>>>>>>>>>>>>>

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int findSwapValues(int a[], int n, int b[], int m)
    {
        // Your code goes here
        int sum_a = 0, sum_b = 0;
        for (int i = 0; i < n; i++)
            sum_a += a[i];
        for (int i = 0; i < m; i++)
            sum_b += b[i];

        if ((sum_a - sum_b) % 2 != 0)
            return -1;
        int target = (sum_a - sum_b) / 2;
        int i = 0, j = 0;
        sort(a, a + n);
        sort(b, b + m);
        while (i < n && j < m)
        {
            int difference = a[i] - b[j];
            if (difference == target)
                return 1;
            else if (difference < target)
                i++;
            else
                j++;
        }
        return -1;
    }
};
