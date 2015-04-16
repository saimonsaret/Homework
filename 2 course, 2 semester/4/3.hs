mapCount :: [Integer] -> Integer
mapCount = sum . map (\x -> mod (x + 1) 2)

filterCount :: [Integer] -> Int
filterCount = length . filter (\x -> mod x 2 == 0)

foldrCount :: [Integer] -> Integer
foldrCount = foldr (\x y -> (mod (x + 1) 2) + y) 0