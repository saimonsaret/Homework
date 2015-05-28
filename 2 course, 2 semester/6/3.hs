data BinarySearchTree a = Leaf | Node (BinarySearchTree a) a (BinarySearchTree a) deriving (Eq, Show)

addTreeElement :: (Ord a) => BinarySearchTree a -> a -> BinarySearchTree a
addTreeElement Leaf newVal = Node Leaf newVal Leaf
addTreeElement (Node leftBranch val rightBranch) newVal = if (newVal < val)
                                                             then Node (addTreeElement leftBranch newVal) val rightBranch
                                                             else if (newVal > val)
                                                                  then Node leftBranch val (addTreeElement rightBranch newVal)   
                                                                  else Node leftBranch val rightBranch

removeTreeElement :: (Ord a) => BinarySearchTree a -> a -> BinarySearchTree a
removeTreeElement Leaf val = Leaf
removeTreeElement (Node leftBranch val rightBranch) delVal = if (delVal < val)
                                                                then Node (removeTreeElement leftBranch delVal) val rightBranch
                                                                else if (delVal > val)
                                                                     then Node leftBranch val (removeTreeElement rightBranch delVal)
                                                                     else case (leftBranch, rightBranch) of
                                                                               (Leaf, Leaf) -> Leaf
                                                                               (Leaf, _) -> rightBranch
                                                                               (_, Leaf) -> leftBranch
                                                                               (_, Node Leaf tempVal tempRight) -> Node leftBranch tempVal tempRight
                                                                               (_, Node tempLeft tempVal tempRight) -> Node leftBranch minElement (removeTreeElement rightBranch minElement) 
                                                                                   where minElement = getMinElement rightBranch

getMinElement :: (Ord a) => BinarySearchTree a -> a
getMinElement Leaf = error "No nodes in the tree"
getMinElement (Node Leaf val _) = val
getMinElement (Node leftBranch val _) = getMinElement leftBranch

findTreeElement :: (Ord a) => BinarySearchTree a -> a -> Bool
findTreeElement Leaf searchVal = False
findTreeElement (Node leftBranch val rightBranch) searchVal = if (searchVal < val)
                                                              then findTreeElement leftBranch searchVal
                                                              else if (searchVal > val)
                                                                  then findTreeElement rightBranch searchVal
                                                                  else True
treeSize :: BinarySearchTree a -> Int
treeSize Leaf = 0
treeSize (Node leftBranch val rightBranch) = treeSize(leftBranch) + treeSize(rightBranch) + 1

treeHeight :: BinarySearchTree a -> Int
treeHeight (Leaf) = 0
treeHeight (Node leftBranch val rightBranch) = 1 + max (treeHeight leftBranch) (treeHeight rightBranch)