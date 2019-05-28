
class Solution(object):
    def nthUglyNumber(self, n):
        uglyNumbers = [1]
        idx2=0
        idx3=0
        idx5=0
        for i in range(n-1):
            num2=uglyNumbers[idx2]*2
            num3=uglyNumbers[idx3]*3
            num5=uglyNumbers[idx5]*5
            num = min(num2, num3, num5)
            uglyNumbers.append(num)
            if num == num2:
                idx2 += 1
            if num == num3:
                idx3 += 1
            if num == num5:
                idx5 += 1
        return uglyNumbers[n-1]



if __name__ == '__main__':
    obj = Solution()
    print("the 1690th ugly number is ", obj.nthUglyNumber(1690))
