digitSum :: Integer -> Integer
digitSum(n) = if (n == 0)
              then 0
              else (mod n 10) + digitSum(div n 10) 