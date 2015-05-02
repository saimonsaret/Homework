helper :: Int -> Int -> String -> IO()
helper 0 max stack = putStrLn(stack)
helper num max stack = if (num < max) then
                           return ()
                       else 
                       if (num == max) then 
                           helper 0 max (concat[stack, show(num)])
                       else do
                           helper (num - max) max (concat[stack, show(max), " + "])
                           helper num (max + 1) stack
                           return ()
                           
printDecompositions :: Int -> IO()
printDecompositions n = helper n 1 (concat[show(n), " = "])