// Given an array arr, partition it into two subsets(possibly empty) such that each element must belong to only one subset. Let the sum of the elements of these two subsets be S1 and S2.
// Given a difference d, count the number of partitions in which S1 is greater than or equal to S2 and the difference between S1 and S2 is equal to d. Since the answer may be large return it modulo 109 + 7.

// Example 1:

// Input:
// n = 4
// d = 3
// arr[] =  { 5, 2, 6, 4}
// Output: 1
// Explanation:
// There is only one possible partition of this array. Partition : {6, 4}, {5, 2}. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.
// Example 2:

// Input:
// n = 4
// d = 0
// arr[] = {1, 1, 1, 1}
// Output: 6
// Explanation:
// we can choose two 1's from indices {0,1}, {0,2}, {0,3}, {1,2}, {1,3}, {2,3} and put them in S1 and remaning two 1's in S2.
// Thus there are total 6 ways for partition the array arr.
// Your Task:
// You don't have to read input or print anything. Your task is to complete the function countPartitions() which takes the integer n and d and array arr and returns the count of partitions.

// Solution ------------------

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int mod = 1e9 + 7;
    int solve(int i, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (i == 0)
        {
            if (target == 0)
            {
                return 1;
            }
            return 0;
        }
        if (dp[i][target] != -1)
            return dp[i][target];

        dp[i][target] = solve(i - 1, target, arr, dp) % mod;

        if (arr[i - 1] <= target)
        {
            dp[i][target] += solve(i - 1, target - arr[i - 1], arr, dp);
            dp[i][target] %= mod;
        }

        return dp[i][target];
    }

    int countPartitions(int n, int d, vector<int> &arr)
    {

        // Code here

        int total = 0;
        for (int i = 0; i < n; i++)
        {
            total += arr[i];
        }
        if (total < d || (total - d) % 2 == 1)
            return 0;

        int target = (total - d) / 2;

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

        return solve(n, target, arr, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}