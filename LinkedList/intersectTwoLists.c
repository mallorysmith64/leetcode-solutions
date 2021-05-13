// 160. Intersection of Two Linked Lists

// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect.
// If the two linked lists have no intersection at all, return null.
// For example, the following two linked lists begin to intersect at node c1:
// It is guaranteed that there are no cycles anywhere in the entire linked structure.
// Note that the linked lists must retain their original structure after the function returns.

// Example 1:

// Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
// Output: Intersected at '8'
// Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
// From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
// Example 2:

// Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
// Output: Intersected at '2'
// Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
// From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.

// Example 3:

// Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
// Output: No intersection
// Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
// Explanation: The two lists do not intersect, so return null.

// Constraints:
// The number of nodes of listA is in the m.
// The number of nodes of listB is in the n.
// 0 <= m, n <= 3 * 104
// 1 <= Node.val <= 105
// 0 <= skipA <= m
// 0 <= skipB <= n
// intersectVal is 0 if listA and listB do not intersect.
// intersectVal == listA[skipA + 1] == listB[skipB + 1] if listA and listB intersect.

// Follow up: Could you write a solution that runs in O(n) time and use only O(1) memory?

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>

// Definition for singly-linked lists
struct ListNode
{
  int val;
  struct ListNode *next;
} *head = NULL, *second = NULL;

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
  // two pointers
  struct ListNode *A = headA, *B = headB;

  // check that pointers are not null
  while (A != NULL || B != NULL)
  {
    // while there is an intersection, return intersecting node
    if (A == B)
      printf("Intersects at %d", A->val);
    return A;
    // no intersection, move next, if null begin on other head
    A = A ? A->next : headB;
    B = B ? B->next : headA;
  }
  // return intersecting node
  printf("Intersects at %d", A->val);
  return A;
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
  int i;

  int A[] = {1, 2, 3, 4, 5}; // headA
  int B[] = {6, 7, 8, 4, 5}; // headB

  create(A, 5);
  create2(B, 5);

  printList(head);

  // testing WIP
  // intersecting node should be 4
  // printf("\n The node of intersection is %d \n", getIntersectionNode(head->val, second->val));

  printf("\n\n");

  printList(second);

  return 0;
}