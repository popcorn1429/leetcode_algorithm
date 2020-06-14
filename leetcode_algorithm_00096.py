class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        traces = {0:1, 1:1}
        for i in range(2, n+1):
            sum = 0
            if i % 2 == 0:
                for j in range(i/2):
                    sum += 2*traces[j]*traces[i-j-1]
            else:
                for j in range(i/2):
                    sum += 2*traces[j]*traces[i-j-1]
                sum += traces[i/2]*traces[i/2]
            
            traces[i] = sum
        return traces[n]
