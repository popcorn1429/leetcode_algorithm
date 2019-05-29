# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0

        dl = self.minDepth(root.left)
        dr = self.minDepth(root.right)
        dmin = min(dl, dr)
        dmax = max(dl, dr)
        if dmin == 0:
            return 1 + dmax
        else:
            return 1 + dmin
