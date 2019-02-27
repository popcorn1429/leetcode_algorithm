class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        dict=set()
        for i in nums:
            if i in dict:
                return True
            else:
                dict.add(i)
        return False