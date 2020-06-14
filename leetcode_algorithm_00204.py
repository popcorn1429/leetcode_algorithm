'''
Count the number of prime numbers less than a non-negative number, n.
'''

class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 2:
            return 0
        
        cnt = 1
        primes = [True]*n
        i = 3
        while i < n:
            if primes[i-1]:
                cnt += 1
                j = 3
                while i * j < n:
                    if primes[i*j-1]:
                        primes[i*j-1]=False
                    j += 2
            i += 2
        return cnt

