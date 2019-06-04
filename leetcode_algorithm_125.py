class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s=s.upper()

        def isAlphaOrDigit(c):
            return 'A' <= c <= 'Z' or '0' <= c <= '9'

        n = len(s)
        i=0
        j=n-1
        while i <= j:
            while i < n and not isAlphaOrDigit(s[i]):
                i += 1
            while j >= 0 and not isAlphaOrDigit(s[j]):
                j -= 1

            if i >= n or j < 0:
                return True

            if s[i] != s[j]:
                return False

            i += 1
            j -= 1

        return True
            
    def another_solution(self, s):
        temp = "".join([c for c in s.lower() if c in "0123456789abcdefghijklmnopqrstuvwxyz"])
        return temp == temp[::-1]

    def another_solution_(self, s):
        import re
        s = s.lower()
        s = re.sub('[^a-z0-9]', '', s)
        left, right = 0, len(s)-1
        while left < right:
            if (s[left] != s[right]):
                return False
            left += 1
            right -= 1
        return True
