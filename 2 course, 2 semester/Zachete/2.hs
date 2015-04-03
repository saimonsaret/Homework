data Tree a = Leaf a | Branch (Tree a) a (Tree a)

fnHelper :: Tree Int -> [Int] -> [Int]
fnHelper (Leaf a) buf = if (a < 0)
                        then a : buf
                        else buf
fnHelper (Branch lb a rb) buf = if (a < 0)
                                then fnHelper rb (a : (fnHelper lb buf))
                                else fnHelper rb (fnHelper lb buf)

filterNegative :: Tree Int -> [Int]
filterNegative tr = fnHelper tr []