// 1441. Build an Array With Stack Operations

// Given an array target and an integer n.
// In each iteration, you will read a number from  list = {1,2,3..., n}.

// Build the target array using the following operations:
// Push: Read a new element from the beginning list, and push it in the array.
// Pop: delete the last element of the array.

// If the target array is already built, stop reading more elements.
// Return the operations to build the target array. You are guaranteed that the answer is unique.

// Example 1:
// Input: target = [1,3], n = 3
// Output: ["Push","Push","Pop","Push"]

// Explanation:
// Read number 1 and automatically push in the array -> [1]
// Read number 2 and automatically push in the array then Pop it -> [1]
// Read number 3 and automatically push in the array -> [1,3]

// Example 2:
// Input: target = [1,2,3], n = 3
// Output: ["Push","Push","Push"]

// Example 3:
// Input: target = [1,2], n = 4
// Output: ["Push","Push"]
// Explanation: You only need to read the first 2 numbers and stop.

// Example 4:
// Input: target = [2,3,4], n = 4
// Output: ["Push","Pop","Push","Push","Push"]

// Constraints:
// 1 <= target.length <= 100
// 1 <= target[i] <= n
// 1 <= n <= 100
// target is strictly increasing.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>

char **buildArray(int *target, int targetSize, int n, int *returnSize)
{
    char **newArray = malloc(sizeof(char * [n * 2])), j = 0;
    for (int i = 0, k = 1; i < targetSize;)
    {
        newArray[j++] = "Push", k++ != target[i] ? newArray[j++] = "Pop" : i++;
    }

    return *returnSize = j, newArray;