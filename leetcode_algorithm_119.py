class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        if rowIndex == 0:
            return [1]

        def factorial(n):
            if n <= 1:
                return 1
            result = 1
            for i in range(2, n+1):
                result *= i
            return result

        def combination(i, rowIndex):
            return factorial(rowIndex)/(factorial(i)*factorial(rowIndex-i))

        row = []
        for i in range(rowIndex+1):
            row.append(combination(i, rowIndex))

        return row