// Given a string str of length n, find if the string is K-Palindrome or not. A k-palindrome string transforms into a palindrome on removing at most k characters from it.

// Example 1:

// Input: str = "abcdecba"
// n = 8, k = 1
// Output: 1
// Explaination: By removing 'd' or 'e'
// we can make it a palindrome.

// Example 2:

// Input: str = "abcdefcba"
// n = 9, k = 1
// Output: 0
// Explaination: By removing a single
// character we cannot make it a palindrome.

// Your Task:
// You do not need to read input or print anything. Your task is to complete the function kPalindrome() which takes string str, n, and k as input parameters and returns 1 if str is a K-palindrome else returns 0.

// Solution ---------------

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lcs(string &s, string &r, int n)
    { // We will use LCS here longest common subsequence
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (s[i - 1] == r[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][n];
    }

    int kPalindrome(string str, int n, int k)
    {
        // code here
        string r = str;
        reverse(r.begin(), r.end());

        int x = lcs(str, r, n);
        int rem = n - x;
        return rem <= k;
    }
};