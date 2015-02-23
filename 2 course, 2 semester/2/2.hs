revpows :: Integer -> [Integer]
revpows n = if (n == 1)
            then [2]
            else let res = revpows(n - 1)
                 in head res * 2 : res
powers :: Integer -> [Integer]
powers n = let list = revpows(n) 
           in reverse list
