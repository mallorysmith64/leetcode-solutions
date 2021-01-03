// 234. Palindrome Linked List

// Given a singly linked list, determine if it is a palindrome.

// Example 1:
// Input: 1->2
// Output: false

// Example 2:
// Input: 1->2->2->1
// Output: true

// Follow up:
// Could you do it in O(n) time and O(1) space?

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

bool isPalindrome(struct ListNode *head)
{
    struct ListNode *fast = head, *slow = head;
    struct ListNode *prev = NULL;
    struct ListNode *temp;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        temp = slow;
        slow = slow->next;
        temp->next = prev;
        prev = temp;
    }

    if (fast != NULL)
    {
        slow = slow->next;
    }

    while (prev != NULL && slow != NULL)
    {
        if (prev->val != slow->val)
        {
            return false;
        }

        prev = prev->next;
        slow = slow->next;
    }
    return (prev == NULL && slow == NULL);
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

// create second list
void create2(int A[], int n)
{
    int i;
    struct ListNode *t, *last;
    second = (struct ListNode *)malloc(sizeof(struct ListNode));
    second->val = A[0];
    second->next = NULL;
    last = second;

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
    int A[] = {1,2,2,1}; // palindrome
    int B[] = {1,2,3,4}; // not a palindrome
    create(A, 4);
    create2(B, 4);

    printList(head);
    isPalindrome(head) ? printf("\nIs a Palindrome") : printf("\nNot a Palindrome");
    
    printf("\n\n");
    
    printList(second);
    isPalindrome(second) ? printf("\nIs a Palindrome") : printf("\nNot a Palindrome");

    return 0;
}