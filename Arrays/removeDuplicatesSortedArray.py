# Given an integer array nums sorted in non-decreasing order, 
# remove the duplicates in-place such that each unique element appears only once. 
# The relative order of the elements should be kept the same.

# Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. 
# After removing duplicates, return the number of unique elements k.

# The first k elements of nums should contain the unique numbers in sorted order. 
# The remaining elements beyond index k - 1 can be ignored.

# Custom Judge:

# The judge will test your solution with the following code:

# int[] nums = [...]; // Input array
# int[] expectedNums = [...]; // The expected answer with correct length

# int k = removeDuplicates(nums); // Calls your implementation

# assert k == expectedNums.length;
# for (int i = 0; i < k; i++) {
#     assert nums[i] == expectedNums[i];
# }
# If all assertions pass, then your solution will be accepted.

# Example 1:

# Input: nums = [1,1,2]
# Output: 2, nums = [1,2,_]
# Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
# It does not matter what you leave beyond the returned k (hence they are underscores).

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        # Get the total number of elements in the input list
        n = len(nums)
    
        # 'j' is a pointer; it tracks where the next unique element should be placed
        # We start at 1 because the first element (index 0) is always unique
        j = 1

        # 'i' is a pointer; it scans through the list starting from the second element
        for i in range(1, n):
            # If the current element is different from the one before it, it's a new unique value
            if nums[i] != nums[i-1]:
                # Move the unique value found at 'i' to the position tracked by 'j'
                nums[j] = nums[i]
                # Increment 'j' to prepare the next available slot for a unique element
                j += 1
        
        # Return 'j', which now represents the count of unique elements found
        return j