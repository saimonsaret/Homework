newtype Polynom = Polynom [Int] deriving (Eq)

addition :: Polynom -> Polynom -> Polynom
addition (Polynom p1) (Polynom p2) = let plus p [] = p
                                         plus [] p = p
                                         plus (x:xs) (y:ys) = (x + y) : (plus xs ys)
                                     in Polynom (plus p1 p2)

substraction :: Polynom -> Polynom -> Polynom
substraction (Polynom p1) (Polynom p2) = let minus [] [] = []
                                             minus p [] = p
                                             minus [] (x:xs) = (-x) : (minus [] xs)
                                             minus (x : xs) (y : ys) = (x - y) : minus xs ys
                                         in Polynom (minus p1 p2)

adapt :: [Int] -> Int -> [Int]
adapt xs len = if (length xs < len)
                then xs ++ (replicate (len - length xs) 0)
                else take len xs
                                         
mult :: Polynom -> Polynom -> Polynom
mult (Polynom p1) (Polynom p2) = Polynom [sum $ zipWith (*) (adapt p1 i) (reverse (adapt p2 i)) | i <- [1..(length p1 + length p2)]]

showSign :: Int -> String
showSign x = if (x > 0)
             then "+"
             else ""

showSummand :: Int -> Int -> String
showSummand 0 _ = ""
showSummand x 0 = show x
showSummand x 1 = (showSign x) ++ (show x) ++ "X"
showSummand 1 power = "+X^" ++ (show power)
showSummand (-1) power = "-X^" ++ (show power)
showSummand x power = (showSign x) ++ (show x) ++ "X^" ++ (show power)

showHelper :: [Int] -> Int -> String
showHelper [] _ = ""
showHelper (x:xs) power = (showSummand x power) ++ (showHelper xs (power + 1))

instance Show Polynom where
    show (Polynom p) = showHelper p 0