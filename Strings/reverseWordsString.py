class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.strip()
        words = s.split()
        reversed_words = words[::-1]
        print(" ".join(reversed_words))
        return " ".join(reversed_words)