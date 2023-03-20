# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree_rec(self, i1, i2, p1, p2):
        if i1 >= i2 or p1 >= p2:
            return None
        root_val = self.postorder[p2-1]
        root = TreeNode(root_val)
        it = self.inorder.index(root_val)
        diff = it - i1
        root.left = self.buildTree_rec(i1, i1+diff, p1, p1+diff)
        root.right = self.buildTree_rec(i1+diff+1, i2, p1+diff, p2-1)
        return root
    
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        n = len(inorder)
        if n == 0:
            return None
        self.inorder = inorder
        self.postorder = postorder
        return self.buildTree_rec(0, n, 0, n)