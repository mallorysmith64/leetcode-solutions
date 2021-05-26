// 155. Min Stack
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:
// MinStack() initializes the stack object.
// void push(val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.

// Example 1:
// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// Output
// [null,null,null,null,-3,null,0,-2]

// Explanation:
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2
 
// Constraints:
// -231 <= val <= 231 - 1
// Methods pop, top and getMin operations will always be called on non-empty stacks.
// At most 3 * 104 calls will be made to push, pop, top, and getMin.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    int max;
    int min;
    int *items;
    int top;
} MinStack;

/** initialize your data structure here. */
struct stack* createStack(int capacity) {
    MinStack *newStack = (MinStack*)malloc(sizeof(MinStack)*1);
        newStack -> max = capacity;
        newStack -> top = -1;
        newStack -> items = (int*)malloc(sizeof(int) * capacity);
        printf("created a stack");
    return newStack;
}

// write push function here
// void minStackPush(MinStack* obj, int val) {
//     int top = -1;
//     if(top < max - 1) {
//         top++;
//         stack[top] = val;
//     } else {
//         printf("Stack Overflow");
//     }
//   newStack.push(val);
// }

// // write pop function here
// void minStackPop(MinStack* obj) {
//   newStack.pop(val);
// }

// // write top function here
// int minStackTop(MinStack* obj) {
//   newStack.top(val);
// }

// // write get min function here
// int minStackGetMin(MinStack* obj) {
//   newStack.getMin(val);
// }

// // write free function here
// void minStackFree(MinStack* obj) {
//     newStack.free(val);
// }

// test
int main() {
    struct stack *newStack = createStack(5);
 
    push(newStack, 1);
    push(newStack, 2);
    push(newStack, 3);
}


/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/