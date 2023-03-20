# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCompleteTree(self, root: Optional[TreeNode]) -> bool:
        null_seen= False

        queue =collections.deque([root])
        while queue:
            if null_seen:
                return not any(queue)
            else:
                for _ in range(len(queue)):
                    node = queue.popleft()

                    if not node:
                        null_seen =True
                    else:
                        if null_seen:
                            return False
                        else:
                            queue.append(node.left)
                            queue.append(node.right)
        return True