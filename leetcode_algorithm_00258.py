class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        while num >= 10:
            sum = 0
            while num >= 10:
                sum += num%10
                num /= 10
            sum += num
            num = sum
        return num
