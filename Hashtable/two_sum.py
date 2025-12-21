# Given an array of integers nums and an integer target, 
# return indices of the two numbers such that they add up to target.

# You may assume that each input would have exactly one solution, 
# and you may not use the same element twice.

# You can return the answer in any order.

class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        prev_map = {} 

        for i, n in enumerate(nums):
            diff = target - n
            
            if diff in prev_map:
                return [prev_map[diff], i]
            
            prev_map[n] = i
            
