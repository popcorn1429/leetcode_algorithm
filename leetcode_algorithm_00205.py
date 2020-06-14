
class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """

        dict = {}
        rdict = {}
        for k,v in zip(s, t):
            if k != dict.setdefault(v, k) or v != rdict.setdefault(k, v):
                return False

        return True

