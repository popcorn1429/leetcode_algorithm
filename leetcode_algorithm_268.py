class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt = len(nums)
        sum = (1+cnt)*cnt/2
        for n in nums:
            sum -= n
        return sum