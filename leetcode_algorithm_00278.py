# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        if isBadVersion(1):
            return 1
        if n == 2:
            return 2

        start = 1
        end = n
        while end - start > 1:
            checkPoint = (start + end)/2
            if isBadVersion(checkPoint):
                end = checkPoint
            else:
                start = checkPoint
        return end
