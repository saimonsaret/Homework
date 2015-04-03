helper :: Int -> Int -> Int -> Int -> Int
helper x y a len = if (y > 0)
                 then y
                 else if (x == a) 
                      then len - abs(y)
                      else y - 1

findPos :: [Int] -> Int -> Int
findPos list a = let len = length list
                 in let res = foldr (\x y -> helper x y a len) 0 list
                    in if res > 0 
                       then res
                       else -1