class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        num = 1
        while num <= n:
            if num == n:
                return True
            num = num*2
        return False
