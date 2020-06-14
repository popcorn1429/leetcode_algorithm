class Solution(object):
    def match(self, s1, l1, i1, s2, l2, i2, c3, cntC3):
        '''
        思路：
        s3 假设从某字符 x 开头，持续 n 个x之后，遇到一个其他字符 y
        然后检查：
        从s1的开头开始，计算有 j 个字符 x
        从s2的开头开始，计算有 k 个字符 x

        接下来
        1 如果 j + k 刚好等于 n，那么 s3 的这 n 个 x就是s1 与s2 里面的x合并一起得到的
         接下来考虑字符y，就是下一次执行这个函数的事情了
         这次就可以直接返回 true 了
         因为要把进展掉的部分跳过，所以返回的是一个元组 (true, j, k)

        2 如果 j + k < n, 有问题，这样无论如何 s1 和 s2 也不能拼出来 s3
         这种情况也很省心，连后续的执行都省了
         返回 false 
         依旧保持返回的内容格式一致 (false, j, k) 这时的 j k 没啥用处

        3 如果 j + k > n ，这就是比较复杂的情况了
         3.1 j > n and k > n:  又是没有可能成功的情况，s1 s2 里面的字符x过多了
             返回 (false, j, k)
         3.2 j 或者 k 之一大于 n，姑且认为 j > n
             另一个小于等于n,也就是  k <= n
             返回 (true, n-k, k)
         3.3 j <= n and k <= n
             返回 ((true, j, n-j), (true, n-k, k))
        '''
        cntC1 = 0
        while i1 < l1 and s1[i1] == c3:
            cntC1 += 1
            i1 += 1

        cntC2 = 0
        while i2 < l2 and s2[i2] == c3:
            cntC2 += 1
            i2 += 1

        if cntC1 + cntC2 == cntC3:
            return ((True, cntC1, cntC2),)
        elif cntC1 + cntC2 < cntC3:
            return ((False, cntC1, cntC2),)
        else:
            if cntC1 > cntC3 and cntC2 > cntC3:
                return ((False, cntC1, cntC2),)
            elif cntC1 > cntC3:
                return ((True, cntC3 - cntC2, cntC2),)
            elif cntC2 > cntC3:
                return ((True, cntC1, cntC3 - cntC1),)
            else:
                return ((True, cntC1, cntC3 - cntC1), (True, cntC3 - cntC2, cntC2))
       
    def check(self, s1, l1, i1, s2, l2, i2, s3, l3, i3):
        if i3 == l3:
            return True

        c3 = s3[i3]
        cntC3 = 0
        while i3 < l3 and s3[i3] == c3:
            i3 += 1
            cntC3 += 1
        
        result = self.match(s1, l1, i1, s2, l2, i2, c3, cntC3)
        if len(result) == 1:
            if result[0][0]:
                return self.check(s1, l1, i1 + result[0][1], s2, l2, i2 + result[0][2], s3, l3, i3)
            else:
                return False
        else:
            return self.check(s1, l1, i1 + result[0][1], s2, l2, i2 + result[0][2], s3, l3, i3) or self.check(s1, l1, i1 + result[1][1], s2, l2, i2 + result[1][2], s3, l3, i3)

    def isInterleave(self, s1, s2, s3):
        l1 = len(s1)
        l2 = len(s2)
        l3 = len(s3)
        if l1 + l2 != l3:
            return False

        if l3 == 0:
            return True

        return self.check(s1, l1, 0, s2, l2, 0, s3, l3, 0)

    
         


def main():
    s1 = 'aabcc'
    s2 = 'dbbca'
    s3 = 'aadbbbaccc'
    solution = Solution()
    print(solution.isInterleave(s1, s2, s3))

if __name__ == '__main__':
    main()
