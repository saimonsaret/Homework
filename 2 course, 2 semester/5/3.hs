findAllSeq :: Int -> [[Int]]
findAllSeq 1 = [[1], [2], [3]]
findAllSeq n = concatMap(\x -> [(1:x), (2:x), (3:x)]) (findAllSeq(n - 1))