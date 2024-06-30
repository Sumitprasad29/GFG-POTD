// Delete node in Doubly Linked List

// Given a doubly Linked list and a position. The task is to delete a node from a given position (position starts from 1) in a doubly linked list and return the head of the doubly Linked list.

// Examples:

// Input: LinkedList = 1 <--> 3 <--> 4, x = 3
// Output: 1 3
// Explanation:
// After deleting the node at position 3 (position starts from 1),the linked list will be now as 1 <--> 3.

// Input: LinkedList = 1 <--> 5 <--> 2 <--> 9, x = 1
// Output: 5 2 9
// Explanation:

// Expected Time Complexity: O(n)

// Solution -------------->>>>>>>>>>>>>>>>>

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

// } Driver Code Ends
/* Structure of Node
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;

  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }

};
*/

class Solution
{
public:
    Node *deleteNode(Node *head, int x)
    {

        struct Node *remoove = head;
        x = x - 1;
        while (x--)
        {
            remoove = remoove->next;
        }
        if (head == NULL || remoove == NULL)
        {
            return NULL;
        }
        if (head == remoove)
        {
            head = remoove->next;
        }
        if (remoove->next != NULL)
        {
            remoove->next->prev = remoove->prev;
        }
        if (remoove->prev != NULL)
        {
            remoove->prev->next = remoove->next;
        }
        free(remoove);
        return head;
    }
};
