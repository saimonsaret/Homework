data Tree a = Leaf a | Branch (Tree a) a (Tree a)

foldTree :: Tree a -> (b -> a -> b) -> b -> b
treeFold (Leaf a) f res = f res a
treeFold (Branch leftBranch a rightBranch) f res = treeFold rightBranch f (treeFold leftBranch f (f res a))