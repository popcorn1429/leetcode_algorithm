class Solution(object):
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num == 1:
            return True
        if num < 4:
            return False

        while num % 4 == 0:
            if num == 4:
                return True
            num /= 4
        return num == 0
