findMax :: ([Integer], Integer, Integer, Integer) -> Integer
findMax (x1:x2:x3:list, curMax, pos, maxPos) = if list == []
                                               then if x1 + x3 > curMax
                                                    then pos
                                                    else maxPos
                                               else if x1 + x3 > curMax
                                                    then findMax(x2:x3:list, x1 + x3, pos + 1, pos)
                                                    else findMax(x2:x3:list, curMax, pos + 1, maxPos)
maxPos list = let len = length list
			  in if (len <= 2)
			  then -1
			  else let curMax = head list + head(tail $ tail list)
			  in findMax(list, curMax - 1, 2, -1)