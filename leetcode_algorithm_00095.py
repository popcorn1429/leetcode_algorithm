# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        if n == 0:
            return []
        forest = self.generate(1, n)
        #self.showForest(forest)
        return forest

    def generate(self, floor, ceiling):
        if floor > ceiling:
            return [None]

        forest = []
        for i in range(floor, ceiling+1):
            leftForest = self.generate(floor, i-1)
            rightForest = self.generate(i+1, ceiling)
            forest += self.mixForests(i, leftForest, rightForest)
        return forest
        

    def mixForests(self, parent, leftForest, rightForest):
        forest = []
        for i in range(len(leftForest)):
            for j in range(len(rightForest)):
                dupParent = TreeNode(parent)
                dupParent.left = leftForest[i]
                dupParent.right = rightForest[j]
                forest.append(dupParent)
        return forest

    def showForest(self, forest):
        print("whole forest:")
        for tree in forest:
            tree_detail = '['
            tree_detail += self.showTree(tree)
            tree_detail += ']'
            print(tree_detail)

    def showTree(self, tree):
        if tree == None:
            return 'null,'

        detail = str(tree.val)
        detail += ','
        detail += self.showTree(tree.left)
        detail += self.showTree(tree.right)
        return detail

if __name__ == '__main__':
    s = Solution()
    s.generateTrees(4)
