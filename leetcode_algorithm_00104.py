# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root == None:
            return 0
        return 1 + max(self.depth(root.left), self.depth(root.right))
    
    def depth(self, tree):
        if tree == None:
            return 0
        return 1 + max(self.depth(tree.left), self.depth(tree.right))
