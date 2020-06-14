class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        s = set(nums1)
        t = set()
        for i in nums2:
            if i in s:
                t.add(i)
        r = list(t)
        return r
