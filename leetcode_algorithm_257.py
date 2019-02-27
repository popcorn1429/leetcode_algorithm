# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        result = []
        if root == None:
            return result

        route = str(root.val)
        self.traceAllPaths(root, route, result)
        return result

    def traceAllPaths(self, root, route, result):
        if root.left == None and root.right == None:
            result.append(route)
            return
        
        if root.left != None:
            route_left = route + "->" + str(root.left.val)
            self.traceAllPaths(root.left, route_left, result)
        if root.right != None:
            route_right = route + "->" + str(root.right.val)
            self.traceAllPaths(root.right, route_right, result)