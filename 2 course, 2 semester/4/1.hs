import Data.Maybe

data Tree a = Leaf a | Branch (Tree a) a (Tree a)

findElement :: Tree a -> (a -> Bool) -> Maybe a
findElement (Leaf a) f = if (f a)
                            then Just a
                            else Nothing
findElement (Branch leftBranch a rightBranch) f = if (f a)
                                                   then Just a
                                                   else case (findElement leftBranch f, findElement rightBranch f) of
                                                       (Just x, _) -> Just x
                                                       (_, Just x) -> Just x
                                                       (_, _) -> Nothing