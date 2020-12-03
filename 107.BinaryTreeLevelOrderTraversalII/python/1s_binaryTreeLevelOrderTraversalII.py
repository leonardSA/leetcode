from typing import List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        return self.__levelOrderBottomRec(root, 0, [])[::-1]

    def __levelOrderBottomRec(self, root, level, res: List[List[int]]):
        if len(res) > level:
            res[level].append(root.val)
        else:
            res.append([root.val])

        if root.left:
            self.__levelOrderBottomRec(root.left, level + 1, res)
        if root.right:
            self.__levelOrderBottomRec(root.right, level + 1, res)

        return res
