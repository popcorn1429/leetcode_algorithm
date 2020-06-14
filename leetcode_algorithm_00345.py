class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels = set('aiueoAIUEO')
        lstS = list(s)
        cnt = len(s)
        i = 0
        j = cnt-1
        while i < j:
            if lstS[i] in vowels:
                if lstS[j] in vowels:
                    lstS[i], lstS[j] = lstS[j], lstS[i]
                    i += 1
                    j -= 1
                else:
                    j -= 1
            else:
                i += 1
                if not lstS[j] in vowels:
                    j -= 1
        return "".join(lstS)
