class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) == 0:
            return 0

        profit = 0
        low = prices[0]
        high = prices[0]
        for price in prices:
            if price <= low:
                profit += (high - low)
                low = price
                high = price
            else:
                if price < high:
                    profit += (high - low)
                    low = price
                    high = price
                else:
                    high = price
        profit += (high - low)
        return profit