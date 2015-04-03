bolting :: [Int] -> [Int]
bolting (x : list) = x : bolting [y | y <- list, mod y x > 0]

primeNumbers = bolting [2..]