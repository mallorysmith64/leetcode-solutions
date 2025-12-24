class Solution:
    def moveZeroes(self, nums: list) -> None:
        # nums.sort() modifies the list in-place.
        # The 'key' parameter takes a function that tells Python 
        # HOW to compare the items.
        
        # lambda x: x == 0
        # 'lambda' creates a quick, one-line function.
        # 'x == 0' is the logic: 
        #    - If it's NOT a zero, it returns False (which Python treats as 0).
        #    - If it IS a zero, it returns True (which Python treats as 1).
        nums.sort(key=lambda x: x == 0) #if I made x!=0 zeros would move to the front
        
nums = [0, 1, 0, 3, 12]
Solution().moveZeroes(nums)
print(nums)