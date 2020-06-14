class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        zeroPos = -1
        
        pos = 0
        last = len(nums)
        while pos < last:
            if nums[pos] == 0:
                if zeroPos == -1:
                    zeroPos = pos
            elif zeroPos > -1:
                nums[zeroPos] = nums[pos]
                nums[pos] = 0
                zeroPos += 1
            pos += 1
