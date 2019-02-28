class Solution(object):
    def reverseString(self, s):
        """
        :type s: List[str]
        :rtype: None Do not return anything, modify s in-place instead.
        """

        cnt = len(s)
        if cnt <= 1:
            return 
        i = 0
        j = cnt-1
        while i < j:
            s[i], s[j] = s[j], s[i]
            i += 1
            j -= 1