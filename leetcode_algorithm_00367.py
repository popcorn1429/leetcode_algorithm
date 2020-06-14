class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        begin, end = 1, num
        while begin < end - 1:
            middle = (begin + end) // 2
            if middle ** 2 == num:
                return True
            elif middle ** 2 < num:
                begin = middle
            else:
                end = middle
        return begin ** 2 == num or end ** 2 == num
