// Linked list of strings forms a palindrome

// Given a linked list with string data, check whether the combined string formed is palindrome. If the combined string is palindrome then return true otherwise return false.

// Example:

// Input:

// Output : true
// Explanation: As string "abcddcba" is palindrome the function should return true.
// Input:

// Output : false
// Explanation: As string "abcdba" is not palindrome the function should return false.
// Expected Time Complexity:  O(n)

// Solution ----------->>>>>>>>>>

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool palindrome(string str)
    {
        int n = str.length();
        for (int i = 0; i < n; i++)
        {
            if (str[i] != str[n - 1 - i])
                return false;
        }
        return true;
    }

    bool compute(Node *head)
    {
        string ans = "";
        Node *temp = head;
        if (temp == NULL)
        {
            return false;
        }
        while (temp)
        {
            ans.append(temp->data);
            temp = temp->next;
        }
        return palindrome(ans);
    }
};