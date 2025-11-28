class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.strip()
        words = s.split()
        words.reverse()
        return " ".join(words)

s = " coyote is a word"
print(Solution().reverseWords(s))