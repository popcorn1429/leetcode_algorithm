# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrderBottom(self, root:TreeNode) -> list[list[int]]:
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []

        result=[]

        def countOn(root:TreeNode, level:int):
            if not root:
                return
            if level < len(result):
                result[level].append(root.val)
            else:
                result.append([root.val])
            countOn(root.left, level+1)
            countOn(root.right, level+1)

        countOn(root, 0)
        return result[::-1]

