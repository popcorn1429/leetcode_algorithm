class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        words = str.split()
        dict_words = {}
        dict_pattern = {}
        cnt = len(pattern)
        if cnt != len(words):
            return False

        i = 0
        while i < cnt:
            k = pattern[i]
            v = words[i]
            if v != dict_words.setdefault(k, v) or k != dict_pattern.setdefault(v, k):
                return False
            i += 1
        return True
