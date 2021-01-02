// 237. Delete Node in a Linked List

// Write a function to delete a node in a singly-linked list.
// You will not be given access to the head of the list, instead you will be given access to the node to be deleted directly.
// It is guaranteed that the node to be deleted is not a tail node in the list.

// Example 1:
// Input: head = [4,5,1,9], node = 5
// Output: [4,1,9]
// Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.

// Example 2:
// Input: head = [4,5,1,9], node = 1
// Output: [4,5,9]
// Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.

// Example 3:
// Input: head = [1,2,3,4], node = 3
// Output: [1,2,4]

// Example 4:
// Input: head = [0,1], node = 0
// Output: [1]

// Example 5:
// Input: head = [-3,5,-99], node = -3
// Output: [5,-99]

// Constraints:

// The number of the nodes in the given list is in the range [2, 1000].
// -1000 <= Node.val <= 1000
// The value of each node in the list is unique.
// The node to be deleted is in the list and is not a tail node

#include <stdio.h>  // allows printf
#include <stdlib.h> // allows malloc
#include <stddef.h> // allows NULL

// Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
} *head = NULL;

// My solution:
void deleteNode(struct ListNode *node)
{

    if (node->next != NULL)
    {
        node->val = node->next->val;
        node->next = node->next->next;
    }
}

// create nodes, assign data
void create(int A[], int n)
{
    int i;
    struct ListNode *t, *last;
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = A[0];
    head->next = NULL;
    last = head;

    for (i = 1; i < n; i++)
    {
        t = (struct ListNode *)malloc(sizeof(struct ListNode));
        t->val = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// // utility function to print linked list
void printList(struct ListNode *p)
{
    while (p != NULL)
    {
        printf("%d -> ", p->val);
        p = p->next;
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6};
    create(A, 6);

    deleteNode(head); // deletes the first node's val
    printList(head);

    return 0;
}