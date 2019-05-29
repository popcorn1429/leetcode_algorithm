class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        if numRows == 0:
            return []

        result = [[1]]
        for i in range(2, numRows + 1):
            last_pascal = result[-1]
            pascal = []
            for j in range(i):
                if j == 0 or j == i-1:
                    pascal.append(1)
                else:
                    pascal.append(last_pascal[j-1] + last_pascal[j])
            result.append(pascal)

        return result