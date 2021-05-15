// Given head, the head of a linked list, determine if the linked list has a cycle in it.
// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
// Internally, pos is used to denote the index of the node that tail's next pointer is connected to.
// Note that pos is not passed as a parameter.

// Return true if there is a cycle in the linked list. Otherwise, return false.

// Example 1:
// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

// Example 2:
// Input: head = [1,2], pos = 0
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

// Example 3:
// Input: head = [1], pos = -1
// Output: false
// Explanation: There is no cycle in the linked list.

// Constraints:
// The number of the nodes in the list is in the range [0, 104].
// -105 <= Node.val <= 105
// pos is -1 or a valid index in the linked-list.

// Follow up: Can you solve it using O(1) (i.e. constant) memory?

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
} *head = NULL, *second = NULL;

// Floyd’s Cycle-Finding Algorithm Method
bool hasCycle(struct ListNode *head)
{
    struct ListNode *slow = head, *fast = head; // two pointers

    while (slow && fast && fast->next)
    {
        // after one interation dist btwn pointers becomes k+1, then k+2...
        slow = slow->next;
        fast = fast->next->next;
        // if pointers meet, there is a cycle
        if (slow == fast)
        {
            return true;
        }
    }
    // if pos == -1 || pointers do not meet, cycle doesn't exist
    return false;
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

// utility function to print linked list
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
    int i;

    int A[] = {1, 2, 3, 4, 5}; // headA

    create(A, 5);

    printList(head);
    printf("\n");

    // Test for cycles
    // head->next->next->next->next->next = head;

    // Test for no cycles
    head->next->next->next->next->next = NULL;

    if (hasCycle(head))
        printf("Loop found");
    else
        printf("No loops");

    return 0;
}