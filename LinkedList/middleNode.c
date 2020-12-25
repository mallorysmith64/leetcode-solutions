// 876. Middle of the Linked List

// Given a non-empty, singly linked list with head node head, return a middle node of linked list.
// If there are two middle nodes, return the second middle node.

// Example 1:
// Input: [1,2,3,4,5]
// Output: Node 3 from this list (Serialization: [3,4,5])
// The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
// Note that we returned a ListNode object ans, such that:
// ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.

// Example 2:
// Input: [1,2,3,4,5,6]
// Output: Node 4 from this list (Serialization: [4,5,6])
// Since the list has two middle nodes with values 3 and 4, we return the second one.

// Note:
// The number of nodes in the given list will be between 1 and 100.
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> // ability to use NULL

// Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

// my solution:
void middleNode(struct ListNode *head)
{
    struct ListNode *fast = head, *slow = head;

    if (head != NULL)
    {
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        printf("\n middle element is: %d \n", slow->val);
        // return slow;
    }
}

void push(struct ListNode **head_ref, int new_data)
{
    // allocate node
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));

    // assign data
    new_node->val = new_data;

    // link the old list off the new node
    new_node->next = (*head_ref);

    // move the head to point to the new node
    (*head_ref) = new_node;
}

// utility function to print linked list
void printList(struct ListNode *p)
{
    while (p != NULL)
    {
        printf("%d -> ",p->val);
        p = p->next;
    }
        printf("NULL");
}

int main()
{
    struct ListNode *head = NULL;
    int i;

    for (i = 6; i > 0; i--)
    {
        push(&head, i);
        printList(head);
        middleNode(head);
    }

    return 0;
}