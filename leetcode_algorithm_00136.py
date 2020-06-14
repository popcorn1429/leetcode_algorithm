'''
题目：
一个无序的正整数数组，非空，其中有且仅有一个数字仅出现一次，其他的数字都是出现了两次
找出这个特别的数字

题目本身超级简单
但是有一个额外的限制：额外空间使用 O(1) ,时间复杂度 O(n)
所以，一切针对数组进行排序，或者排重的算法几乎都不可用了
我自己想不到解法，看了答案才知道，是要通过异或运算~
'''

class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        for n in nums:
            result ^= n
        return result
