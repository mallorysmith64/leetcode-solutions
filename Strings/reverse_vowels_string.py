class Solution(object):
    def reverseVowels(self, s):
        vowels = set("aeiouAEIOU")
        l = 0
        r = len(s) - 1 # -1 b/c 0th indexing
        if len(s) == 0: #empty return itself
            return s
        while l < r:
            if s[l] in vowels and s[r] in vowels:
                s[r], s[l] = s[l], s[r]
                l = l + 1
                r = r - 1
            elif s[l] not in vowels:
                l = l + 1
            elif s[r] not in vowels:
                r = r - 1
        # Convert the list of characters back into a string before returning
        return "".join(s)
    
    s = "IceCreAm"
    s = "coyote"
    print(reverseVowels(None, list(s)))