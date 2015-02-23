find :: ([Integer], Integer) -> Integer
find([], n) = -1
find(list, n) = if head list == n
                then 1
                else let ans = find(tail list, n)
                     in if ans == -1
                        then -1
                        else ans + 1
