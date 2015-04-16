areAllDifferent :: (Eq a) => [a] -> Bool
areAllDifferent [] = True
areAllDifferent (x:list) = if (elem x list)
                         then False
                         else areAllDifferent list