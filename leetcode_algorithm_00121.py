class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) == 0:
            return 0

        low = prices[0]
        cur_profit = 0
        for price in prices:
            if low < price:
                if cur_profit < price - low:
                    cur_profit = price - low
            else:
                low = price
        return cur_profit

       
