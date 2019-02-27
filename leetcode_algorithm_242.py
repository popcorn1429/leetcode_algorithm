class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """

        #dict_s = {}
        #for c in s:
        #    if dict_s.get(c) == None:
        #        dict_s[c] = 1
        #    else:
        #        dict_s[c] += 1
        #
        #dict_t = {}
        #for c in t:
        #    if dict_t.get(c) == None:
        #        dict_t[c] = 1
        #    else:
        #        dict_t[c] += 1
        #
        #return dict_t == dict_s

        return collections.Counter(s) == collections.Counter(t)
        
        
        