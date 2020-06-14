# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True

        def depth(tree):
            if not tree:
                return 0
            return 1 + max(depth(tree.left), depth(tree.right))

        return self.isBalanced(root.left) and self.isBalanced(root.right) and abs(depth(root.left) - depth(root.right)) <= 1
