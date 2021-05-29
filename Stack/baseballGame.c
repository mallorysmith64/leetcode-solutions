// 682. Baseball Game
// Easy

// You are keeping score for a baseball game with strange rules.
// The game consists of several rounds, where the scores of past rounds may affect future rounds' scores.

// At the beginning of the game, you start with an empty record.
// You are given a list of strings ops, where ops[i] is the ith operation you must apply to the record and is one of the following:

// An integer x - Record a new score of x.
// "+" - Record a new score that is the sum of the previous two scores. It is guaranteed there will always be two previous scores.
// "D" - Record a new score that is double the previous score. It is guaranteed there will always be a previous score.
// "C" - Invalidate the previous score, removing it from the record. It is guaranteed there will always be a previous score.
// Return the sum of all the scores on the record.

// Example 1:
// Input: ops = ["5","2","C","D","+"]
// Output: 30
// Explanation:
// "5" - Add 5 to the record, record is now [5].
// "2" - Add 2 to the record, record is now [5, 2].
// "C" - Invalidate and remove the previous score, record is now [5].
// "D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
// "+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
// The total sum is 5 + 10 + 15 = 30.

// Example 2:

// Input: ops = ["5","-2","4","C","D","9","+","+"]
// Output: 27
// Explanation:
// "5" - Add 5 to the record, record is now [5].
// "-2" - Add -2 to the record, record is now [5, -2].
// "4" - Add 4 to the record, record is now [5, -2, 4].
// "C" - Invalidate and remove the previous score, record is now [5, -2].
// "D" - Add 2 * -2 = -4 to the record, record is now [5, -2, -4].
// "9" - Add 9 to the record, record is now [5, -2, -4, 9].
// "+" - Add -4 + 9 = 5 to the record, record is now [5, -2, -4, 9, 5].
// "+" - Add 9 + 5 = 14 to the record, record is now [5, -2, -4, 9, 5, 14].
// The total sum is 5 + -2 + -4 + 9 + 5 + 14 = 27.

// Example 3:

// Input: ops = ["1"]
// Output: 1

// Constraints:
// 1 <= ops.length <= 1000
// ops[i] is "C", "D", "+", or a string representing an integer in the range [-3 * 104, 3 * 104].
// For operation "+", there will always be at least two previous scores on the record.
// For operations "C" and "D", there will always be at least one previous score on the record.

// Solution
#include <stdio.h>
#include <stdlib.h>

int calPoints(char **ops, int opsSize)
{
    int i = 0;
    int num = 0;

    struct stack
    {
        unsigned int capacity;
        int top;
        int *arr;
    } * s_ops;

    struct stack *create_stack(unsigned capacity)
    {
        struct stack *s1 = (struct stack *)malloc(sizeof(struct stack));
        s1->top = -1;
        s1->capacity = capacity;
        s1->arr = (struct stack *)malloc(sizeof(int) * capacity);
        return s1;
    }

    int push(struct stack * s, int new_char)
    {
        s->arr[++s->top] = new_char;
        return s->top;
    }

    int pop(struct stack * s)
    {
        s->arr[s->top--] = -1;
        return s->top;
    }

    int total(struct stack * s)
    {
        int sum = 0;
        for (int i = 0; i <= s->top; i++)
        {
            sum = sum + s->arr[i];
        }
        return sum;
    }

    if (opsSize > 0)
    {
        s_ops = create_stack(opsSize);
    }

    for (i = 0; i < opsSize; i++)
    {
        if (*ops[i] == '+')
        {
            push(s_ops, ((s_ops->arr[s_ops->top]) + (s_ops->arr[(s_ops->top) - 1])));
        }
        else if (*ops[i] == 'C')
        {
            pop(s_ops);
        }
        else if (*ops[i] == 'D')
        {
            push(s_ops, ((s_ops->arr[s_ops->top]) * 2));
        }
        else
        {
            num = atoi(ops[i]);
            push(s_ops, num);
        }
    }
    return total(s_ops);
}

// need to test