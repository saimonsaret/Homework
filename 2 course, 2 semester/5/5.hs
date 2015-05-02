import Control.Monad

isBigger :: (Ord a) => (a, a, a) -> Maybe a
isBigger(x1, x2, x3) = if (x1 < x2 && x3 < x2)
                       then Just x2
                       else Nothing

findBigger :: (Ord a) => [a] -> Maybe a
findBigger (x1:x2:x3:xs) = mplus (isBigger(x1, x2, x3)) (findBigger(x2:x3:xs))
findBigger _ = Nothing