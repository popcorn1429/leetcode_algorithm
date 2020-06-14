class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        dict = {}
        totalCount = len(nums)
        for i in range(0, totalCount):
            num = nums[i]
            if dict.get(num) == None:
                dict[num] = i
            else:
                if i - dict[num] <= k:
                    return True
                dict[num] = i
                        
        return False
        
