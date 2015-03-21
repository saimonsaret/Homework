data TreeNode = Leaf | Branch(TreeNode)(TreeNode) 

treeHeight :: TreeNode -> Integer
treeHeight(Leaf) = 0
treeHeight(Branch left right) = max(treeHeight left)(treeHeight right) + 1

minLeafDist :: TreeNode -> Integer
minLeafDist(Leaf) = 0
minLeafDist(Branch left right) = min(minLeafDist left)(minLeafDist right) + 1